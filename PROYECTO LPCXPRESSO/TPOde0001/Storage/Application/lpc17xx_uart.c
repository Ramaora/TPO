/**************************************************************************//**
 * @file     lpc17xx_uart.c
 * @brief    Drivers for UART peripheral in lpc17xx.
 * @version  1.0
 * @date     18. Nov. 2010
 *
 * @note
 * Copyright (C) 2010 NXP Semiconductors(NXP), All rights reserved.
 *
 ******************************************************************************/

#include "lpc17xx_uart.h"

#if USE_LIB_PRINTF==0
#include <stdarg.h>
#endif

/**
  * @brief  Initializes the UART0.
  *
  * @param  baudrate: Specifies the baud rate in Hz.
  * @retval None 
  */
void  UART_Init(uint32_t baudrate)
{
	uint32_t SystemCoreClock = 100000000;
    uint32_t  Fdiv;
	uint32_t  pclkdiv, pclk;

    LPC_PINCON->PINSEL0 |= 0x00000050;       /* RxD0 and TxD0 */

	/* Bit 6~7 is for UART0 clock divider. */
	pclkdiv = (LPC_SC->PCLKSEL0 >> 6) & 0x03;
	switch ( pclkdiv )
	{
	  case 0x00:
	  default:
		pclk = SystemCoreClock/4;
		break;
	  case 0x01:
		pclk = SystemCoreClock;
		break; 
	  case 0x02:
		pclk = SystemCoreClock/2;
		break; 
	  case 0x03:
		pclk = SystemCoreClock/8;
		break;
	}
	
    LPC_UART0->LCR = 0x83;		/* 8 bits, no Parity, 1 Stop bit */
	Fdiv = ( pclk / 16 ) / baudrate ;	/*baud rate */
    LPC_UART0->DLM = Fdiv / 256;							
    LPC_UART0->DLL = Fdiv % 256;
    LPC_UART0->LCR = 0x03;		/* DLAB = 0 */
    LPC_UART0->FCR = 0x07;		/* Enable and reset TX and RX FIFO. */
}

/**
  * @brief  Transmit a single charecter through UART0.
  *
  * @param  ch: charecter to be transmitted.
  * @retval None 
  */
void  UART_PutChar (uint8_t ch)
{
   while (!(LPC_UART0->LSR & 0x20));
   LPC_UART0->THR  = ch;
}

/**
  * @brief  Receive a single charecter through UART0.
  *
  * @param  None.
  * @retval Received character 
  */
uint8_t UART_GetChar (void) 
{
  while (!(LPC_UART0->LSR & 0x01));
  return (LPC_UART0->RBR);
}

/**
  * @brief  Transmit a string through UART0.
  *
  * @param  str: Ponter to the string terminated with '\0'.
  * @retval None 
  */
void  UART_PutString (const uint8_t * str)
{
#if 1 // UART_PutString ("string\n");
    while ((*str) != 0) 
    {
        if (*str == '\n') {
            UART_PutChar(*str++);
            UART_PutChar('\r');
        } else {
            UART_PutChar(*str++);
        }    
    }
#else // UART_PutString ("string\n\r");
    while (*str != 0) 
    {
        UART_PutChar(*str++);
    }
#endif
}

/**
  * @brief  Print formatted string.
  *
  * @param  Allow variable length of arguments.
  * @retval None 
  */
#if USE_LIB_PRINTF==0
void  UART_Printf (const  uint8_t *format, ...)
{
    static  uint8_t  buffer[40 + 1];
            va_list     vArgs;


    va_start(vArgs, format);
    vsprintf((char *)buffer, (char const *)format, vArgs);
    va_end(vArgs);
    UART_PutString((uint8_t *) buffer);
}
#endif
