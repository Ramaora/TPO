/*
 * Reproduction.c
 *
 *  Created on: 18/09/2013
 *      Author: andresdemski
 */

#include "MyLPC1769.h"
#include "InfotronicKit.h"
#include "port.h"
#include "ff.h"
#include "ffconf.h"
#include "MP3.h"
#include "vs1003.h"
#include "timer.h"
#include "ssp.h"
#include "dac.h"

WAV format;

uint8_t Reproduction (void)
{
	uint16_t sample;
	SetPin(LPCXPRESSOLED);
	if (Buffers[ActualBuf].Actual >= Buffers[ActualBuf].Final)
	{
		Buffers[ActualBuf].Estado=EMPTY;
		ClrPin(LPCXPRESSOLED);
		if ( Buffer_Next() )
		{
			return 1;
		}
	}
	if (format.BitsPerSample>=10)  //No esta en servicio, solo 8 bits
	{
		sample= ((Buffers[ActualBuf].Buf)[Buffers[ActualBuf].Actual+1]) | (((Buffers[ActualBuf].Buf)[Buffers[ActualBuf].Actual])<<8);
		sample=((sample )^(1<<16))>> (format.BitsPerSample-10);
		Buffers[ActualBuf].Actual = Buffers[ActualBuf].Actual+  2* format.Channels;
	}
	else
	{
		sample= Buffers[ActualBuf].Buf[Buffers[ActualBuf].Actual];
		//sample= sample* cte ... Control de volumen
		Buffers[ActualBuf].Actual= Buffers[ActualBuf].Actual + format.Channels;
	}
	Write_Dac(sample);
	ClrPin(LPCXPRESSOLED);

	return 0;
}
void Stop_Reproduction (void)
{
	TIMER0.TCR=0;
	Timer0_IrqDisable();
	Close_File();
}

void Start_Reproduction (uint32_t Raw)
{
	uint8_t buff[44];
	uint32_t cant,Match;
	if (! f_open (&FP,&(FileList[Raw][0]),FA_READ) ) //Buffer fill
	{
		if (f_read(&FP,buff,43,&cant) == FR_OK && cant==43)
		{
			buff[44]=0;
			format.Channels=*((uint16_t*)(buff+22));
			format.BitsPerSample=*((uint32_t*)(buff+34));
			format.ByteRate=*((uint16_t*)(buff+4));
			format.SampleRate=*((uint16_t*)(buff+24));

			Match= 1000000/(format.SampleRate/*format.Channels*/);
			Timer0_Match0(1,Match);
			Buffers_Fill();
		}
	}
	else Stop_Reproduction();
}


/*   Con Vs1003
void Reproduction (void)
{
	uint32_t aux;
	SSP_DATA_SETUP_Type SDI;
	SDI.rx_data = NULL;


	while (! GetPin(DREQ));

	ClrPin(xDCS);

    if (GetPin(DREQ))
	{
		if (Buffers[ActualBuf].Estado == EMPTY)
		{
			if ( Buffer_Next() ) {SetPin(xDCS); return; }
		}

		aux = Buffers[ActualBuf].Final - Buffers[ActualBuf].Actual;

		if (aux > 32) aux = 32;
		else Buffers[ActualBuf].Estado=EMPTY;
		SDI.length=aux;
		SDI.tx_data= Buffers[ActualBuf].Buf + Buffers[ActualBuf].Actual;

		if (aux) SSP_ReadWrite(&SSP1,&SDI);    //Se hizo manual porque el SDI era ineficiente   //WriteSdi(Buffers[ActualBuf].Buf,aux);

		Buffers[ActualBuf].Actual += aux;
	}

	SetPin(xDCS);

	return;
}

void Stop_Reproduction (void)
{
	Close_File();
}

void Start_Reproduction (uint32_t Raw)
{
	WriteSci(SCI_MODE,SM_RESET|SM_SDINEW);
	f_open (&FP,&(FileList[Raw][0]),FA_READ);
}


*/
