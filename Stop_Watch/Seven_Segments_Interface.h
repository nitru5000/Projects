/*
 * Seven_Segments_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */
#include "STD_Types.h"
#include "Common_macros.h"
#include "DIO_Interface.h"


#ifndef SEVEN_SEGMENTS_INTERFACE_H_
#define SEVEN_SEGMENTS_INTERFACE_H_

void SevenSeg_VoidInit     (void);

void SevenSeg_VoidWrite    (u8 number);

void SevenSeg1_VoidEnable  (void);
void SevenSeg1_VoidDisable (void);

void SevenSeg2_VoidEnable  (void);
void SevenSeg2_VoidDisable (void);

void SevenSeg3_VoidEnable  (void);
void SevenSeg3_VoidDisable (void);

void SevenSeg4_VoidEnable  (void);
void SevenSeg4_VoidDisable (void);

#endif /* SEVEN_SEGMENTS_INTERFACE_H_ */
