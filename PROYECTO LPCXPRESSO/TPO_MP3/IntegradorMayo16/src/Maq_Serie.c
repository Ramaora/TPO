/*
 * Maq_Serie.c

 *
 *  Created on: 6 de nov. de 2017
 *      Author: Matias
 */


#include "Aplicacion.h"
extern uint8_t estado2;

void maq1 (void){
	extern uint16_t timeoutSerie;
	uint8_t recibido;
	static uint8_t estado=REPOSO;
	static uint8_t bufferposta;
	extern uint8_t tecla;
	if (PopRx0(&recibido))return;

	switch (estado){

		case REPOSO:
			if (recibido=='a') estado=VALIDACION;
			break;

		case VALIDACION:
			if (recibido!='S' && recibido!='A' && recibido!='P' && recibido!='p' && recibido!='Y' && recibido!='N' && recibido>100){
			estado=REPOSO;
			break;
			}else{
				bufferposta=recibido; estado=FINDETRAMA;break;}
			break;

		case FINDETRAMA:
			if (recibido!='j'){
				estado=REPOSO;break;
			}

			if(bufferposta=='S'){
				tecla=3;estado=REPOSO;break;
			}

			if(bufferposta=='A'){
				tecla=2;estado=REPOSO;break;
			}
			if(bufferposta=='p'){
				tecla=1;estado=REPOSO;break;
			}
			if(bufferposta=='P'){
				tecla=1;estado=REPOSO;break;
			}
			if(bufferposta=='N'){
					mandarlista();timeoutSerie=1000;estado=REPOSO;break;
			}
			if(bufferposta=='Y'){
					timeoutSerie=1000;estado=REPOSO;break;
			}

			reproduciractual(bufferposta);
			estado2=REPRODUCIENDO;
			break;
	}
}


