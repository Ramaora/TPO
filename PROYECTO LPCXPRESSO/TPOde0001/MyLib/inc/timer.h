/*
 * timer.h
 *
 *  Created on: 18/09/2013
 *      Author: andresdemski
 */

#ifndef TIMER_H_
#define TIMER_H_

void Init_Timer0_Match0 (void);
void Timer0_ClrIrq_Match0 (void);
void Timer0_Match0 (uint8_t estado, uint32_t Match);
void Timer0_IrqDisable ();
void Timer0_IrqEnable ();


#endif /* TIMER_H_ */
