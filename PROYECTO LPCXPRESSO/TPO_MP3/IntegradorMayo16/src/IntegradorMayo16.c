/*
===============================================================================
 Name        : IntegradorMayo16.c
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



void mandarlista(void){
	int i=0;
	uint8_t bufferamandar [400];
	for (i=0;i<400;i++)bufferamandar[i]='\0';

	for (i=0;i<MAX_FILE-1;i++){
		strcat(bufferamandar,FileList[i]);
		if ((i+1)!=(MAX_FILE-1)){
			strcat(bufferamandar,",");
		}

	}
	strcat(bufferamandar,"$");
	EnviarString0(bufferamandar);

}






int main(void) {
	ApagarTimer0();
	InicializarKit();
	ApagarTimer0();
	FRESULT res;
	uint8_t header [44];


	// Prueba del display

	unsigned char i;
	for(i = 0; i < 80; i++){
		WDato(0x41);
	}

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
	RTC_CCR &= ~(1);
	RTC_MIN=0;
	RTC_SEC=0;


	FileList_Fill();

	if (f_open(&File, FileList[ArchivoActual] , FA_READ)!=FR_OK){
		SetPIN(LED2,OFF);
		SetPIN(LED3,ON);
		SetPIN(LED4,ON);
		//printf ("error al abrir archivo;");
	}

	f_read (&File,header,43,(UINT*)&cant);
	f_read (&File,bufferswav[0],1024,(UINT*)&cant);
	f_read (&File,bufferswav[1],1024,(UINT*)&cant);
	SetPIN (LEDXpresso, ON);

	while (1){


		if (flagtermino){flagtermino=0;SiguienteTema();}

		tecla=getkey();

		maq1();
		maqreproduccion();


}
	return 0;
}

