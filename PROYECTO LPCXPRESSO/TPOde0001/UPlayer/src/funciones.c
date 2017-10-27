/*
 * funciones.c
 *
 *  Created on: 01/10/2013
 *      Author: andresdemski
 */

#include "MyLPC1769.h"
#include "InfotronicKit.h"
#include "ssp.h"
#include "uart0.h"
#include "timer.h"
#include "interruption.h"
#include "port.h"
#include "Touch.h"
#include "TFT.h"
#include "MP3.h"
#include "delay.h"
#include "vs1003.h"
#include "Flags.h"
#include "variables.h"
#include "systick.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "dac.h"
#include "time.h"

uint8_t ESTADO_REPRODUCCION=0;
uint8_t CHANGE=0;
uint8_t BACK=0;
uint8_t PLAY=0;
uint8_t STOP=0;
uint8_t NEXT=0;
uint8_t U_CHANGE=0;

/**
 * \fn void Init (void)
 * \brief Inicializaciones
 * \details Contiene la inicilizaciones de los perifericos y hardware utilizado
 */
void Init (void)
{
	uint8_t i=0;

	Init_PLL();
	//Init_Infotronik();

	SSP_CFG_Type sspconf;
	sspconf.CPOL=SSP_CPOL_HI;
	sspconf.ClockRate=1000000;
	sspconf.CPHA=SSP_CPHA_FIRST;
	sspconf.Databit=SSP_DATABIT_8;
	sspconf.FrameFormat=SSP_FRAME_SPI;
	sspconf.Mode=SSP_MASTER_MODE;
	SSP_Init(&SSP1,&sspconf);
	SSP_Cmd(&SSP1,ENABLE);


	//InitVS1003();

	Init_UART0(115200);
	Init_Dac();
	Init_Touch();
	Init_TFT();
	Init_Timer0_Match0();

	TFT_Screen_Color(0,0,0);

	while (Init_Pendrive());

	Init_IGraf();

	/// Touch IRQ
  	GPIO_IrqEnable(TOUCH_PENIRQ,ENABLE,FALLING);
	GPIO_IrqEnable(TOUCH_PENIRQ,DISSABLE,RISING);

	NVIC_IrqEnable(IRQ_EINT3);

	SysTick_Enable();
}

/**
 * \fn void Init_IGraf (void)
 * \brief Inializa la interfaz grafica
 * \details Dibuja las lineas y escribe la lista de archivos
 */
void Init_IGraf (void)
{
	uint32_t i;

	Display_FileList ();

	TFT_Print(&(FileList[File_Selected][0]),16,67,SMALL_FONT,GREEN);

	TFT_Set_Address(0,50,239,50);
	for (i=0;i<240;i++)
	{
		TFT_Send_Color(TFT_Color(0xFF,0xFF,0xFF));
	}

	TFT_Set_Address(0,260,239,260);
	for (i=0;i<240;i++)
	{
		TFT_Send_Color(TFT_Color(0xFF,0xFF,0xFF));
	}

	TFT_Set_Address(60,0,60,50);
	for (i=0;i<240;i++)
	{
		TFT_Send_Color(TFT_Color(0xFF,0xFF,0xFF));
	}

	TFT_Set_Address(120,0,120,50);
	for (i=0;i<240;i++)
	{
		TFT_Send_Color(TFT_Color(0xFF,0xFF,0xFF));
	}

	TFT_Set_Address(180,0,180,50);
	for (i=0;i<240;i++)
	{
		TFT_Send_Color(TFT_Color(0xFF,0xFF,0xFF));
	}

	TFT_Print("PREV",13,20,SMALL_FONT,WHITE);
	TFT_Print("NEXT",196,20,SMALL_FONT,WHITE);
	TFT_Print("STOP",136,20,SMALL_FONT,WHITE);
	TFT_Print("PLAY",76,20,SMALL_FONT,WHITE);


}


/**
 * \fn void Display_FileList (void)
 * \brief Imprime la lista de archivos
 * \details Imprime la lista de archivos
 */
void Display_FileList (void)
{
	uint8_t i=0;
	while ( FileList[i][0] && i<MAXLIST)
	{
		if (i <8)
		{
			TFT_Print(&(FileList[i][0]),16,67+i*25,SMALL_FONT,WHITE);
		}
		else
		{
			TFT_Print(&(FileList[i][0]),130,67+(i-8)*25,SMALL_FONT,WHITE);
		}
		i++;
	}
}

/**
 * \fn uint8_t Select_FileList (void)
 * \brief Interpreta las cordenadas del Touch
 * \details Interpreta las cordenadas del Touch
 * \retval N Archivo seleccionado
 * \retval MAXLIST No es archivo
 */
uint8_t Select_FileList (void)
{
	uint8_t i=0;
	if (TOUCH_Y<52) return MAXLIST;
	while ( ((TOUCH_Y - 63-(i*25)) > 6) && (i<8))
	{
		i++;
	}
	if (i==8) return MAXLIST;
	if (TOUCH_X >120) i += MAXLIST/2;
	if (FileList[i][0])	return i;
	return MAXLIST;
}


/**
 * \fn void Maquina_Touch (void)
 * \brief Maquina de estado del Tocuh
 * \details Controla y hace un promedio de los datos adquiridos por el touch:)
 */

void Maquina_Touch (void)
{
	//Conversion disponible
	static uint8_t TOUCH_CNT=0;
	static uint16_t TOUCH_PROMEDIO_X=0,TOUCH_PROMEDIO_Y=0;
	static uint8_t ESTADO=0;

	 if (ESTADO==0 || ESTADO >3) //Reposo
	 {
		 if (TOUCH_GET_FLAG)
		 {
			 ESTADO=1;
			 TOUCH_CNT=15;
		 }
		 else return;
	 }

	 if (ESTADO==1) //Waiting
	 {
		 if (!TOUCH_CNT)
		 {
			 ESTADO=2;
			 TOUCH_CNT=20;
			 return;
		 }

		 TOUCH_CNT--;
		 Get_Touch();
		 return;
	 }

	 if (ESTADO==2) //Scan
	 {
		 TOUCH_CNT--;
		 Get_Touch();
		 TOUCH_PROMEDIO_X += TouchXY.X;
		 TOUCH_PROMEDIO_Y += TouchXY.Y;
		 if (!TOUCH_CNT) ESTADO=3;
		 return;
	 }

	 if (ESTADO==3) //Calculando
	 {
		TOUCH_X = TOUCH_PROMEDIO_X/20;
		TOUCH_Y = 320 - TOUCH_PROMEDIO_Y/20;

		ESTADO=0;
		TOUCH_PROMEDIO_X =0;
		TOUCH_PROMEDIO_Y =0;
		TOUCH_CNT=0;

		TOUCH_FLAG=1; //Flag del mundo main

		if (!TOUCH_Y) {TOUCH_X=0;TOUCH_Y=0;TOUCH_FLAG=0;}

		TOUCH_GET_FLAG=0;
		GPIO_IrqClr(TOUCH_PENIRQ);
		GPIO_IrqEnable(TOUCH_PENIRQ,1,FALLING);

	 }
}
/*
void TOUCH (void)
{
	if (TOUCH_GET_FLAG)
	{
		if (TOUCH_CNT<15)
		{
			TOUCH_CNT++;
			Get_Touch();
		}

		else if (TOUCH_CNT>14 && TOUCH_CNT<35)  //5 muestras
		{
			Get_Touch();
			TOUCH_PROMEDIO_X += TouchXY.X;
			TOUCH_PROMEDIO_Y += TouchXY.Y;
			TOUCH_CNT++;
		}

		else if (TOUCH_CNT ==35)
		{
			TOUCH_X = TOUCH_PROMEDIO_X/20;
			TOUCH_Y = TOUCH_PROMEDIO_Y/20;


			TOUCH_PROMEDIO_X =0;
			TOUCH_PROMEDIO_Y =0;
			TOUCH_CNT=0;

			TOUCH_GET_FLAG=0;
			TOUCH_FLAG=1;

			if (TOUCH_Y==320) {TOUCH_X=0;TOUCH_Y=0;TOUCH_FLAG=0;}

			GPIO_IrqClr(TOUCH_PENIRQ);
			GPIO_IrqEnable(TOUCH_PENIRQ,1,FALLING);
		}
	}
}
	*/

/**
 * \fn void Maquina_Reproduction(void)
 * \brief Maquina de estado que controla la reproduccion
 * \details Interpreta los flags obtenidos en otras partes del programa para controlar la reproduccion
 */
void Maquina_Reproduction(void)
{

	if (ESTADO_REPRODUCCION>2) ESTADO_REPRODUCCION=0;

	if (ESTADO_REPRODUCCION==0) // Reposo
	{
		if (REP_START)
		{
			REP_STOP=0;
			REP_START=0;
			Start_Reproduction(File_Selected);

			if ( Buffers_Fill() ) //Si no se lleno el buffer
			{
				Stop_Reproduction();
				ESTADO_REPRODUCCION=0;
				return;
			}

			FILE_END=0;
			ESTADO_REPRODUCCION=1;
			Timer0_IrqEnable();
			return;
		}
		return;
	}
	if (ESTADO_REPRODUCCION==1) //Reproduciendo
	{
		if (FILE_END && !(Buffers_Scan())) //Fin de la rep
		{
			FILE_END=0;
			REP_STOP=1; //Agregar flags para la parte grafica
		}

		if (REP_START)  //Funciona, pero no se usa
		{
			REP_START=0;
			Stop_Reproduction();

			Start_Reproduction(File_Selected);

			FILE_END=0;
			ESTADO_REPRODUCCION=1;
			Timer0_IrqEnable();
			return;
		}

		if (REP_STOP)
		{
			Timer0_IrqDisable();
			REP_STOP=0;
			Stop_Reproduction();
			ESTADO_REPRODUCCION=0;
			return;
		}

		if (REP_PAUSE)
		{
			TIMER0.TCR=0;
			Timer0_IrqDisable();
			REP_PAUSE=0;
			ESTADO_REPRODUCCION=2;
			return;
		}

		return;
	}
	if (ESTADO_REPRODUCCION==2) //Paused
	{
		if (REP_CONT)
		{
			TIMER0.TCR=1;
			REP_CONT=0;
			ESTADO_REPRODUCCION=1;
			Timer0_IrqEnable();
			return;
		}

		if (REP_STOP)
		{
			REP_STOP=0;
			Stop_Reproduction();
			ESTADO_REPRODUCCION=0;
			Timer0_IrqDisable();
			return;
		}

		if (REP_START)  // Tampoco se usa
		{
			REP_START=0;
			Stop_Reproduction();
			Start_Reproduction(File_Selected);
			FILE_END=0;
			ESTADO_REPRODUCCION=1;
			Timer0_IrqEnable();
			return;
		}

		return;
	}

}


/**
 * \fn void Interfaz_Grafica (void)
 * \brief Controla y actualiza la interfaz
 * \details Controla y actualiza la interfaz
 */
void Interfaz_Grafica (void)
{
	uint8_t Boton=0,selected=0;
	uint8_t bufuart[10];
	if (TOUCH_FLAG)
	{
		TOUCH_FLAG=0;

		if ((selected= Select_FileList())<MAXLIST)
		{
			File_Selected=selected;
			sprintf (bufuart,"&s.%d\n",File_Selected);
			Uart_Push(bufuart);

		}
		else
		{
			if (TOUCH_Y<52)
			{
				Boton= TOUCH_X/60;
				CHANGE=1;
				switch (Boton)
				{
					case 0:
						BACK=1;
						break;
					case 1:
						PLAY=1;
						break;
					case 2:
						STOP=1;
						break;
					case 3:
						NEXT=1;
						break;

				}

			}
		}
	}

	if (CHANGE)
	{
		CHANGE=0;
		if (BACK)//Back
		{
			BACK=0;
			if (!U_CHANGE) Uart_Push("&b.\n");
			if (!File_Selected) File_Selected= MAX_FILE-1;
			File_Selected--;
		}
		else if (PLAY)//Play/Pause
		{
			PLAY=0;
			TFT_Print("PREV",13,20,SMALL_FONT,WHITE);
			TFT_Print("NEXT",196,20,SMALL_FONT,WHITE);
			TFT_Print("STOP",136,20,SMALL_FONT,WHITE);

			if (ESTADO_REPRODUCCION==0)
			{
				if (!U_CHANGE) Uart_Push("&p.\n");

				TFT_Print("PLAY",76,20,SMALL_FONT,BLACK);

				TFT_Print(&(FileList[File_Playing][0]),16,280,SMALL_FONT,BLACK);

				File_Playing=File_Selected;

				TFT_Print(&(FileList[File_Playing][0]),16,280,SMALL_FONT,WHITE);

				TFT_Print("PAUSE",72,20,SMALL_FONT,WHITE);

				REP_START=1;
			}
			if (ESTADO_REPRODUCCION==1)
			{
				if (!U_CHANGE) Uart_Push("&p.\n");

				TFT_Print("PAUSE",72,20,SMALL_FONT,BLACK);
				REP_PAUSE=1;
				TFT_Print("PLAY",76,20,SMALL_FONT,WHITE);

			}
			if (ESTADO_REPRODUCCION==2)
			{
				if (!U_CHANGE) Uart_Push("&p.\n");

				TFT_Print("PLAY",76,20,SMALL_FONT,BLACK);

				TFT_Print("PAUSE",72,20,SMALL_FONT,WHITE);

				REP_CONT=1;
			}
		}
		else if (STOP)//Stop
		{
			STOP=0;
			if (!U_CHANGE) Uart_Push("&x.\n");
			if (ESTADO_REPRODUCCION != 0)
			{
				TFT_Print("PAUSE",72,20,SMALL_FONT,BLACK);

				TFT_Print(&(FileList[File_Playing][0]),16,280,SMALL_FONT,BLACK);

				TFT_Print("PLAY",76,20,SMALL_FONT,WHITE);

				REP_STOP=1;
			}
		}
		else if (NEXT)//Next
		{
			NEXT=0;

			if (!U_CHANGE) Uart_Push("&n.\n");
			if (File_Selected<MAXLIST-1 && FileList[File_Selected+1][0])
			{
				File_Selected++;
			}
			else
			{
				File_Selected = 0;
			}

		}
	}

	U_CHANGE=0;

	if (FILE_END)
	{
		Uart_Push("&s.\n");
		TFT_Print("PAUSE",72,20,SMALL_FONT,BLACK);
		TFT_Print("PLAY",76,20,SMALL_FONT,WHITE);
		TFT_Print(&(FileList[File_Playing][0]),16,280,SMALL_FONT,BLACK);
	}

	if (File_Selected != File_Before)
	{
		TFT_Print(&(FileList[File_Before][0]),16+114*(File_Before/8),67+(File_Before%8)*25,SMALL_FONT,WHITE);
		File_Before = File_Selected;
		TFT_Print(&(FileList[File_Selected][0]),16+114*(File_Selected/8),67+(File_Selected%8)*25,SMALL_FONT,GREEN);
	}
}

//----------------------------------------------------------------------------------------//
//                                      UART                                              //
//----------------------------------------------------------------------------------------//
uint8_t UART_BUSY=0;

uint8_t UART_TxFIFO [16][25];
uint8_t UART_TxFIFO_ESTADO=EMPTY;
uint8_t UART_TxPointer=0;

uint8_t UART_RxFIFO [16][17];
uint8_t UART_RxFIFO_ESTADO;
uint8_t UART_RxPointer=0;

/**
 * \fn void Uart_Control (void)
 * \brief Controla la Uart
 * \details Se encarga del enviado y recepcion en buffers
 */
void Uart_Control (void)
{
	static uint8_t Rx=0;
	if (UART_TxFIFO_ESTADO>0)
	{
		if (!UART_BUSY)
		{
			UART_BUSY=1;
			UART0_Send(UART_TxFIFO[UART_TxPointer]);
			UART_TxFIFO_ESTADO--;
			UART_TxFIFO[UART_TxPointer][0]=0;
			UART_TxPointer++;
			UART_TxPointer = UART_TxPointer % 16;
		}
	}

	if (UART_RxFIFO_ESTADO >0)
	{
		if (UART_RxFIFO[Rx][0]=='&' && UART_RxFIFO[Rx][2]=='.')
		{
			switch (UART_RxFIFO[Rx][1])
			{
				case 's':  //Sel
					File_Selected= atoi (& UART_RxFIFO[Rx][3]);
					break;
				case 'p':  //play
					PLAY=1;
					CHANGE=1;
					U_CHANGE=1;
					break;
				case 'x': //Stop
					CHANGE=1;
					U_CHANGE=1;
					STOP=1;
					break;
				case 'n': //Next
					CHANGE=1;
					NEXT=1;
					U_CHANGE=1;
					break;
				case 'b': //Back
					CHANGE=1;
					BACK=1;
					U_CHANGE=1;
					break;
				case 'c': //connect
					CHANGE=1;
					STOP=1;
					Enviar_Actual();
					break;
			}
		}
		UART_RxFIFO[Rx][0]=0;
		UART_RxFIFO_ESTADO--;
		Rx++;
		Rx= Rx%16;
	}
}

/**
 * \fn void Uart_Push (uint8_t *Dato)
 * \brief Push de datos a el buffer TX de la Uart
 * \details Agrega al buffer los datos.
 */
void Uart_Push (uint8_t *Dato)
{
	uint8_t ptr= UART_TxPointer;
	while (UART_TxFIFO_ESTADO>15);
	ptr = (ptr + UART_TxFIFO_ESTADO)%16;
	strcpy(UART_TxFIFO[ptr],Dato);
	UART_TxFIFO_ESTADO++;
}

/**
 * \fn void Enviar_Actual(void)
 * \brief Pushea datos actuales
 * \details Pushea datos actuales
 */
void Enviar_Actual(void)
{
	uint8_t i;
	uint8_t buffer[25];
	for (i=0;i<MAX_FILE-1;i++)
	{
		sprintf (buffer,"&f.%s\n",FileList[i]);
		Uart_Push(buffer);
	}
	sprintf (buffer,"&s.%d\n",File_Selected);
	Uart_Push(buffer);

}
