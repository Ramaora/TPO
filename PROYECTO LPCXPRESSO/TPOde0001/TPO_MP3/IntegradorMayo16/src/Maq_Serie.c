/*
 * Maq_Serie.c

 *
 *  Created on: 6 de nov. de 2017
 *      Author: Matias
 */


#include <Aplicacion.h>


void maq1 (void){
uint8_t recibido;
static uint8_t estado=REPOSO;
static uint8_t bufferposta;

if (PopRx0(&recibido))return;

switch (estado){

case REPOSO:
	if (recibido=='#') estado=VALIDACION;
	break;

case VALIDACION:
	if (recibido!='S' && recibido!='A' && recibido!='P'){
	estado=REPOSO;
	}else{
		bufferposta=recibido; estado=FINDETRAMA;
	break;

case FINDETRAMA:
	if (recibido!='$'){
		estado=REPOSO;break;
	}

	Display (bufferposta-48);

	if(bufferposta=='S'){
		SiguienteTema();
	}

	if(bufferposta=='A'){
		AnteriorTema();
		}

	if(bufferposta=='P'){
		PausarReproduccion();
	}

	}
}


}
void maq2 (void){

uint8_t tecla=getkey();

switch (tecla){

case 1:

	EnviarString0("#1$");
	break;
case 2:
	EnviarString0("#2$");
	break;
case 3:
	EnviarString0("#3$");
	break;
case 4:
	EnviarString0("#4$");
	break;
}
}
