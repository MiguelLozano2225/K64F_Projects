/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "My_led_n_sw.h"
#include "NVIC.h"
#include "pin_n_clocks.h"
#include "UART.h"


unsigned char Data_u8;

int main(void)
{

	Init_clocks();
	Init_Pins();
	Init_UART();
	INIT_LEDS;
	
	NVIC_EnableIRQ(INT_UART3_RX_TX);
	
	for(;;) 
	{	   

		switch(Data_u8)
		{
			case 'r':
				LED_RED_ON;
				LED_BLUE_OFF;
				LED_GREEN_OFF;
				break;
				
			case 'b':
				LED_RED_OFF;
				LED_BLUE_ON;
				LED_GREEN_OFF;
				break;
				
			case 'g':
				LED_RED_OFF;
				LED_BLUE_OFF;
				LED_GREEN_ON;	
				break;
				
		}

	}
	
	return 0U;
}

void UART3_Status_IRQHandler(void)
{
	
	if(UART3_S1 & UART_S1_RDRF_MASK)
		Data_u8=UART3_D;
		UART3_D=Data_u8;
}

