/**
 * ===============================================================================
 *  Name        : main.c
 *  Author      : $(author)
 *  Version     :
 *  Copyright   : $(copyright)
 *  Description : main definition
 * ===============================================================================
 *
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
//__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;


#include "Aplicacion.h"
#include "lcd.h"


volatile uint8_t BufferEntradas;				//Buffer de Entradas Digitales

volatile unsigned int inxInLCD;
volatile unsigned int inxOutLCD;
volatile unsigned int cantidadColaLCD;
volatile int demoraLCD;
uint8_t bufferLCD[100];
volatile uint8_t ptrLecturaLCD = 0;
volatile uint8_t ptrEscrituraLCD = 0;

uint32_t f_tick_rtc  = 6000;

int main(void)
{
	unsigned char i;



	InicializarKit ();


	// Prueba del display

	for(i = 0; i < 80; i++){
		WDato(0x41);
	}

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString("   Hola mundo...");
	//WComando8(LCD_HOME2);
	//WString("    Info II");
	//WComando8(LCD_CLEAR);
	//Display_lcd("Hola denuevo...",0,1);
	//Display_lcd("Info II",1,1);
	//DisplayInt_lcd(2017 ,1 ,9);

	//WComando8(LCD_OFF);
	//WComando8(LCD_ON);
	//WComando8(LCD_INC);
	//WComando8(LCD_DEC);

	//WComando8(CURSOR_ON);
	//WComando8(BLINK_ON);
	//WComando8(LCD_CURSORINC);
	//WComando8(LCD_CURSORDEC);
	//WComando8(LCD_HOME2);
	//WComando8(LCD_HOME1);
	//WComando8(LCD_CURSOROFF);

	//WComando8(LCD_CLEAR);

	while(1) {

	}
	return 0 ;
}
