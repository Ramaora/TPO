/*
 * funciones.c
 *
 *  Created on: 01/10/2013
 *      Author: andresdemski
 */

#ifndef FUNCIONES_C_
#define FUNCIONES_C_

void Init (void);
void Maquina_Touch (void);
void Maquina_Reproduction(void);

void Uart_Control (void);
void Enviar_Actual(void);

extern uint8_t UART_BUSY;
extern uint8_t UART_TxFIFO [16][25];
extern uint8_t UART_TxFIFO_ESTADO;
extern uint8_t UART_RxFIFO [16][17];
extern uint8_t UART_RxFIFO_ESTADO;
extern uint8_t UART_RxPointer;
extern uint8_t UART_TxPointer;

void Display_FileList (void);
uint8_t Select_FileList (void);
void Interfaz_Grafica (void);
void Init_IGraf (void);




#endif /* FUNCIONES_C_ */
