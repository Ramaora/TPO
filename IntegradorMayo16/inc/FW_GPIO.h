/*
 * FW_GPIO.h
 *
 *  Created on: 14/06/2013
 *      Author: Marcelo
 */

#ifndef FW_GPIO_H_
#define FW_GPIO_H_

	#include "RegsLPC1769.h"

    void 		SetPINSEL 	( uint8_t  , uint8_t  ,uint8_t );
    void 		SetPINMODE	( uint8_t  , uint8_t  ,uint8_t );
    void 		SetDIR		( uint8_t  , uint8_t  , uint8_t  );
    void 		SetPIN		( uint8_t  , uint8_t  , uint8_t  );
    uint8_t 	GetPIN		( uint8_t  , uint8_t  , uint8_t );
    void 		TooglePIN	( uint8_t  , uint8_t);

    #define		ACTIVO_BAJO		0
    #define		ACTIVO_ALTO		1

	// dirección en FIODIR
	#define 	ENTRADA			0
	#define 	SALIDA			1

    // Modo OD
    	#define		NORMAL			0
    	#define		OPEN_DRAIN		1

	// identificadores de los puertos
	#define 	PORT0			0
	#define 	PORT1			1
	#define 	PORT2			2
	#define 	PORT3			3
	#define 	PORT4			4


#endif /* FW_GPIO_H_ */
