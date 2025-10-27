#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->btn, 1, BTNC);
	nvboard_bind_pin( &top->sw, 10, SW0, SW1, SW2, SW3, SW4, SW5, SW6, SW7, SW8, SW9);
	nvboard_bind_pin( &top->led, 8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->seg0, 7, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
	nvboard_bind_pin( &top->seg1, 7, SEG1G, SEG1F, SEG1E, SEG1D, SEG1C, SEG1B, SEG1A);
}
