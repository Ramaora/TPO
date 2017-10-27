
/////////////////////////////////////////////////////////////////////////////////////
//                                PUERTOS                                          //
/////////////////////////////////////////////////////////////////////////////////////


void SetPinSel (uint8_t port, uint8_t pin,uint8_t sel);  
	Selecciona la funcion del pin

void SetPinDir (uint8_t port,uint8_t pin,uint8_t dir);
	Si la funcion del pin es GPIO, se configura su comportamiento: ENTRADA / SALIDA

void SetPinMode (uint8_t port,uint8_t pin, uint8_t Mode);
	Si es entrada, se configura si es PULLUP, PULLDOWN , REPEATER o NEITHER

void SetPinModeOD (uint8_t port, uint8_t pin, uint8_t OD);
	Si es salida, se configura si es O_NORMAL o O_OPENDRAIN

void WritePort (uint8_t port,uint32_t Value);
	Escribe el valor deseado en el puerto
	
uint32_t ReadPort (uint8_t port);
	Retorna el valor actual del puerto
	
void SetPin (uint8_t port, uint8_t pin);
	Pone en 1 el pin
	
void ClrPin (uint8_t port, uint8_t pin);
	Pone en 0 el pin
	
uint8_t GetPin (uint8_t port, uint8_t pin);
	Retorna el valor actual del pin
	
void InvPin (uint8_t port,uint8_t pin);
	Invierte el estado actual del pin
	
void WritePortMask (uint8_t port, uint32_t value, uint32_t mask);
	Igual que WritePort pero aplica una mascara
	
void WritePin (uint8_t port, uint8_t pin, uint8_t value);
	Pone el valor deseado en el pin

/////////////////////////////////////////////////////////////////////////////////////
//                             INFOTRONIC                                          //
/////////////////////////////////////////////////////////////////////////////////////

void Init_Exp3 ();
	Inicializa los pines para la expansion3
	
void Init_Exp4 ();
	Inicializa los pines para la expansion4

uint32_t ReadAllExpantions ();
	Retorna el estado actual de todos los pines de expansion
	
void WriteAllExpantions( uint32_t Data);
	Escribe todos los pines de expansion

/////////////////////////////////////////////////////////////////////////////////////
//                          INFOTRONIC - EXP3                                      //
/////////////////////////////////////////////////////////////////////////////////////

Variables Globales:
				Dig_n: Digito mostrado en los displays
				Disp7BCD_char_n: Digito del BCD_txt en el que se encuentra
				Disp7BCD_txt[13] : Numero a mostrar en los displays

void DISP7BCD_inc ();
	Incrementa la columna visible
	
void DISP7BCD_dig (uint8_t Data);
	Pone el valor desiado a la columna actual
	
void DISP7BCD_Handdler ();
	Funcion llamada por la IRQ

/////////////////////////////////////////////////////////////////////////////////////
//                          INFOTRONIC - EXP4                                      //
/////////////////////////////////////////////////////////////////////////////////////

Variables Globales:
				M_n: Columna actual del caracter mostrado
				M_Character: Caracter en el que se encuetra.
				String[20]: String que sera mostrada en la matriz
				
				Matrix [COLUMNAS]:  La matriz que se va a mostrar
				Show_col: Columna mostrada

void MATRIX_Left ();
	Desplaza la matriz hacia la izquierda

void MATRIX_Right ();
	Desplaza la matriz hacia la derecha
	
void MATRIX_Down ();
	Desplaza la matriz hacia abajo
	
void MATRIX_Up ();
	Desplaza la matriz hacia arriba
	
void MATRIX_Encolar (uint8_t);
	Encola a la matriz una columna
	
void MATRIX_Encolar_Char ();
	Encola en la matriz la columna correspondiente a el String que se esta presentando

void MATRIX_Mostrar_Handdler ();

void MATRIX_Inc_Col ();
	Incrementa la columna actual
	
void MATRIX_Show_Col (uint8_t i);
	Muestra la columna actual
	
void MATRIX_NotShow_Col (uint8_t i);
	Apaga la columna actual
		
/////////////////////////////////////////////////////////////////////////////////////
//                                 NVIC                                            //
/////////////////////////////////////////////////////////////////////////////////////

void NVIC_IrqEnable (uint8_t Irq);
	Habilita La interrupcion en el NVIC
	
void NVIC_IrqDisable (uint8_t Irq);
	Desabilita la interrupcion en el NVIC
	
void NVIC_Pending (uint8_t Irq);
void NVIC_NotPending (uint8_t Irq);

void NVIC_IrqPriority (uint8_t Irq, uint8_t Prio);
	Establece una prioridad a la interrupcion
	
void NVIC_TriggerIrq (uint8_t Irq);
	Hace el llamado de la interrupcion a pesar de no haber ocurrido.
				
/////////////////////////////////////////////////////////////////////////////////////
//                                EXT-IRQ                                          //
/////////////////////////////////////////////////////////////////////////////////////

uint8_t EXT_GetIrqFlag ();
	Obtiene el flag que generan las interrupciones externas
	
void EXT_ClrIrqFlag (uint8_t Flag);
	Limpia la interrupcion
	
void EXT_IrqMode (uint8_t Ext, uint8_t Mode);
	Establece la condicion para el ext seleccionado. Nivel o Flanco
	
void EXT_IrqPolarity (uint8_t Ext, uint8_t Polar);
	Ascendente, descendente, nivel alto o bajo.

/////////////////////////////////////////////////////////////////////////////////////
//                                 GPIO-IRQ                                        //
/////////////////////////////////////////////////////////////////////////////////////

void GPIO_IrqEnable (uint8_t port, uint8_t pin, uint8_t enable, uint8_t Edge);
	Habilita la interrupcion del GPIO en el flanco correspondiente
	
uint8_t GPIO_IrqPending ();
	Devuelve si hay pendiente: bit0: no hay pendiente, bit1:Pendiente en Port0 bit2: Pendiente en Port2

uint32_t GPIO_IrqStat (uint8_t port,uint8_t Edge);
	Devuelve el estado de la bandera correspondiente al Flanco.

void GPIO_IrqClr (uint8_t port, uint8_t pin);
	Limpia las Flags.
