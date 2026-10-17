/* Host presentation of the game's ROM terrain columns and scenery records.
   No guest memory, timing, input, or executable authority is modified here. */
#include "jungle/widescreen.h"
#include "jungle/renderer_v10_30.h"
#include <string.h>
static int floor16(int value) {
  return value >= 0 ? value / 16 : (value - 15) / 16;
}
static uint16_t word(const uint8_t *w, unsigned a) {
  return (uint16_t)(w[a] | ((uint16_t)w[a + 1u] << 8));
}
static int rom_byte(const uint8_t *rom, size_t size, unsigned bank,
                    unsigned addr, uint8_t *v) {
  size_t offset = ((bank & 127u) * 32768u) + (addr & 32767u);
  if (addr < 32768u || addr > 65535u || offset >= size)
    return 0;
  *v = rom[offset];
  return 1;
}
static int rom_word(const uint8_t *rom, size_t size, unsigned bank,
                    unsigned addr, uint16_t *v) {
  uint8_t lo, hi;
  if (!rom_byte(rom, size, bank, addr, &lo) ||
      !rom_byte(rom, size, bank, addr + 1u, &hi))
    return 0;
  *v = (uint16_t)(lo | ((uint16_t)hi << 8));
  return 1;
}
void jungle_wide_invalidate(JungleWideState *wide) {
  if (!wide)
    return;
  wide->valid = 0;
  wide->view_shift_x = wide->view_shift_y = 0;
  wide->work_scanlines = 0;
  wide->active = 0;
  wide->console = 0;
  wide->foreground_ready = 0;
  memset(wide->sprite_seen, 0, sizeof(wide->sprite_seen));
  memset(wide->column_valid, 0, sizeof(wide->column_valid));
}
static void console_copy(JungleWideState *wide, const uint32_t *native,
                         unsigned sx, unsigned sy, unsigned width,
                         unsigned height, unsigned dx, unsigned dy) {
  unsigned y;
  for (y = 0; y < height; y++)
    memcpy(wide->pixels + (dy + y) * JUNGLE_WIDE_WIDTH + dx,
           native + (sy + y) * 256u + sx, width * sizeof(uint32_t));
}

void jungle_wide_console(JungleWideState *wide, const js_machine_v10_40 *m,
                         const uint32_t native[256u * 224u]) {
  unsigned state, x, y, i;
  uint32_t chassis;
  if (!wide || !wide->enabled)
    return;
  wide->console = 0;
  state = word(m->bus.base.wram, 0xc0bu);
  /* Stable information-console states only. Briefings, title screens and
     transitions keep their original presentation. */
  if ((state != 0x834cu && state != 0x83fbu && state != 0x84cfu) ||
      m->ppu.bg_mode != 1u || m->ppu.layer[0].large_tiles ||
      m->ppu.layer[1].large_tiles)
    return;
  chassis = native[50u * 256u + 4u];
  for (i = 0; i < JUNGLE_WIDE_WIDTH * JUNGLE_WIDE_HEIGHT; i++)
    wide->pixels[i] = chassis;
  /* Extend original chrome, never resample letters, digits or map pixels. */
  for (y = 24; y < 256; y++) {
    unsigned sy = 40u + ((y - 24u) & 7u);
    for (x = 0; x < 8; x++) {
      wide->pixels[y * JUNGLE_WIDE_WIDTH + x] = native[sy * 256u + x];
      wide->pixels[y * JUNGLE_WIDE_WIDTH + JUNGLE_WIDE_WIDTH - 56u + x] =
          native[sy * 256u + 200u + x];
    }
  }
  /* Keep map-edge markers with the complete original main pane. */
  console_copy(wide, native, 0, 40, 208, 144,
               (JUNGLE_WIDE_WIDTH - 48u - 208u) / 2u, 68);
  console_copy(wide, native, 0, 16, 32, 24, 0, 0);
  console_copy(wide, native, 32, 16, 144, 24,
               (JUNGLE_WIDE_WIDTH - 48u - 144u) / 2u, 0);
  console_copy(wide, native, 176, 16, 32, 24, JUNGLE_WIDE_WIDTH - 80u, 0);
  for (y = 0; y < 16; y++)
    for (x = 0; x < JUNGLE_WIDE_WIDTH - 48u; x++) {
      wide->pixels[(256u + y) * JUNGLE_WIDE_WIDTH + x] =
          native[(184u + y) * 256u + 24u + (x & 7u)];
      wide->pixels[(272u + y) * JUNGLE_WIDE_WIDTH + x] =
          native[(200u + y) * 256u + 192u + (x & 7u)];
    }
  console_copy(wide, native, 0, 184, 200, 16, 0, 256);
  console_copy(wide, native, 200, 184, 8, 16, JUNGLE_WIDE_WIDTH - 56u, 256);
  console_copy(wide, native, 0, 200, 64, 16, 0, 272);
  console_copy(wide, native, 64, 200, 64, 16,
               (JUNGLE_WIDE_WIDTH - 48u - 64u) / 2u, 272);
  console_copy(wide, native, 128, 200, 64, 16, JUNGLE_WIDE_WIDTH - 128u, 272);
  console_copy(wide, native, 192, 200, 16, 16, JUNGLE_WIDE_WIDTH - 64u, 272);
  for (y = 0; y < 256; y++) {
    unsigned block = y / 36u, local = y % 36u;
    if (block > 6u)
      block = 6u;
    /* The first eight rows of each original statistic are blank grid.
       Repeat that background in new gaps, never the last digit row. */
    if (local > 23u)
      local &= 7u;
    for (x = 208; x < 256; x++)
      wide->pixels[y * JUNGLE_WIDE_WIDTH + x + JUNGLE_WIDE_WIDTH - 256u] =
          native[(16u + block * 24u + local) * 256u + x];
  }
  console_copy(wide, native, 208, 184, 48, 32, JUNGLE_WIDE_WIDTH - 48u, 256);
  wide->view_shift_x = wide->view_shift_y = 0;
  memset(wide->hud_mask, 0, sizeof(wide->hud_mask));
  memset(wide->edge_sprite_pixels, 0, sizeof(wide->edge_sprite_pixels));
  wide->valid = wide->active = wide->console = 1;
}

static int terrain_column(JungleWideState *wide, const uint8_t *w,
                          const uint8_t *rom, size_t size, int x) {
  unsigned slot = (unsigned)x & 63u, p, n = 0u, limit = word(w, 0x10f6au) / 16u,
           steps = 0u;
  if (x < 0 || x >= (int)(word(w, 0x10f68u) / 16u) || limit > 260u)
    return 0;
  if (wide->column_valid[slot] && wide->column_key[slot] == x)
    return 1;
  p = word(w, 0x10200u + (unsigned)x * 2u);
  while (n < limit && steps++ < 1024u) {
    uint8_t command;
    unsigned count, q, i;
    uint16_t offset;
    if (!rom_byte(rom, size, wide->map_bank, p++, &command) || !command)
      return 0;
    count = command & 127u;
    q = p;
    if (command & 128u) {
      if (!rom_word(rom, size, wide->map_bank, p, &offset))
        return 0;
      q = (wide->map_base + offset) & 65535u;
      p += 2u;
    } else
      p += count * 2u;
    if (count > limit - n)
      return 0;
    for (i = 0u; i < count; i++)
      if (!rom_word(rom, size, wide->map_bank, q + i * 2u,
                    &wide->columns[slot][n + i]))
        return 0;
    n += count;
  }
  if (n != limit)
    return 0;
  wide->column_valid[slot] = 1u;
  wide->column_key[slot] = x;
  return 1;
}
static js_stop_reason tile_pixel(const js_ppu_v09c *ppu, uint16_t raw,
                                 unsigned fine_x, unsigned fine_y,
                                 unsigned layer, uint16_t *color,
                                 uint8_t *priority) {
  js_tilemap_entry_v10_28 entry;
  js_bg_character_v10_28 chr;
  uint8_t row[8];
  js_stop_reason stop;
  js_renderer_v10_28_decode_tilemap_entry(raw, &entry);
  stop = js_renderer_v10_28_bg_resolve_character(&entry, 16u, (uint8_t)fine_x,
                                                 (uint8_t)fine_y, &chr);
  if (stop != JS_STOP_NONE)
    return stop;
  stop = js_renderer_v10_28_decode_tile_row(
      ppu, ppu->layer[layer].chr_address, chr.tile_index, 4u, chr.pixel_y, row);
  if (stop != JS_STOP_NONE)
    return stop;
  if (!row[chr.pixel_x]) {
    *priority = 0u;
    return JS_STOP_NONE;
  }
  stop = js_renderer_v10_28_read_cgram_color(
      ppu, (uint16_t)(entry.palette * 16u + row[chr.pixel_x]), color);
  if (stop != JS_STOP_NONE)
    return stop;
  return js_renderer_v10_29_mode1_priority_slot(ppu, layer, entry.priority,
                                                priority);
}
/* The original uploader splits each 16x16 scenery tile into two 64-byte
   halves. $80:F8CF maps its frozen tile number to the cartridge byte offset. */
static int scenery_pixel(const uint8_t *w, const uint8_t *rom, size_t size,
                         unsigned record, int tx, int ty, unsigned fx,
                         unsigned fy, uint16_t *cg, uint8_t *priority) {
  unsigned width = word(w, record + 16u), height = word(w, record + 18u),
           raw_addr;
  uint16_t raw, offset;
  unsigned tile, px, py, ptr, bank, base, plane, index = 0u;
  uint8_t bits;
  if (tx < 0 || ty < 0 || (unsigned)tx >= width || (unsigned)ty >= height)
    return 0;
  raw_addr = 0xa000u + word(w, record + 20u) +
             ((unsigned)ty * width + (unsigned)tx) * 2u;
  if (raw_addr >= 65535u)
    return 0;
  raw = word(w, raw_addr);
  px = (raw & 0x4000u) ? 15u - fx : fx;
  py = (raw & 0x8000u) ? 15u - fy : fy;
  tile = raw & 0x3ffu;
  if (!rom_word(rom, size, 0x80u, 0xf8cfu + ((tile & 0x3e8u) >> 2u), &offset))
    return 0;
  bank = word(w, record + 26u) & 255u;
  ptr = word(w, record + 28u) + offset;
  base = ptr + (py / 8u) * 64u + (px / 8u) * 32u + (py & 7u) * 2u;
  for (plane = 0u; plane < 4u; plane++) {
    if (!rom_byte(rom, size, bank, base + (plane / 2u) * 16u + (plane & 1u),
                  &bits))
      return 0;
    index |= ((bits >> (7u - (px & 7u))) & 1u) << plane;
  }
  if (!index)
    return 0;
  *cg = (uint16_t)(((raw >> 10u) & 7u) * 16u + index);
  *priority = (raw & 0x2000u) ? 7u : 4u;
  return 1;
}
/* Foreground DMA deliberately trails its producer by a frame at tile crossings.
   Match the displayed tilemap to the three possible producer origins rather
   than following an already advanced WRAM camera. This also works on old saves.
 */
static uint16_t foreground_raw(const uint8_t *w, unsigned map, int tx, int ty) {
  unsigned o;
  uint16_t raw = 0u;
  for (o = 0x111b2u; o + 0x4cu <= 0x20000u; o += 0x4cu) {
    uint16_t flags = word(w, o);
    int lx, ly;
    unsigned width, height, addr;
    if (!flags)
      break;
    if (flags & 4u)
      continue;
    if (((flags & 1u) != 0u) != (map == 0x400u))
      continue;
    lx = tx - (int)word(w, o + 8u);
    ly = ty - (int)word(w, o + 10u);
    width = word(w, o + 16u);
    height = word(w, o + 18u);
    if (lx < 0 || ly < 0 || (unsigned)lx >= width || (unsigned)ly >= height)
      continue;
    addr =
        0xa000u + word(w, o + 20u) + ((unsigned)ly * width + (unsigned)lx) * 2u;
    if (addr < 65535u)
      raw = word(w, addr);
  }
  return raw;
}
static void foreground_origin(JungleWideState *wide, const js_ppu_v09c *p,
                              const uint8_t *w) {
  uint64_t hash = 1469598103934665603ull;
  unsigned x, y;
  int dx, dy, best = -100000;
  int origin_x = word(w, 0x38u), origin_y = word(w, 0x3au);
  hash ^= (unsigned)origin_x | ((uint64_t)(unsigned)origin_y << 16u);
  hash *= 1099511628211ull;
  for (y = 0; y < 17u; y++)
    for (x = 0; x < 23u; x++) {
      uint16_t raw =
          p->vram[(p->layer[0].tilemap_address + y * 32u + x) & 32767u];
      hash ^= raw;
      hash *= 1099511628211ull;
    }
  if (wide->foreground_ready && wide->foreground_hash == hash)
    return;
  wide->foreground_hash = hash;
  wide->foreground_ready = 1;
  wide->foreground_x = origin_x;
  wide->foreground_y = origin_y;
  for (dy = -1; dy <= 1; dy++)
    for (dx = -1; dx <= 1; dx++) {
      int score = 0;
      for (y = 0; y < 15u; y += 2u)
        for (x = 0; x < 18u; x += 2u) {
          uint16_t actual =
              p->vram[(p->layer[0].tilemap_address + y * 32u + x) & 32767u];
          uint16_t expected;
          if (!actual)
            continue;
          expected = foreground_raw(w, p->layer[0].tilemap_address,
                                    origin_x + dx + (int)x + 1,
                                    origin_y + dy + (int)y + 1);
          score += ((actual & 0xfff9u) == (expected & 0xfff9u)) ? 1 : -1;
        }
      /* On an empty plane keep the producer origin; there is no scenery to
       * shift. */
      if (dx == 0 && dy == 0)
        score++;
      if (score > best) {
        best = score;
        wide->foreground_x = origin_x + dx;
        wide->foreground_y = origin_y + dy;
      }
    }
}
static js_stop_reason render_row(JungleWideState *wide,
                                 const js_machine_v10_40 *m,
                                 const js_ppu_v09c *p, const uint8_t *rom,
                                 size_t size, int output_y,
                                 const js_rgb8_v10_28 native[256]) {
  int y = output_y + wide->render_shift_y;
  const uint8_t *w = m->bus.base.wram;
  js_obj_record_v10_28 sprites[128];
  int sprite_rows[128], sprite_columns[128];
  unsigned sprite_indices[128];
  unsigned count = 0u, records[512], record_count = 0u, x, i;
  uint32_t *row =
      wide->work +
      (unsigned)(output_y + (int)JUNGLE_WIDE_MARGIN_Y) * JUNGLE_WIDE_WIDTH;
  int gameplay;
  memset(row + wide->clip_left, 0,
         (wide->clip_right - wide->clip_left) * sizeof(*row));
  memset(wide->pixel_object + (unsigned)(output_y + 32) * JUNGLE_WIDE_WIDTH +
             wide->clip_left,
         0, wide->clip_right - wide->clip_left);
  if (native)
    for (x = 0u; x < 256u; x++)
      row[x + JUNGLE_WIDE_MARGIN] = 0xff000000u |
                                    ((uint32_t)native[x].r << 16) |
                                    ((uint32_t)native[x].g << 8) | native[x].b;
  gameplay = p->bg_mode == 1u && p->layer[0].large_tiles &&
             p->layer[1].large_tiles && p->layer[1].tilemap_address == 0u &&
             p->layer[1].chr_address == 0u;
  if (!wide->enabled || !gameplay || p->forced_blank || !p->brightness)
    return JS_STOP_NONE;
  wide->work_active = 1;
  if (wide->map_bank != w[0x106u] || wide->map_base != word(w, 0x78u)) {
    memset(wide->column_valid, 0, sizeof(wide->column_valid));
    wide->map_bank = w[0x106u];
    wide->map_base = word(w, 0x78u);
  }
  foreground_origin(wide, p, w);
  if (p->main_screen_layers & 16u)
    for (i = 0u; i < 128u; i++) {
      js_obj_record_v10_28 obj;
      unsigned idx =
          (i + (p->oam_priority ? ((p->oam_ram_address >> 1u) & 127u) : 0u)) &
          127u;
      js_stop_reason stop =
          js_renderer_v10_28_decode_obj(p, (uint8_t)idx, &obj);
      if (stop != JS_STOP_NONE)
        return stop;
      if (wide->sprite_seen[idx] && y >= wide->sprite_y[idx] &&
          y < wide->sprite_y[idx] + (int)obj.size.height) {
        /* Carry the unwrapped coordinate alongside the decoded record. */
        sprite_columns[count] = wide->sprite_x[idx];
        sprite_indices[count] = idx;
        sprite_rows[count] = wide->sprite_y[idx];
        sprites[count++] = obj;
      }
    }
  for (i = 0x111b2u; i + 0x4cu <= 0x20000u && record_count < 512u; i += 0x4cu) {
    uint16_t flags = word(w, i);
    int oy, local_y;
    if (!flags)
      break;
    if (flags & 4u)
      continue;
    if (((flags & 1u) != 0u) != (p->layer[0].tilemap_address == 0x400u))
      continue;
    oy = (int)word(w, i + 10u) - wide->foreground_y;
    local_y = floor16(y + (int)p->layer[0].v_scroll) + 1 - oy;
    if (local_y >= 0 && local_y < (int)word(w, i + 18u))
      records[record_count++] = i;
  }
  for (x = wide->clip_left; x < wide->clip_right; x++) {
    int sx = (int)x - (int)JUNGLE_WIDE_MARGIN + wide->render_shift_x, wx, wy;
    uint16_t color = p->cgram[0];
    uint8_t priority = 0u, source = 5u, palette = 0u;
    js_stop_reason stop;
    if (native && x >= JUNGLE_WIDE_MARGIN && x < JUNGLE_WIDE_MARGIN + 256u &&
        !(y >= (int)JUNGLE_WIDE_HUD_TOP &&
          wide->work_hud_mask[(unsigned)(y - (int)JUNGLE_WIDE_HUD_TOP) * 256u +
                              x - JUNGLE_WIDE_MARGIN]))
      continue;
    wx = (int)word(w, 0x40u);
    wx += ((int)((p->layer[1].h_scroll - (unsigned)wx + 256u) & 511u) - 256);
    wy = (int)word(w, 0x42u) - 1;
    wy += ((int)((p->layer[1].v_scroll - (unsigned)wy + 256u) & 511u) - 256);
    wx += sx;
    wy += (int)y;
    if ((p->main_screen_layers & 2u) && wx >= 0 && wy >= 0 &&
        wy < (int)word(w, 0x10f6au) &&
        terrain_column(wide, w, rom, size, wx / 16)) {
      uint16_t raw = wide->columns[(unsigned)(wx / 16) & 63u][wy / 16];
      stop = tile_pixel(p, raw, (unsigned)wx & 15u, (unsigned)wy & 15u, 1u,
                        &color, &priority);
      if (stop != JS_STOP_NONE)
        return stop;
      if (priority)
        source = 1u;
    }
    if (p->main_screen_layers & 1u) {
      unsigned selected = 0u;
      int px = sx + (int)p->layer[0].h_scroll;
      int py = (int)y + (int)p->layer[0].v_scroll;
      int world_tx =
          (px >= 0 ? px / 16 : (px - 15) / 16) + 1 + wide->foreground_x;
      int world_ty = floor16(py) + 1 + wide->foreground_y;
      uint16_t cg;
      uint8_t slot;
      /* The guest builds a tilemap, so later records replace whole cells,
         including transparent cells, rather than blending their pixels. */
      for (i = 0u; i < record_count; i++) {
        unsigned o = records[i];
        int tx = world_tx - (int)word(w, o + 8u);
        int ty = world_ty - (int)word(w, o + 10u);
        if (tx >= 0 && ty >= 0 && (unsigned)tx < word(w, o + 16u) &&
            (unsigned)ty < word(w, o + 18u))
          selected = o;
      }
      if (selected &&
          scenery_pixel(w, rom, size, selected,
                        world_tx - (int)word(w, selected + 8u),
                        world_ty - (int)word(w, selected + 10u),
                        (unsigned)px & 15u, (unsigned)py & 15u, &cg, &slot) &&
          slot > priority) {
        stop = js_renderer_v10_28_read_cgram_color(p, cg, &color);
        if (stop != JS_STOP_NONE)
          return stop;
        priority = slot;
        source = 0u;
      }
    }

    for (i = 0u; i < count; i++) {
      const js_obj_record_v10_28 *obj = &sprites[i];
      int ox = sprite_columns[i], local;
      unsigned px, py;
      uint16_t tile, cg;
      uint8_t indices[8], index, slot;
      local = sx - ox;
      if (local < 0 || local >= obj->size.width)
        continue;
      px = (unsigned)local;
      py = (unsigned)(y - sprite_rows[i]);
      if (obj->hflip)
        px = obj->size.width - 1u - px;
      if (obj->vflip)
        py = obj->size.height - 1u - py;
      stop = js_renderer_v10_28_obj_tile_word_address(
          p, obj->tile_low, obj->name_select, (uint8_t)(px / 8u),
          (uint8_t)(py / 8u), &tile);
      if (stop != JS_STOP_NONE)
        return stop;
      stop = js_renderer_v10_28_decode_tile_row(p, tile, 0u, 4u,
                                                (uint8_t)(py & 7u), indices);
      if (stop != JS_STOP_NONE)
        return stop;
      index = indices[px & 7u];
      if (!index)
        continue;
      slot = js_renderer_v10_30_obj_priority_slot(p, obj->priority);
      if (slot > priority) {
        cg = (uint16_t)(128u + obj->palette * 16u + index);
        stop = js_renderer_v10_28_read_cgram_color(p, cg, &color);
        if (stop != JS_STOP_NONE)
          return stop;
        priority = slot;
        source = 4u;
        palette = obj->palette;
        wide->pixel_object[(unsigned)(output_y + 32) * JUNGLE_WIDE_WIDTH + x] =
            (uint8_t)(sprite_indices[i] + 1u);
      }
      break;
    }
    if ((p->color_math_enabled & (1u << source)) &&
        (source != 4u || palette >= 4u))
      color = js_renderer_v10_30_color_math(
          color, p->fixed_color, p->color_math_subtract, p->color_math_half);
    color = js_renderer_v10_30_apply_brightness(color, p->brightness);
    {
      js_rgb8_v10_28 rgb;
      js_renderer_v10_28_bgr555_to_rgb8(color, &rgb);
      row[x] = 0xff000000u | ((uint32_t)rgb.r << 16) | ((uint32_t)rgb.g << 8) |
               rgb.b;
    }
  }
  return JS_STOP_NONE;
}

/* The native camera stops 64 pixels inside the cartridge map. Keep the wider
   viewport inside those same valid world bounds instead of exposing unused
   border columns or inventing scenery outside the map. Move the complete
   native world image and OBJ ownership together; HUD composition follows. */
static js_stop_reason clamp_view(JungleWideState *wide,
                                 const js_machine_v10_40 *m, const uint8_t *rom,
                                 size_t size) {
  const uint8_t *w = m->bus.base.wram;
  int ox = (int)word(w, 0x40) - (int)JUNGLE_WIDE_MARGIN,
      oy = (int)word(w, 0x42) - 1 - 32;
  int maxx = (int)word(w, 0x10f68) - (int)JUNGLE_WIDE_WIDTH;
  int maxy = (int)word(w, 0x10f6a) - 288;
  int vx = ox, vy = oy, dx, dy, yy;
  unsigned left, right;
  if (maxx < 64 || maxy < 63)
    return JS_STOP_NONE;
  if (vx < 64)
    vx = 64;
  else if (vx > maxx)
    vx = maxx;
  if (vy < 63)
    vy = 63;
  else if (vy > maxy)
    vy = maxy;
  dx = vx - ox;
  dy = vy - oy;
  if (dx > (int)JUNGLE_WIDE_MARGIN)
    dx = (int)JUNGLE_WIDE_MARGIN;
  else if (dx < -(int)JUNGLE_WIDE_MARGIN)
    dx = -(int)JUNGLE_WIDE_MARGIN;
  if (dy > 32)
    dy = 32;
  else if (dy < -32)
    dy = -32;
  wide->view_shift_x = dx;
  wide->view_shift_y = dy;
  if (!dx && !dy)
    return JS_STOP_NONE;
  left = dx < 0 ? (unsigned)-dx : 0u;
  right = dx > 0 ? JUNGLE_WIDE_WIDTH - (unsigned)dx : JUNGLE_WIDE_WIDTH;
  for (yy = 0; yy < 288; yy++) {
    int dst = dy >= 0 ? yy : 287 - yy, source = dst + dy;
    if (source < 0 || source >= 288)
      continue;
    memmove(wide->work + dst * JUNGLE_WIDE_WIDTH + left,
            wide->work + source * JUNGLE_WIDE_WIDTH + left + dx,
            (right - left) * sizeof(uint32_t));
    memmove(wide->pixel_object + dst * JUNGLE_WIDE_WIDTH + left,
            wide->pixel_object + source * JUNGLE_WIDE_WIDTH + left + dx,
            right - left);
  }
  wide->render_shift_x = dx;
  wide->render_shift_y = dy;
  for (yy = 0; yy < 288; yy++) {
    js_stop_reason s;
    if (yy + dy < 0 || yy + dy >= 288) {
      wide->clip_left = 0;
      wide->clip_right = JUNGLE_WIDE_WIDTH;
    } else if (dx) {
      wide->clip_left = dx > 0 ? right : 0;
      wide->clip_right = dx > 0 ? JUNGLE_WIDE_WIDTH : left;
    } else
      continue;
    s = render_row(wide, m, &wide->edge_ppu, rom, size, yy - 32, NULL);
    if (s != JS_STOP_NONE)
      return s;
  }
  wide->clip_left = 0;
  wide->clip_right = JUNGLE_WIDE_WIDTH;
  wide->render_shift_x = wide->render_shift_y = 0;
  return JS_STOP_NONE;
}

/* Interpret signed vertical positions continuously across OAM's 8-bit wrap.
   The game parks unused entries at ($E0,$E0), retaining stale tile bytes. */
static void prepare_sprites(JungleWideState *wide, const js_ppu_v09c *p) {
  unsigned i;
  for (i = 0; i < 128u; i++) {
    int y = p->oam[i * 4u + 1u], candidate = y;
    int x = p->oam[i * 4u] |
            (((p->oam[512u + i / 4u] >> (2u * (i % 4u))) & 1u) << 8u);
    if (x >= 256)
      x -= 512;
    if (p->oam[i * 4u] == 0xe0u && y == 0xe0) {
      wide->sprite_seen[i] = 0;
      continue;
    }
    if (wide->sprite_seen[i]) {
      int previous = wide->sprite_y[i];
      while (candidate - previous > 128)
        candidate -= 256;
      while (previous - candidate > 128)
        candidate += 256;
      if (candidate < -32 || candidate >= 256)
        candidate = y >= 240 ? y - 256 : y;
    } else
      candidate = y >= 240 ? y - 256 : y;
    wide->sprite_y[i] = (int16_t)candidate;
    candidate = x;
    if (wide->sprite_seen[i]) {
      int previous = wide->sprite_x[i];
      while (candidate - previous > 256)
        candidate -= 512;
      while (previous - candidate > 256)
        candidate += 512;
      if (candidate < -192 || candidate >= 448)
        candidate = x < -128 ? x + 512 : x;
    } else
      candidate = x < -128 ? x + 512 : x;
    wide->sprite_x[i] = (int16_t)candidate;
    wide->sprite_seen[i] = 1;
  }
}
js_stop_reason jungle_wide_scanline(JungleWideState *wide,
                                    const js_machine_v10_40 *m,
                                    const uint8_t *rom, size_t size, unsigned y,
                                    const js_rgb8_v10_28 native[256]) {
  js_stop_reason stop;
  int extra;
  /* A restored snapshot can own a partial native frame. Host-only wide
     buffers have no saved scanlines: wait for a complete scanline-0 frame. */
  if (y != 0u && wide->work_scanlines != y)
    return JS_STOP_NONE;
  if (y == 0u) {
    wide->work_scanlines = 0;
    wide->render_shift_x = wide->render_shift_y = 0;
    wide->clip_left = 0;
    wide->clip_right = JUNGLE_WIDE_WIDTH;
    wide->work_active = 0;
    memset(wide->work_hud_mask, 0, sizeof(wide->work_hud_mask));
    wide->edge_ppu = m->ppu;
    prepare_sprites(wide, &m->ppu);
    for (extra = -(int)JUNGLE_WIDE_MARGIN_Y; extra < 0; extra++) {
      stop = render_row(wide, m, &wide->edge_ppu, rom, size, extra, NULL);
      if (stop != JS_STOP_NONE)
        return stop;
    }
  }
  if (y >= 192u && !m->ppu.forced_blank && m->ppu.brightness &&
      m->ppu.bg_mode == 1u && m->ppu.layer[0].large_tiles &&
      m->ppu.layer[1].large_tiles && m->ppu.layer[1].tilemap_address == 0u &&
      m->ppu.layer[1].chr_address == 0u)
    wide->edge_ppu = m->ppu;
  if (y >= JUNGLE_WIDE_HUD_TOP && wide->work_active) {
    unsigned x, row = (y - JUNGLE_WIDE_HUD_TOP) * 256u;
    for (x = 0; x < 256u; x++) {
      js_bg_pixel_v10_29 bg;
      wide->work_hud_pixels[row + x] =
          0xff000000u | ((uint32_t)native[x].r << 16) |
          ((uint32_t)native[x].g << 8) | native[x].b;
      /* Forced blanking is cartridge presentation, not message content.
         Keep the reconstructed world visible beneath and beside the HUD. */
      if (!m->ppu.forced_blank && (m->ppu.main_screen_layers & 4u)) {
        stop = js_renderer_v10_29_sample_mode1_bg(&m->ppu, 2u, (uint16_t)x,
                                                  (uint16_t)y, &bg);
        if (stop != JS_STOP_NONE)
          return stop;
        if (!bg.transparent) {
          js_screen_pixel_v10_30 pixel;
          /* Use a host PPU copy: OBJ evaluation may update overflow flags. */
          stop = js_renderer_v10_30_render_source_pixel(
              &wide->edge_ppu, (uint16_t)x, (uint16_t)y, &pixel);
          if (stop != JS_STOP_NONE)
            return stop;
          wide->work_hud_mask[row + x] =
              (uint8_t)(pixel.main_pixel.source == JS_PIXEL_V10_30_BG3);
        }
      }
    }
  }
  /* Relocate visible HUD pixels; restore world beneath native blanking. */
  if (y >= 220u && wide->work_active && m->ppu.forced_blank)
    stop = render_row(wide, m, &wide->edge_ppu, rom, size, (int)y, NULL);
  else
    stop = render_row(wide, m, &m->ppu, rom, size, (int)y, native);
  if (stop != JS_STOP_NONE)
    return stop;
  if (y == 223u) {
    for (extra = 224; extra < 224 + (int)JUNGLE_WIDE_MARGIN_Y; extra++) {
      stop = render_row(wide, m, &wide->edge_ppu, rom, size, extra, NULL);
      if (stop != JS_STOP_NONE)
        return stop;
    }
    if (wide->work_active) {
      unsigned row, x;
      stop = clamp_view(wide, m, rom, size);
      if (stop != JS_STOP_NONE)
        return stop;
      for (row = 0; row < JUNGLE_WIDE_HUD_HEIGHT; row++)
        for (x = 0; x < 256u; x++)
          if (wide->work_hud_mask[row * 256u + x])
            wide->work[(JUNGLE_WIDE_HEIGHT - JUNGLE_WIDE_HUD_HEIGHT + row) *
                           JUNGLE_WIDE_WIDTH +
                       JUNGLE_WIDE_MARGIN + x] =
                wide->work_hud_pixels[row * 256u + x];
    }
    memset(wide->edge_sprite_pixels, 0, sizeof(wide->edge_sprite_pixels));
    if (wide->work_active) {
      unsigned yy, xx;
      for (yy = 0; yy < JUNGLE_WIDE_HEIGHT; yy++)
        for (xx = 0; xx < JUNGLE_WIDE_WIDTH; xx++) {
          unsigned owner = wide->pixel_object[yy * JUNGLE_WIDE_WIDTH + xx];
          if (yy >= 272u && xx >= JUNGLE_WIDE_MARGIN &&
              xx < JUNGLE_WIDE_MARGIN + 256u &&
              wide->work_hud_mask[(yy - 272u) * 256u + xx - JUNGLE_WIDE_MARGIN])
            continue;
          if (!owner)
            continue;
          owner--;
          if (xx < JUNGLE_WIDE_MARGIN)
            wide->edge_sprite_pixels[owner][0]++;
          if (xx >= JUNGLE_WIDE_MARGIN + 256u)
            wide->edge_sprite_pixels[owner][1]++;
          if (yy < 32u)
            wide->edge_sprite_pixels[owner][2]++;
          if (yy >= 256u)
            wide->edge_sprite_pixels[owner][3]++;
        }
    }
    memcpy(wide->hud_mask, wide->work_hud_mask, sizeof(wide->hud_mask));
    memcpy(wide->hud_pixels, wide->work_hud_pixels, sizeof(wide->hud_pixels));
    memcpy(wide->pixels, wide->work, sizeof(wide->pixels));
    wide->active = wide->work_active;
    wide->console = 0;
    wide->valid = 1;
  }
  wide->work_scanlines++;
  return JS_STOP_NONE;
}
