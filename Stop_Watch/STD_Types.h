 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for AVR
 *
 * 
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#define HIGH        (1u)
#define LOW         (0u)
#define NULL        (0u)

typedef unsigned char         u8;          /*           0 .. 255             */
typedef signed char           s8;          /*        -128 .. +127            */
typedef unsigned short        u16;         /*           0 .. 65535           */
typedef signed short          s16;         /*      -32768 .. +32767          */
typedef unsigned long         u32;         /*           0 .. 4294967295      */
typedef signed long           s32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    u64;         /*       0..18446744073709551615  */
typedef signed long long      s64;
typedef float                 f32;
typedef double                f64;

#endif /* STD_TYPE_H_ */
