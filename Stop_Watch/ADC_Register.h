/*
 * ADC_Register.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX				*((volatile u8*) 0x27)

#define REFS1         7							//Reference selection bit1
#define REFS0         6							//Reference selection bit0
#define ADLAR         5							//ADC left adjust result

#define ADCSRA				*((volatile u8*) 0x26)

#define ADPS0         0
#define ADPS1         1
#define ADPS2         2
#define ADIE          3
#define ADIF          4
#define ADATE         5
#define ADSC          6
#define ADEN          7

#define ADCH				*((volatile u8*) 0x25)		//ADC high register
#define ADCL				*((volatile u8*) 0x24)		//ADC Low register
#define ADC_LH 		        *((volatile u16*)0x24)		//ADC Low + High

#define SFIOR               *((volatile u8 *)0x50)


#endif /* ADC_REGISTER_H_ */
