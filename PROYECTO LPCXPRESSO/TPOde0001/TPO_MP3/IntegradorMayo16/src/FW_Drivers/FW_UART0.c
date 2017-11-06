/*
 * FW_UART.c
 *
 *  Created on: 14/10/2013
 *      Author: marcelo
 */

#include "Aplicacion.h"

extern uint8_t buffer[TOPE];
extern uint8_t inx_out;
extern uint8_t inx_in;
extern uint8_t enviando;

void UART0_IRQHandler (void)
{
	static uint8_t makeupper = 1;		//arranco pasando a MAYUSCULA...
	uint8_t iir, aux;

	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U0IIR;

		if ( iir & 0x04 ) //Data ready
		{
			buffer[inx_in++] = (uint8_t) U0RBR;   	//guardo en buffer e incremento índice
			inx_in %= TOPE;					//garantizo el buffer circular
			if (!enviando) 		//si no estoy enviando....fuerzo la Tx.
				iir |= 0x02;	//simulando a la fuerza la existencia de b1 de IIR = 1.
		}

		if ( iir & 0x02 ) //THRE
		{
			if (inx_in != inx_out)		//Cada vea que saco un dato, vuelve a interrumpir.
			{//Cuando saque el último...y los índices queden empatados...hay que cortar la Tx
				enviando = 1;	 		//aviso que estoy enviando
				aux = buffer[inx_out];
				if ( (aux>' ' && aux<'A') | (aux>'Z' && aux<'a') | (aux>'z') ) 	{
					U0THR = (uint8_t)'@';	//verifico que el dato enviado es imprimible
					U0THR = (uint8_t) ' ';	//imprimo un espacio entre cada par de caracteres
					inx_out++;				//sino, imprimo '@'
					return;
				}

				if (makeupper)	 		//hago mayúscula
					U0THR = upper (buffer[inx_out++]);
				else			 		//hago minúscula
					U0THR = lower (buffer[inx_out++]);

				U0THR = (uint8_t) ' ';	//imprimo un espacio entre cada par de caracteres
				makeupper = !makeupper;	 //ciclo la variable entre o y 1
				inx_out %= TOPE; 		//garantizo el buffer circular
			}
			else
				enviando = 0;  //aviso que terminé de transmitir.
		}
	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}
