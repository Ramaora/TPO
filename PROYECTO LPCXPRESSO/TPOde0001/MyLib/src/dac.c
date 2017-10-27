/*
 * dac.c
 *
 *  Created on: 22/10/2013
 *      Author: andresdemski
 */
#include "MyLPC1769.h"
#include "port.h"

void Init_Dac (void)
{
	PCLKSEL0 &= ~(0x11<22);
	SetPinSel(0,26,2);
	SetPinMode(0,26,PULLDOWN);

	DAC.DACCTRL=0;
	DAC.DACCNTVAL=0;
	DAC.DACR=0;
}

void Write_Dac (uint16_t val)
{
	DAC.DACR= (val & 0x3FF)<<6;
	return;
}
