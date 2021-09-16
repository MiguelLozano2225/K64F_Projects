/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "pin_n_clocks.h"
#include "My_led_n_sw.h"

int main(void)
{
	Init_clocks();
	INIT_LEDS;
	ptr_func=led_blue;
	
	for(;;)
	{
		ptr_func();
	}
	
	return 0;
}
