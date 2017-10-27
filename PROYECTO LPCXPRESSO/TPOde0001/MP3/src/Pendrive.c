/*
 * Pendrive.c
 *
 *  Created on: 18/09/2013
 *      Author: andresdemski
 */
#include "LPC17xx.h"
#include <string.h>
#include "ff.h"
#include "ffconf.h"
#include "usbhost_inc.h"
#include "usbhost_lpc17xx.h"
#include "Storage.h"
#include "MP3.h"

FILINFO Finfo;
FATFS Fatfs[_VOLUMES];		/* File system object for each logical drive */
FIL FP;			        /* File objects */
DIR Dir;

uint8_t FileList[MAXLIST][13];
uint8_t MAX_FILE=0;

int USBHost_Init(void)
{
    int32_t  rc;
	uint32_t  numBlks, blkSize;
	uint8_t  inquiryResult[INQUIRY_LENGTH];

    Host_Init();               /* Initialize the lpc17xx host controller */
    rc = Host_EnumDev();       /* Enumerate the device connected  */
	if (rc != OK)	return 1;
	rc = MS_Init( &blkSize, &numBlks, inquiryResult );
	if ((rc != OK) || (blkSize != 512))		return 2;

	return OK;
}

uint8_t Init_Pendrive (void)
{
	uint32_t i;
	if (USBHost_Init()) return !OK;
	if (f_mount(0, &Fatfs[0] )) return !OK;
	if (f_opendir(&Dir,"0:")) return !OK;

	for (i=0;i<MAXLIST;i++) FileList[i][0] = (uint8_t)0;
	FileList_Fill();

	return OK;
}

void FileList_Fill (void)
{
	uint32_t i=0;
	do
	{
		f_readdir(&Dir, &Finfo);
		strcpy ((char*)&(FileList[i][0]),(const char*)Finfo.fname);
		i++;
	}while (Finfo.fname[0] && i<MAXLIST);
	MAX_FILE=i;
}

