/**
 	\file KitInfo2PR_7Seg.c
 	\brief Primitiva de Display de 7 segmentos
 	\details Valida para Expansion 2 y Expansion 3
 	\author Ing. Marcelo Trujillo
 	\date 2012.04.25
*/

#include "Aplicacion.h"
extern volatile uint8_t msgDisplay[DIGITOS];			//!< Buffer de display
/*----------------------------------------------
*	\fn  void Display(int Val,char dsp)
*	\brief Presentacion de valores en el display de 3 dígitos
*	\param [in] val valor a mostrar
* 	\param [in] dsp seleccion del sector del display
*	\return void
*/
	/**
		\fn  void Display(int Val)
		\brief Presentacion de valores en el display de 6 dígitos
	 	\param [in] val valor a mostrar
		\return void
	*/

	void Display (uint32_t val)
	{
	    uint8_t i;
	    uint8_t auxDisplay[DIGITOS];
	    auxDisplay[0] =auxDisplay[1] =auxDisplay[2]=0;
	    auxDisplay[3] =auxDisplay[4] =auxDisplay[5]=0;

	    for (i=0; i<DIGITOS ; i++,val /= 10)
	    	auxDisplay[i] = val%10;

	    for (i=0; i<DIGITOS ; i++)
	    {
	    	TICKINT = OFF; 	//deshabilito el systick
	    	msgDisplay[DIGITOS-1-i] = auxDisplay [i];
	    	TICKINT = ON;	//habilito el systick
	    }
	}
