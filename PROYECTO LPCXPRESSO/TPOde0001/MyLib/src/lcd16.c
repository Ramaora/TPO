/*
 * lcd16.c
 *
 *  Created on: 15/08/2013
 *      Author: Andres
 */

#include "mylib.h"



void LCD16_Com4 (uint8_t com)
{
	ClrPin (LCD_D4);
	ClrPin (LCD_D5);
	ClrPin (LCD_D6);
	ClrPin (LCD_D7);

	ClrPin(LCD_RST);


	if (com & 1 ) SetPin (LCD_D4);
	if (com & 2 ) SetPin (LCD_D5);
	if (com & 4 ) SetPin (LCD_D6);
	if (com & 8 ) SetPin (LCD_D7);

	SetPin (LCD_E);
	ClrPin (LCD_E);
}

void LCD16_Com (uint8_t com)
{
	uint32_t i=0;
	LCD16_Com4 (com >>4);
	LCD16_Com4 (com & 0xF);
	for (i=0;i<1000;i++);
}

void LCD16_Dat4 (uint8_t Dat)
{
	ClrPin (LCD_D4);
	ClrPin (LCD_D5);
	ClrPin (LCD_D6);
	ClrPin (LCD_D7);

	SetPin(LCD_RST);

	if (Dat & 1 ) SetPin (LCD_D4);
	if (Dat & 2 ) SetPin (LCD_D5);
	if (Dat & 4 ) SetPin (LCD_D6);
	if (Dat & 8 ) SetPin (LCD_D7);

	SetPin (LCD_E);
	ClrPin (LCD_E);
}

void LCD16_Dat (uint8_t Dat)
{
	LCD16_Dat4 (Dat >>4);
	LCD16_Dat4 (Dat & 0xF);
}

void Init_LCD16 (void)
{
	msDelay (30);
	LCD16_Com4 (0b0010);
	LCD16_Com4 (0b0010);
	LCD16_Com4 (0b1100);
	msDelay (1);
	LCD16_Com4 (0b0000);
	LCD16_Com4 (0b1111); //b2: on/off b1: Cursor b0:Blink
	msDelay (1);
	LCD16_Com4 (0b0000);
	LCD16_Com4 (0b0001);
	msDelay (2);
	LCD16_Com4 (0b0000);
	LCD16_Com4 (0b0011);
	msDelay (1);
	LCD16_Com(0x28);
	msDelay (1);
}

void LCD16_Mostrar (uint8_t *string, uint8_t Linea, uint8_t Posicion)
{
	LCD16_Com(0x80+ Linea*40 + Posicion);
	while (*string) { LCD16_Dat(*string); string++;}
}




