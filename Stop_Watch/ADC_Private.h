/*
 * ADC_Private.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



typedef enum
{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7,
}ADC_CHANNEL_TYPE;

#define ADC_DISABLE             0
#define ADC_ENABLE              1

#define INT_DISABLE             0
#define INT_ENABLE              1

#define AREF                    0
#define AVCC                    1
#define INTERNAL_2_56           3


#define ADC_PRE_MASK            0b11111000
#define ADC_PRE_2               0b00000000
#define ADC_PRE_4               0b00000010
#define ADC_PRE_8               0b00000011
#define ADC_PRE_16              0b00000100
#define ADC_PRE_32              0b00000101
#define ADC_PRE_64              0b00000110
#define ADC_PRE_128             0b00000111




#define ADC_SINGLE_CONVERSION   0
#define ADC_AUTO_TRIGGER        1

#define ADC_MODE_MASK           0b00011111
#define ADC_FREE_RUNNING        0b00000000
#define ADC_ANALOG_COMPARATOR   0b00100000
#define ADC_EXTI0               0b01000000
#define ADC_TIM0_CTC            0b01100000
#define ADC_TIM0_OVF            0b10000000
#define ADC_TIM1_CTC_CHANNEL_B  0b10100000
#define ADC_TIM1_OVF            0b11000000
#define ADC_TIM1_ICU            0b11100000

#endif /* ADC_PRIVATE_H_ */
