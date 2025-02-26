
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


#define EXTI_0_Init_State   EXTI_Enable
#define EXTI_1_Init_State   EXTI_Enable
#define EXTI_2_Init_State   EXTI_Disable
/*
 *  CHOOSE BETWEEN :
 *
 *  EXTI_Enable
 *  EXTI_Disable
 */


#define EXTI_0_Mode         EXTI_Rising_Edge

/*
 *  EXTI0 Configuration :
 *
 *  EXTI_Low_Level
 *  EXTI_Any_Logical_Change
 *  EXTI_Rising_Edge
 *  EXTI_Falling_Edge
 */



#define EXTI_1_Mode        EXTI_Rising_Edge

/*
 *  EXTI1 Configuration :
 *
 *  EXTI_Low_Level
 *  EXTI_Any_Logical_Change
 *  EXTI_Rising_Edge
 *  EXTI_Falling_Edge
 */

#define EXTI_2_Mode       EXTI_INT2_Falling_Edge

/*
 *  EXTI2 Configuration :
 *
 *  EXTI_INT2_Rising_Edge
 *  EXTI_INT2_Falling_Edge
 */


#endif /* EXTI_CONFIG_H_ */
