/*************************************************************************
 * @file		Storage.c
 * @brief		Links physical storage driver (SD/MMC/USB) to FatFS library
 * @version		1.0
 * @date		06. Mar. 2012
 * @author		NXP MCU SW Application Team
 *************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 ************************************************************************/

#include "Storage.h"
#include "SD/lpc17xx_sd.h"
#include "diskio.h"
#include "USBHost/MassStorage/usbhost_ms.h"

/* The sector size is fixed to 512bytes */
#define SECTOR_SIZE 512

/* Local variables */
static volatile WORD Timer1, Timer2;	/* 100Hz decrement timer stopped at zero (disk_timerproc()) */
static volatile DSTATUS Stat = STA_NOINIT;	/* Disk status */

/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                  */
/*-----------------------------------------------------------------------*/
DSTATUS disk_initialize (
	BYTE drv		/* Physical drive number */
)
{
#ifdef SUPPORT_USB
	if(drv == 0)
	{
		Stat &= ~STA_NOINIT;
		return Stat;
	}
#endif

#ifdef SUPPORT_SD
	if(drv == 1)
	{
		if (SD_Init() && SD_ReadConfiguration())
			Stat &= ~STA_NOINIT;
		return Stat;
	}
#endif

	return STA_NOINIT;
}

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/
#if _USE_IOCTL!=0
DRESULT disk_ioctl (
	BYTE drv,		/* Physical drive number */
	BYTE ctrl,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;
	uint32_t numBlks, blkSize;
	BYTE n, *ptr = buff;

	res = RES_ERROR;

#ifdef SUPPORT_USB
	if(drv == 0)
	{
		if (Stat & STA_NOINIT) return RES_NOTRDY;
		switch (ctrl) {
		case CTRL_SYNC :		/* Make sure that no pending write process */
			res = RES_OK;
			break;

		case GET_SECTOR_COUNT :	/* Get number of sectors on the disk (DWORD) */
			MS_ReadCapacity(&numBlks, &blkSize);
			*(DWORD*)buff = numBlks;
			res = RES_OK;
			break;

		case GET_SECTOR_SIZE :	/* Get R/W sector size (WORD) */
			MS_ReadCapacity(&numBlks, &blkSize);
			*(WORD*)buff = blkSize;		//512;
			res = RES_OK;
			break;

		case GET_BLOCK_SIZE :	/* Get erase block size in unit of sector (DWORD) */
			MS_ReadCapacity(&numBlks, &blkSize);
			*(DWORD*)buff = blkSize;
			res = RES_OK;
			break;

		default:
			res = RES_PARERR;
		}

		return res;
	}
#endif

#ifdef SUPPORT_SD
	if(drv == 1)
	{
		if (Stat & STA_NOINIT) return RES_NOTRDY;
		switch (ctrl) {
		case CTRL_SYNC :		/* Make sure that no pending write process */
	        SD_Select();
			if (SD_WaitForReady() == SD_TRUE)
				res = RES_OK;
			break;

		case GET_SECTOR_COUNT :	/* Get number of sectors on the disk (DWORD) */
			*(DWORD*)buff = CardConfig.sectorcnt;
			res = RES_OK;
			break;

		case GET_SECTOR_SIZE :	/* Get R/W sector size (WORD) */
			*(WORD*)buff = CardConfig.sectorsize;	//512;
			res = RES_OK;
			break;

		case GET_BLOCK_SIZE :	/* Get erase block size in unit of sector (DWORD) */
			*(DWORD*)buff = CardConfig.blocksize;
			res = RES_OK;
			break;

		case MMC_GET_TYPE :		/* Get card type flags (1 byte) */
			*ptr = CardType;
			res = RES_OK;
			break;

		case MMC_GET_CSD :		/* Receive CSD as a data block (16 bytes) */
			for (n=0;n<16;n++)
				*(ptr+n) = CardConfig.csd[n];
			res = RES_OK;
			break;

		case MMC_GET_CID :		/* Receive CID as a data block (16 bytes) */
			for (n=0;n<16;n++)
				*(ptr+n) = CardConfig.cid[n];
			res = RES_OK;
			break;

		case MMC_GET_OCR :		/* Receive OCR as an R3 resp (4 bytes) */
			for (n=0;n<4;n++)
				*(ptr+n) = CardConfig.ocr[n];
			res = RES_OK;
			break;

		case MMC_GET_SDSTAT :	/* Receive SD status as a data block (64 bytes) */
			for (n=0;n<64;n++)
	            *(ptr+n) = CardConfig.status[n];
	        res = RES_OK;
			break;

		default:
			res = RES_PARERR;
		}

	    SD_DeSelect();

		return res;
	}
#endif

	return RES_PARERR;
}
#endif

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/
DRESULT disk_read (
	BYTE drv,			/* Physical drive number */
	BYTE *buff,			/* Pointer to the data buffer to store read data */
	DWORD sector,		/* Start sector number (LBA) */
	BYTE count			/* Sector count (1..255) */
)
{
	if(!count) return RES_PARERR;

#ifdef SUPPORT_USB
	if(drv == 0)
	{
		if (Stat & STA_NOINIT) return RES_NOTRDY;

		if(MS_BulkRecv(sector, count, buff) == OK)
			return RES_OK;
		else
			return RES_ERROR;
	}
#endif

#ifdef SUPPORT_SD
	if(drv == 1)
	{
		if (Stat & STA_NOINIT) return RES_NOTRDY;

		if (SD_ReadSector (sector, buff, count) == SD_TRUE)
			return RES_OK;
		else
			return RES_ERROR;
	}
#endif

	return RES_PARERR;
}

/*-----------------------------------------------------------------------*/
/* Get Disk Status                                                       */
/*-----------------------------------------------------------------------*/
DSTATUS disk_status (
	BYTE drv		/* Physical drive number */
)
{
#ifdef SUPPORT_USB
	if(drv == 0)
	{
		return Stat;
	}
#endif

#ifdef SUPPORT_SD
	if(drv == 1)
	{
		return Stat;
	}
#endif

	return STA_NOINIT;
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/
#if _READONLY == 0
DRESULT disk_write (
	BYTE drv,			/* Physical drive number */
	const BYTE *buff,	/* Pointer to the data to be written */
	DWORD sector,		/* Start sector number (LBA) */
	BYTE count			/* Sector count (1..255) */
)
{
	if(!count) return RES_PARERR;

#ifdef SUPPORT_USB
	if(drv == 0)
	{
		if (Stat & STA_NOINIT) return RES_NOTRDY;

		if ( MS_BulkSend(sector, count, buff) == OK)
			return RES_OK;
		else
			return 	RES_ERROR;
	}
#endif

#ifdef SUPPORT_SD
	if(drv == 1)
	{
		if (Stat & STA_NOINIT) return RES_NOTRDY;

		if ( SD_WriteSector(sector, buff, count) == SD_TRUE)
			return RES_OK;
		else
			return 	RES_ERROR;
	}
#endif

	return RES_PARERR;
}
#endif /* _READONLY == 0 */

/*-----------------------------------------------------------------------*/
/* Device timer function  (Platform dependent)                           */
/*-----------------------------------------------------------------------*/
/* This function must be called from timer interrupt routine in period
/  of 10 ms to generate card control timing.
*/
void disk_timerproc (void)
{
#ifdef SUPPORT_SD
    WORD n;

	n = Timer1;						/* 100Hz decrement timer stopped at 0 */
	if (n) Timer1 = --n;
	n = Timer2;
	if (n) Timer2 = --n;
#endif
}

/* --------------------------------- End Of File ------------------------------ */
