#include "DIO_Interface.h"


void DIO_SetPotDirection (DIO_Port PORT , DIO_Direction DIRECTION)
{
  if (OUTPUT == DIRECTION)
  {
	  switch (PORT)
	  {
	  case PORTA : DDRA = 0xFF;break;
	  case PORTB : DDRB = 0xFF;break;
	  case PORTC : DDRC = 0xFF;break;
	  case PORTD : DDRD = 0xFF;break;
	  }
  }

  else if (INPUT == DIRECTION)
  {
	  switch (PORT)
	  {
	  case PORTA : DDRA = 0x00;break;
	  case PORTB : DDRB = 0x00;break;
	  case PORTC : DDRC = 0x00;break;
	  case PORTD : DDRD = 0x00;break;
	  }
  }
}

/**********************************************************************************************************/

void DIO_SetPortValue (DIO_Port PORT , u8 Value)
{


	if (HIGH == Value)
	{
		switch (PORT)
		{
		  case PORTA : PORTA_ = 0xFF;break;
		  case PORTB : PORTB_ = 0xFF;break;
		  case PORTC : PORTC_ = 0xFF;break;
		  case PORTD : PORTD_ = 0xFF;break;
		}
	}
	else if (LOW == Value)
	{
		switch (PORT)
		{
		  case PORTA : PORTA_ = 0x00;break;
		  case PORTB : PORTB_ = 0x00;break;
		  case PORTC : PORTC_ = 0x00;break;
		  case PORTD : PORTD_ = 0x00;break;
		}
	}
	else
	{
		switch (PORT)
		{
		  case PORTA : PORTA_ = Value;break;
		  case PORTB : PORTB_ = Value;break;
		  case PORTC : PORTC_ = Value;break;
		  case PORTD : PORTD_ = Value;break;
		}
	}

}

/**********************************************************************************************************/

void DIO_SetPinDirection (DIO_Port PORT , DIO_Pin PIN , DIO_Direction DIRECTION)
{
	  if (OUTPUT == DIRECTION)
	  {
		  switch (PORT)
		  {
		  case PORTA : SET_BIT(DDRA,PIN);break;
		  case PORTB : SET_BIT(DDRB,PIN);break;
		  case PORTC : SET_BIT(DDRC,PIN);break;
		  case PORTD : SET_BIT(DDRD,PIN);break;
		  }
	  }

	  else if (INPUT == DIRECTION)
	  {
		  switch (PORT)
		  {
		  case PORTA : CLR_BIT(DDRA,PIN);break;
		  case PORTB : CLR_BIT(DDRB,PIN);break;
		  case PORTC : CLR_BIT(DDRC,PIN);break;
		  case PORTD : CLR_BIT(DDRD,PIN);break;
		  }
	  }

}

/**********************************************************************************************************/
void DIO_SetPinValue     (DIO_Port PORT , DIO_Pin PIN , u8 Value)
{
	if    (HIGH == Value)
	{
		switch (PORT)
		{
		case PORTA : SET_BIT(PORTA_,PIN);break;
		case PORTB : SET_BIT(PORTB_,PIN);break;
		case PORTC : SET_BIT(PORTC_,PIN);break;
		case PORTD : SET_BIT(PORTD_,PIN);break;
		}
	}
	else if (LOW == Value)
	{
		switch (PORT)
		{
		case PORTA : CLR_BIT(PORTA_,PIN);break;
		case PORTB : CLR_BIT(PORTB_,PIN);break;
		case PORTC : CLR_BIT(PORTC_,PIN);break;
		case PORTD : CLR_BIT(PORTD_,PIN);break;
		}
	}

}

/**********************************************************************************************************/
u8 DIO_GetPinValue       (DIO_Port PORT , DIO_Pin PIN)
{
    u8 PinValue = 0 ;
    switch (PORT)
    {
		case PORTA:PinValue = GET_BIT(PINA,PIN);break;
		case PORTB:PinValue = GET_BIT(PINB,PIN);break;
		case PORTC:PinValue = GET_BIT(PINC,PIN);break;
		case PORTD:PinValue = GET_BIT(PIND,PIN);break;

	}
   return PinValue;
}


void DIO_VoidWriteHighNibbles (DIO_Port PORT , u8 Value)
{
	if (PORT <= PORTD)
	{

		Value = (Value<<4) ;
		switch (PORT)
		{
		case PORTA :
			PORTA_&=0x0f;                   // make sure the high bits = 0000
			PORTA_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		case PORTB :
			PORTB_&=0x0f;                   // make sure the high bits = 0000
			PORTB_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		case PORTC :
			PORTC_&=0x0f;                   // make sure the high bits = 0000
			PORTC_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		case PORTD :
			PORTD_&=0x0f;                   // make sure the high bits = 0000
			PORTD_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		default: break ;
		}

	}
}

void DIO_VoidWriteLowNibbles (DIO_Port PORT , u8 Value)
{
	if (PORT <= PORTD)
	{

		Value = 0x0f;
		switch (PORT)
		{
		case PORTA :
			PORTA_&=0xf0;                   // make sure the high bits = 0000
			PORTA_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		case PORTB :
			PORTB_&=0xf0;                    // make sure the high bits = 0000
			PORTB_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		case PORTC :
			PORTC_&=0xf0;                    // make sure the high bits = 0000
			PORTC_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		case PORTD :
			PORTD_&=0xf0;                    // make sure the high bits = 0000
			PORTD_|=Value;			//Set only the high nibble of the port A by the given value
			break ;
		default: break ;
		}

	}
}

