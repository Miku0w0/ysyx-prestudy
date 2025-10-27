#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->SW, 8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->SW8, 1, SW8);
	nvboard_bind_pin( &top->LEDR, 3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->LED4, 1, LD4);
	nvboard_bind_pin( &top->HEX0, 7, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
}
