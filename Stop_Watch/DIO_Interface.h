
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "DIO_Private.h"
#include "DIO_Register.h"
#include "STD_Types.h"
#include "Common_macros.h"

void DIO_SetPotDirection (DIO_Port PORT ,  DIO_Direction DIRECTION);
void DIO_SetPortValue    (DIO_Port PORT ,  u8 Value);

void DIO_SetPinDirection (DIO_Port PORT , DIO_Pin PIN , DIO_Direction DIRECTION);
void DIO_SetPinValue     (DIO_Port PORT , DIO_Pin PIN , u8 Value);

u8 DIO_GetPinValue       (DIO_Port PORT , DIO_Pin PIN);

void DIO_VoidWriteHighNibbles (DIO_Port PORT , u8 Value);
void DIO_VoidWriteLowNibbles  (DIO_Port PORT , u8 Value);
#endif /* DIO_INTERFACE_H_ */
