#include "Aplicacion.h"

//void SysTick_Handler ( void );
//extern volatile uint8_t led;
extern volatile uint8_t delayteclado;
extern volatile uint8_t flagIntExt;
extern void disk_timerproc(void);

void SysTick_Handler(void)
{
	if (delayteclado){
		delayteclado--;
	}else{
		DriverTeclado();
	}


	disk_timerproc();

}
