/*
 * KitInic.c
 *
 *  Created on: 17/04/2012
 *      Author: Mica y Chor
 */
	#include "Aplicacion.h"

void InitGPIOs_EXP3 ( void )
{
		/******************** PLACA EXPANSION 3 **********************++*/
		SetPINSEL (A_BCD,PINSEL_GPIO);
		SetPINSEL (B_BCD,PINSEL_GPIO);
		SetPINSEL (C_BCD,PINSEL_GPIO);
		SetPINSEL (D_BCD,PINSEL_GPIO);
		SetPINSEL (CLK,PINSEL_GPIO);
		SetPINSEL (RST,PINSEL_GPIO);
		SetPINSEL (seg_dp,PINSEL_GPIO);

		SetDIR (A_BCD,SALIDA);
		SetDIR (B_BCD,SALIDA);
		SetDIR (C_BCD,SALIDA);
		SetDIR (D_BCD,SALIDA);
		SetDIR (CLK,SALIDA);
		SetDIR (RST,SALIDA);
		SetDIR (seg_dp,SALIDA);


// 	//Empiezo el programa con los LEDs y el buzzer apagados
// 	SetPIN(LED1,OFF);
// 	SetPIN(LED4,OFF);
// 	SetPIN(LED2,OFF);
// 	SetPIN(LED3,OFF);
// 	SetPIN(BUZZ,BUZZ_OFF);

}

