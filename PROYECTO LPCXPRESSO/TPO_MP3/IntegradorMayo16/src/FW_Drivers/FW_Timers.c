/**
 \file		: FW_isr.c
 \brief     : Isr de interrupciones externas
 \details   :
 \author    : GOS
 \date 	    : 2014.05.06
*/

#include "Aplicacion.h"

/**
 * \fn void TIMER0_IRQHandler (void)
 * \brief ISR de timer0
 * \details Limpia flag y guarda captura Ch0 para ser usada en otra parte del programa
 * \author GOS
 * \date   2014.05.06
 * \param [in] void
 * \return void
 * */
extern uint8_t bufferswav[2][1024];
extern uint32_t cant;
extern FIL File;
extern uint8_t ArchivoActual;
extern uint8_t tecla;
extern uint8_t MAX_FILE;
extern uint8_t FileList[20][13];
extern uint8_t estado2;
extern uint8_t flagtermino;
extern FILINFO Finfo;
extern DIR Dir;

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
void TIMER0_IRQHandler (void)
{

	static uint32_t i=0;
	static uint8_t actual=0;
	uint8_t aux=0;
	static uint32_t cont=0;
	//printf ("\ncant vale %d\n\n",cant);

	if(T0IR & MR0)
	{
		// Si interrumpio match 0
		T0IR |= MR0;
		if (cant<1024){
			ApagarTimer0();
			flagtermino=1;
			return;

		}else{
		Write_Dac(bufferswav[actual][i]);
		i++;
		//printf ("%d\n",bufferswav[aux][i]);
		i%=cant;
		if (!i){
			cont++;
			aux=actual;
			actual++;
			actual%=2;
			ApagarTimer0();
			f_read (&File,bufferswav[aux],1024,(UINT*)&cant);
			PrenderTimer0();

		}
		}

	}
}

void AnteriorTema (void){
	tecla=NO_KEY;
	ApagarTimer0();
	ArchivoActual++;
	ArchivoActual%=MAX_FILE-1;
	f_open(&File, FileList[ArchivoActual] , FA_READ);
	f_read (&File,bufferswav[0],43,(UINT*)&cant);
	f_read (&File,bufferswav[0],1024,(UINT*)&cant);
	f_read (&File,bufferswav[1],1024,(UINT*)&cant);
	PrenderTimer0();

	RTC_CCR &= ~(1);
	RTC_MIN=0;
	RTC_SEC=0;
	RTC_CCR |= (1);
	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("ANTERIOR$");

}

void SiguienteTema(void)
{
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
f_read (&File,bufferswav[0],43,(UINT*)&cant);
f_read (&File,bufferswav[0],1024,(UINT*)&cant);
f_read (&File,bufferswav[1],1024,(UINT*)&cant);
PrenderTimer0();
RTC_CCR &= ~(1);
RTC_MIN=0;
RTC_SEC=0;
RTC_CCR |= (1);
WComando8(LCD_CLEAR);
WComando8(LCD_HOME1);
WString(FileList[ArchivoActual]);
EnviarString0("SIGUIENTE$");
PrenderTimer0();
}

void reproduciractual(uint8_t recibido){

	tecla=NO_KEY;
	ArchivoActual=(recibido-'0'+1);
	f_open(&File, FileList[ArchivoActual] , FA_READ);
	f_read (&File,bufferswav[0],43,(UINT*)&cant);
	f_read (&File,bufferswav[0],1024,(UINT*)&cant);
	f_read (&File,bufferswav[1],1024,(UINT*)&cant);
	RTC_CCR &= ~(1);
	RTC_MIN=0;
	RTC_SEC=0;
	RTC_CCR |= (1);
	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("ARRANCAR$");
	PrenderTimer0();

}
void ArrancarReproduccion(void){
						tecla=NO_KEY;
						PrenderTimer0();
						estado2=REPRODUCIENDO;
						RTC_CCR |= (1);
						WComando8(LCD_CLEAR);
						WComando8(LCD_HOME1);
						WString(FileList[ArchivoActual]);
						EnviarString0("ARRANCAR$");

}
void PausarReproduccion(void){

	tecla=NO_KEY;
	estado2=REPOSO;
	ApagarTimer0();
	RTC_CCR &= ~(1);
	Write_Dac(70);
	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString(FileList[ArchivoActual]);
	EnviarString0("PAUSAR$");
}

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
