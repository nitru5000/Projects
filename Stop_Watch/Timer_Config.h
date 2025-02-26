/*
 * Timer_Config.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/************************************************** Timer_0 ***************************************/

    #define TIMER_0_PreLoad_OV_Val                               0
    #define TIMER_0_PreLoad_CTC_Val                              244

    #define TIMER_0_PRESCALER                              TIMER_0_PreScaler_1024
/* CHOOSE BETWEEN :
	 TIMER_0_NO_CLOCK_SOURCE
	 TIMER_0_NO_PRESCALER
	 TIMER_0_PreScaler_8
	 TIMER_0_PreScaler_64
	 TIMER_0_PreScaler_256
	 TIMER_0_PreScaler_1024
	 TIMER_0_External_Source_Falling
	 TIMER_0_External_Source_Raising
*/
    #define TIMER_0_OV_INTERRUPT                           TIMER_OV_Interrupt_Disable

	/* Choose between
	 * 1. TIMER_OV_Interrupt_Enable
	 * 2. TIMER_OV_Interrupt_Disable
	 */

    #define TIMER_0_CTC_INTERRUPT                         TIMER_CTC_Interrupt_Enable

	/* Choose between
	 * 1. TIMER_CTC_Interrupt_Enable
	 * 2. TIMER_CTC_Interrupt_Disable
	 */


	#define TIMER_0_WAVEFORM_GENERATION_MODE		      TIMER_CTC_Mode

	/*Set Timer0 Waveform Generation Mode
	 * Choose between
	 * 1. TIMER_Normal_Mode
	 * 2. TIMER_PWM_Phase_Correct_Mode
	 * 3. TIMER_CTC_Mode
	 * 4. TIMER_Fast_PWM_Mode
	 */

    #define  TIMER_0_PWM_PHASE_CORRECT_OPTION             TIMER_Set_OC0_on_comp_match

	/*Set CTC Mode Option
	 * Choose between
	 * 1. TIMER_OC0_Disconnected
	 * 2. TIMER_Clear_OC0_on_comp_match
	 * 3. TIMER_Set_OC0_on_comp_match
	 */

    #define  TIMER_0_CTC_OPTION                           TIMER_OC0_Disconnected

	/*Set CTC Mode
	 * Choose between
	 * 1. TIMER_OC0_Disconnected
	 * 2. TIMER_Toggle_OC0_on_comp_match
	 * 3. TIMER_Clear_OC0_on_comp_match
	 * 4. TIMER_Set_OC0_on_comp_match
	 */


    #define  TIMER_0_FAST_PWM_OPTION                      TIMER_Clear_OC0_on_comp_match

	/*Set CTC Mode Option
	 * Choose between
	 * 1. TIMER_OC0_Disconnected
	 * 2. TIMER_Clear_OC0_on_comp_match
	 * 3. TIMER_Set_OC0_on_comp_match
	 */


#endif /* TIMER_CONFIG_H_ */
