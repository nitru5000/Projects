#include "STD_Types.h"
#include "Common_macros.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "DIO_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Private.h"



#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

void Keypad_VoidInoit(void);
u8   Keypad_u8GetPressedKey (void);

#endif /* KEYPAD_INTERFACE_H_ */
