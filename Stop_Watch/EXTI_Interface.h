/*
 * EXTI_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "EXTI_Register.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "STD_Types.h"
#include "Common_macros.h"

void EXTI_GI_Enable    (void);
void EXTI_GI_Disable   (void);

void EXTI_Initialize (void);


void EXTI_0_Enable     (void);
void EXTI_0_Disable   (void);

void EXTI_1_Enable     (void);
void EXTI_1_Disable   (void);

void EXTI_2_Enable     (void);
void EXTI_2_Disable   (void);

void EXTI_0_SendToISR  (void (*FuncPtr1) (void));
void EXTI_1_SendToISR  (void (*FuncPtr2) (void));
void EXTI_2_SendToISR  (void (*FuncPtr3) (void));


#endif /* EXTI_INTERFACE_H_ */
