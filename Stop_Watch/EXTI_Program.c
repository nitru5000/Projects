/*
 * EXTI_Program.c
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#include "EXTI_Interface.h"

void (*GlobalFuncPtr0) (void) = NULL;
void (*GlobalFuncPtr1) (void) = NULL;
void (*GlobalFuncPtr2) (void) = NULL;

void EXTI_GI_Enable    (void)
{
	SET_BIT(SREG,7);
}

void EXTI_GI_Disable   (void)
{
	CLR_BIT(SREG,7);
}


void EXTI_Initialize (void)
{
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
	CLR_BIT(MCUCSR,0);

/************************************* INT_0 ************************************************/
#if   EXTI_0_Mode == EXTI_Low_Level
	  MCUCR |= EXTI_Low_Level;
#elif EXTI_0_Mode == EXTI_Any_Logical_Change
      MCUCR |= EXTI_Any_Logical_Change;

#elif EXTI_0_Mode == EXTI_Falling_Edge
	  MCUCR |= EXTI_Falling_Edge;
#elif EXTI_0_Mode == EXTI_Rising_Edge
	  MCUCR |= EXTI_Rising_Edge;
#endif


#if    EXTI_0_Init_State  == EXTI_Disable
	   CLR_BIT(GICR,6);
#elif  EXTI_0_Init_State  == EXTI_Enable
	   SET_BIT(GICR,6);
#endif


/************************************* INT_1 ************************************************/
#if   EXTI_1_Mode == EXTI_Low_Level
	  MCUCR |= ( EXTI_Low_Level << 2 );
#elif EXTI_1_Mode == EXTI_Any_Logical_Change
	  MCUCR |= ( EXTI_Any_Logical_Change << 2 );
#elif EXTI_1_Mode == EXTI_Rising_Edge
	  MCUCR |= ( EXTI_Rising_Edge << 2 );
#elif EXTI_1_Mode == EXTI_Falling_Edge
	  MCUCR |= ( EXTI_Falling_Edge << 2 );
#endif

#if    EXTI_1_Init_State  == EXTI_Disable
	   CLR_BIT(GICR,7);
#elif  EXTI_1_Init_State  == EXTI_Enable
	   SET_BIT(GICR,7);
#endif

/************************************* INT_2 ************************************************/
#if   EXTI_2_Mode == EXTI_INT2_Rising_Edge
	  SET_BIT(MCUCSR,6);
#elif EXTI_2_Mode == EXTI_INT2_Falling_Edge
	  CLR_BIT(MCUCSR,6);
#endif

#if    EXTI_2_Init_State  == EXTI_Disable
	   CLR_BIT(GICR,5);
#elif  EXTI_2_Init_State  == EXTI_Enable
	   SET_BIT(GICR,5);
#endif


}


void EXTI_0_Enable    (void)
{
    SET_BIT(GICR,6);
}
void EXTI_0_Disable   (void)
{
	CLR_BIT(GICR,6);
}

void EXTI_1_Enable    (void)
{
	SET_BIT(GICR,7);
}
void EXTI_1_Disable   (void)
{
	CLR_BIT(GICR,7);
}

void EXTI_2_Enable    (void)
{
	SET_BIT(GICR,5);
}
void EXTI_2_Disable   (void)
{
	CLR_BIT(GICR,5);
}

/***********************************************************************************/
void EXTI_0_SendToISR  (void (*FuncPtr0) (void))
{
	GlobalFuncPtr0 = FuncPtr0;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (GlobalFuncPtr0 != NULL)
	{
		GlobalFuncPtr0();
	}
}

/***********************************************************************************/

void EXTI_1_SendToISR  (void (*FuncPtr1) (void))
{
	GlobalFuncPtr1 = FuncPtr1;
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (GlobalFuncPtr1 != NULL)
	{
		GlobalFuncPtr1();
	}
}

/***********************************************************************************/

void EXTI_2_SendToISR  (void (*FuncPtr2) (void))
{
	GlobalFuncPtr2 = FuncPtr2;
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (GlobalFuncPtr2 != NULL)
	{
		GlobalFuncPtr2();
	}
}
