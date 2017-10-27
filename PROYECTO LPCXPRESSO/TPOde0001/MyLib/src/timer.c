/*
 * timer.c
 *
 *  Created on: 18/09/2013
 *      Author: andresdemski
 */

#include "MyLPC1769.h"
#include "interruption.h"

void Init_Timer0_Match0 (void)
{
	PCONP |= 1<<1;
	PCLKSEL0 &= ~(0x3<<2);
	TIMER0.IR=0;
	TIMER0.TCR=2;
	TIMER0.CTCR=0;
	TIMER0.PR=25;
	TIMER0.MCR=3;
	NVIC_IrqEnable(IRQ_TIMER0);
}

void Timer0_ClrIrq_Match0 (void)
{
	TIMER0.IR = 1;
}

void Timer0_Match0 (uint8_t estado, uint32_t Match)
{
	TIMER0.TCR=2;
	TIMER0.MR0=Match;
	TIMER0.IR=1;
	TIMER0.MCR=3;
	if (estado)	TIMER0.TCR=1;
}

void Timer0_IrqDisable ()
{
	TIMER0.IR=0;
}

void Timer0_IrqEnable ()
{
	TIMER0.IR=1;
}
