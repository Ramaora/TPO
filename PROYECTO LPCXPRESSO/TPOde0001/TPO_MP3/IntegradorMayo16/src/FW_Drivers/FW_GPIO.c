/**
 \file		: FW_GPIO.c
 \brief     : Funciones de bajo nivel de acceso al HW GPIO
 \details   :
 \author    : GOS
 \date 	    : 2014.04.08
*/

#include "Aplicacion.h"
#include "RegsLPC1769.h"

/**
 * \fn 		void SetPINSEL( uint8_t port , uint8_t pin ,uint8_t sel)
 * \brief 	Configura funcion de pin de GPIO
 * \details
 * \author 	GOS
 * \date   	2016.03.29
 * \param 	[in] uint8_t port , uint8_t pin ,uint8_t sel
 * \return 	void*/


void Write_Dac(uint16_t valor){

		DAC.DACR= (valor & 0x3FF)<<6;
		return;

}


void SetPINSEL(uint8_t port, uint8_t pin, uint8_t sel)
{
	port = port * 2 + pin / 16;								//!< Calcula registro PINSEL
	pin = ( pin % 16 ) * 2;									//!< Calcula campo de bits
	PINSEL[ port ] = PINSEL[ port ] & ( ~ ( 3 << pin ) );	//!< Limpia campo de bits
	PINSEL[ port ] = PINSEL[ port ] | ( sel << pin );		//!< Set de bits en campo
}

/**
 * \fn 		void SetPINMODE( uint8_t port , uint8_t pin ,uint8_t modo)
 * \brief 	Configura funcion de modo de pin de GPIO
 * \details
 * \author 	GOS
 * \date   	2016.03.29
 * \param 	[in] uint8_t port , uint8_t pin ,uint8_t modo
 * \return 	void
 * */
void SetPINMODE(uint8_t port, uint8_t pin, uint8_t modo)
{
	port = port * 2 + pin / 16;								//!< Calcula registro PINMODE
	pin = ( pin % 16 ) * 2;									//!< Calcula campo de bits
	PINMODE[ port ] = PINMODE[ port ] & ( ~ ( 3 << pin ) );	//!< Limpia campo de bits
	PINMODE[ port ] = PINMODE[ port ] | ( modo << pin );	//!< Set de bits en campo
}


/**
 * \fn 		void SetDIR( uint8_t port , uint8_t pin , uint8_t dir )
 * \brief 	Configura pin de GPIO como entrada o salida
 * \details
 * \author 	GOS
 * \date   	2016.03.29
 * \param 	[in]  uint8_t port , uint8_t pin , uint8_t dir
 * \return 	void
 * */
void SetDIR(uint8_t port, uint8_t pin, uint8_t dir )
{
	port = port * 8;									//!< Calcula registro FIODIR
	GPIOs[ port ] = GPIOs[ port ] & ( ~ ( 1 << pin ) );	//!< Limpia campo de bits
	GPIOs[ port ] = GPIOs[ port ] | ( dir << pin );		//!< Set de bits en campo
}

/**
 * \fn 		void SetPIN( uint8_t port , uint8_t pin , uint8_t estado )
 * \brief 	Pone un valor en el pin elegido
 * \details
 * \author 	GOS
 * \date   	2016.03.29
 * \param 	uint8_t port , uint8_t pin , uint8_t estado
 * \return 	void
 * */
void SetPIN(uint8_t port, uint8_t pin, uint8_t estado )
{
	port = port * 8 + 5;									//!< Calcula registro FIOPIN
	GPIOs[ port ] = GPIOs[ port ] & ( ~ ( 1 << pin ) );		//!< Limpia campo de bits
	GPIOs[ port ] = GPIOs[ port ] | ( estado << pin );		//!< Set de bits en campo
}

/**
 * \fn 		uint8_t GetPIN( uint8_t port , uint8_t pin , uint8_t actividad )
 * \brief 	Lee valor del pin elegido
 * \details
 * \author 	GOS
 * \date   	2016.03.29
 * \param 	 uint8_t port , uint8_t pin , uint8_t actividad
 * \return 	uint8_t
 * */
uint8_t GetPIN(uint8_t port, uint8_t pin, uint8_t actividad )
{
	port = port * 8 + 5;							//!< Calcula registro FIOPIN
	return ( ( ( GPIOs[ port ] >> pin ) & 1 ) == actividad ) ? 1 : 0;	//!< Retorna estado de pin en relacion a la actividad
}


/**
 * \fn 		void SetMODE_OD( uint8_t port , uint8_t pin , uint8_t dir )
 * \brief 	Configura MODE_OD
 * \details
 * \author 	GOS
 * \date   	2016.03.29
 * \param 	uint8_t port , uint8_t pin , uint8_t dir
 * \return 	void
 * */
void SetMODE_OD( uint8_t port , uint8_t pin , uint8_t dir )
{

	PINMODE_OD[ port ] = PINMODE_OD[ port ] & ( ~ ( 1 << pin ) );	//!< Limpia campo de bits
	PINMODE_OD[ port ] = PINMODE_OD[ port ] | ( dir << pin );		//!< Set de bits en campo

}

/**
 * \fn 		void TooglePIN ( uint8_t port , uint8_t pin)
 * \brief 	Invierte el valor del pin elegido
 * \details
 * \author 	GOS
 * \date   	2016.03.29
 * \param 	uint8_t port , uint8_t pin
 * \return 	void
 * */
void TooglePIN( uint8_t port , uint8_t pin)
{
	port = port * 8 + 5;			//!< Calcula registro FIOPIN
	
	if ( (GPIOs[ port ] >> pin) & 1 )
		GPIOs[ port ] &= ( ~ ( 1 << pin ) );	//!< Si vale 1, lo limpia
	else
		GPIOs[ port ] |= ( 1 << pin );		//!< Si vale 0, lo setea
}
