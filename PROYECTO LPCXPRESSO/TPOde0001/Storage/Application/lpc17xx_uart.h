 /**************************************************************************//**
 * @file     lpc17xx_uart.h
 * @brief    Header file for UART peripheral in lpc17xx.
 * @version  1.0
 * @date     18. Nov. 2010
 *
 * @note
 * Copyright (C) 2010 NXP Semiconductors(NXP), All rights reserved.
 *
 ******************************************************************************/

#ifndef LPC17XX_UART_H
#define LPC17XX_UART_H


#include  "LPC17xx.h"

/* 1: use printf in stdio library, 0: use UART_Printf */
#define USE_LIB_PRINTF  1
#if USE_LIB_PRINTF==1
#include <stdio.h>
#endif


void    UART_Init (uint32_t  baudrate);
void    UART_PutChar (uint8_t   ch);
uint8_t UART_GetChar (void);
void    UART_PutString (const uint8_t  *str);
#if USE_LIB_PRINTF==0
void    UART_Printf (const uint8_t  *format, ...);
#else
#define UART_Printf printf
#endif


#endif

