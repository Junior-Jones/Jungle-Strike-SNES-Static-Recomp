#ifndef JUNGLE_PRESENTATION_SNAPSHOT_H
#define JUNGLE_PRESENTATION_SNAPSHOT_H
#include "jungle/widescreen.h"
#include "jungle/gameplay_water_60.h"
/* Same-build presentation extension. Decode owns its temporary allocation;
   initialize this object to zero, and clear it after apply or abandonment. */
typedef struct JunglePresentationSnapshot {
    JungleWideState *wide;
    JungleWater60Palette water;
    uint8_t water_valid;
} JunglePresentationSnapshot;
size_t jungle_presentation_snapshot_size(int with_wide);
int jungle_presentation_snapshot_encode(const JungleWideState *wide,
    const JungleWater60Palette *water,int water_valid,void *wire,size_t size);
int jungle_presentation_snapshot_decode(JunglePresentationSnapshot *out,
    const void *wire,size_t size);
void jungle_presentation_snapshot_clear(JunglePresentationSnapshot *snapshot);
/* Consumes an allocated wide temporary when the destination has none.
   Host wide-enable preference is preserved; all peripheral pointers rebind. */
void jungle_presentation_snapshot_apply(JunglePresentationSnapshot *snapshot,
    JungleWideState **wide,js_machine_v10_40 *machine,
    JungleWater60Palette *water,uint8_t *water_valid);
#endif
