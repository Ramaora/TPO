#include "Aplicacion.h"

	//1°)Selecciono FUNCION del pin en PINSELx.
	//void SetPINSEL (uint8_t puerto, uint8_t pin, uint8_t modo)

	//2°)A aquellos pines configurados como GPIO, les configuro su DIRECCION en FIOxDIR
	//void SetDIR(registro* puerto,uint8_t pin,uint8_t direccion)
	//ENTRADA = 0 - SALIDA = 1

	//3°) SI son ENTRADAS, debe definirse su configuración eléctrica
	// void SetPINMODE( uint8_t port , uint8_t pin ,uint8_t modo)
	//!< 00	Pull Up resistor enable (reset value)		01	repeated mode enable
	//!< 11	Pull Down resistor enable					10	ni Pull Up ni Pull DOwn

void Inicializar_EXP1( void )
{
	SetPINSEL ( LED1_EXP1 , PINSEL_GPIO);
	SetPINSEL ( LED2_EXP1 , PINSEL_GPIO);
	SetPINSEL ( LED3_EXP1 , PINSEL_GPIO);
	SetPINSEL ( LED4_EXP1 , PINSEL_GPIO);
	SetPINSEL ( LED5_EXP1 , PINSEL_GPIO);
	SetPINSEL ( LED6_EXP1 , PINSEL_GPIO);
	SetPINSEL ( LED7_EXP1 , PINSEL_GPIO);
	SetPINSEL ( LED8_EXP1 , PINSEL_GPIO);


	SetDIR ( LED1_EXP1 , SALIDA);
	SetDIR ( LED2_EXP1 , SALIDA);
	SetDIR ( LED3_EXP1 , SALIDA);
	SetDIR ( LED4_EXP1 , SALIDA);
	SetDIR ( LED5_EXP1 , SALIDA);
	SetDIR ( LED6_EXP1 , SALIDA);
	SetDIR ( LED7_EXP1 , SALIDA);
	SetDIR ( LED8_EXP1 , SALIDA);

	SetPIN (LED6_EXP1, OFF); 	//lo apago pues arranca prendido

}
