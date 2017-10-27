/*
 * matrix.c
 *
 *  Created on: 30/06/2013
 *      Author: demski
 */

#include "MyLPC1769.h"
#include "port.h"
#include "InfotronicKit.h"
#include "Exp4.h"


//uint8_t SP[] = { 0x0,0x0,0x0,0x0,0x0 };
__R uint8_t simbolos[] = {
			0x0,0x0,0x0,0x0,0x0,
			0x0,0x0,0x7D,0x0,0x0, // !
		    0X0,0x60,0x0,0x60,0x0, // "
		    0x22,0x7F,0x22,0x7F,0x22, // #
		    0x3A,0x2A,0x7F,0x2A,0x2E, // $
		    0x11,0x02,0x04,0x08,0x11,
		    0x36,0x49,0x49,0x3F,0x9,
		    0x00,0x0,0x60,0x0,0x0,
		    0x3E,0x41,0x41,0x0,0x0,
		    0x0,0x0,0x41,0x41,0x3E,
		    0x4,0x15,0xE,0x15,0x4,
		    0x4,0x4,0x1F,0x4,0x4,
		    0x2,0x1,0x0,0x0,0x0,
		    0x8,0x8,0x8,0x8,0x8,
		    0x01,0x0,0x0,0x0,0x0,
		    0x01,0x2,0x4,0x8,0x10,
		    0x3E,0x45,0x49,0x51,0x3E,
		    0x41,0x41,0x7F,0x1,0x1,  //1
		    0x47,0x49,0x49,0x49,0x31, //2
		    0x41,0x49,0x49,0x49,0x36, //3
		    0x78,0x8,0x8,0x8,0x7F, //4
		    0x79,0x49,0x49,0x49,0x46, //5
		    0x3E,0x49,0x49,0x49,0x06,
		    0x60,0x40,0x40,0x40,0x7F,
		    0x36,0x49,0x49,0x49,0x36,
		    0x30,0x49,0x49,0x49,0x3E,//9
		    0x0,0x0,0x12,0x0,0x0,
		    0x12,0x1,0x0,0x0,0x0,
		    0x0,0x8,0x14,0x22,0x0,
		    0x0,0x14,0x14,0x14,0x14,
		    0x0,0x22,0x14,0x8,0x0,
		    0x20,0x40,0x4D,0x48,0x30,
		    0x7F,0x41,0x5D,0x45,0x7C,
		    0x3F,0x44,0x44,0x44,0x3F,//A
		    0x7f,0x49,0x49,0x39,0x06,
		    0x3E,0x41,0x41,0x41,0x22,
		    0x41,0x7F,0x41,0x41,0x3E,
		    0x7F,0x49,0x49,0x49,0x49,
		    0x7F,0x48,0x48,0x48,0x48,
		    0x3E,0x41,0x49,0x49,0x2E,
		    0x7F,0x08,0x08,0x08,0x7F,
		    0x41,0x41,0x7F,0x41,0x41,
		    0x42,0x41,0x41,0x41,0x7E,
 		    0x7F,0x08,0x14,0x22,0x41,
 		    0x7F,0x01,0x01,0x01,0x01,
 		    0x7F,0x20,0x10,0x20,0x7F,
 		    0x7F,0x10,0x08,0x04,0x7F,
//char NN[] = { 0x5F,0x04,0x02,0x01,0x5F,
 		    0x3E,0x41,0x41,0x41,0x3E,
 		    0x7F,0x48,0x48,0x48,0x30,
 		    0x3E,0x41,0x4D,0x43,0x3E,
 		    0x7F,0x48,0x48,0x4C,0x33,
 		    0x32,0x49,0x49,0x49,0x26,
		    0x40,0x40,0x7F,0x40,0x40,
		    0x7E,0x01,0x01,0x01,0x7E,
		    0x78,0x06,0x01,0x06,0x78,
 		    0x7F,0x02,0x04,0x02,0x7F,
 		    0x63,0x14,0x08,0x14,0x63,
 		    0x70,0x08,0x07,0x08,0x70,
		    0x43,0x45,0x49,0x51,0x61, //Z
		    0x7F,0x41,0x41,0x0,0x0,
		    0x10,0x8,0x4,0x2,0x1,
		    0x0,0x0,0x41,0x41,0x7F,
		    0x8,0x10,0x20,0x10,0x8,
		    0x0,0x1,0x1,0x1,0x0,
		    0x0,0x40,0x20,0x0,0x0,
		    0x3F,0x44,0x44,0x44,0x3F,//A
		    0x7f,0x49,0x49,0x39,0x06,
		    0x3E,0x41,0x41,0x41,0x22,
		    0x41,0x7F,0x41,0x41,0x3E,
		    0x7F,0x49,0x49,0x49,0x49,
		    0x7F,0x48,0x48,0x48,0x48,
		    0x3E,0x41,0x49,0x49,0x2E,
		    0x7F,0x08,0x08,0x08,0x7F,
		    0x41,0x41,0x7F,0x41,0x41,
		    0x42,0x41,0x41,0x41,0x7E,
 		    0x7F,0x08,0x14,0x22,0x41,
 		    0x7F,0x01,0x01,0x01,0x01,
 		    0x7F,0x20,0x10,0x20,0x7F,
 		    0x7F,0x10,0x08,0x04,0x7F,
//char NN[] = { 0x5F,0x04,0x02,0x01,0x5F,
 		    0x3E,0x41,0x41,0x41,0x3E,
 		    0x7F,0x48,0x48,0x48,0x30,
 		    0x3E,0x41,0x4D,0x43,0x3E,
 		    0x7F,0x48,0x48,0x4C,0x33,
 		    0x32,0x49,0x49,0x49,0x26,
		    0x40,0x40,0x7F,0x40,0x40,
		    0x7E,0x01,0x01,0x01,0x7E,
		    0x78,0x06,0x01,0x06,0x78,
 		    0x7F,0x02,0x04,0x02,0x7F,
 		    0x63,0x14,0x08,0x14,0x63,
 		    0x70,0x08,0x07,0x08,0x70,
		    0x43,0x45,0x49,0x51,0x61, //Z
		    0x8,0x77,0x41,0x41,0x0,
		    0x0,0x0,0x7F,0x0,0x0,
		    0x0,0x41,0x41,0x77,0x8,

};

__RW uint8_t M_n=0;  //Columna de la matriz del caracter en el que se encuentra
__RW uint8_t M_Character=0; //Caracter en el que se encuetra de la String a enviar
__RW uint8_t M_String[20];  //String a enviar

__RW uint8_t Matrix [COLUMNAS];  // La matriz que se va a mostrar
__RW uint8_t Show_col=0; // Columna mostrada
void (*M_funptr) (void) = NULL;


void Init_Exp4 ()
{
	int i=0;

	SetPinSel(Expantion0,0);
	SetPinDir(Expantion0,SALIDA);
	SetPinModeOD(Expantion0,O_NORMAL);

	SetPinSel(Expantion1,0);
	SetPinDir(Expantion1,SALIDA);
	SetPinModeOD(Expantion1,O_NORMAL);

	SetPinSel(Expantion2,0);
	SetPinDir(Expantion2,SALIDA);
	SetPinModeOD(Expantion2,O_NORMAL);

	SetPinSel(Expantion3,0);
	SetPinDir(Expantion3,SALIDA);
	SetPinModeOD(Expantion3,O_NORMAL);

	SetPinSel(Expantion4,0);
	SetPinDir(Expantion4,SALIDA);
	SetPinModeOD(Expantion4,O_NORMAL);

	SetPinSel(Expantion5,0);
	SetPinDir(Expantion5,SALIDA);
	SetPinModeOD(Expantion5,O_NORMAL);

	SetPinSel(Expantion6,0);
	SetPinDir(Expantion6,SALIDA);
	SetPinModeOD(Expantion6,O_NORMAL);

	SetPinSel(Expantion7,0);
	SetPinDir(Expantion7,SALIDA);
	SetPinModeOD(Expantion7,O_NORMAL);

	SetPinSel(Expantion8,0);
	SetPinDir(Expantion8,SALIDA);
	SetPinModeOD(Expantion8,O_NORMAL);

	SetPinSel(Expantion9,0);
	SetPinDir(Expantion9,SALIDA);
	SetPinModeOD(Expantion9,O_NORMAL);

	SetPinSel(Expantion10,0);    //TECLADO!!!
	SetPinDir(Expantion10,SALIDA);
	SetPinModeOD(Expantion10,O_NORMAL);

	SetPinSel(Expantion11,0);
	SetPinDir(Expantion11,SALIDA);
	SetPinModeOD(Expantion11,O_NORMAL);

	SetPinSel(Expantion12,0);
	SetPinDir(Expantion12,SALIDA);
	SetPinModeOD(Expantion12,O_NORMAL);

	SetPinSel(Expantion13,0);
	SetPinDir(Expantion13,ENTRADA);
	SetPinMode(Expantion13,PULLDOWN);

	SetPinSel(Expantion14,0);
	SetPinDir(Expantion14,ENTRADA);
	SetPinMode(Expantion14,PULLDOWN);

	SetPinSel(Expantion15,0);
	SetPinDir(Expantion15,ENTRADA);
	SetPinMode(Expantion15,PULLDOWN);

	WriteAllExpantions( ReadAllExpantions() & ~0x1FFF);

	for (i=0;i<COLUMNAS;i++) Matrix[i]=0;
}

void MATRIX_Encolar_Char () // Encola una columna del caracter que corresponde
{
  uint8_t * m;
  if (M_String [M_Character])
  {
    m= simbolos + 5*( (M_String[M_Character]) - ('!' - 1));  //Busca en la tabla la direccion de la letra
    if (M_n==5) {MATRIX_Encolar (0); M_Character++;}  // Si supero las 5 columnas, encolar una col vacia y
    												  // Aumentar un character
    	else MATRIX_Encolar (m[M_n]);	//Encola la columna correspondiente en la matriz
    if (M_n<5) M_n++; else M_n=0;		//Aumentar de columna o poner en 0 si se empezo una nueva  letra
  }
  else
  {
	  MATRIX_Encolar (0);
	  M_Character =0;
	  M_n=0;
  }
}

void MATRIX_Left ()  //mueve la matriz a la izq
{
  uint8_t i;
  for (i=0;i<COLUMNAS-1;i++)
  {
    Matrix[i]=Matrix[i+1];
  }
  Matrix[i]=0;
}

void MATRIX_Right () //Mueve la matriz a la der
{
  int i;
  for (i=COLUMNAS-1;i>=0;i--)
  {
    Matrix[i]=Matrix[i-1];
  }
  Matrix[0]=0;
}

void MATRIX_Up () //para arriba y bien sabrozo
{
  int i;
  for (i=0;i<COLUMNAS;i++)
  {
    if (Matrix[i]) Matrix[i]= (Matrix[i]*2) & 0x7F;
  }
}

void MATRIX_Down () //Para abajo
{
  int i;
  for (i=0;i<COLUMNAS;i++) Matrix[i]=(Matrix[i]/2)& 0x7F;

}

void MATRIX_Encolar (uint8_t A) //Encola una columna
{
  MATRIX_Left ();
  Matrix[COLUMNAS-1]=A;
}

/////////////////////////////// MATRIX SHOW /////////////////////////////////////////

void MATRIX_Inc_Col ()  //Incrementa la columa a mostrar
{
	if (Show_col== COLUMNAS) Show_col =0;

	if (! Show_col)
	{
		SetPin(Expantion7); //Pongo un uno en el Registro desplazamiento
		//Wait
	}

	SetPin (Expantion9);  //Avanzo una posicion el registro
	//wait
	SetPin(Expantion8); //Lo muestro

	ClrPin(Expantion7); //Limpio
	ClrPin(Expantion8);
	ClrPin(Expantion9);

	Show_col++;
}

void MATRIX_Show_Col (uint8_t i) //Muestra la columna
{
	int a;
	WriteAllExpantions( ( (a=ReadAllExpantions())  & (~0x7F) ) | Matrix[i] );
}

void MATRIX_NotShow_Col (uint8_t i) //Apaga la columna
{
	WriteAllExpantions( (ReadAllExpantions() & ~0x7F) );
}

void MATRIX_Mostrar_Handdler ()  //Muestra toda la matriz, cada vez que lo llama muestra una columna
{
	MATRIX_NotShow_Col (Show_col-1);
	MATRIX_Inc_Col();
	//Wait un tiempito para estabilizar
	MATRIX_Show_Col (Show_col-1);
}


