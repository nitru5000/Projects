#include "Timer_Register.h"
#include "Timer_Config.h"
#include "Timer_Private.h"
#include "Common_macros.h"
#include "STD_Types.h"

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_





void TIMER_0_voidInit(void) ;
void TIMER_0_voidSetOVPreload  (u8 Copy_u8Preload) ;
void TIMER_0_voidSetCTCPreload (u8 Copy_u8CTC) ;
u8   TIMER_0_u8GetCounterValue (void) ;
u8   TIMER_0_u8Get_OV_Flag (void);
u8   TIMER_0_u8Get_CTC_Flag(void);
void TIMER_0_VoidClear_OV_Flag (void);
void TIMER_0_VoidClear_CTC_Flag (void);
void TIMER_0_VoidCTC_ISR(void (*PtrFuncTimer0CTC)(void) ) ;
void TIMER_0_VoidOV_ISR (void (*PtrFuncTimer0OV) (void) ) ;
void TIMER_0_VoidPause(void);
void TIMER_0_VoidContinue(void);

#endif /* TIMER_INTERFACE_H_ */
