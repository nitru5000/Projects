/*
 * EXTI_Register.h
 *
 *  Created on: ???/???/????
 *      Author: Lenovo
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define SREG                       *(  (volatile u8*) 0x5F)

#define MCUCR                      *(  (volatile u8*) 0x55)

#define MCUCSR                     *(  (volatile u8*) 0x54)

#define GICR                       *(  (volatile u8*) 0x5B)

#define GIFR                       *(  (volatile u8*) 0x5A)

#endif /* EXTI_REGISTER_H_ */
