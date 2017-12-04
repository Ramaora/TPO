/*
 * FW_EXPANSION1.h
 *
 *  Created on: 14/06/2013
 *      Author: Marcelo
 */

#ifndef FW_EXPANSION1_H_
#define FW_EXPANSION1_H_

	/*Realizo las definiciones del HW contenido en la placa de expansión*/

    #include "../../Reproductor/inc/Aplicacion.h"
    
	//LEDS
	    #define 	LED1_EXP1	EXPANSION0
	#define 	LED2_EXP1 	EXPANSION1
	#define 	LED3_EXP1 	EXPANSION2
	#define 	LED4_EXP1 	EXPANSION3
	#define 	LED5_EXP1 	EXPANSION4
	#define 	LED6_EXP1 	EXPANSION5
	#define 	LED7_EXP1 	EXPANSION6
	#define 	LED8_EXP1 	EXPANSION7

	//DIP1
	#define		DIP1_1		EXPANSION8
	#define		DIP1_2		EXPANSION9
	#define		DIP1_3		EXPANSION10
	#define		DIP1_4		EXPANSION11
	#define		DIP1_5		EXPANSION12
	#define		DIP1_6		EXPANSION13
	#define		DIP1_7		EXPANSION14
	#define		DIP1_8		EXPANSION15

	//DIP2
	#define		DIP2_1		EXPANSION16
	#define		DIP2_2		EXPANSION17
	#define		DIP2_3		EXPANSION18

	//Prototipos de función:
	void Inicializar_EXP1( void );


#endif /* FW_EXPANSION1_H_ */
