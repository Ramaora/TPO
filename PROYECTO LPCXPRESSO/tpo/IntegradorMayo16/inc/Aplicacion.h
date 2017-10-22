/*
 * Aplicacion.h
 *
 *  Created on: 14/06/2013
 *      Author: Marcelo
 */

#ifndef APLICACION_H_
#define APLICACION_H_

	#include "FW_EXPANSION1.h"
	#include "FW_GPIO.h"
	#include "RegsLPC1769.h"
	#include "KitInfo2_BaseBoard.h"
	#include "Oscilador.h"
	#include "Teclado_4x1.h"
	#include <string.h>
	#include "rtc176x.h"
	#include "uart176x.h"
	#include "xprintf.h"
	#include "diskio.h"
	#include "ff.h"
	#include "sound.h"
	#include <stdio.h>

	#define	INVIERTO_LED1_EXP1	TooglePIN (LED1_EXP1)
	#define	INVIERTO_LED3_EXP1	TooglePIN (LED3_EXP1)
	#define	INVIERTO_LED5_EXP1	TooglePIN (LED5_EXP1)
	#define	INVIERTO_LED7_EXP1	TooglePIN (LED7_EXP1)
	#define	INVIERTO_RGB_ROJO	TooglePIN (RGBR)

	#define		PORT0		0
	#define		PORT1		1
	#define		PORT2		2
	#define		PORT3		3
	#define		PORT4		4
	//Dir
	#define		SALIDA 		1
	#define 	ENTRADA		0
	//Mode
	#define 	PULLUP		0
	#define		REPEATER	1
	#define		NEITHER		2
	#define		PULLDOWN	3
	//ModeOD
	#define 	O_NORMAL		0
	#define		O_OPENDRAIN		1
	//EDGE
	#define 	RISING 		0
	#define		FALLING		1
	#define REPRODUCIENDO 1
	uint8_t getkey(void);
	void Init_Dac(void);
	void ApagarTimer0(void);
	void Write_Dac (uint16_t);
	void PrenderTimer0(void);
	void InicializarKit ( void );

#endif /* APLICACION_H_ */
