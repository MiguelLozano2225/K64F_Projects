/*
 * UART.c
 *
 *  Created on: Sep 16, 2021
 *      Author: migue
 */
#include "UART.h"

void Init_UART (void)
{
	UART3_BDH = UART_BDH_SBR((SBR>>8) & 0x1FU);
	UART3_BDL = (SBR & 0xFFU);
	UART3_C4 = UART_C4_BRFA(BRFA);
	
	UART3_C1 = 0U;
	UART3_C2 |= UART_C2_TE_MASK | UART_C2_RE_MASK | UART_C2_RIE_MASK; 	
}

void UART_SendString (unsigned char* String)
{
	
	while(*String |= '\0')
	{
		UART3_D = *String;				
		while(!(UART3_S1 & UART_S1_TC_MASK));						//Wait for transmission complete flag
		String ++;
	}
	
}
