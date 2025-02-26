#include "KEYPAD_Interface.h"


u8 Keypad_u8Buttons [4][4] = { { 1 , 2 , 3 , 4 },
		                       { 5 , 6 , 7 , 8 },
							   { 9 , 0 ,'c','='},
							   {'+','-','/','*'}  };

void Keypad_VoidInoit(void)
{

DIO_SetPinDirection(KEYPAD_ROW_PORT,ROW_1,INPUT);
DIO_SetPinDirection(KEYPAD_ROW_PORT,ROW_2,INPUT);
DIO_SetPinDirection(KEYPAD_ROW_PORT,ROW_3,INPUT);
DIO_SetPinDirection(KEYPAD_ROW_PORT,ROW_4,INPUT);


DIO_SetPinDirection(KEYPAD_COL_PORT,COL_1,INPUT);
DIO_SetPinDirection(KEYPAD_COL_PORT,COL_2,INPUT);
DIO_SetPinDirection(KEYPAD_COL_PORT,COL_3,INPUT);
DIO_SetPinDirection(KEYPAD_COL_PORT,COL_4,INPUT);

}





u8   Keypad_u8GetPressedKey (void)
{
	u8 LOC_u8Flag = 0;
	u8 LOC_u8Row;
	u8 LOC_u8COL;

	u8 LOC_u8Data = NO_DATA ;

	for(LOC_u8Row = 0 + ROW_1 ;LOC_u8Row > ROW_4 - 1 ;LOC_u8Row--)
	{
		DIO_SetPinDirection(KEYPAD_ROW_PORT,LOC_u8Row,OUTPUT);
		DIO_SetPinValue(KEYPAD_ROW_PORT,LOC_u8Row,LOW);

		for (LOC_u8COL = 0 + COL_1 ;LOC_u8COL > COL_4 - 1 ;LOC_u8COL--)
		{
                if(LOC_u8COL == 4)
                	{
                	LOC_u8COL--;
                	if (DIO_GetPinValue(KEYPAD_COL_PORT,LOC_u8COL) == LOW)
                	       {
                	       	_delay_ms(40);

                 	         while(LOW ==  DIO_GetPinValue(KEYPAD_COL_PORT,LOC_u8COL) )

                	          LOC_u8Data = Keypad_u8Buttons [ROW_1 - LOC_u8Row ][COL_1 - 4] ;
                              LOC_u8Flag = 1;
                         	break;
                	       }

                	}


                else if (DIO_GetPinValue(KEYPAD_COL_PORT,LOC_u8COL) == LOW)
                {
                	_delay_ms(40);

                	while(LOW ==  DIO_GetPinValue(KEYPAD_COL_PORT,LOC_u8COL) )

                    LOC_u8Data = Keypad_u8Buttons [ROW_1 - LOC_u8Row ][COL_1 - LOC_u8COL] ;
                   LOC_u8Flag = 1;
                	break;
                }

		}
		DIO_SetPinDirection(KEYPAD_ROW_PORT,LOC_u8Row,INPUT);
             if (LOC_u8Flag == 1)break;
	}
	return LOC_u8Data;

}
