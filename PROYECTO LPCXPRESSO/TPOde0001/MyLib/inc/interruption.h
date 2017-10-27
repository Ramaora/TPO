/*
 * interruption.h
 *
 *  Created on: 27/07/2013
 *      Author: tigermax
 */

#ifndef INTERRUPTION_H_
#define  INTERRUPTION_H_

#define		IRQ_WDT			0
#define 	IRQ_TIMER0 		1
#define 	IRQ_TIMER1 		2
#define     IRQ_TIMER2  	3
#define     IRQ_TIMER3 		4
#define     IRQ_UART0 		5
#define     IRQ_UART1 		6
#define     IRQ_UART2 		7
#define     IRQ_UART3 		8
#define     IRQ_PWM1 		9
#define     IRQ_I2C0 		10
#define     IRQ_I2C1 		11
#define     IRQ_I2C2 		12
#define     IRQ_SPI 		13
#define     IRQ_SSP0 		14
#define     IRQ_SSP1 		15
#define     IRQ_PLL0 		16
#define     IRQ_RTC 		17
#define     IRQ_EINT0 		18
#define     IRQ_EINT1 		19
#define     IRQ_EINT2 		20
#define     IRQ_EINT3 		21
#define     IRQ_ADC 		22
#define     IRQ_BOD 		23
#define     IRQ_USB 		24
#define     IRQ_CAN 		25
#define     IRQ_DMA			26
#define     IRQ_I2S 		27
#define     IRQ_ENET		28
#define     IRQ_RIT 		29
#define     IRQ_MCPWM		30
#define     IRQ_QEI 		31
#define     IRQ_PLL1 		32
#define     IRQ_USBActivity	33
#define     IRQ_CANActivity 34

void NVIC_IrqEnable (uint8_t Irq);
void NVIC_IrqDisable (uint8_t Irq);
void NVIC_Pending (uint8_t Irq);
void NVIC_NotPending (uint8_t Irq);
void NVIC_IrqPriority (uint8_t Irq, uint8_t Prio);
void NVIC_TriggerIrq (uint8_t Irq);

////////////////////EXT//////////////////////////////////////

uint8_t EXT_GetIrqFlag ();
void EXT_ClrIrqFlag (uint8_t Flag);
void EXT_IrqMode (uint8_t Ext, uint8_t Mode);
void EXT_IrqPolarity (uint8_t Ext, uint8_t Polar);

//////////////////////GPIO/////////////////////////////////

void GPIO_IrqEnable (uint8_t port, uint8_t pin, uint8_t enable, uint8_t Edge);
uint32_t GPIO_IrqPending (); //bit0: no hay pendientes bit1:Port0 pendiente bit2: Port1 pendiente
uint32_t GPIO_IrqStat (uint8_t port,uint8_t pin,uint8_t Edge);
void GPIO_IrqClr (uint8_t port, uint8_t pin);

#endif /* INTERRUPTION_H_ */
