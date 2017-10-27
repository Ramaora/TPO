/*
 * InfotronicKit.c
 *
 *  Created on: 02/07/2013
 *      Author: Andres
 */
#include "MyLPC1769.h"
#include "port.h"
#include "InfotronicKit.h"



uint8_t Expantions [18][2] =
{
		{Expantion0},
		{Expantion1},
		{Expantion2},
		{Expantion3},
		{Expantion4},
		{Expantion5},
		{Expantion6},
		{Expantion7},
		{Expantion8},
		{Expantion9},
		{Expantion10},
		{Expantion11},
		{Expantion12},
		{Expantion13},
		{Expantion14},
		{Expantion15},
		{Expantion16},
		{Expantion17}
};

void Init_Infotronik ()
{
	SetPinSel(ED0,0);
	SetPinMode(ED0,PULLUP);
	SetPinDir (ED0,ENTRADA);

	SetPinSel (ED1,0);
	SetPinMode (ED1,PULLUP);
	SetPinDir (ED1,ENTRADA);

	SetPinSel (ED2,0);
	SetPinMode (ED2, PULLUP);
	SetPinDir (ED2,ENTRADA);

	SetPinSel (SD0,0);
	SetPinModeOD(SD0,O_NORMAL);
	SetPinDir (SD0,SALIDA);
	ClrPin (SD0);

	SetPinSel (SD1,0);
	SetPinModeOD(SD1,O_NORMAL);
	SetPinDir (SD1,SALIDA);
	ClrPin(SD1);

	SetPinSel (SD2,0);
	SetPinModeOD(SD2,O_NORMAL);
	SetPinDir (SD2,SALIDA);
	ClrPin(SD2);

	SetPinSel (SD3,0);
	SetPinModeOD(SD3,O_OPENDRAIN);
	SetPinDir (SD3,SALIDA);
	ClrPin(SD3);

	SetPinSel (SD4,0);
	SetPinModeOD(SD4,O_OPENDRAIN);
	SetPinDir (SD4,SALIDA);
	ClrPin(SD4);

	SetPinSel (LCD_D4,0);
	SetPinModeOD(LCD_D4,O_NORMAL);
	SetPinDir (LCD_D4,SALIDA);
	ClrPin(LCD_D4);

	SetPinSel (LCD_D5,0);
	SetPinModeOD(LCD_D5,O_NORMAL);
	SetPinDir (LCD_D5,SALIDA);
	ClrPin(LCD_D5);

	SetPinSel (LCD_D6,0);
	SetPinModeOD(LCD_D6,O_NORMAL);
	SetPinDir (LCD_D6,SALIDA);
	ClrPin(LCD_D6);

	SetPinSel (LCD_D7,0);
	SetPinModeOD(LCD_D7,O_NORMAL);
	SetPinDir (LCD_D7,SALIDA);
	ClrPin(LCD_D7);


	SetPinSel (LCD_E,0);
	SetPinModeOD(LCD_E,O_NORMAL);
	SetPinDir (LCD_E,SALIDA);
	ClrPin(LCD_E);

	SetPinSel (LCD_RST,0);
	SetPinModeOD(LCD_RST,O_NORMAL);
	SetPinDir (LCD_RST,SALIDA);
	ClrPin(LCD_RST);


}

void WriteAllExpantions( uint32_t Data)
{
	uint8_t i=0;
	while (i<18)
	{
		if ((Data>>i) & (1)) SetPin(Expantions[i][0],Expantions[i][1]);
		else ClrPin (Expantions[i][0],Expantions[i][1]);
		i++;

	}
}

uint32_t ReadAllExpantions ()
{
	uint8_t i=0, aux=0;
	uint32_t Data =0;
	while (i<18)
	{
		if ( (aux= GetPin(Expantions[i][0],Expantions[i][1])) ) Data = ((Data )| (aux << i));
		i++;

	}
	return Data;

}

void Init_PLL ( void )
{
	SCS       = SCS_Value;

	if (SCS_Value & (1 << 5))               /* If Main Oscillator is enabled      */
		while ((SCS & (1<<6)) == 0);/* Wait for Oscillator to be ready    */

	CCLKCFG   = CCLKCFG_Value;      /* Setup Clock Divider                */

	PCLKSEL0  = PCLKSEL0_Value;     /* Peripheral Clock Selection         */
	PCLKSEL1  = PCLKSEL1_Value;

	CLKSRCSEL = CLKSRCSEL_Value;    /* Select Clock Source for PLL0       */

	PLL0CFG   = PLL0CFG_Value;      /* configure PLL0                     */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	PLL0CON   = 0x01;             /* PLL0 Enable                        */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	while (!(PLL0STAT & (1<<26)));/* Wait for PLOCK0                    */

	PLL0CON   = 0x03;             /* PLL0 Enable & Connect              */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	while (!(PLL0STAT & ((1<<25) | (1<<24))));/* Wait for PLLC0_STAT & PLLE0_STAT */

	PLL1CFG   = PLL1CFG_Value;
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	PLL1CON   = 0x01;             /* PLL1 Enable                        */
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	while (!(PLL1STAT & (1<<10)));/* Wait for PLOCK1                    */

	PLL1CON   = 0x03;             /* PLL1 Enable & Connect              */
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	while (!(PLL1STAT & ((1<< 9) | (1<< 8))));/* Wait for PLLC1_STAT & PLLE1_STAT */

	PCONP     = PCONP_Value;        /* Power Control for Peripherals      */

	CLKOUTCFG = CLKOUTCFG_Value;    /* Clock Output Configuration         */

	FLASHCFG  = (FLASHCFG & ~0x0000F000) | FLASHCFG_Value;
}
