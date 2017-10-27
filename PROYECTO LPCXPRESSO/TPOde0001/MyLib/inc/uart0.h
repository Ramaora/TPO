/*
 * uart0.h
 *
 *  Created on: 03/09/2013
 *      Author: Andres
 */

#ifndef UART0_H_

void Init_UART0(uint32_t baudrate);
void  UART0_PutChar (uint8_t ch);
uint8_t UART0_GetChar (void);
void  UART0_PutString (const uint8_t * str);
void UART0_Send (uint8_t *str);

#endif /* UART0_H_ */
