/*
 * PR_UART0.c
 *
 *  Created on: 7/9/2015
 *      Author: Gabriel
 */

#include "Aplicacion.h"

#define TX0BUFFER_SIZE	100
#define RX0BUFFER_SIZE	100
// Buffer de Transmision
uint8_t bufferTx0[TX0BUFFER_SIZE];
// Buffer de Recepcion
uint8_t bufferRx0[RX0BUFFER_SIZE];

// Indices de Transmision
uint8_t tx0_in,tx0_out;
// Indices de Recepcion
uint8_t rx0_in,rx0_out;
// Flags de estado de los buffers
uint8_t tx0_buffer_full = 0, tx0_buffer_empty = 1;
uint8_t rx0_buffer_full = 0, rx0_buffer_empty = 1;

extern uint8_t tx0Start;

uint8_t PushTx0(uint8_t dato)
{
	if(tx0_buffer_full)
		return 1;	//buffer lleno

	bufferTx0[tx0_in] = dato;
	tx0_in++;
	tx0_in %= TX0BUFFER_SIZE;
	tx0_buffer_empty = 0;	//si agrego un dato el buffer ya no esta vacio

	if(tx0_in == tx0_out)
		tx0_buffer_full = 1;	//se lleno el buffer

	if (tx0Start == 0)
	{
		tx0Start = 1;
		U0THR='%';
	}
	return 0;	//dato agregado al buffer
}

uint8_t PopTx0( uint8_t *dato )
{
	if(tx1_buffer_empty)
		return 1;	//buffer vacio

	*dato = (uint8_t) bufferTx0[tx0_out];
	tx0_out++;
	tx0_out %= TX0BUFFER_SIZE;
	tx0_buffer_full = 0;	//si saco un dato el buffer ya no esta lleno

	if(tx0_out == tx0_in)
		tx0_buffer_empty = 1;	//se vacio el buffer

	return 0;	//dato sacado del buffer
}

uint8_t PushRx0( uint8_t dato )
{
	if(rx0_buffer_full)
		return 1;	//buffer lleno

	bufferRx0[rx0_in] = dato;
	rx0_in ++;
	rx0_in %= RX0BUFFER_SIZE;
	rx0_buffer_empty = 0;	//si agrego un dato el buffer ya no esta vacio

	if(rx0_in == rx0_out)
		rx0_buffer_full = 1;	//se lleno el buffer

	return 0;	//dato agregado al buffer
}

uint8_t PopRx0( uint8_t *dato )
{
	if(rx0_buffer_empty)
		return 1;	//buffer vacio

	*dato = (uint8_t) bufferRx0[rx0_out];
	rx0_out++;
	rx0_out %= RX0BUFFER_SIZE;
	rx0_buffer_full = 0;	//si saco un dato el buffer ya no esta lleno

	if(rx0_out == rx0_in)
		rx0_buffer_empty = 1;	//se vacio el buffer

	return 0;	//dato sacado del buffer
}

void EnviarString0 (const char *str)
{
	uint32_t i;
	for( i = 0 ; str[i] ; i++ )
		PushTx0( str[i] );
}

