/*
 * UART.h
 *
 *  Created on: Sep 16, 2021
 *      Author: migue
 */

#ifndef UART_H_
#define UART_H_

#include "derivative.h"

#define F_BUS      		20970000U
#define BAUD_RATE	 	9600U
#define SBR  			(F_BUS/(16U*BAUD_RATE))
#define BRFA 			(32U*((F_BUS/(16U*BAUD_RATE)) - SBR))  

void Init_UART (void);
void UART_SendString (unsigned char* String);

#endif /* UART_H_ */
