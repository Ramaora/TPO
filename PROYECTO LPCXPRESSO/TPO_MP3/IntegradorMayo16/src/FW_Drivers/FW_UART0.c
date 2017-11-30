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

/**
 * \fn void UART0_IRQHandler (void)
 * \brief handler de interrupciones del UART0
 * \details
 * \param [in] void
 * \return void
 * */
void UART0_IRQHandler (void)
{
	uint8_t iir, dato;

	do{
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
	while( ! ( iir & 0x01 ) );

}
