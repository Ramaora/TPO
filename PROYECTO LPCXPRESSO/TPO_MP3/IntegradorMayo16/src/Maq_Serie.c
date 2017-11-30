/*
 * Maq_Serie.c

 *
 *  Created on: 6 de nov. de 2017
 *      Author: Matias
 */


#include "Aplicacion.h"
extern uint8_t FileList[20][13];
extern uint8_t estado2;
extern uint8_t MAX_FILE;

#define TIMEOUT_SERIE 1000
#define TAMLISTACANCIONES 400

#define INICIO_TRAMA 'a'
#define FINAL_TRAMA 'j'
/**
 * \fn void maq1 (void)
 * \brief Maquina de estado com. Serie
 * \details
 * \param [in] void
 * \return void
 * */
void maq1 (void){
	extern uint16_t timeoutSerie;
	uint8_t recibido;
	static uint8_t estado=REPOSO;
	static uint8_t contenidoTrama;
	extern uint8_t tecla;
	if (PopRx0(&recibido))return;

	switch (estado){

		case REPOSO:
			if (recibido==INICIO_TRAMA) estado=VALIDACION;
			break;

		case VALIDACION:
			if (recibido!='S' && recibido!='A' && recibido!='P' && recibido!='p' && recibido!='Y' && recibido!='N' && recibido>100){
			estado=REPOSO;
			break;
			}else{
				contenidoTrama=recibido; estado=FINDETRAMA;break;}
			break;

		case FINDETRAMA:
			if (recibido!=FINAL_TRAMA){
				estado=REPOSO;break;
			}

			if(contenidoTrama=='S'){
				tecla=3;estado=REPOSO;break;
			}

			if(contenidoTrama=='A'){
				tecla=2;estado=REPOSO;break;
			}
			if(contenidoTrama=='p'){
				tecla=1;estado=REPOSO;break;
			}
			if(contenidoTrama=='P'){
				tecla=1;estado=REPOSO;break;
			}
			if(contenidoTrama=='N'){
					mandarlista();timeoutSerie=TIMEOUT_SERIE;estado=REPOSO;break;
			}
			if(contenidoTrama=='Y'){
					timeoutSerie=TIMEOUT_SERIE;estado=REPOSO;break;
			}

			reproducirActual(contenidoTrama);
			estado2=REPRODUCIENDO;
			break;
	}
}
/**
 * \fn void mandarLista (void)
 * \brief Envia la lista de canciones por puerto Serie
 * \details
 * \param [in] void
 * \return void
 * */
void mandarlista(void){
	int i=0;
	uint8_t bufferAMandar [TAMLISTACANCIONES];
	for (i=0;i<TAMLISTACANCIONES;i++)bufferAMandar[i]='\0';	//Limpia buffer de canciones

	for (i=0;i<MAX_FILE-1;i++){
		strcat(bufferAMandar,FileList[i]);		//Llena buffer de canciones con nombres, separados por coma
		if ((i+1)!=(MAX_FILE-1)){
			strcat(bufferAMandar,",");			//CSV
		}
	}
	strcat(bufferAMandar,"$");					//Agrega $ al final de la trama
	EnviarString0(bufferAMandar);				//Envia el buffer
}
