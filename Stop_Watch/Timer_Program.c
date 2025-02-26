
#include "Timer_Interface.h"

void (*GlobalPtrCTCTimer0) (void) = NULL;
void (*GlobalPtrOVTimer0)  (void) = NULL;

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (*GlobalPtrCTCTimer0 != NULL)
	{
		GlobalPtrCTCTimer0();
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11 (void)
{
	if (*GlobalPtrOVTimer0 != NULL)
	{
		GlobalPtrOVTimer0();
	}
}

u8   TIMER_0_u8Get_OV_Flag(void)
{
    return GET_BIT(TIFR,TOV0) ;
}

void TIMER_0_VoidClear_OV_Flag (void)
{
	SET_BIT(TIFR,TOV0);
}

void TIMER_0_VoidClear_CTC_Flag (void)
{
	SET_BIT(TIFR,OCF0);
}

u8   TIMER_0_u8Get_CTC_Flag(void)
{
    return GET_BIT(TIFR,OCF0) ;
}

void TIMER_0_voidInit(void)
{
#if             TIMER_0_WAVEFORM_GENERATION_MODE	==	TIMER_Normal_Mode
                       CLR_BIT(TCCR0,WGM00);
                       CLR_BIT(TCCR0,WGM01);
                       SET_BIT(TCCR0,FOC0);

           			/*Set the Required Preload Value*/
           			TCNT0 = TIMER_0_PreLoad_OV_Val ;

           			/*Timer0 Overflow Interrupt Enable*/
           			#if   TIMER_0_OV_INTERRUPT == TIMER_OV_Interrupt_Enable
       			     	SET_BIT(TIMSK ,TOIE0) ;
           			#elif TIMER_0_OV_INTERRUPT == TIMER_OV_Interrupt_Disable
           				CLR_BIT(TIMSK ,TOIE0) ;
           			#else
           				#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
           			#endif

#elif           TIMER_0_WAVEFORM_GENERATION_MODE	==	TIMER_PWM_Phase_Correct_Mode
                       SET_BIT(TCCR0,WGM00);
                       CLR_BIT(TCCR0,WGM01);
                       CLR_BIT(TCCR0,FOC0);

                       OCR0 = TIMER_0_PreLoad_CTC_Val ;

              			/*Timer0 Fast PWM Options*/
              			#if   TIMER_0_PWM_PHASE_CORRECT_OPTION == TIMER_OC0_Disconnected
              				CLR_BIT(TCCR0 ,COM00) ;
              				CLR_BIT(TCCR0 ,COM01) ;
              			#elif TIMER_0_PWM_PHASE_CORRECT_OPTION == TIMER_Clear_OC0_on_comp_match
              				CLR_BIT(TCCR0 ,COM00) ;
              				SET_BIT(TCCR0 ,COM01);
	                    #elif TIMER_0_PWM_PHASE_CORRECT_OPTION == TIMER_Set_OC0_on_comp_match
              				SET_BIT(TCCR0 ,COM00);
              				SET_BIT(TCCR0 ,COM01);
              			#else
              				#error "Wrong TIMER_0_PWM_PHASE_CORRECT_OPTION Config"
              			#endif


#elif           TIMER_0_WAVEFORM_GENERATION_MODE	==	TIMER_CTC_Mode
                       SET_BIT(TCCR0,WGM01);
                       CLR_BIT(TCCR0,WGM00);
                       SET_BIT(TCCR0,FOC0);

              			/*Set the Required Preload Value*/
              			OCR0 = TIMER_0_PreLoad_CTC_Val ;

            			/*Timer0 Compare Match Interrupt Enable*/
            			#if   TIMER_0_CTC_INTERRUPT == TIMER_CTC_Interrupt_Enable
       			     	    SET_BIT(TIMSK ,OCIE0) ;
            			#elif TIMER_0_CTC_INTERRUPT == TIMER_CTC_Interrupt_Disable
               				CLR_BIT(TIMSK ,OCIE0) ;
            			#else
            				#error "Wrong TIMER_0_CTC_INTERRUPT Config"
            			#endif

              			/*Timer0 Fast PWM Options*/
              			#if   TIMER_0_CTC_OPTION == TIMER_OC0_Disconnected
              				CLR_BIT(TCCR0 ,COM00) ;
              				CLR_BIT(TCCR0 ,COM01) ;
              			#elif TIMER_0_CTC_OPTION == TIMER_Toggle_OC0_on_comp_match
              				SET_BIT(TCCR0 ,COM00) ;
              				CLR_BIT(TCCR0 ,COM01) ;
	                    #elif TIMER_0_CTC_OPTION == TIMER_Clear_OC0_on_comp_match
              				CLR_BIT(TCCR0 ,COM00) ;
              				SET_BIT(TCCR0 ,COM01) ;
                        #elif TIMER_0_CTC_OPTION == TIMER_Set_OC0_on_comp_match
		                    SET_BIT(TCCR0 ,COM00) ;
		                    SET_BIT(TCCR0 ,COM01) ;
              			#else
              				#error "Wrong TIMER_0_CTC_OPTION Config"
              			#endif


#elif           TIMER_0_WAVEFORM_GENERATION_MODE	==	TIMER_Fast_PWM_Mode
                       SET_BIT(TCCR0,WGM00);
                       SET_BIT(TCCR0,WGM01);
                       CLR_BIT(TCCR0,FOC0);

                       OCR0 = TIMER_0_PreLoad_CTC_Val ;

	                   #if   TIMER_0_FAST_PWM_OPTION == TIMER_OC0_Disconnected
		                    CLR_BIT(TCCR0 ,COM00) ;
		                    CLR_BIT(TCCR0 ,COM01) ;
                      #elif TIMER_0_FAST_PWM_OPTION == TIMER_Clear_OC0_on_comp_match
	                    	CLR_BIT(TCCR0 ,COM00) ;
	                     	SET_BIT(TCCR0 ,COM01);
                      #elif TIMER_0_FAST_PWM_OPTION == TIMER_Set_OC0_on_comp_match
	                     	SET_BIT(TCCR0 ,COM00);
	                    	SET_BIT(TCCR0 ,COM01);
	                  #else
	                    	#error "Wrong TIMER_0_FAST_PWM_OPTION Config"
	                  #endif

#endif

	                    	TCCR0 &= TIMER_0_PRESCALER_MASK ;
	                    	TCCR0 |= TIMER_0_PRESCALER ;
}

void TIMER_0_voidSetOVPreload (u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload ;
}

void TIMER_0_voidSetCTCPreload (u8 Copy_u8CTC)
{
	OCR0 = Copy_u8CTC ;
}


u8 TIMER_0_u8GetCounterValue (void)
{
	return TCNT0 ;
}

void   TIMER_0_VoidCTC_ISR(void (*FuncPtrCTCTimer0)(void) )
{
	GlobalPtrCTCTimer0 = FuncPtrCTCTimer0;
}
void   TIMER_0_VoidOV_ISR(void (*FuncPtrOVTimer0) (void) )
{
	GlobalPtrOVTimer0 = FuncPtrOVTimer0 ;
}

void TIMER_0_VoidPause(void)
{
	TCCR0 &= TIMER_0_PRESCALER_MASK ;
	TCCR0 |= TIMER_0_NO_CLOCK_SOURCE ;
}

void TIMER_0_VoidContinue(void)
{
	TCCR0 &= TIMER_0_PRESCALER_MASK ;
	TCCR0 |= TIMER_0_PRESCALER ;
}

