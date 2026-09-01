/* generated compact exact-context S-CPU shard - do not edit */
#include "static_core_compact_generated.h"
typedef struct js_compact_record {
    uint32_t key;
    uint32_t parameter_offset;
    uint16_t template_id;
    uint16_t reserved;
} js_compact_record;
static const js_compact_record records[5] = {
    {0x0089D400u,0x00000000u,0x0075u,0u},
    {0x0089D401u,0x00000001u,0x0075u,0u},
    {0x0089D402u,0x00000002u,0x0075u,0u},
    {0x0089D403u,0x00000003u,0x0075u,0u},
    {0x0089D407u,0x00000004u,0x0075u,0u},
};
static const uint32_t parameters[5] = {
    0x000009D4u,0x000009D4u,0x000009D4u,0x000009D4u,0x000009D4u,
};
int js_compact_scpu_group_0022(js_machine_v05c *m,
                                  uint32_t packed,
                                  js_stop_reason *out) {
    unsigned lo = 0u, hi = 5u;
    while (lo < hi) {
        unsigned mid = lo + (hi - lo) / 2u;
        uint32_t found = records[mid].key;
        if (packed < found) hi = mid;
        else if (packed > found) lo = mid + 1u;
        else {
            *out = js_compact_scpu_execute(
                m, records[mid].template_id,
                parameters + records[mid].parameter_offset);
            return 1;
        }
    }
    return 0;
}
