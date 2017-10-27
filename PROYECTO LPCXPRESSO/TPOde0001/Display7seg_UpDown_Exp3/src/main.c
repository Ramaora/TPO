/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include "Aplicacion.h"
volatile uint8_t msgDisplay[DIGITOS];			//!< Buffer de display

int main(void)
{
	InicializarKit ();
	Display (0);				/*(1 display de 6 dígitos)*/
	
	while(1)
		cuentoPulsos() ;

	return 0 ;
}
