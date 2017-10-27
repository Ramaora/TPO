/*
 * 7segBCD.c
 *
 *  Created on: 18/07/2013
 *      Author: tigermax
 */

#include "MyLPC1769.h"
#include "Exp3.h"
#include "port.h"
#include "InfotronicKit.h"

__RW uint8_t Dig_n=7;
__RW uint8_t Disp7BCD_char_n=0;
__RW uint8_t Disp7BCD_txt[13]= {0,0,0,0,0,0,0,0,0,0,0,0,0};

void Init_Exp3 ()
{
	SetPinSel(Expantion0,0);
	SetPinDir(Expantion0,SALIDA);
	SetPinModeOD(Expantion0,O_NORMAL);
	ClrPin (Expantion0);

	SetPinSel(Expantion1,0);
	SetPinDir(Expantion1,SALIDA);
	SetPinModeOD(Expantion1,O_NORMAL);
	ClrPin (Expantion1);

	SetPinSel(Expantion2,0);
	SetPinDir(Expantion2,SALIDA);
	SetPinModeOD(Expantion2,O_NORMAL);
	ClrPin (Expantion2);

	SetPinSel(Expantion3,0);
	SetPinDir(Expantion3,SALIDA);
	SetPinModeOD(Expantion3,O_NORMAL);
	ClrPin (Expantion3);

	SetPinSel(Expantion4,0);
	SetPinDir(Expantion4,SALIDA);
	SetPinModeOD(Expantion4,O_NORMAL);
	ClrPin (Expantion4);

	SetPinSel(Expantion5,0);
	SetPinDir(Expantion5,SALIDA);
	SetPinModeOD(Expantion5,O_NORMAL);
	ClrPin (Expantion5);

	SetPinSel(Expantion6,0);
	SetPinDir(Expantion6,SALIDA);
	SetPinModeOD(Expantion6,O_NORMAL);
	ClrPin (Expantion6);

	Dig_n=7;
	//SetPin(Expantion5);  //Incremento el 4017 (Clk)
	//ClrPin(Expantion5);
}

void DISP7BCD_inc ()
{
	Dig_n++;  //incremento mis dos indexadores
	Disp7BCD_char_n++;
	if (Dig_n>=6 || !( Disp7BCD_txt[Disp7BCD_char_n ]) )  //Me pase de digito o termino el string?
	{
		Dig_n=0;  //Vuelvo a empezar
		Disp7BCD_char_n=0;
		SetPin (Expantion6);  //Reset
		//wait
		ClrPin(Expantion6);
	}
	else
	{
		SetPin(Expantion5);  //Incremento el 4017 (Clk)
		//wait
		ClrPin(Expantion5);
	}

	if (Disp7BCD_txt[Disp7BCD_char_n] == '.') Disp7BCD_char_n++;

}

void DISP7BCD_dig (uint8_t Data)
{
	if (Data<'0' || Data>'9') Data=10;   //Lo pongo en 10 para que hag aun blank (el 4511 muestra hasta 9)
	else Data=Data-'0'; //Transformo en BCD
	WriteAllExpantions( (ReadAllExpantions() & (~0xF) ) | (Data & 0xF));  //Muestro
}

void DISP7BCD_text (uint8_t *string)
{
	uint8_t i=0;
	while (string[i]) Disp7BCD_txt[i]=string[i];
}

void DISP7BCD_Handdler ()
{
	DISP7BCD_dig(0);  //Lo pongo en blanco para que no muestre cualquier cosa en el cambio
	ClrPin (Expantion4); //Saco el punto
	DISP7BCD_inc(); //Incremento el digito
	DISP7BCD_dig(Disp7BCD_txt[Disp7BCD_char_n]); //Muestro el numero
	if (Disp7BCD_txt[Disp7BCD_char_n +1] == '.') SetPin(Expantion4); //Pongo el punto
}

