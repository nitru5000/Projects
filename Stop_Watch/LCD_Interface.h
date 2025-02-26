#define F_CPU 16000000UL

#include "LCD_Private.h"
#include "LCD_Config.h"

#include "DIO_Interface.h"
#include "util/delay.h"

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_FOUR_BITS                 0x20
#define LCD_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character
#define LCD_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character
#define LCD_DisplayOff_CursorOff      0x08          // turn display off
#define LCD_Clear                     0x01          //replace all characters with ASCII 'space'
#define LCD_EntryMode                 0x06          // shift cursor from left to right on read/write
#define LCD_Home                      0x02          // return cursor to first position on first line
#define LCD_CGRAM                     0x40          // the first Place/Address at CGRAM
#define LCD_SetCursor                 0x80          // set cursor position
#define LCD_FunctionReset             0x30          // reset the LCD
#define LCD_FunctionSet_2Line         0x28          // N=1 , F=0
#define LCD_FunctionSet_1Line         0x20          // N=0 , F=0



void LCD_VoidInit (void);
void LCD_VoidWriteCMD (u8 cmd);
void LCD_VoidSendData (u8 cmd);
void LCD_VoidWriteString(const u8 *str);
void LCD_VoidGoToXY (u8 x ,u8 y);
void LCD_VoidClearScreen(void);
void LCD_VoidSendNumber(u32 Copy_u32Number);

#endif /* LCD_INTERFACE_H_ */
