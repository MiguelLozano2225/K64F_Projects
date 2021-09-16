/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "pin_n_clocks.h"
#include "My_led_n_sw.h"
#include "NVIC.h"

int main(void)
{
	Init_clocks();
	GPIOC_PDDR &= ~(1<<6U);
	PORTC_PCR6	|= PORT_PCR_MUX(1)
				|  PORT_PCR_IRQC(0b1000);
	
	INIT_LEDS;
	NVIC_EnableIRQ(INT_PORTC);
	NVIC_SetPriority(INT_PORTC, 0xAAU);
	
	for(;;)
	{
		LED_RED_OFF;
		LED_BLUE_OFF;
		LED_GREEN_OFF;
	}
	
	return 0;
}

void PORTC_IRQHandler(void)
{
	
	PORTC_PCR6 |= PORT_PCR_ISF_MASK;
	LED_RED_ON;
	
}
