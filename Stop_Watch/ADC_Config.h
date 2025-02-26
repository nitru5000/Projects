/*
 * ADC_Config.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define       ADC_Vref      AREF

/*
 *  ADC Reference Voltage Configuration :
 *
 *  AREF
 *  AVCC
 *  INTERNAL_2_56
 */

#define      ADC_PRESCALER   ADC_PRE_64

/*
 *  ADC PRESCALER Configuration :
 *
 * ADC_PRE_2
 * ADC_PRE_4
 * ADC_PRE_8
 * ADC_PRE_16
 * ADC_PRE_32
 * ADC_PRE_64
 * ADC_PRE_128
 */

#define     ADC_MODE   ADC_SINGLE_CONVERSION

/*
 *  ADC MODE Configuration :
 *
 * ADC_SINGLE_CONVERSION
 * ADC_AUTO_TRIGGER
 */

#define     ADC_AUTO_TRIGGER_SOURCE    ADC_FREE_RUNNING
/*
 * ADC_FREE_RUNNING
 * ADC_ANALOG_COMPARATOR
 * ADC_EXTI0
 * ADC_TIM0_CTC
 * ADC_TIM0_OVF
 * ADC_TIM1_CTC_CHANNEL_B
 * ADC_TIM1_OVF
 * ADC_TIM1_ICU
 */

#define     ADC_INTERRUPT   INT_DISABLE

/*
 *  ADC PRESCALER Configuration :
 *
 *INT_DISABLE
 *INT_ENABLE
 */

#endif /* ADC_CONFIG_H_ */
