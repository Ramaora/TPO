/*
 * interrupciones.c
 *
 *  Created on: 25/09/2013
 *      Author: andresdemski
 */

#include "MyLPC1769.h"
#include "InfotronicKit.h"
#include "ssp.h"
#include "timer.h"
#include "interruption.h"
#include "port.h"
#include "Touch.h"
#include "TFT.h"
#include "MP3.h"
#include "delay.h"
#include "vs1003.h"
#include "Flags.h"
#include "variables.h"
#include "systick.h"
#include "funciones.h"

extern uint8_t TICK;


/**
 * \fn void SysTick_Handler(void)
 * \brief Interrupcion de Systick
 * \details Contiene la maquina de estado del Touch y el control de la uart
 */
void SysTick_Handler(void)
{
	SysTick_ClrIrq();
	Maquina_Touch ();
	Uart_Control();
}


/**
 * \fn void EINT3_IRQHandler(void)
 * \brief Interrupcion de la EINT3
 * \details Interrumpe si se preciono la pantalla
 */
void EINT3_IRQHandler(void)
{
	if (GPIO_IrqStat(TOUCH_PENIRQ,FALLING))
	{
		GPIO_IrqEnable(TOUCH_PENIRQ,0,FALLING);
		GPIO_IrqClr(TOUCH_PENIRQ);
		TOUCH_GET_FLAG=1;
	}

}

/**
 * \fn void TIMER0_IRQHandler(void)
 * \brief Interrupcion del Timer0
 * \details Contiene la escritura del DAC
 */
void TIMER0_IRQHandler(void)
{
	Timer0_ClrIrq_Match0();
	if (Reproduction())
	{
		//TFT_Print(&(FileList[File_Playing][0]),16,280,SMALL_FONT,BLACK);
	}
}

/**
 * \fn void UART0_IRQHandler(void)
 * \brief Interrupcion del uart
 * \details Interrumpe por recepcion y transmicion, no se encarga de enviar.
 */
void UART0_IRQHandler(void)
{
	uint32_t Inter;
	static uint8_t i=0;
	uint8_t ch=0;
	Inter= ((UART0.IIR & (0b11<<1))>>1);
	switch (Inter)
	{
		case 1:   ///Finalizacion del envio
			if (UART0.RBR);
			UART_BUSY=0;
			break;
		case 2:  // Si llego algo
			ch=UART0.RBR;
			if (ch=='\n')
			{
				UART_RxFIFO[UART_RxPointer][i]=0;
				UART_RxFIFO_ESTADO++;
				i=0;
				UART_RxPointer++;
				UART_RxPointer= UART_RxPointer%16;
			}
			else
			{
				UART_RxFIFO[UART_RxPointer][i]=ch;
				i++;
			}
			break;


	}
	return;
	/*
	if ()//TXfifo vacia
	{

	}*/
}
