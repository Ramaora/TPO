/*
 * port.h
 *
 *  Created on: 16/06/2013
 *      Author: demski
 */



#ifndef PORT_H_
#define PORT_H_

#define		PORT0		0
#define		PORT1		1
#define		PORT2		2
#define		PORT3		3
#define		PORT4		4
//Dir
#define		SALIDA 		1
#define 	ENTRADA		0
//Mode
#define 	PULLUP		0
#define		REPEATER	1
#define		NEITHER		2
#define		PULLDOWN	3
//ModeOD
#define 	O_NORMAL		0
#define		O_OPENDRAIN		1
//EDGE
#define 	RISING 		0
#define		FALLING		1
//Enable



//// Configuracion de Pines /////

//Seleccion de función///
void SetPinSel (uint8_t port, uint8_t pin,uint8_t sel);

///// GPIO /////

// Entrada o salida?? //
void SetPinDir (uint8_t port,uint8_t pin,uint8_t dir);

// Tipo de entrada //
void SetPinMode (uint8_t port,uint8_t pin, uint8_t sel);

//Tipo de salida //
void SetPinModeOD (uint8_t port, uint8_t pin, uint8_t OD);

///Manejo de GPIO //

void WritePort (uint8_t port,uint32_t Value);
uint32_t ReadPort (uint8_t port);
void SetPin (uint8_t port, uint8_t pin);
void ClrPin (uint8_t port, uint8_t pin);
uint8_t GetPin (uint8_t port, uint8_t pin);
void InvPin (uint8_t port,uint8_t pin);
void WritePortMask (uint8_t port, uint32_t value, uint32_t mask);
void WritePin (uint8_t port, uint8_t pin, uint8_t value);


///Interruptions




#endif /* PORT_H_ */
