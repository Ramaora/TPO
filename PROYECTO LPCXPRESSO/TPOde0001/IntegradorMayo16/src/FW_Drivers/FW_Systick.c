#include "Aplicacion.h"

//void SysTick_Handler ( void );
//extern volatile uint8_t led;
extern volatile uint8_t delayteclado;
extern volatile uint8_t flagIntExt;
extern void disk_timerproc(void);

extern volatile uint8_t estado;

void SysTick_Handler(void)
{
	static uint16_t prueba=0;
	if (delayteclado){
		delayteclado--;
	}else{
		DriverTeclado();
	}
	Display(RTC_SEC,0);
	Display(RTC_MIN,1);

	if (estado!=REPOSO){
	BarridoDisplay();
	}
	prueba++;

	if (prueba==100)prueba=0;
	if ((estado==REPOSO)&&(!prueba)){
		BarridoDisplay();
	}

	disk_timerproc();

}
