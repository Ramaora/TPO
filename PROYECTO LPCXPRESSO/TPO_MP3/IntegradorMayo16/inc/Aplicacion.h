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
    #include "FW_Display-Expansion2.h"
	#include "lcd.h"


	#define	INVIERTO_LED1_EXP1	TooglePIN (LED1_EXP1)
	#define	INVIERTO_LED3_EXP1	TooglePIN (LED3_EXP1)
	#define	INVIERTO_LED5_EXP1	TooglePIN (LED5_EXP1)
	#define	INVIERTO_LED7_EXP1	TooglePIN (LED7_EXP1)
	#define	INVIERTO_RGB_ROJO	TooglePIN (RGBR)
	#define VALIDACION 1
	#define FINDETRAMA 2
	#define TX0BUFFER_SIZE	100
	#define RX0BUFFER_SIZE	100

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

	#define LCD_ANCHO	16

	uint8_t getkey(void);
	void Init_Dac(void);
	void ApagarTimer0(void);
	void Write_Dac (uint16_t);
	void PrenderTimer0(void);
	void InicializarKit ( void );
	void ArrancarReproduccion(void);
	void PausarReproduccion(void);
	void AnteriorTema(void);
	void SiguienteTema(void);
	void Inicializar_Display7s( void );
	void BarridoDisplay(void);
	void Display(uint16_t,uint8_t);
	void InitUART0 (void);
	void EnviarString0 (const char *str);
	uint8_t PushRx0( uint8_t dato );
	uint8_t PopTx0(uint8_t*);
	void FileList_Fill (void);
	void maqreproduccion(void);
	void cargarBuffer(void);
	void reiniciarRTC(void);
	void prenderRTC(void);
	void apagarRTC(void);
	void mandarlista(void);

#endif /* APLICACION_H_ */
