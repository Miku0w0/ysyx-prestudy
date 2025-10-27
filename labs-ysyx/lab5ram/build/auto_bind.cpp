#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->sw, 8, SW0, SW1, SW2, SW3, SW4, SW5, SW6, SW7);
	nvboard_bind_pin( &top->addr, 4, SW0, SW1, SW2, SW3);
	nvboard_bind_pin( &top->we, 1, SW9);
	nvboard_bind_pin( &top->seg0, 7, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
	nvboard_bind_pin( &top->seg1, 7, SEG1G, SEG1F, SEG1E, SEG1D, SEG1C, SEG1B, SEG1A);
}
