/*
 * Aplicacion.h
 *
 *  Created on: 14/06/2013
 *      Author: Marcelo
 */

#ifndef APLICACION_H_
#define APLICACION_H_

	#include "FW_Display_Exp3.h"
	#include "FW_GPIO.h"
	#include "KitInfo2_BaseBoard.h"
	#include "Oscilador.h"
	#include "RegsLPC1769.h"


	#define 	KEY4_RC_PRESS	GetPIN (KEY4_RC, ACTIVO_BAJO)
	#define 	KEY3_RC_PRESS	GetPIN (KEY3_RC, ACTIVO_BAJO)
	#define		LED2_ON			SetPIN(LED2,ON)
	#define		LED2_OFF		SetPIN(LED2,OFF)
	#define		LED3_ON			SetPIN(LED3,ON)
	#define		LED3_OFF		SetPIN(LED3,OFF)

	void cuentoPulsos (void);


#endif /* APLICACION_H_ */
