#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->a0, 2, SW2, SW3);
	nvboard_bind_pin( &top->a1, 2, SW4, SW5);
	nvboard_bind_pin( &top->a2, 2, SW6, SW7);
	nvboard_bind_pin( &top->a3, 2, SW8, SW9);
	nvboard_bind_pin( &top->s, 2, SW0, SW1);
	nvboard_bind_pin( &top->y, 2, LD0, LD1);
}
