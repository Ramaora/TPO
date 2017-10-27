/*
 * buffer.c
 *
 *  Created on: 18/09/2013
 *      Author: andresdemski
 */

#include "MyLPC1769.h"
#include "ff.h"
#include "ffconf.h"
#include "MP3.h"

Buffer_s Buffers[3];
uint8_t ActualBuf=0;

uint8_t Buffers_Fill (void)   ///Devuelve 1 si se termino el archivo
{
	uint8_t i;
	Buffer_s * Fill;
	for (i=0;i<3;i++)
	{
		Fill = & Buffers [(ActualBuf+i)%3];
		if (Fill->Estado == EMPTY)
		{
			if (f_read (&FP,Fill->Buf,512,&Fill->Final) != FR_OK)
			{
				return 1;
			}
			if (Fill->Final) Fill->Estado=FULL;
			Fill->Actual=0;
			if (Fill->Final < 512)
			{
				return END;
			}
		}
	}
	return 0;

}

uint8_t Buffers_Scan (void)
{
	return (Buffers[0].Estado | Buffers[1].Estado |Buffers[2].Estado);
}

uint8_t Open_File (uint8_t * file)  //Abre el archivo y carga los buffers
{
	if (f_open (&FP,(char*)file,FA_READ)) return 1;
	return 0;
}

void Close_File (void) // Cierra el archivo y vacia los bufers
{
	uint8_t i;
	f_close (&FP);

	for (i=0;i<3;i++)
	{
		Buffers[i].Actual=0;
		Buffers[i].Final=0;
		Buffers[i].Estado=EMPTY;
	}

	ActualBuf=0;
}

uint8_t Buffer_Next (void)  /// Devuelve 1 si no hay buffer lleno
{
	uint32_t act = ActualBuf;
	while (Buffers[ActualBuf].Estado == EMPTY)
	{
		ActualBuf= (ActualBuf+1)%3;
		if (ActualBuf==act) return 1;
	}
	return 0;
}
