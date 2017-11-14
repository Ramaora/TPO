/*
 * FW_UART.c
 *
 *  Created on: 14/10/2013
 *      Author: marcelo
 */

#include "Aplicacion.h"

extern uint8_t inx_out;
extern uint8_t inx_in;
extern uint8_t enviando;
extern uint8_t tx0Start;

void UART0_IRQHandler (void)
{
	uint8_t iir, dato;

	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U0IIR;

		if ( iir & 0x02 ) //THRE
		{
			if( !PopTx0(&dato) )
				U0THR = dato;
			else
				tx0Start = 0;
		}
		if ( iir & 0x04 ) //Data ready
		{
			PushRx0((uint8_t )U0RBR );
			Display(U0RBR,1);

		}

	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */

}
