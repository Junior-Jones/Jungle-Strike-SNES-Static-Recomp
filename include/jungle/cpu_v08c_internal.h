#ifndef JUNGLE_CPU_V08C_INTERNAL_H
#define JUNGLE_CPU_V08C_INTERNAL_H
#include <stddef.h>
#include <stdint.h>
#include "jungle/cpu_dispatch_v08c.h"

js_stop_reason js_v05c_guard_code(js_machine_v05c *m, uint32_t file_offset, const uint8_t *expected, size_t length);
js_stop_reason js_v05c_read8(js_machine_v05c *m, uint32_t addr, uint8_t *value);
js_stop_reason js_v05c_write8(js_machine_v05c *m, uint32_t addr, uint8_t value);
js_stop_reason js_v05c_idle_cycles(js_machine_v05c *m, unsigned cycles);
js_stop_reason js_v05c_read_value(js_machine_v05c *m, uint32_t addr, unsigned width, int bank0_wrap, uint16_t *value);
js_stop_reason js_v05c_write_value(js_machine_v05c *m, uint32_t addr, unsigned width, int bank0_wrap, uint16_t value);
js_stop_reason js_v05c_write_rmw_value(js_machine_v05c *m, uint32_t addr, unsigned width, int bank0_wrap, uint16_t value);
uint32_t js_v05c_addr_direct(const js_machine_v05c *m, uint8_t offset);
uint32_t js_v05c_addr_direct_x(const js_machine_v05c *m, uint8_t offset);
uint32_t js_v05c_addr_abs(const js_machine_v05c *m, uint16_t absolute);
uint32_t js_v05c_addr_abs_x(const js_machine_v05c *m, uint16_t absolute);
uint32_t js_v05c_addr_abs_y(const js_machine_v05c *m, uint16_t absolute);
js_stop_reason js_v05c_addr_dir_ind_y(js_machine_v05c *m, uint8_t offset, uint32_t *effective);
js_stop_reason js_v05c_addr_dir_ind_long(js_machine_v05c *m, uint8_t offset, uint32_t *effective);
js_stop_reason js_v05c_addr_dir_ind_long_y(js_machine_v05c *m, uint8_t offset, uint32_t *effective);
js_stop_reason js_v05c_read_abs_ind_target(js_machine_v05c *m, uint16_t pointer, uint16_t *target_pc);
js_stop_reason js_v05c_read_abs_x_ind_target(js_machine_v05c *m, uint16_t base, uint16_t *target_pc);

js_stop_reason js_v05c_push8(js_machine_v05c *m, uint8_t value);
js_stop_reason js_v05c_pull8(js_machine_v05c *m, uint8_t *value);
js_stop_reason js_v05c_push16(js_machine_v05c *m, uint16_t value);
js_stop_reason js_v05c_pull16(js_machine_v05c *m, uint16_t *value);
void js_v05c_normalize(js_cpu65816_state *s, uint8_t old_p);
void js_v05c_set_nz(js_cpu65816_state *s, uint16_t value, unsigned width);
uint16_t js_v05c_adc(js_cpu65816_state *s, uint16_t a, uint16_t b, unsigned width);
uint16_t js_v05c_sbc(js_cpu65816_state *s, uint16_t a, uint16_t b, unsigned width);
uint16_t js_v05c_compare(js_cpu65816_state *s, uint16_t lhs, uint16_t rhs, unsigned width);
uint16_t js_v05c_asl(js_cpu65816_state *s, uint16_t value, unsigned width);
uint16_t js_v05c_lsr(js_cpu65816_state *s, uint16_t value, unsigned width);
uint16_t js_v05c_rol(js_cpu65816_state *s, uint16_t value, unsigned width);
uint16_t js_v05c_ror(js_cpu65816_state *s, uint16_t value, unsigned width);
void js_v05c_bit(js_cpu65816_state *s, uint16_t a, uint16_t mem, unsigned width, int immediate);
uint16_t js_v05c_trb(js_cpu65816_state *s, uint16_t a, uint16_t mem, unsigned width);
uint16_t js_v05c_increment(js_cpu65816_state *s, uint16_t value, unsigned width, int delta);
void js_v05c_write_a(js_cpu65816_state *s, uint16_t value, unsigned width, int set_flags);
void js_v05c_write_x(js_cpu65816_state *s, uint16_t value, unsigned width, int set_flags);
void js_v05c_write_y(js_cpu65816_state *s, uint16_t value, unsigned width, int set_flags);
void js_v05c_set_key(js_cpu65816_state *s, js_static_context_key key);
js_stop_reason js_v05c_validate_current_key(js_machine_v05c *m, const js_static_context_key *allowed, size_t count, js_stop_reason failure);
js_stop_reason js_v05c_finish_fixed(js_machine_v05c *m, js_static_context_key target);
void js_v05c_diagnostic_begin_step(js_machine_v05c *m);
void js_v05c_diagnostic_capture_stop(js_machine_v05c *m, js_stop_reason stop);

#endif
