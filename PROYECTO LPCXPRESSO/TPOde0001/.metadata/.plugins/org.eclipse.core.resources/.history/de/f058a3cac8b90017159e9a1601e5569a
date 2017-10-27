/*
 * KitInic.c
 */
#include "Aplicacion.h"

void Inicializar_Teclado( void )
{
	SetPINSEL ( KEY0 , PINSEL_GPIO);
	SetPINSEL ( KEY1 , PINSEL_GPIO);
	SetPINSEL ( KEY2 , PINSEL_GPIO);
	SetPINSEL ( KEY3_RC , PINSEL_GPIO);
	SetPINSEL ( KEY4_RC , PINSEL_GPIO);

	SetDIR ( KEY0 , ENTRADA);
	SetDIR ( KEY1 , ENTRADA);
	SetDIR ( KEY2 , ENTRADA);
	SetDIR ( KEY3_RC , ENTRADA);
	SetDIR ( KEY4_RC , ENTRADA);

	SetPINMODE ( KEY0 , PINMODE_PULLUP);
	SetPINMODE ( KEY1 , PINMODE_PULLUP);
	SetPINMODE ( KEY2 , PINMODE_PULLUP);
}
void Init_Dac (void)
{
	PCLKSEL0 &= ~(0x11<22);
	SetPINSEL(0,26,2);
	SetPINMODE(0,26,3);

	DAC.DACCTRL=0;
	DAC.DACCNTVAL=0;
	DAC.DACR=0;
}
//-----------------------------------------------------------------------------
// Configuración del SysTick para 10ms
//-----------------------------------------------------------------------------
void InicSysTick(void){ //si divido x 4, interrumpe cada 2,5ms
		STRELOAD  = ( STCALIB / 4 ) - 1 ;   //N=1 para 10ms
		STCURR = 0;

		ENABLE = 1;
		TICKINT = 1;
		CLKSOURCE = 1;
		return;
}

//-----------------------------------------------------------------------------
// Configuración de interrupciones externas
//-----------------------------------------------------------------------------
void InicExtInt(void){

		////////////// Configuracion interrupcion externa EINT3, EINT2, EINT1, EINT0  ////////////////////////////
		SetPINSEL(KEY0, PINSEL_FUNC1);			// Configuro el P210 como interrup Ext EINT 0
		SetPINSEL(KEY3_RC, PINSEL_FUNC1);			// Configuro el P213 como interrup Ext EINT 3
//		EXTMODE=(0x0F);							// Todas x Flanco
		EXTMODE |= (1<<EINT0);					// EINT0 x Flanco
		EXTMODE |= (1<<EINT3);					// EINT3 x Flanco

//		EXTPOLAR=(0x00);						// Todas Polaridad activo bajo
		EXTPOLAR &= ~(1<<EINT0);				// EINT0, polaridad activo bajo
		EXTPOLAR &= ~(1<<EINT3);				// EINT3, polaridad activo bajo

		ISER0 |=(0x01 << 18);            		// Habilito Interrupcion externa 0
		ISER0 |=(0x01 << 21);            		// Habilito Interrupcion externa 3

}

/**
 \fn  void InicTimeo0 (void)
 \brief Inicializa timer 0 para trabajar como contador del canal 0 generando interrupciones
 \author CATEDRA INFO2
 \date: - Nov2012
 \param  void
 \return void
*/
void InicTimer0(void)
{
	PCONP		|= ALIMENTA_T0;		//!<  Habilitar Timer 0
	PCLKSEL0 &= ~(0x03<<2);
	PCLKSEL0 	|= PCLK_CCLK_T0;	//!<  Clock for timer PCLK = CCLK Selecciono clock
	T0PR 		= 100;	//!<
	T0CTCR 		&= ~(0x03);			// Timer que cuenta pulsos de PCLK

	T0MR0 		= 62;			//!<  Configuro el tiempo del match 0   CUENTO 62 MICRO SEGUNDOS PARA MUESTREAR EN 16KHZ
	T0MCR 		&= CLR_MTCH_CONFIG;	//!<  Pongo en cero los bits de control de match DE TODOS LOS TIMERS para aplicar máscara a continuación
	T0MCR 		|= MATCH0_INT_RST;	//!<  Configuro match 1 para interrumpir y resetear timer

	T0TCR 		&= CLEAR_RST_EN;	// Limpio bits de control de reset y encendido del timer
	T0TCR 		|= TIMER_OFFyRST;	// Apago y reseteo el temporizador
	T0TCR 		&= TIMER_RST_OFF;	// Limpio bit de control de reset, sino, continúa en estado de reset
	T0TCR 		|= TIMER_ON;
	T0TCR 		&= ~(3);
	T0TCR 		|= TIMER_OFFyRST;	// Apago y reseteo el temporizador
	ApagarTimer0();

	ISER0 		|= (1 << ISE_TIMER0);  		// Habilito Interrupcion TIMER0
}

void PrenderTimer0(void){
	T0TCR 		|= TIMER_OFFyRST;	// Apago y reseteo el temporizador
	T0TCR 		&= ~(3);	// Limpio bit de control de reset, sino, continúa en estado de reset
	T0TCR 		|= TIMER_ON;		// Enciendo timer
}

void ApagarTimer0(void){
	T0TCR &= ~(3);
	T0TCR 		|= TIMER_OFFyRST;	// Apago y reseteo el temporizador
}

/**
	\fn  void InicTimeo1 (void)
	\brief Inicializa timer 1 para trabajar con interrupciones de match 0 a 3
	\details
	\author  CATEDRA INFO2
	\date Nov2012
 	\param 	void
	\return void
*/
void InicTimer1(void){
	PCONP		|= ALIMENTA_T1;		// Habilitar Timer1
	PCLKSEL0 	|= PCLK_CCLK_T1;	// Clock for timer PCLK = CCLK Selecciono clock
	T1PR 		= PREESCALER_T1;	// Configura preescaler para contar ms
	T1MR0 		= MATCH00;			// Configuro el tiempo del match 0
	T1MR1 		= MATCH01;			// Configuro el tiempo del match 1
	T1MR2 		= MATCH02;			// Configuro el tiempo del match 2
	T1MR3 		= MATCH03;			// Configuro el tiempo del match 3
	T1CTCR 		&= TIMER;			// Timer que cuenta pulsos de PCLK
	T1MCR 		&= CLR_MTCH_CONFIG;	// limpio bits para aplicar máscara a continuación
	T1MCR 		|= MATCH0_INT;		// Configuro match 0 para interrumpir
	T1MCR 		|= MATCH1_INT;		// Configuro match 1 para interrumpir
	T1MCR 		|= MATCH2_INT;		// Configuro match 2 para interrumpir
	T1MCR 		|= MATCH3_INT_RST;	// Configuro match 3 para interrumpir y resetear timer

	T1TCR 		&= CLEAR_RST_EN;	// Limpio bits de control de reset y encendido del timer
	T1TCR 		|= TIMER_OFFyRST;	// Apago y reseteo el temporizador
	T1TCR 		&= TIMER_RST_OFF;	// Limpio bit de control de reset, sino, continúa en estado de reset
	T1TCR 		|= TIMER_ON;		// Enciendo timer

	ISER0 		|= (1 << ISE_TIMER1);  		// Habilito Interrupcion TIMER1
}


//-----------------------------------------------------------------------------
// Inicialización general del Kit de acuerdo al uso que se le dará.
//-----------------------------------------------------------------------------
void InicializarKit ( void )
{
	InicPLL();
	ApagarTimer0();
	InicTimer0();
	ApagarTimer0();
	InicSysTick();
	Init_Dac();
	Inicializar_Teclado();
	Inicializar_Relay();
	SetPIN(LED1,OFF);
	SetPIN(LED2,OFF);
	SetPIN(LED3,OFF);
	SetPIN(LED4,OFF);



	
	//inicializo LEDXpresso (P0.22)
	SetPINSEL ( LEDXpresso , PINSEL_GPIO);
	SetDIR ( LEDXpresso , SALIDA);
	SetPIN (LEDXpresso, OFF);
}
