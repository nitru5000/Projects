/*
 * Seven_Segments_Program.c
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */
#include "Seven_Segments_Interface.h"
#include "Seven_Segments_Private.h"
#include "Seven_Segments_Config.h"


void SevenSeg_VoidInit     (void)
{
	if ( SEVEVEN_SEGMENTS_1_TYPE == COMMON_ANODE)
	DIO_SetPinDirection(SEVEN_SEGMENTS_1_POWER_PORT,SEVEN_SEGMENTS_1_POWER_PIN,OUTPUT);
	else
	DIO_SetPinDirection(SEVEN_SEGMENTS_1_POWER_PORT,SEVEN_SEGMENTS_1_POWER_PIN,INPUT);
//***********************************************************************************************************
	if ( SEVEVEN_SEGMENTS_2_TYPE == COMMON_ANODE)
	DIO_SetPinDirection(SEVEN_SEGMENTS_2_POWER_PORT,SEVEN_SEGMENTS_2_POWER_PIN,OUTPUT);
	else
	DIO_SetPinDirection(SEVEN_SEGMENTS_2_POWER_PORT,SEVEN_SEGMENTS_2_POWER_PIN,INPUT);
//***********************************************************************************************************
	if ( SEVEVEN_SEGMENTS_3_TYPE == COMMON_ANODE)
	DIO_SetPinDirection(SEVEN_SEGMENTS_3_POWER_PORT,SEVEN_SEGMENTS_3_POWER_PIN,OUTPUT);
	else
	DIO_SetPinDirection(SEVEN_SEGMENTS_3_POWER_PORT,SEVEN_SEGMENTS_3_POWER_PIN,INPUT);
//***********************************************************************************************************
	if ( SEVEVEN_SEGMENTS_4_TYPE == COMMON_ANODE)
	DIO_SetPinDirection(SEVEN_SEGMENTS_4_POWER_PORT,SEVEN_SEGMENTS_4_POWER_PIN,OUTPUT);
	else
	DIO_SetPinDirection(SEVEN_SEGMENTS_4_POWER_PORT,SEVEN_SEGMENTS_4_POWER_PIN,INPUT);
//***********************************************************************************************************
	DIO_SetPinDirection(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_A,OUTPUT);
	DIO_SetPinDirection(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_B,OUTPUT);
	DIO_SetPinDirection(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_C,OUTPUT);
	DIO_SetPinDirection(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_D,OUTPUT);

//***********************************************************************************************************

#if      SevenSeg_1_State == SevenSeg_Enable
	     DIO_SetPinValue(SEVEN_SEGMENTS_1_POWER_PORT,SEVEN_SEGMENTS_1_POWER_PIN,HIGH);
#elif    SevenSeg_1_State == SevenSeg_Disable
	     DIO_SetPinValue(SEVEN_SEGMENTS_1_POWER_PORT,SEVEN_SEGMENTS_1_POWER_PIN,LOW);
#endif

#if      SevenSeg_2_State == SevenSeg_Enable
	     DIO_SetPinValue(SEVEN_SEGMENTS_2_POWER_PORT,SEVEN_SEGMENTS_2_POWER_PIN,HIGH);
#elif    SevenSeg_2_State == SevenSeg_Disable
	     DIO_SetPinValue(SEVEN_SEGMENTS_2_POWER_PORT,SEVEN_SEGMENTS_2_POWER_PIN,LOW);
#endif

#if      SevenSeg_3_State == SevenSeg_Enable
	     DIO_SetPinValue(SEVEN_SEGMENTS_3_POWER_PORT,SEVEN_SEGMENTS_3_POWER_PIN,HIGH);
#elif    SevenSeg_3_State == SevenSeg_Disable
	     DIO_SetPinValue(SEVEN_SEGMENTS_3_POWER_PORT,SEVEN_SEGMENTS_3_POWER_PIN,LOW);
#endif

#if      SevenSeg_4_State == SevenSeg_Enable
	     DIO_SetPinValue(SEVEN_SEGMENTS_4_POWER_PORT,SEVEN_SEGMENTS_4_POWER_PIN,HIGH);
#elif    SevenSeg_4_State == SevenSeg_Disable
	     DIO_SetPinValue(SEVEN_SEGMENTS_4_POWER_PORT,SEVEN_SEGMENTS_4_POWER_PIN,LOW);
#endif
}


/****************************************** WRTIE FUNCTION *********************************************/

void SevenSeg_VoidWrite    (u8 number)
{

	if (number < 10)
	{
		DIO_SetPinValue(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_A,GET_BIT(number,0));
		DIO_SetPinValue(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_B,GET_BIT(number,1));
		DIO_SetPinValue(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_C,GET_BIT(number,2));
		DIO_SetPinValue(SEVEN_SEGMENTS_DATA_PORT,SEVEN_SEGMENTS_DATA_PIN_D,GET_BIT(number,3));
	}
}

/****************************************** Seven Segments 1 *********************************************/

void SevenSeg1_VoidEnable  (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_1_POWER_PORT,SEVEN_SEGMENTS_1_POWER_PIN,HIGH);
}
void SevenSeg1_VoidDisable (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_1_POWER_PORT,SEVEN_SEGMENTS_1_POWER_PIN,LOW);
}

/****************************************** Seven Segments 2 *********************************************/

void SevenSeg2_VoidEnable  (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_2_POWER_PORT,SEVEN_SEGMENTS_2_POWER_PIN,HIGH);
}
void SevenSeg2_VoidDisable (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_2_POWER_PORT,SEVEN_SEGMENTS_2_POWER_PIN,LOW);
}

/****************************************** Seven Segments 3 *********************************************/
void SevenSeg3_VoidEnable  (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_3_POWER_PORT,SEVEN_SEGMENTS_3_POWER_PIN,HIGH);
}
void SevenSeg3_VoidDisable (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_3_POWER_PORT,SEVEN_SEGMENTS_3_POWER_PIN,LOW);
}

/****************************************** Seven Segments 4 *********************************************/

void SevenSeg4_VoidEnable  (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_4_POWER_PORT,SEVEN_SEGMENTS_4_POWER_PIN,HIGH);
}
void SevenSeg4_VoidDisable (void)
{
	DIO_SetPinValue(SEVEN_SEGMENTS_4_POWER_PORT,SEVEN_SEGMENTS_4_POWER_PIN,LOW);
}
