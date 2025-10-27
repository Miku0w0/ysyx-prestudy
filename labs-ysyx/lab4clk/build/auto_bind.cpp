#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->rst, 1, BTNC);
	nvboard_bind_pin( &top->btn_start, 1, BTNU);
	nvboard_bind_pin( &top->btn_pause, 1, BTNL);
	nvboard_bind_pin( &top->btn_reset, 1, BTNR);
	nvboard_bind_pin( &top->seg0, 7, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
	nvboard_bind_pin( &top->seg1, 7, SEG1G, SEG1F, SEG1E, SEG1D, SEG1C, SEG1B, SEG1A);
	nvboard_bind_pin( &top->led, 1, LD0);
}
