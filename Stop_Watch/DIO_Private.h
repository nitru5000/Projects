

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_



typedef enum
{
	INPUT , //0
	OUTPUT, //1
} DIO_Direction;

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
}DIO_Port;

typedef enum
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
} DIO_Pin;


#endif /* DIO_PRIVATE_H_ */
