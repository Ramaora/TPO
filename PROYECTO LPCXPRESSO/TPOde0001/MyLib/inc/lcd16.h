/*
 * lcd16.h
 *
 *  Created on: 15/08/2013
 *      Author: Andres
 */

#ifndef LCD16_H_
#define LCD16_H_

void LCD16_Com4 (uint8_t com);
void LCD16_Com (uint8_t com);
void LCD16_Dat4 (uint8_t Dat);
void LCD16_Dat (uint8_t Dat);
void Init_LCD16 (void);
void LCD16_Mostrar (uint8_t *string,uint8_t Linea, uint8_t Posicion);


#endif /* LCD16_H_ */
