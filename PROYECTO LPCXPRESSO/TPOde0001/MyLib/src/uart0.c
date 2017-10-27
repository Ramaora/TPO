/*
 * uart0.c
 *
 *  Created on: 03/09/2013
 *      Author: Andres
 */

#include "MyLPC1769.h"
#include "interruption.h"
#include "port.h"
#include "InfotronicKit.h"

void Init_UART0(uint32_t baudrate)
{
    uint32_t  Fdiv;

	SetPinSel(U0TX,1);
	SetPinSel(U0RX,1);

	PCONP |= 0x01<<3; //Turn on the radio (?
	PCLKSEL0 &= ~(0x03<<6); //25Mhz

	UART0.LCR = (uint8_t) 0x83; /* 8 bits, no Parity, 1 Stop bit */
	Fdiv = ( 25000000 / 16 ) / baudrate ;
	UART0.DLM = Fdiv / 256;
	UART0.DLL = Fdiv % 256;
    UART0.LCR = 0x03;		/* DLAB = 0 */

    UART0.LCR = (uint8_t) 0x03;
    UART0.FCR = 0x07;		/* Enable and reset TX and RX FIFO. */
    UART0.IER = 0x03;
    NVIC_IrqEnable(IRQ_UART0);
}

void  UART0_PutChar (uint8_t ch)
{
	while (!(UART0.LSR & 0x20));
	UART0.THR  = ch;
}


uint8_t UART0_GetChar (void)
{
	while (!(UART0.LSR & 0x01));
	return (UART0.RBR);
}

void  UART0_PutString (const uint8_t * str)
{
    while ((*str) != 0)
    {
        if (*str == '\n')
        {
            UART0_PutChar(*str);
            UART0_PutChar("\r");
        }
        else UART0_PutChar(*str);
        str++;
    }
}

void UART0_Send (uint8_t *str)
{
	while (*str)
	{
		UART0.THR  = *str;
		str++;
	}
}
