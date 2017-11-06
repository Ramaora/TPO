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
extern uint8_t estado;

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
			SiguienteTema();

		}else{
		Write_Dac(bufferswav[actual][i]);
		i++;
		//printf ("%d\n",bufferswav[aux][i]);
		i%=cant;

		if (!i){
			cont++;
			//printf ("\nllegue hasta %d bytes\n\n",cont*1024);
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

}

void ArrancarReproduccion(void){
						tecla=NO_KEY;
						PrenderTimer0();
						estado=REPRODUCIENDO;
						RTC_CCR |= (1);

}
void PausarReproduccion(void){

	tecla=NO_KEY;
	estado=REPOSO;
	ApagarTimer0();
	RTC_CCR &= ~(1);
	Write_Dac(70);
}
