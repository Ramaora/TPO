/*
 * systick.c
 *
 *  Created on: 14/08/2013
 *      Author: Andres
 */
#include "MyLPC1769.h"


void SysTick_ClrIrq (void)
{
	if (SYSTICK_CTRL);
}


void SysTick_Enable ()
{
	SYSTICK_RLOAD = SYSTICK_CALIB/ 10 -1; // Cada 1ms a 100Mhz
	SYSTICK_CTRL = 0x7; // b0: Enable,b1: interruption,b2: Cpu clock
}

