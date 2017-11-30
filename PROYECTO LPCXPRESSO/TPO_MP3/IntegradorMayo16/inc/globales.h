/*
 * globales.h
 *
 *  Created on: 6 de nov. de 2017
 *      Author: Rama
 */

#ifndef INTEGRADORMAYO16_INC_GLOBALES_H_
#define INTEGRADORMAYO16_INC_GLOBALES_H_

volatile uint8_t msgDisplay[6];
extern void disk_timerproc (void);
uint8_t bufferTx0[TX0BUFFER_SIZE];
// Buffer de Recepcion
uint8_t bufferRx0[RX0BUFFER_SIZE];

// Indices de Transmision
uint8_t tx0_in,tx0_out;
// Indices de Recepcion
uint8_t rx0_in,rx0_out;
// Flags de estado de los buffers
uint8_t tx0_buffer_full = 0, tx0_buffer_empty = 1;
uint8_t rx0_buffer_full = 0, rx0_buffer_empty = 1;

uint8_t tx0Start=0;
DWORD AccSize;				/* Work register for fs command */
WORD AccFiles, AccDirs;
FILINFO Finfo;

char Line[256];				/* Console input buffer */

volatile FATFS FatFs;				/* File system object for each logical drive */
volatile FIL File;				/* File objects */
volatile DIR Dir;
/* Directory object */
volatile uint8_t FileList[20][13];	//nombres de las canciones
volatile uint8_t MAX_FILE=0;
volatile uint8_t buffKey=NO_KEY;	//buffer de valor de teclado



volatile uint8_t estado2=REPOSO;		//estado de la maquina de reproduccion
volatile uint8_t bufferswav[2][1024];	//buffer de datos de la reproduccion
volatile uint32_t cant=0;				//guarda la cantidad de bytes que se mandaron al DAC
volatile UINT Timer;
volatile uint8_t ArchivoActual=0;		//index de cancion actual
volatile uint8_t delayteclado=0;
volatile uint8_t tecla=NO_KEY;
volatile uint8_t flagtermino=0;			//indica si se acabo el buffer de datos de reproduccion
//lcd
volatile unsigned int inxInLCD;
volatile unsigned int inxOutLCD;
volatile unsigned int cantidadColaLCD;
volatile int demoraLCD;
uint8_t bufferLCD[100];
volatile uint8_t ptrLecturaLCD = 0;
volatile uint8_t ptrEscrituraLCD = 0;
volatile uint16_t timeoutSerie=1000;
uint32_t f_tick_rtc  = 6000;


#endif /* INTEGRADORMAYO16_INC_GLOBALES_H_ */
