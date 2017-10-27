/*
 * MyLPC1769.h
 *
 *  Created on: 25/06/2013
 *      Author: demski
 */

#ifndef __LPC17xx_H__   //solo se declara si no se usa la CMSIS

#ifndef MYLPC1769_H_

#define MYLPC1769_H_


#define		__R			volatile const
#define		__W			volatile
#define		__RW		volatile
#define 	NULL		(void*)0

typedef		unsigned int	uint32_t;
typedef 	short unsigned int 	uint16_t;
typedef 	unsigned char 		uint8_t;


#define		PCONP		( *( uint32_t  * ) 0x400FC0C4UL )
#define		PCLKSEL0		( *( uint32_t  * ) 0x400FC1A8UL )
#define     PCLKSEL1	( *( uint32_t  * ) 0x400FC1ACUL )

#define GPIO_BASE   ((__RW uint32_t*) 0x2009C000UL)
#define PINSEL_BASE ((__RW uint32_t*) 0x4002C000UL)
#define PINMODE_BASE ((__RW uint32_t*) 0x4002C040UL)
#define PINMODEOD_BASE ((__RW uint32_t*) 0x4002C068UL)

#define FIOPIN0		 (*(__RW uint32_t*) 0x2009C014UL)
#define	FIOPIN1		 (*(__RW uint32_t*) 0x2009C034UL)
#define	FIOPIN2 	 (*(__RW uint32_t*) 0x2009C054UL)
#define	FIOPIN3 	 (*(__RW uint32_t*) 0x2009C074UL)
#define	FIOPIN4 	 (*(__RW uint32_t*) 0x2009C094UL)

#define FIOSET0		 (*(__RW uint32_t*) 0x2009C018UL )
#define FIOSET1		 (*(__RW uint32_t*) 0x2009C038UL )
#define FIOSET2		 (*(__RW uint32_t*) 0x2009C058UL )
#define FIOSET3		 (*(__RW uint32_t*) 0x2009C078UL )
#define FIOSET4		 (*(__RW uint32_t*) 0x2009C098UL )

#define FIOCLR0		 (*(__RW uint32_t*) 0x2009C01CUL )
#define FIOCLR1		 (*(__RW uint32_t*) 0x2009C03CUL )
#define FIOCLR2		 (*(__RW uint32_t*) 0x2009C05CUL )
#define FIOCLR3		 (*(__RW uint32_t*) 0x2009C07CUL )
#define FIOCLR4		 (*(__RW uint32_t*) 0x2009C09CUL )

#define NVIC_ISER_BASE ((__RW uint32_t*) 0xE000E100UL)
#define NVIC_ICER_BASE ((__RW uint32_t*) 0xE000E180UL)
#define NVIC_ISPR_BASE ((__RW uint32_t*) 0xE000E200UL)
#define NVIC_ICPR_BASE ((__RW uint32_t*) 0xE000E280UL)
#define NVIC_IABR_BASE ((__R uint32_t*) 0xE000E300UL)
#define NVIC_IPR_BASE ((__RW uint32_t*) 0xE000E400UL)
#define NVIC_STIR ((__W uint32_t*) 0xE000EF00UL)

#define EXT_INTFLAG		((__RW uint32_t*) 0x400FC140UL)
#define EXT_MODE		((__RW uint32_t*) 0x400FC148UL)
#define	EXT_POLAR		((__RW uint32_t*) 0x400FC14CUL)

#define	GPIO_INTSTATUS		((__R uint32_t*) 0x40028080 )
#define GPIO_STATR_BASE 	((__R uint32_t*) 0x40028084 )
#define GPIO_STATF_BASE		((__R uint32_t*) 0x40028088 )
#define GPIO_INTCLR_BASE 	((__W uint32_t*) 0x4002808C )
#define GPIO_INTENR_BASE 	((__RW uint32_t*) 0x40028090 )
#define	GPIO_INTENF_BASE	((__RW uint32_t*) 0x40028094 )

#define	SYSTICK_CTRL	(*(__RW uint32_t*) 0xE000E010)
#define	SYSTICK_RLOAD	(*(__RW uint32_t*) 0xE000E014)
#define	SYSTICK_CUR	(*(__RW uint32_t*) 0xE000E018)
#define	SYSTICK_CALIB	(*(__R uint32_t*) 0xE000E01C)



///////////////////////UART0//////////////////////////////

typedef struct
{
  union {
  __R  uint8_t  RBR;
  __W  uint8_t  THR;
  __RW uint8_t  DLL;
       uint32_t RESERVED0;
  };
  union {
  __RW uint8_t  DLM;
  __RW uint32_t IER;
  };
  union {
  __R  uint32_t IIR;
  __W  uint8_t  FCR;
  };
  __RW uint8_t  LCR;
       uint8_t  RESERVED1[7];
  __R  uint8_t  LSR;
       uint8_t  RESERVED2[7];
  __RW uint8_t  SCR;
       uint8_t  RESERVED3[3];
  __RW uint32_t ACR;
  __RW uint8_t  ICR;
       uint8_t  RESERVED4[3];
  __RW uint8_t  FDR;
       uint8_t  RESERVED5[7];
  __RW uint8_t  TER;
       uint8_t  RESERVED6[39];
  __RW uint32_t FIFOLVL;
} LPC_UART0_S;

#define		UART0		(*(LPC_UART0_S *) 0x4000C000UL )
//-----------------------------------------------------------------------------
// SSP
//-----------------------------------------------------------------------------
typedef struct
{
  __RW uint32_t CR0;
  __RW uint32_t CR1;
  __RW uint32_t DR;
  __R uint32_t SR;
  __RW uint32_t CPSR;
  __RW uint32_t IMSC;
  __RW uint32_t RIS;
  __RW uint32_t MIS;
  __RW uint32_t ICR;
  __RW uint32_t DMACR;
} LPC_SSP;

#define			SSP1		(*(LPC_SSP*) 0x40030000UL)

//-----------------------------------------------------------------------------
//  DAC
//-----------------------------------------------------------------------------
typedef struct
{
  __RW uint32_t DACR;
  __RW uint32_t DACCTRL;
  __RW uint16_t DACCNTVAL;
} LPC_DAC;

#define 	DAC			(*(LPC_DAC*) 0x4008C000UL)

//-----------------------------------------------------------------------------
// Timer
//-----------------------------------------------------------------------------

typedef struct
{
  __RW uint32_t IR;
  __RW uint32_t TCR;
  __RW uint32_t TC;
  __RW uint32_t PR;
  __RW uint32_t PC;
  __RW uint32_t MCR;
  __RW uint32_t MR0;
  __RW uint32_t MR1;
  __RW uint32_t MR2;
  __RW uint32_t MR3;
  __RW uint32_t CCR;
  __R  uint32_t CR0;
  __R  uint32_t CR1;
       uint32_t RESERVED0[2];
  __RW uint32_t EMR;
       uint32_t RESERVED1[12];
  __RW uint32_t CTCR;
} LPC_TIMER;

#define     TIMER0		  (*(LPC_TIMER*)0x40004000)

//-----------------------------------------------------------------------------
// Oscilador
//-----------------------------------------------------------------------------

//////////////Registros del CLOCK y de sistema/////////////////
//0x400FC1A0UL: Registro de control de sistema y registro de status:
#define		DIR_SCS			( (uint32_t *) 0x400FC1A0UL)
//0x400FC104UL: Registro de configuracion del clock:
#define		DIR_CCLKCFG		( (uint32_t *) 0x400FC104UL)
//0x400FC10CUL: Registro de seleccion del clock:
#define		DIR_CLKSRCSEL	( (uint32_t *) 0x400FC10CUL)
//0x400FC1C8UL: Clock Output Config register:
#define		DIR_CLKOUTCFG	( (uint32_t *) 0x400FC1C8UL)
//0x400FC000UL: Flash access configuration:
#define		DIR_FLASHCFG	( (uint32_t *) 0x400FC000UL)
/////////////////Registros de los PLL///////////////////////////
//0x400FC080UL: Registro de control del PLL0:
#define		DIR_PLL0CON		( (uint32_t *) 0x400FC080UL)
//0x400FC084UL: Registro de configuracion del PLL0:
#define		DIR_PLL0CFG		( (uint32_t *) 0x400FC084UL)
//0x400FC088UL: Registro de estado del PLL0:
#define		DIR_PLL0STAT	( (uint32_t *) 0x400FC088UL)
//0x400FC08CUL: Registro de control del PLL0:
#define		DIR_PLL0FEED	( (uint32_t *) 0x400FC08CUL)
//0x400FC0A0UL: Registro de control del PLL1:
#define		DIR_PLL1CON		( (uint32_t *) 0x400FC0A0UL)
//0x400FC0A4UL: Registro de configuracion del PLL1:
#define		DIR_PLL1CFG		( (uint32_t *) 0x400FC0A4UL)
//0x400FC0A8UL: Registro de estado del PLL1:
#define		DIR_PLL1STAT	( (uint32_t *) 0x400FC0A8UL)
//0x400FC0ACUL: Registro de control del PLL1:
#define		DIR_PLL1FEED	( (uint32_t *) 0x400FC0ACUL)
//Registro de status y configuracion del sistema:
#define		SCS			DIR_SCS[0]
#define 	FLASHCFG	DIR_FLASHCFG[0]
//Registros de control del CLOCK:
#define		CCLKCFG		DIR_CCLKCFG[0]
#define		CLKSRCSEL	DIR_CLKSRCSEL[0]
#define		CLKOUTCFG	DIR_CLKOUTCFG[0]
//PLL0:
#define		PLL0CON		DIR_PLL0CON[0]
#define		PLL0CFG		DIR_PLL0CFG[0]
#define		PLL0STAT	DIR_PLL0STAT[0]
#define		PLL0FEED	DIR_PLL0FEED[0]
//PLL1:
#define		PLL1CON		DIR_PLL1CON[0]
#define		PLL1CFG		DIR_PLL1CFG[0]
#define		PLL1STAT	DIR_PLL1STAT[0]
#define		PLL1FEED	DIR_PLL1FEED[0]




#endif /* MYLPC1769_H_ */
#endif // __LPC17xx_H__
