/*
 * delay.c
 *
 *  Created on: 20/08/2013
 *      Author: Andres
 */


#include "mylib.h"

void msDelay (uint32_t ms)
{
	uint32_t i=0;
	uint32_t Ctrl = SYSTICK_CTRL;
	uint32_t RLoad = SYSTICK_RLOAD;

	SYSTICK_CTRL &= ~ (0x3) ; //apago interrupcion
	SYSTICK_RLOAD = (SYSTICK_CALIB / 10) - 1 ;

	SYSTICK_CUR= SYSTICK_RLOAD; //Lo pongo en el valor de arranque
	SYSTICK_CTRL |= 0x5; //Prendo

	for (i=0;i<ms;i++)
	{
		while (SYSTICK_CUR);
	}

	SYSTICK_RLOAD= RLoad;
	SYSTICK_CTRL = Ctrl;
}
