/*
===============================================================================
 Name        : FW_Systick.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : Handler de Systick y funciones relacionadas
===============================================================================
*/

#include "Aplicacion.h"

extern volatile uint8_t delayteclado;
extern volatile uint8_t flagIntExt;
extern void disk_timerproc(void);
extern volatile int demoraLCD;
extern uint32_t f_tick_rtc;
void armarTramaACK(uint8_t*);

extern volatile uint8_t estado2;
extern uint16_t timeoutSerie;
extern uint8_t ArchivoActual;

#define RGB_VERDE_ON SetPIN(RGBB, 0);SetPIN(RGBG, 1);SetPIN(RGBR, 0);
#define RGB_ROJO_ON SetPIN(RGBB, 0);SetPIN(RGBG, 0);SetPIN(RGBR, 1);

#define TIMEOUT_ACK 400

void SysTick_Handler(void)
{
	static uint16_t flameo=0;
	static uint16_t ack=TIMEOUT_ACK;
	uint8_t aux[10]="";

	if (delayteclado){
		delayteclado--;
	}else{
		DriverTeclado();
	}

	if(!ack){
		ack=TIMEOUT_ACK;
		armarTramaACK(aux);
		EnviarString0(aux);
	}

	if(!timeoutSerie){
		RGB_VERDE_ON

	}else{
		RGB_ROJO_ON
		timeoutSerie--;
	}

	ack--;
	Display(RTC_MIN,1);
	Display(RTC_SEC,0);



	if (estado2!=REPOSO){
		BarridoDisplay();
	}

	flameo++;
	flameo%=100;
	if ((estado2==REPOSO)&&(!flameo)){
		BarridoDisplay();
	}

	disk_timerproc();

	if ( demoraLCD ){
		demoraLCD--;
	}

	if ( f_tick_rtc ){
		f_tick_rtc--;
	}

}

/**
 * \fn void armarTramaACK (uint8_t*)
 * \brief Arma trama de ACK
 * \details deja en aux todo lo necesario para enviarla por puerto serie
 * \param [in] uint8_t*
 * \return void
 * */
void armarTramaACK(uint8_t* aux){

	uint8_t aux2[4];
	aux2[0]=ArchivoActual+1;
	aux2[1]=(uint8_t)RTC_MIN+1;
	aux2[2]=(uint8_t)RTC_SEC;
	aux2[3]='\0';

	strcat(aux,"ack");
	strcat(aux,aux2);
	strcat(aux,"$");
}
