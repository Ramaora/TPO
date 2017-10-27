/*
 * ports.c
 *
 *  Created on: 16/06/2013
 *      Author: demski
 */
#include "MyLPC1769.h"
#include "port.h"

void SetPinSel (uint8_t port, uint8_t pin,uint8_t sel)
{
	if (port<5)
	{
		port = port*2 + pin/16;
		pin = (pin%16)*2;
		PINSEL_BASE [port] &= (~(3<<pin));
		PINSEL_BASE [port] |= (sel << pin);
	}
}

void SetPinDir (uint8_t port,uint8_t pin,uint8_t dir)
{
	if (port<5)
	{
		port *= 8;
		GPIO_BASE [port] &= ~(1<<pin);
		GPIO_BASE [port] |= dir << pin;
	}
}

void SetPinMode (uint8_t port,uint8_t pin, uint8_t sel)
{
	if (port<5)
	{
		port = port*2 + pin/16;
		pin = (pin%16)*2;
		PINMODE_BASE [port] &= (~(3<<pin));
		PINMODE_BASE [port] |= (sel << pin);
	}
}

void SetPinModeOD (uint8_t port, uint8_t pin, uint8_t OD)
{
	if (port<5)
	{
		PINMODEOD_BASE [port] &= (~(1<<pin));
		PINMODEOD_BASE [port] |= (OD << pin);
	}
}

uint32_t ReadPort (uint8_t port)
{
	if (port<5)
	{
		port= (port*8)+5;
		return GPIO_BASE[port];
	}
	return 0;
}

void WritePort (uint8_t port, uint32_t value)
{
	if (port<5)
	{
		port= (port*8)+5;
		GPIO_BASE[port] = value;
	}
}

void SetPin (uint8_t port, uint8_t pin)
{
	if (port<5)
	{
		port= (port*8)+5;
		GPIO_BASE[port] |= (1<<pin);
	}
}

void ClrPin (uint8_t port, uint8_t pin)
{
	if (port<5)
	{
		port= (port*8)+5;
		GPIO_BASE[port] &= ~(1<<pin);
	}
}

void InvPin (uint8_t port,uint8_t pin)
{
	if (port<5)
	{
		port = (port *8) + 5;
		GPIO_BASE [port] ^= (1<<pin);
	}
}

uint8_t GetPin (uint8_t port,uint8_t pin)
{
	if (port<5)
	{
		port = (port * 8) + 5;
		return ((GPIO_BASE[port] >>pin)& (0x1));
	}
	return 0;
}

void WritePortMask (uint8_t port, uint32_t value, uint32_t mask)
{
	if (port<5)
	{
		port= (port*8)+4;
		GPIO_BASE[port]=mask;
		GPIO_BASE[port+1] =value;
		GPIO_BASE[port]=0;
	}
}

void WritePin (uint8_t port, uint8_t pin,uint8_t value)
{
	if (port<5)
	{
		port= (port*8)+5;
		GPIO_BASE[port] &= ~(1<<pin);
		GPIO_BASE[port] |= (value << pin);
	}
}



