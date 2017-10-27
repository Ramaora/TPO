/*************************************************************************
 * @file		Storage.h
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

#ifndef STORAGE_H
#define STORAGE_H

#include "LPC17xx.h"                 /* LPC17xx Definitions */
#include "diskio.h"

/* Enable playback MP3 in USB flash disk and/or SDC/MMC card */
#define SUPPORT_USB
#define SUPPORT_SD

#if  !defined SUPPORT_USB  && !defined SUPPORT_SD
    #error At least USB or SD should be supported!!!
#endif

/* type defintion */
typedef unsigned char    USB_BOOL;
#define USB_TRUE     1
#define USB_FALSE    0

#ifndef NULL
 #ifdef __cplusplus              // EC++
  #define NULL          0
 #else
  #define NULL          ((void *) 0)
 #endif
#endif

/* Public functions */
DSTATUS disk_initialize (BYTE drv);
DRESULT disk_ioctl (BYTE drv, BYTE ctrl, void *buff);
DRESULT disk_read (BYTE drv, BYTE *buff, DWORD sector, BYTE count);
DSTATUS disk_status (BYTE drv);
DRESULT disk_write (BYTE drv, const BYTE *buff, DWORD sector, BYTE count);
void disk_timerproc (void);


#endif 	//STORAGE_H
