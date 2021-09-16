/*
 * pin_n_clocks.c
 *
 *  Created on: Jun 14, 2021
 *      Author: migue
 */
#include "pin_n_clocks.h"
#include "My_led_n_sw.h"

void delay(void)
{
	uint32_t a=TIME;
	while(a--);
}

void Init_clocks(void)
{/*Turn on the clocks for the PORTB and PORTD*/
	SIM_SCGC5 |= (SIM_SCGC5_PORTB_MASK  | SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTC_MASK );
}

void Init_pin(void)
{
	GPIOE_PDDR |= (1<<26); //Configure the PORTD 1 as and output
	GPIOB_PDDR |= (1<<21); //Configure the PORTB 18 as and output
	GPIOB_PDDR |= (1<<22); //Configure the PORTB 19 as and output
	

	
	GPIOE_PDOR |= (1<<26);
	GPIOB_PDOR |= (1<<21);
	GPIOB_PDOR |= (1<<22);
}

void led_blue(void)
{
	LED_BLUE_ON;
	delay();
	LED_BLUE_OFF;
	ptr_func = led_red;
}

void led_red(void)
{
	LED_RED_ON;
	delay();
	LED_RED_OFF;
	ptr_func = led_green;
}

void led_green(void)
{
	LED_GREEN_ON;
	delay();
	LED_GREEN_OFF;
	ptr_func = led_blue;
}

