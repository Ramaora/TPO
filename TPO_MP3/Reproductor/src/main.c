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

#include "../../Reproductor/inc/Aplicacion.h"
#include "../../Reproductor/inc/globales.h"

#define LED2OFF SetPIN(LED2,OFF)
#define LED3ON SetPIN(LED3,ON)
#define LED4ON SetPIN(LED4,ON)

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
		LED2OFF;
		LED3ON;
		LED4ON;
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

