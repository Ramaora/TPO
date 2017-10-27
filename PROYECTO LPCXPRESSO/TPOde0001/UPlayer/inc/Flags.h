/*
 * Flags.h
 *
 *  Created on: 25/09/2013
 *      Author: andresdemski
 */

#ifndef FLAGS_H_
#define FLAGS_H_

typedef struct
{
	uint32_t	TouchFlag:1;
	uint32_t 	TouchGetFlag:1;
	uint32_t 	ReproductionStart:1;
	uint32_t 	ReproductionStop:1;
	uint32_t	ReproductionPause:1;
	uint32_t	ReproductionContinue:1;
	uint32_t 	ReproductionNext:1;
	uint32_t 	ReproductionPrev:1;
	uint32_t	FileEnd:1;

}FLAGS_S;

extern FLAGS_S	Flags;

#define		TOUCH_GET_FLAG		Flags.TouchGetFlag
#define		TOUCH_FLAG			Flags.TouchFlag
#define		REP_START			Flags.ReproductionStart
#define		REP_STOP			Flags.ReproductionStop
#define		REP_PAUSE			Flags.ReproductionPause
#define		REP_CONT			Flags.ReproductionContinue
#define		REP_NEXT			Flags.ReproductionNext
#define		REP_PREV			Flags.ReproductionPrev
#define		FILE_END			Flags.FileEnd

#endif /* FLAGS_H_ */
