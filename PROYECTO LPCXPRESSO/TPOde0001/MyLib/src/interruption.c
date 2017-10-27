/*
 * interruption.c
 *
 *  Created on: 27/07/2013
 *      Author: tigermax
 */
#include "MyLPC1769.h"
#include "interruption.h"

void NVIC_IrqEnable (uint8_t Irq)
{
	if (Irq >31)
	{
		(*(NVIC_ISER_BASE+1)) = 1<<(Irq-32);
	}
	else
	{
		(*(NVIC_ISER_BASE)) = 1<<Irq;
	}
}

void NVIC_IrqDisable (uint8_t Irq)
{
	if (Irq >31)
	{
		(*(NVIC_ICER_BASE+1)) = 1<<(Irq-32);
	}
	else
	{
		(*(NVIC_ICER_BASE)) = 1<<Irq;
	}
}

void NVIC_Pending (uint8_t Irq)
{
	if (Irq >31)
	{
		(*(NVIC_ISPR_BASE+1)) = 1<<(Irq-32);
	}
	else
	{
		(*(NVIC_ISPR_BASE)) = 1<<Irq;
	}
}

void NVIC_NotPending (uint8_t Irq)
{
	if (Irq >31)
	{
		(*(NVIC_ICPR_BASE+1)) = 1<<(Irq-32);
	}
	else
	{
		(*(NVIC_ICPR_BASE)) = 1<<Irq;
	}
}

void NVIC_IrqPriority (uint8_t Irq, uint8_t Prio)
{
	uint8_t Aux = (Irq%4);
	NVIC_IPR_BASE[Irq/4] =(Prio & 0x1F) << (( 3*(Aux+1) )+ 5*(Aux));
}

void NVIC_TriggerIrq (uint8_t Irq)
{
	(*NVIC_STIR) = Irq;
}

//////////////////////////EXTTERNAL///////////////////////

uint8_t EXT_GetIrqFlag ()
{
	return *EXT_INTFLAG;
}

void EXT_ClrIrqFlag (uint8_t Flag)
{
	*EXT_INTFLAG &= ~(1<<Flag);
}

void EXT_IrqMode (uint8_t Ext, uint8_t Mode)
{
	(*EXT_MODE) &= ~(1<<Ext);
	(*EXT_MODE) |= Mode * (1<<Ext);
}

void EXT_IrqPolarity (uint8_t Ext, uint8_t Polar)
{
	(*EXT_POLAR) &= (1<<Ext);
	(*EXT_POLAR) |= Polar * (1<<Ext);
}


//////////////////////////GPIO///////////////////////


void GPIO_IrqEnable (uint8_t port, uint8_t pin, uint8_t enable, uint8_t Edge) //enable: ENABLE o DISSABLE inter: RISING o FALLING
{
	if (port <3 && port != 1)
	{
		(*(GPIO_INTENR_BASE + ((port==2)? 1:0) * 8 + Edge)) &= (~(1<<pin)); //Lo pongo en 0
		(*(GPIO_INTENR_BASE + ((port==2)? 1:0) * 8 + Edge)) |= enable * (1<<pin);  //escribo lo que me pida
	}
}

uint32_t GPIO_IrqPending ()
{
	return (*GPIO_INTSTATUS) & 0x3;
}

uint32_t GPIO_IrqStat (uint8_t port,uint8_t pin,uint8_t Edge)
{
	return ((*(GPIO_STATR_BASE + port * 8 + Edge))&(1<<pin));
}
void GPIO_IrqClr (uint8_t port, uint8_t pin)
{
	if (port <2) (*(GPIO_INTCLR_BASE + port * 8)) = (1<<pin);
}
