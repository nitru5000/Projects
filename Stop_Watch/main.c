#include "util/delay.h"
#include "Seven_Segments_Interface.h"
#include "Timer_Interface.h"
#include "EXTI_Interface.h"

u8 d1  = 0;
u8 d2  = 0;
u8 d3  = 0;
u8 d4  = 0;
u8 counter  = 0;

void StopWatch_stop(void)
{
	TIMER_0_VoidPause();
	 d1  = 0;
     d2  = 0;
	 d3  = 0;
	 d4  = 0;
}

void StopWatch_Cont(void)
{
	TIMER_0_VoidContinue();
}


void Time_Function ()
{
	counter++;

  if(counter == 4)
  {
	  counter = 0;
	  d1++;

	  if( d1 == 10)
	    {
			d1=0;
			d2++;

			if (d2 == 10)
			{
				d2=0;
				d3++;

				if (d3 == 10)
				{
					d3=0;
					d4++;
				}
			}
	    }

  }

}


int main (void)
{
//-----------------------------------------------------------------------------------------------------------------------------------------
// COMMON ANODE (4 DIGITS)7SEGMENTS
SevenSeg_VoidInit();
//-----------------------------------------------------------------------------------------------------------------------------------------
DIO_SetPotDirection(PORTD , INPUT);
DIO_SetPortValue(PORTD ,LOW);
//-----------------------------------------------------------------------------------------------------------------------------------------
EXTI_GI_Enable();
TIMER_0_voidInit();
TIMER_0_VoidCTC_ISR( &Time_Function ) ;
//-----------------------------------------------------------------------------------------------------------------------------------------
EXTI_Initialize();
EXTI_0_SendToISR( &StopWatch_stop);
EXTI_1_SendToISR( &StopWatch_Cont);
//-----------------------------------------------------------------------------------------------------------------------------------------
while (1)
    {


	 PORTC_ = 0b00000001;
	 SevenSeg_VoidWrite(d1);
	 _delay_ms(5);
	 PORTC_ = 0b00000010;
	 SevenSeg_VoidWrite(d2);
	 _delay_ms(5);
	 PORTC_ = 0b00000100;
	 SevenSeg_VoidWrite(d3);
	 _delay_ms(5);
	 PORTC_ = 0b00001000;
	 SevenSeg_VoidWrite(d4);
	 _delay_ms(5);


	    if(HIGH == DIO_GetPinValue(PORTD , PIN_4))
	    {
	    	TIMER_0_VoidPause();
	    }

	}



}
