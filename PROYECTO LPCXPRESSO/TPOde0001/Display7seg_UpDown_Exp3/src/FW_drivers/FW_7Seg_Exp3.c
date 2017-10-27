/**
 \file KitInfo2FW_7Seg.c
 \brief Drivers del display de 7 segmentos
 \details Expansion 2
 \author Ing. Marcelo Trujillo
 \date 2012.04.25
 */

#include "Aplicacion.h"

extern volatile uint8_t msgDisplay[];		//!< Buffer de display
void BarridoDisplay(void);

	void BarridoDisplay(void)
	{
		static uint8_t i = 0;

		SetPIN(A_BCD, (msgDisplay[i] & 	  (uint8_t) 0x01) );
		SetPIN(B_BCD, (msgDisplay[i]>>1 & (uint8_t) 0x01));
		SetPIN(C_BCD, (msgDisplay[i]>>2 & (uint8_t) 0x01));
		SetPIN(D_BCD, (msgDisplay[i]>>3 & (uint8_t) 0x01));

		if(!i) { //reseteo al comienzo de cada ciclo
			SetPIN (RST, ON);
			SetPIN (RST, OFF);
		}
		else {	//produzco el desplazamiento de dígito con un clock
			SetPIN (CLK, ON);
			SetPIN (CLK, OFF);
		}
		i++;
		i%= DIGITOS;
	}

	//Para evitar blinking, apago (los segmentos) el BCD enviando un código no permitido al CD4511

	//		SetPIN (A_BCD,ON);		//EX3_BCDA = ON ;
	//		SetPIN (B_BCD,ON);		//EX3_BCDB = ON ;
	//		SetPIN (C_BCD,ON);		//EX3_BCDC = ON ;
	//		SetPIN (D_BCD,ON);		//EX3_BCDD = ON ;
	//		SetPIN (seg_dp,OFF);		//EX3_dp = OFF;
