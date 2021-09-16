/*
 * pin_n_clocks.c
 *
 *  Created on: Jun 14, 2021
 *      Author: migue
 */
#include "pin_n_clocks.h"
#include "My_led_n_sw.h"


void Init_clocks(void)
{/*Turn on the clocks for the PORTB, PORTD, PORTC and UART3*/
	SIM_SCGC4 |=  SIM_SCGC4_UART3_MASK; 
	
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK |SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTE_MASK ;
}

void Init_Pins(void)
{
	PORTC_PCR16 |= PORT_PCR_MUX(3U);	//Select the PTC16 as UART3_RX
	PORTC_PCR17 |= PORT_PCR_MUX(3U); //Select the PTC17 as UART3_TX
}

