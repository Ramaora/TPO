/*
 * FW_Display_Exp3.h
 *
 *  Created on: 07/09/2013
 *      Author: marcelo
 */

#ifndef FW_DISPLAY_EXP3_H_
#define FW_DISPLAY_EXP3_H_

	#include "KitInfo2_BaseBoard.h"
	#include "RegsLPC1769.h"
	#include "FW_Display_Exp3.h"

	/** -------------------------------------------------------------------------------------
	 *PLACA EXPANSION 3
	 */
	//!< Display
	#define		A_BCD			EXPANSION0
	#define		B_BCD			EXPANSION1
	#define		C_BCD			EXPANSION2
	#define		D_BCD			EXPANSION3
	#define		seg_dp			EXPANSION4


	#define		RST				EXPANSION6
	#define		CLK				EXPANSION5


	#define		DIGITOS			6

	#define		DSP_ROJO		1				//!< Display rojo
	#define		DSP_VERDE		2				//!< Display verde


	/** ----------------------------------------------------------------------
	 * Prototipos
	 */
		void BarridoDisplay( void );
		void InitGPIOs_EXP3 ( void );

		void Display (uint32_t);
		void BarridoDisplay(void);

#endif /* FW_DISPLAY_EXP3_H_ */
