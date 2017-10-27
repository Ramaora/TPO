/*
 * Exp3.h
 *
 *  Created on: 18/07/2013
 *      Author: tigermax
 */

#ifndef SEG7BCD_H_
#define SEG7BCD_H_

void Init_Exp3 ();
void DISP7BCD_inc ();
void DISP7BCD_dig (uint8_t Data);
void DISP7BCD_Handdler ();

extern __RW uint8_t Dig_n; //Digito mostrado en los displays
extern __RW uint8_t Disp7BCD_char_n; //Digito del BCD_txt en el que se encuentra
extern __RW uint8_t Disp7BCD_txt[13]; //Numero a mostrar en los displays


#endif /* 7SEGBCD_H_ */
