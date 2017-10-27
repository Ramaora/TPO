/*
 * MP3.h
 *
 *  Created on: 18/09/2013
 *      Author: andresdemski
 */

#ifndef MP3_H_
#define MP3_H_

#include "ff.h"

typedef struct
{
	uint8_t Estado;
	uint8_t Buf[512];
	uint32_t Actual;
	uint32_t Final;
}Buffer_s;

typedef struct
{
	uint32_t SampleRate;
	uint32_t ByteRate;
	uint16_t BitsPerSample;
	uint16_t Channels;
} WAV;

#define 	MAXLIST		 16
#define 	END			  1

#define 	EMPTY		  0
#define		FULL		  1

#define		STOPED		  0
#define		WAITING		  1
#define		PLAYING		  2
#define		PAUSED		  3

extern FILINFO Finfo;
extern FATFS Fatfs[1];		/* File system object for each logical drive */
extern FIL FP;			        /* File objects */
extern DIR Dir;
extern uint8_t FileList[MAXLIST][13];
extern uint8_t MAX_FILE;

extern Buffer_s Buffers[3];
extern uint8_t ActualBuf;


//Pendrive Host

int USBHost_Init(void);
uint8_t Init_Pendrive (void);
void FileList_Fill (void);

//BUFFERS

uint8_t Buffers_Scan (void);
uint8_t Buffers_Fill (void);   ///Devuelve 1 si se termino el archivo
uint8_t Open_File (uint8_t * file);  //Abre el archivo y carga los buffers
void Close_File (void); // Cierra el archivo y vacia los bufers
uint8_t Buffer_Next (void);  /// Devuelve 1 si no hay buffer lleno

//Reproduction

uint8_t Reproduction (void);
void Stop_Reproduction (void);
void Start_Reproduction (uint32_t Raw);



#endif /* MP3_H_ */
