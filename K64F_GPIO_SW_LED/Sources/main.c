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
	INIT_SW2;
	LED_RED_OFF;
	LED_GREEN_OFF;
	
	for(;;)
	{
		if(SW2)
		{
			LED_BLUE_OFF;
		}
		
		else
		{
			LED_BLUE_ON;
		}
	}
	
	return 0;
}
