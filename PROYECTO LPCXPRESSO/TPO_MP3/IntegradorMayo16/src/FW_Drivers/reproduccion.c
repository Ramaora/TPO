/*
 * reproduccion.c
 *
 *  Created on: 30 de nov. de 2017
 *      Author: Rama
 */

#include "Aplicacion.h"

extern volatile uint32_t cant;
extern volatile uint8_t bufferswav[2][1024];

extern FIL File;
extern uint8_t ArchivoActual;
extern uint8_t tecla;
extern uint8_t MAX_FILE;
extern uint8_t FileList[20][13];
extern uint8_t estado2;
extern uint8_t flagtermino;
extern FILINFO Finfo;
extern DIR Dir;

/**
 * \fn void cargarBuffer (void)
 * \brief Carga los buffer de datos de reproduccion
 * \details
 * \param [in] void
 * \return void
 * */
void cargarBuffer(){

	uint8_t header [44];
	f_read (&File,header,43,(UINT*)&cant);
	f_read (&File,bufferswav[0],1024,(UINT*)&cant);
	f_read (&File,bufferswav[1],1024,(UINT*)&cant);
	SetPIN (LEDXpresso, ON);
}

/**
 * \fn void FileList_Fill (void)
 * \brief Llena un array FileList con los nombres de las canciones
 * \details
 * \param [in] void
 * \return void
 * */
void FileList_Fill (void)
{
	uint32_t i=0;
	do{
		f_readdir(&Dir, &Finfo);
		strcpy ((char*)&(FileList[i][0]),(const char*)Finfo.fname);
		i++;
	}while (Finfo.fname[0] && i<20);
	MAX_FILE=i;
}

/**
 * \fn void AnteriorTema (void)
 * \brief Cambia a la cancion anterior
 * \details
 * \param [in] void
 * \return void
 * */
void AnteriorTema (void){
	tecla=NO_KEY;
	ApagarTimer0();
	ArchivoActual++;
	ArchivoActual%=MAX_FILE-1;
	f_open(&File, FileList[ArchivoActual] , FA_READ);
	cargarBuffer();
	PrenderTimer0();

	reiniciarRTC();
	prenderRTC();

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("ANTERIOR$");

}

/**
 * \fn void SiguienteTema (void)
 * \brief Cambia a la cancion siguiente
 * \details
 * \param [in] void
 * \return void
 * */
void SiguienteTema(void){
	tecla=NO_KEY;
	ApagarTimer0();
	ArchivoActual--;

	if (ArchivoActual>MAX_FILE-1){
			ArchivoActual=(MAX_FILE-2);
	}
	f_open(&File, FileList[ArchivoActual] , FA_READ);
	cargarBuffer();
	PrenderTimer0();

	reiniciarRTC();
	prenderRTC();

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("SIGUIENTE$");
	PrenderTimer0();
}

/**
 * \fn void reproducirActual (uint8_t)
 * \brief Reproduce una cancion cual index se envia por parametro
 * \details
 * \param [in] uint8_t
 * \return void
 * */
void reproducirActual(uint8_t recibido){

	tecla=NO_KEY;
	ArchivoActual=(recibido-'0'+1);
	f_open(&File, FileList[ArchivoActual] , FA_READ);
	cargarBuffer();

	reiniciarRTC();
	prenderRTC();

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("ARRANCAR$");
	PrenderTimer0();

}

/**
 * \fn void ArrancarReproduccion (void)
 * \brief Play
 * \details
 * \param [in] void
 * \return void
 * */
void ArrancarReproduccion(void){

	tecla=NO_KEY;
	PrenderTimer0();
	estado2=REPRODUCIENDO;

	prenderRTC();

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("ARRANCAR$");

}

/**
 * \fn void PausarReproduccion(void)
 * \brief Pausa
 * \details
 * \param [in] void
 * \return void
 * */
void PausarReproduccion(void){

	tecla=NO_KEY;
	estado2=REPOSO;
	ApagarTimer0();
	apagarRTC();
	Write_Dac(70);
	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("PAUSAR$");
}

/**
 * \fn void maqreproduccion (void)
 * \brief Maquina de estado que maneja la reproduccion
 * \details
 * \param [in] void
 * \return void
 * */
void maqreproduccion(void){
	switch (estado2){

		case (REPOSO):

			if (tecla==1){
				ArrancarReproduccion();
			}
			break;

		case (REPRODUCIENDO):

			if (tecla==1){
			PausarReproduccion();
			break;
			}
			if (tecla==2){
				AnteriorTema();
				break;
			}
			if (tecla==3){
				SiguienteTema();
				break;
			}
			break;
	}
}
