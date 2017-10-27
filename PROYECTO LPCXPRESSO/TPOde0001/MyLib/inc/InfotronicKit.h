/*
 * InfotronicKit.h
 *
 *  Created on: 02/07/2013
 *      Author: Andres
 */

#ifndef INFOTRONICKIT_H_
#define INFOTRONICKIT_H_

/////////////////PLL INIT////////////////////


#define CLOCK_SETUP_Value 	    1
#define SCS_Value				0x00000020
#define CLKSRCSEL_Value         0x00000001
#define PLL0_SETUP_Value        1
#define PLL0CFG_Value           0x00050063
#define PLL1_SETUP_Value        1
#define PLL1CFG_Value           0x00000023
#define CCLKCFG_Value           0x00000003
#define USBCLKCFG_Value         0x00000000
#define PCLKSEL0_Value          0x00000000
#define PCLKSEL1_Value          0x00000000
#define PCONP_Value             0x042887DE
#define CLKOUTCFG_Value         0x00000000
#define FLASHCFG_Value			0x00004000


////////////////Teclado5x1/////////////////////////

#define		Teclado5x1_0		2,10
#define		Teclado5x1_1		0,18
#define		Teclado5x1_2		0,11
#define		Teclado5x1_3		2,13
#define		Teclado5x1_4		1,26    /// Compartido con ED0

////////////////Salida Digital ///////////////////

#define 		SD0				2,0
#define			SD1				0,23
#define			SD2				0,21
#define			SD3				0,27
#define			SD4				0,28

////////////Entradas Digitales///////////////////

#define			ED0				1,26
#define			ED1				4,29
#define			ED2				2,11

///////////////////LCD 16x2 /////////////////////////

#define			LCD_RST 		2,6
#define 		LCD_E			0,4
#define			LCD_D4			0,5
#define			LCD_D5			0,10
#define			LCD_D6			2,4
#define			LCD_D7			2,5

///////////////UART0///////////////////////

#define			U0TX			0,2
#define			U0RX			0,3

////////////////SPI//////////////////////////

#define			MISO			0,8
#define			MOSI			0,9
#define			SCK				0,7
#define			SSEL			0,6

////////////////PWM//////////////////////////

#define		PWM_RGB_R			2,2
#define		PWM_RGB_B			2,1
#define 	PWM_RGB_G			2,3

////////////////EXPANTIONS////////////////////////
#define 	Expantion0 			2,7
#define 	Expantion1 			1,29
#define 	Expantion2			4,28
#define 	Expantion3 			1,23
#define 	Expantion4 			1,20
#define 	Expantion5 			0,19
#define 	Expantion6 			3,26
#define 	Expantion7 			1,25
#define 	Expantion8 			1,22
#define 	Expantion9 			1,19
#define 	Expantion10	 		0,20
#define 	Expantion11			3,25
#define 	Expantion12			1,27
#define 	Expantion13			1,24
#define 	Expantion14			1,21
#define 	Expantion15			1,18
#define 	Expantion16			2,8
#define 	Expantion17			2,12
#define		Expantion18			0,16

#define 	LPCXPRESSOLED		0,22

uint32_t ReadAllExpantions ();
void WriteAllExpantions( uint32_t Data);
void Init_Infotronik ();
void Init_PLL ( void );

#endif /* INFOTRONICKIT_H_ */


