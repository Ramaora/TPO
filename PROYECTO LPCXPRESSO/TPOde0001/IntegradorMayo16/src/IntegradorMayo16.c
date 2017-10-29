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

volatile uint8_t msgDisplay[6];
extern void disk_timerproc (void);


DWORD AccSize;				/* Work register for fs command */
WORD AccFiles, AccDirs;
FILINFO Finfo;

char Line[256];				/* Console input buffer */

volatile FATFS FatFs;				/* File system object for each logical drive */
volatile FIL File;				/* File objects */
volatile DIR Dir;
/* Directory object */
volatile uint8_t FileList[20][13];
volatile uint8_t MAX_FILE=0;
volatile uint8_t buffKey=NO_KEY;


void FileList_Fill (void)
{
	uint32_t i=0;
	do
	{

		f_readdir(&Dir, &Finfo);
		strcpy ((char*)&(FileList[i][0]),(const char*)Finfo.fname);
		//printf ("%s\n",FileList[i]);
		i++;
	}while (Finfo.fname[0] && i<20);
	MAX_FILE=i;
}
volatile uint8_t estado=REPOSO;
volatile uint8_t bufferswav[2][1024];
volatile uint32_t cant=0;
volatile UINT Timer;
volatile uint8_t ArchivoActual=0;
volatile uint8_t delayteclado=0;
volatile uint8_t tecla=NO_KEY;

//lcd
volatile unsigned int inxInLCD;
volatile unsigned int inxOutLCD;
volatile unsigned int cantidadColaLCD;
volatile int demoraLCD;
uint8_t bufferLCD[100];
volatile uint8_t ptrLecturaLCD = 0;
volatile uint8_t ptrEscrituraLCD = 0;

uint32_t f_tick_rtc  = 6000;

int main(void) {
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
	WString("   Hola mundo...");

	char line[100]; /* Line buffer */
	int j=0;
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
		tecla=getkey();

		switch (estado){

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


				j++;

}
	return 0;
}

