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

#include "Aplicacion.h"
#include "globales.h"

int main(void) {
	ApagarTimer0();
	InicializarKit();
	ApagarTimer0();
	FRESULT res;

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString("Reproductor WAV");

	char line[100]; /* Line buffer */
	int w=0;
	while ((res = f_mount(&FatFs, "", 1))!=FR_OK);
	f_opendir(&Dir,"");
	for (w=0;w<20;w++) {
		FileList[w][0] = (uint8_t)0;
	}

	reiniciarRTC();

	FileList_Fill();

	if (f_open(&File, FileList[ArchivoActual] , FA_READ)!=FR_OK){
		SetPIN(LED2,OFF);
		SetPIN(LED3,ON);
		SetPIN(LED4,ON);
		//printf ("error al abrir archivo;");
	}

	cargarBuffer();

	while (1){


		if (flagtermino){flagtermino=0;SiguienteTema();}

		tecla=getkey();

		maq1();
		maqreproduccion();


}
	return 0;
}

