#ifndef JUNGLE_MISSION_BATCH_60_H
#define JUNGLE_MISSION_BATCH_60_H
#include "jungle/machine_v10_40.h"
/* Conservative payload budget within the native forced-blank IRQ window. */
#define JUNGLE_MISSION60_MAX_BYTES 6144u
#define JUNGLE_MISSION60_MAX_PACKETS 8u
#define JUNGLE_MISSION60_WIRE_BYTES (48u+16u*JUNGLE_MISSION60_MAX_PACKETS+JUNGLE_MISSION60_MAX_BYTES)
typedef struct JungleMission60Packet {
    uint16_t control,source,destination,length,palette,offset;
    uint8_t bank;
    uint8_t layout,columns,rows;
} JungleMission60Packet;
typedef struct JungleMission60State {
    uint64_t animation_due,animation_field,publication_due;
    uint32_t descriptor;
    uint16_t used,old_animation,animation_period;
    uint8_t active,ready,draining,animation_armed,animation_advanced,count;
    uint8_t owner;
    JungleMission60Packet packets[JUNGLE_MISSION60_MAX_PACKETS];
    uint8_t bytes[JUNGLE_MISSION60_MAX_BYTES];
} JungleMission60State;
js_stop_reason jungle_mission60_batch_after_instruction(JungleMission60State *s,
    js_machine_v10_40 *m,uint8_t previous_bank,uint16_t previous_pc,int enabled);
void jungle_mission60_batch_encode(const JungleMission60State *s,uint8_t *wire);
int jungle_mission60_batch_decode(JungleMission60State *s,const uint8_t *wire);
#endif
