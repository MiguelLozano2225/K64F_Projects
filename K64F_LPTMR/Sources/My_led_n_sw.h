/*
 * My_led_n_sw.h
 *
 *  Created on: Jun 25, 2021
 *      Author: migue
 */

#ifndef MY_LED_N_SW_H_
#define MY_LED_N_SW_H_

#define INIT_LEDS			(GPIOB_PDDR |= (1<<21) | (1<<22));\
							(GPIOE_PDDR |= (1<<26));\
							(PORTE_PCR26 |= PORT_PCR_MUX(1));\
							(PORTB_PCR21 |= PORT_PCR_MUX(1));\
							(PORTB_PCR22 |= PORT_PCR_MUX(1));\


#define LED_BLUE_ON			GPIOB_PDOR &= ~(1<<21)
#define LED_BLUE_OFF		GPIOB_PDOR |=  (1<<21)
#define LED_BLUE_TOGGLE		GPIOB_PDOR ^=  (1<<21)

#define LED_RED_ON			GPIOB_PDOR &= ~(1<<22)
#define LED_RED_OFF			GPIOB_PDOR |=  (1<<22)
#define LED_RED_TOGGLE		GPIOB_PDOR ^=  (1<<22)

#define LED_GREEN_ON		GPIOE_PDOR &= ~(1<<26)
#define LED_GREEN_OFF		GPIOE_PDOR |=  (1<<26)
#define LED_GREEN_TOGGLE	GPIOE_PDOR ^=  (1<<26)

#endif /* MY_LED_N_SW_H_ */
