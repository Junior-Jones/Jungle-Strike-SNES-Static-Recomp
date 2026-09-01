#ifndef JUNGLE_RENDERER_V10_30_H
#define JUNGLE_RENDERER_V10_30_H
#include <stdint.h>
#include "jungle/renderer_v10_29.h"
#include "jungle/status_v10_30.h"
#ifdef __cplusplus
extern "C" {
#endif
#define JS_V10_30_SOURCE_OBSEL 0x03u
#define JS_V10_30_SOURCE_TM 0x13u
#define JS_V10_30_SOURCE_TM_SMALL_BG12 0x10u
#define JS_V10_30_SOURCE_TS_CC50 0x04u
#define JS_V10_30_SOURCE_TS_IRQ 0x00u
#define JS_V10_30_MAX_LINE_OBJS 32u
#define JS_V10_30_MAX_LINE_SLIVERS 34u
#define JS_V10_30_VISIBLE_WIDTH 256u
#define JS_V10_30_VISIBLE_HEIGHT 224u

typedef enum js_pixel_source_v10_30 {
    JS_PIXEL_V10_30_BG1=0, JS_PIXEL_V10_30_BG2=1, JS_PIXEL_V10_30_BG3=2,
    JS_PIXEL_V10_30_BG4=3, JS_PIXEL_V10_30_OBJ=4, JS_PIXEL_V10_30_BACKDROP=5
} js_pixel_source_v10_30;

typedef struct js_obj_scanline_v10_30 {
    uint8_t first_sprite;
    uint8_t selected_count;
    uint8_t selected_indices[JS_V10_30_MAX_LINE_OBJS];
    uint8_t retained_sliver_mask[JS_V10_30_MAX_LINE_OBJS];
    uint8_t range_over;
    uint8_t time_over;
} js_obj_scanline_v10_30;

typedef struct js_obj_pixel_v10_30 {
    uint8_t transparent;
    uint8_t obj_index;
    uint8_t palette;
    uint8_t priority;
    uint8_t priority_slot;
    uint8_t color_index;
    uint8_t screen_sliver;
    uint16_t cgram_index;
    uint16_t bgr555;
    js_rgb8_v10_28 rgb;
} js_obj_pixel_v10_30;

typedef struct js_screen_plane_pixel_v10_30 {
    js_pixel_source_v10_30 source;
    uint8_t transparent;
    uint8_t priority_slot;
    uint8_t obj_palette;
    uint16_t bgr555;
} js_screen_plane_pixel_v10_30;

typedef struct js_screen_pixel_v10_30 {
    js_screen_plane_pixel_v10_30 main_pixel;
    js_screen_plane_pixel_v10_30 sub_pixel;
    uint8_t color_math_applied;
    uint8_t forced_blank;
    uint8_t brightness;
    uint16_t pre_brightness_bgr555;
    uint16_t final_bgr555;
    js_rgb8_v10_28 rgb;
} js_screen_pixel_v10_30;

/* Source-reached guard. INIDISP is intentionally not finite-domain guarded because $08E3 remains unresolved. */
js_stop_reason js_renderer_v10_30_validate_source_display_configuration(const js_ppu_v09c *ppu);
uint8_t js_renderer_v10_30_obj_priority_slot(const js_ppu_v09c *ppu, uint8_t obj_priority);
js_stop_reason js_renderer_v10_30_evaluate_obj_scanline(js_ppu_v09c *ppu, uint16_t screen_y,
                                                        js_obj_scanline_v10_30 *line);
js_stop_reason js_renderer_v10_30_sample_obj_pixel(const js_ppu_v09c *ppu,
                                                   const js_obj_scanline_v10_30 *line,
                                                   uint16_t screen_x, uint16_t screen_y,
                                                   js_obj_pixel_v10_30 *pixel);
uint16_t js_renderer_v10_30_color_math(uint16_t main_color, uint16_t addend,
                                       uint8_t subtract, uint8_t half);
uint16_t js_renderer_v10_30_apply_brightness(uint16_t color, uint8_t brightness);
js_stop_reason js_renderer_v10_30_render_source_pixel(js_ppu_v09c *ppu,
                                                       uint16_t screen_x, uint16_t screen_y,
                                                       js_screen_pixel_v10_30 *pixel);
js_stop_reason js_renderer_v10_30_render_source_scanline(js_ppu_v09c *ppu, uint16_t screen_y,
                                                          js_rgb8_v10_28 pixels[JS_V10_30_VISIBLE_WIDTH]);
#ifdef __cplusplus
}
#endif
#endif
