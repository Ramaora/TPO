#include "Aplicacion.h"

//void SysTick_Handler ( void );
//extern volatile uint8_t led;
extern volatile uint8_t delayteclado;
extern volatile uint8_t flagIntExt;
extern void disk_timerproc(void);
extern volatile int demoraLCD;
extern uint32_t f_tick_rtc;

extern volatile uint8_t estado2;
extern uint16_t timeoutSerie;
extern uint8_t ArchivoActual;

void SysTick_Handler(void)
{
	static uint16_t prueba=0;
	static uint16_t ack=2000;
	uint8_t minutos = (uint8_t)RTC_MIN;
	uint8_t segundos = (uint8_t)RTC_SEC;
	uint8_t aux[10]="";
	uint8_t aux2[4];
	if (delayteclado){
		delayteclado--;
	}else{
		DriverTeclado();
	}
	if(!ack){
		ack=400;
		aux2[0]=ArchivoActual+1;
		aux2[1]=minutos+1;
		aux2[2]=segundos;
		aux2[3]='\0';
		strcat(aux,"ack");

		strcat(aux,aux2);

		strcat(aux,"$");

		EnviarString0(aux);
	}
	if(!timeoutSerie){
		SetPIN(RGBB, 0);
		SetPIN(RGBG, 1);
		SetPIN(RGBR, 0);

	}else{
		SetPIN(RGBB, 0);
		SetPIN(RGBG, 0);
		SetPIN(RGBR, 1);
		timeoutSerie--;
	}

	ack--;
	//Display(RTC_SEC,0);
	//Display(RTC_MIN,1);

	Display(RTC_MIN,1);
	Display(RTC_SEC,0);



	if (estado2!=REPOSO){
	BarridoDisplay();
	}
	prueba++;

	if (prueba==100)prueba=0;
	if ((estado2==REPOSO)&&(!prueba)){
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
