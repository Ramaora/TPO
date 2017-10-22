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
			SetPIN(LED1,ON);
			SetPIN(LED2,ON);
			SetPIN(LED3,ON);
			SetPIN(LED4,ON);

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


/**
 * \fn void TIMER0_IRQHandler (void)
 * \brief ISR de timer1
 * \details Limpia flags de match 0 a match 4 segun corresponda y marca evento
 * \author GOS
 * \date   2014.05.06
 * \param [in] void
 * \return void
 * */

