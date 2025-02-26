/*
 * Timer_Private.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
      /* TIMSK*/
	#define TOIE0		0
	#define OCIE0		1
	#define TOIE1		2
	#define OCIE1B	    3
	#define OCIE1A	    4
	#define TICIE1	    5
	#define TOIE2		6
	#define OCIE2		7


    /*TIFR*/
	#define TOV0		0
	#define OCF0		1
	#define TOV1		2
	#define OCF1B		3
	#define OCF1A		4
	#define ICF1		5
	#define TOV2		6
	#define OCV2		7


	/****************************** Timer_0 *************************************/
	#define FOC0                                        7
	#define WGM00		                                6
	#define COM01	                                 	5
	#define COM00	                                	4
	#define WGM01		                                3
	#define CS02                                        2
	#define CS01		                                1
	#define CS00		                                0

    #define TIMER_Normal_Mode                           0
    #define TIMER_PWM_Phase_Correct_Mode                1
    #define TIMER_CTC_Mode                              2
    #define TIMER_Fast_PWM_Mode                         3

    #define TIMER_OV_Interrupt_Enable                   1
    #define TIMER_OV_Interrupt_Disable                  0

    #define TIMER_CTC_Interrupt_Enable                  1
    #define TIMER_CTC_Interrupt_Disable                 0

    #define TIMER_Interrupt_Enable                      1
    #define TIMER_Interrupt_Disable                     0

    #define TIMER_OC0_Disconnected                      0
    #define TIMER_Toggle_OC0_on_comp_match              1
    #define TIMER_Clear_OC0_on_comp_match               2
    #define TIMER_Set_OC0_on_comp_match                 3

    #define Timer_Enable                                1
    #define Timer_Disable                               0

    #define TIMER_0_PRESCALER_MASK					    0b11111000

	#define TIMER_0_NO_CLOCK_SOURCE	 	                0
	#define TIMER_0_NO_PRESCALER       	                1
	#define TIMER_0_PreScaler_8	 	                    2
	#define TIMER_0_PreScaler_64	                    3
	#define TIMER_0_PreScaler_256	                    4
	#define TIMER_0_PreScaler_1024	                    5
	#define TIMER_0_External_Source_Falling	            6
	#define TIMER_0_External_Source_Raising		        7
#endif /* TIMER_PRIVATE_H_ */
