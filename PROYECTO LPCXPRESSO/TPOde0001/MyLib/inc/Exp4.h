/*
 * Exp4.h
 *
 *  Created on: 30/06/2013
 *      Author: demski
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#define COLUMNAS 20

void Init_Exp4 ();

void MATRIX_Left ();
void MATRIX_Right ();
void MATRIX_Down ();
void MATRIX_Up ();

void MATRIX_Encolar (uint8_t);
void MATRIX_Encolar_Char ();

void MATRIX_Mostrar_Handdler ();
void MATRIX_Inc_Col ();
void MATRIX_Show_Col (uint8_t i);
void MATRIX_NotShow_Col (uint8_t i);

extern __RW uint8_t M_n;  //Columna de la matriz del caracter en el que se encuentra
extern __RW uint8_t M_Character; //Caracter en el que se encuetra de la String a enviar
extern __RW uint8_t M_String[20];  //String a enviar

extern __RW uint8_t Matrix [COLUMNAS];  // La matriz que se va a mostrar
extern __RW uint8_t Show_col; // Columna mostrada

#endif /* MATRIX_H_ */
