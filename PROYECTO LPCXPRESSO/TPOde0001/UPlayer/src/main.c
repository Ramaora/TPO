/*
===============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Copyright (C) 
 Description : main definition
===============================================================================
*/

#include "MyLPC1769.h"
#include "InfotronicKit.h"
#include "ssp.h"
#include "timer.h"
#include "interruption.h"
#include "port.h"
#include "Touch.h"
#include "TFT.h"
#include "MP3.h"
#include "delay.h"
#include "vs1003.h"
#include "Flags.h"
#include "variables.h"
#include "systick.h"
#include "uart0.h"
#include <string.h>
#include <stdio.h>
#include "funciones.h"
#include "dac.h"

extern uint8_t ESTADO_REPRODUCCION;

FLAGS_S		Flags;

uint16_t TOUCH_X=0;
uint16_t TOUCH_Y=0;

uint8_t 	File_Selected=0;
uint8_t  File_Before=0;
uint8_t  File_Playing=0;
uint8_t TICK=0;

/**
 * \fn int main (void)
 * \brief Main
 * \details Main
 */
int main(void)
{
	Init();

	SetPinSel(LPCXPRESSOLED,0);
	SetPinDir(LPCXPRESSOLED,SALIDA);
	SetPinMode(LPCXPRESSOLED,O_NORMAL);

	ClrPin(LPCXPRESSOLED);

	while(1) {
		__asm ("wfi");

		if (ESTADO_REPRODUCCION==1)
		{
			if (Buffers_Fill())
			{
				FILE_END=1;
			}
		}
		Interfaz_Grafica ();
		Maquina_Reproduction();
	}
}

