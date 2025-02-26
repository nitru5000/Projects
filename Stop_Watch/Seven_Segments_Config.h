/*
 * Seven_Segments_Config.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */
#include "Seven_Segments_Private.h"
#ifndef SEVEN_SEGMENTS_CONFIG_H_
#define SEVEN_SEGMENTS_CONFIG_H_


//******************************** This Driver is designed for Common Anode only ***********************************************************
//******************************************************************************************************************************************
#define   SEVEVEN_SEGMENTS_1_TYPE COMMON_ANODE
#define   SEVEVEN_SEGMENTS_2_TYPE COMMON_ANODE
#define   SEVEVEN_SEGMENTS_3_TYPE COMMON_ANODE
#define   SEVEVEN_SEGMENTS_4_TYPE COMMON_ANODE
/*
 * OPTIONS:
 *
 * COMMON_CATHODE
 * COMMON_ANODE
 */

//******************************************************************************************************************************************
#define   SEVEN_SEGMENTS_1_POWER_PORT     PORTC
#define   SEVEN_SEGMENTS_1_POWER_PIN      Pin0

#define   SEVEN_SEGMENTS_2_POWER_PORT     PORTC
#define   SEVEN_SEGMENTS_2_POWER_PIN      Pin1

#define   SEVEN_SEGMENTS_3_POWER_PORT     PORTC
#define   SEVEN_SEGMENTS_3_POWER_PIN      Pin2

#define   SEVEN_SEGMENTS_4_POWER_PORT     PORTC
#define   SEVEN_SEGMENTS_4_POWER_PIN      Pin3

// PORT OPTIONS : 1-PORTA 2-PORTB 3-PORTB 4-PORTC
/* PIN  OPTION  :
    Pin0
	Pin1
	Pin2
	Pin3
	Pin4
	Pin5
	Pin6
	Pin7
*/

//******************************************************************************************************************************************
#define   SEVEN_SEGMENTS_DATA_PORT      PORTB
#define   SEVEN_SEGMENTS_DATA_PIN_A     Pin0
#define   SEVEN_SEGMENTS_DATA_PIN_B     Pin1
#define   SEVEN_SEGMENTS_DATA_PIN_C     Pin2
#define   SEVEN_SEGMENTS_DATA_PIN_D     Pin3


// OPTIONS : 1-PORTA 2-PORTB 3-PORTB 4-PORTC
/* PIN  OPTION  :
    Pin0
	Pin1
	Pin2
	Pin3
	Pin4
	Pin5
	Pin6
	Pin7
*/


//******************************************************************************************************************************************



#define SevenSeg_1_State  SevenSeg_Enable
/*
 * OPTIONS :
 * SevenSeg_Enable
 * SevenSeg_Disable
 */

#define SevenSeg_2_State  SevenSeg_Enable
/*
 * OPTIONS :
 * SevenSeg_Enable
 * SevenSeg_Disable
 */

#define SevenSeg_3_State  SevenSeg_Enable

/*
 * OPTIONS :
 * SevenSeg_Enable
 * SevenSeg_Disable
 */

#define SevenSeg_4_State  SevenSeg_Enable

/*
 * OPTIONS :
 * SevenSeg_Enable
 * SevenSeg_Disable
 */


#endif /* SEVEN_SEGMENTS_CONFIG_H_ */
