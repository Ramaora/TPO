#include "../../../Reproductor/inc/Aplicacion.h"

void Inicializar_Display7s( void )
{
	SetPINSEL ( EXPANSION0 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION1 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION2 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION3 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION4 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION5 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION6 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION9 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION10 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION11 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION12 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION13 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION14 , PINSEL_GPIO);
	SetPINSEL ( EXPANSION15 , PINSEL_GPIO);

	SetDIR ( EXPANSION0 , SALIDA);
	SetDIR ( EXPANSION1 , SALIDA);
	SetDIR ( EXPANSION2 , SALIDA);
	SetDIR ( EXPANSION3 , SALIDA);
	SetDIR ( EXPANSION4 , SALIDA);
	SetDIR ( EXPANSION5 , SALIDA);
	SetDIR ( EXPANSION6 , SALIDA);
	SetDIR ( EXPANSION9 , SALIDA);
	SetDIR ( EXPANSION10 , SALIDA);
	SetDIR ( EXPANSION11 , SALIDA);
	SetDIR ( EXPANSION12 , SALIDA);
	SetDIR ( EXPANSION13 , SALIDA);
	SetDIR ( EXPANSION14 , SALIDA);
	SetDIR ( EXPANSION15 , SALIDA);

}
