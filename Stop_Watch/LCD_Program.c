#include "LCD_Interface.h"

u8 G_u8KeyPadFlag = 0;
void LCD_VoidInit (void)
{
	 _delay_ms(50);
DIO_SetPinDirection(LCD_CONTROL_PORT,EN,OUTPUT);
DIO_SetPinDirection(LCD_CONTROL_PORT,RS,OUTPUT);

DIO_SetPinValue(LCD_DATA_PORT,RS,LOW); //RS

DIO_SetPinDirection(LCD_DATA_PORT,D4,OUTPUT);
DIO_SetPinDirection(LCD_DATA_PORT,D5,OUTPUT);
DIO_SetPinDirection(LCD_DATA_PORT,D6,OUTPUT);
DIO_SetPinDirection(LCD_DATA_PORT,D7,OUTPUT);

LCD_VoidWriteCMD (0x30);
 _delay_ms(10);
LCD_VoidWriteCMD (0x30);
_delay_ms(10);
LCD_VoidWriteCMD (0x30);
_delay_ms(10);
LCD_VoidWriteCMD (LCD_FOUR_BITS);

G_u8KeyPadFlag = 1;

LCD_VoidWriteCMD (LCD_FunctionSet_2Line);
LCD_VoidWriteCMD (LCD_DisplayOn_CursorOff);
LCD_VoidWriteCMD (LCD_Clear);
LCD_VoidWriteCMD (LCD_EntryMode);

}

void LCD_VoidWriteCMD (u8 cmd)
{



	DIO_SetPinValue(LCD_DATA_PORT,D4,GET_BIT(cmd,4));
	DIO_SetPinValue(LCD_DATA_PORT,D5,GET_BIT(cmd,5));
	DIO_SetPinValue(LCD_DATA_PORT,D6,GET_BIT(cmd,6));
	DIO_SetPinValue(LCD_DATA_PORT,D7,GET_BIT(cmd,7));

	DIO_SetPinValue(LCD_CONTROL_PORT,EN,HIGH); //EN
     _delay_ms(2);
	DIO_SetPinValue(LCD_CONTROL_PORT,EN,LOW); //EN
	 _delay_ms(1);
	 if (G_u8KeyPadFlag == 1)
	 {
	DIO_SetPinValue(LCD_DATA_PORT,D4,GET_BIT(cmd,0));
	DIO_SetPinValue(LCD_DATA_PORT,D5,GET_BIT(cmd,1));
	DIO_SetPinValue(LCD_DATA_PORT,D6,GET_BIT(cmd,2));
	DIO_SetPinValue(LCD_DATA_PORT,D7,GET_BIT(cmd,3));

	DIO_SetPinValue(LCD_CONTROL_PORT,EN,HIGH); //EN
	 _delay_ms(2);
	DIO_SetPinValue(LCD_CONTROL_PORT,EN,LOW); //EN
	 _delay_ms(10);
	 }

}

void LCD_VoidSendData (u8 cmd)
{
   if (cmd != 0xff )
   {
		DIO_SetPinValue(LCD_CONTROL_PORT,RS,HIGH);


		DIO_SetPinValue(LCD_DATA_PORT,D4,GET_BIT(cmd,4));
		DIO_SetPinValue(LCD_DATA_PORT,D5,GET_BIT(cmd,5));
		DIO_SetPinValue(LCD_DATA_PORT,D6,GET_BIT(cmd,6));
		DIO_SetPinValue(LCD_DATA_PORT,D7,GET_BIT(cmd,7));

		DIO_SetPinValue(LCD_CONTROL_PORT,EN,HIGH); //EN
	     _delay_ms(2);
		DIO_SetPinValue(LCD_CONTROL_PORT,EN,LOW); //EN
		 _delay_ms(1);

		DIO_SetPinValue(LCD_DATA_PORT,D4,GET_BIT(cmd,0));
		DIO_SetPinValue(LCD_DATA_PORT,D5,GET_BIT(cmd,1));
		DIO_SetPinValue(LCD_DATA_PORT,D6,GET_BIT(cmd,2));
		DIO_SetPinValue(LCD_DATA_PORT,D7,GET_BIT(cmd,3));

		DIO_SetPinValue(LCD_CONTROL_PORT,EN,HIGH); //EN
		 _delay_ms(2);
		DIO_SetPinValue(LCD_CONTROL_PORT,EN,LOW); //EN
		 _delay_ms(10);

   }


}



void LCD_VoidGoToXY (u8 x ,u8 y)
{
DIO_SetPinValue(LCD_CONTROL_PORT,RS,LOW); //RS
u8 LOCAL_u8Adrs = 0 ;

switch (y) {
case 0: LOCAL_u8Adrs = 0x00; break; //Starting address of 1st line
case 1: LOCAL_u8Adrs = 0x40; break; //Starting address of 2nd line
case 2: LOCAL_u8Adrs = 0x14; break; //Starting address of 3rd line
case 3: LOCAL_u8Adrs = 0x54; break; //Starting address of 4th line
           }
LOCAL_u8Adrs +=x;

u8 cmd = 0x80 | LOCAL_u8Adrs ;
LCD_VoidWriteCMD (cmd);

}

void LCD_VoidWriteString(const u8 *str)
{

	DIO_SetPinValue(LCD_CONTROL_PORT,RS,HIGH);
	u8 LOC_u8Iterator = 0 ;
	while(str[LOC_u8Iterator] != '\0')
	{
		LCD_VoidWriteCMD(str[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}


void LCD_VoidClearScreen(void)
{
DIO_SetPinValue(LCD_CONTROL_PORT,RS,LOW); //RS
LCD_VoidWriteCMD(LCD_Clear);
_delay_ms(10);
}

void LCD_VoidSendNumber(u32 Copy_u32Number)
{

	u32 LOC_u32Reversed = 1 ;

	if( Copy_u32Number == 0 ){ LCD_VoidSendData('0'); }

	else{

		while( Copy_u32Number != 0 )
		{

			LOC_u32Reversed = ( LOC_u32Reversed * 10 ) + ( Copy_u32Number % 10 );
			Copy_u32Number /= 10 ;

		}
		while( LOC_u32Reversed != 1 )
		{

			LCD_VoidSendData( ( LOC_u32Reversed % 10 ) + 48 );
			LOC_u32Reversed /= 10 ;

		}

	}


}
