/**
 \file		: FW_isr.c
 \brief     : Isr de interrupciones externas
 \details   :
 \author    : GOS
 \date 	    : 2014.05.06
*/

#include "../../../Reproductor/inc/Aplicacion.h"

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
extern uint8_t MAX_FILE;
extern uint8_t FileList[20][13];
extern uint8_t estado2;
extern uint8_t flagtermino;
extern FILINFO Finfo;
extern DIR Dir;

void TIMER0_IRQHandler (void)
{

	static uint32_t i=0;
	static uint8_t actual=0;
	uint8_t aux=0;
	static uint32_t cont=0;

	if(T0IR & MR0){

		T0IR |= MR0;
		if (cant<1024){
			ApagarTimer0();
			flagtermino=1;
			return;
		}else{
			Write_Dac(bufferswav[actual][i]);
			i++;
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

/**
 * \fn void reiniciarRTC (void)
 * \brief Pone los valores del RTC en 0
 * \details
 * \param [in] void
 * \return void
 * */
void reiniciarRTC(){
	RTC_CCR &= ~(1);
	RTC_MIN=0;
	RTC_SEC=0;
}
/**
 * \fn void prenderRTC (void)
 * \brief Pone en funcionamiento el RTC
 * \details
 * \param [in] void
 * \return void
 * */
void prenderRTC(){
	RTC_CCR |= (1);
}
/**
 * \fn void apagarRTC (void)
 * \brief apaga el RTC
 * \details
 * \param [in] void
 * \return void
 * */
void apagarRTC(){
	RTC_CCR &= ~(1);
}
