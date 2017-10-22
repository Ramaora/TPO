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

volatile uint8_t bufferswav[2][1024];
volatile uint32_t cant=0;
volatile UINT Timer;
volatile uint8_t ArchivoActual=0;
volatile uint8_t delayteclado=0;

int main(void) {
	InicializarKit();
	ApagarTimer0();
	FRESULT res;
	uint8_t header [44];
	static volatile uint8_t estado=REPOSO;
	uint8_t tecla=NO_KEY;


	char line[100]; /* Line buffer */
	int j=0;
	int w=0;
	res = f_mount(&FatFs, "", 1);
	f_opendir(&Dir,"");
	for (w=0;w<20;w++) {
	FileList[w][0] = (uint8_t)0;
	}
	FileList_Fill();

	if (f_open(&File, FileList[ArchivoActual] , FA_READ)!=FR_OK){
		SetPIN(LED2,OFF);
		SetPIN(LED3,ON);
		SetPIN(LED4,ON);
		printf ("error al abrir archivo;");
	}

	f_read (&File,header,43,(UINT*)&cant);
	f_read (&File,bufferswav[0],1024,(UINT*)&cant);
	f_read (&File,bufferswav[1],1024,(UINT*)&cant);
	//printf ("abri el archivo");
	Write_Dac(15);
	Write_Dac(200);
	Write_Dac(70);


	SetPIN (LEDXpresso, ON);
//	printf ("hola");




	while (1){
		tecla=getkey();

		switch (estado){
		case (REPOSO):
				{

				if (tecla==1){
							tecla=NO_KEY;
							PrenderTimer0();
							estado=REPRODUCIENDO;
							break;
								}
				}
		case (REPRODUCIENDO):{
			if (tecla==1){
				tecla=NO_KEY;
				estado=REPOSO;
				ApagarTimer0();
				break;
			}
			if (tecla==2){
				tecla=NO_KEY;
				ApagarTimer0();
				ArchivoActual++;
				ArchivoActual%=MAX_FILE-1;
				f_open(&File, FileList[ArchivoActual] , FA_READ);
				f_read (&File,header,43,(UINT*)&cant);
				f_read (&File,bufferswav[0],1024,(UINT*)&cant);
				f_read (&File,bufferswav[1],1024,(UINT*)&cant);
				PrenderTimer0();
				break;
			}
				if (tecla==3){
							tecla=NO_KEY;
							ApagarTimer0();
							ArchivoActual--;
							//printf ("ArchivoActual vale%d\n",ArchivoActual);
							if (ArchivoActual>MAX_FILE-1)
									{
										ArchivoActual=(MAX_FILE-2);
									}
							//printf ("ArchivoActual vale%d\n",ArchivoActual);
							f_open(&File, FileList[ArchivoActual] , FA_READ);
							f_read (&File,header,43,(UINT*)&cant);
							f_read (&File,bufferswav[0],1024,(UINT*)&cant);
							f_read (&File,bufferswav[1],1024,(UINT*)&cant);
							PrenderTimer0();
							break;

			}

			}
		}


		j++;

}
	return;
}

