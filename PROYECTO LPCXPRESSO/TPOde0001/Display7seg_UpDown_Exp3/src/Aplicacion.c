/*
 * Aplicacion.c
 *
 *  Created on: 5 de jun. de 2016
 *      Author: marcelo
 */

#include "Aplicacion.h"

void cuentoPulsos (void){
    static uint8_t antPulsador4 = 0;	//variable seguidora KEY4_RC
    static uint8_t antPulsador3 = 0;	//variable seguidora KEY3_RC
    static uint32_t cont = 0;

    if (KEY4_RC_PRESS && !antPulsador4) //Si el pulsador está oprimido
    {	//y se detecta flanco ascendente
	    antPulsador4 = 1;
	    cont++;
	    LED2_ON;

	    Display (cont%1000000);

    }						//si el pulsador no esta presionado
    else if (!KEY4_RC_PRESS && antPulsador4)
    {	    //y se detecta flanco descendente
	    antPulsador4 = 0;
	    LED2_OFF;
    }


    if (KEY3_RC_PRESS && !antPulsador3) //Si el pulsador está oprimido
    {	//y se detecta flanco ascendente
	    antPulsador3 = 1;
	    cont--;
	    if (!cont)
	    	cont = 1000000;
	    LED3_ON;

	    Display (cont%1000000);

    }						//si el pulsador no esta presionado
    else if (!KEY3_RC_PRESS && antPulsador3)
    {	    //y se detecta flanco descendente
	    antPulsador3 = 0;
	    LED3_OFF;
    }
}

