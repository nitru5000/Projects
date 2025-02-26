#ifndef _LIFO_H_
#define _LIFO_H_

#define Element_type unsigned int

typedef struct
{
	Element_type *base;
	Element_type *head;
    unsigned int count;
    unsigned int length;
} LIFO_t;

typedef enum 
{
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null
}LIFO_STATUS;

LIFO_STATUS Lifo_Init(LIFO_t *lifo_controller, Element_type* buffer, unsigned int length);
LIFO_STATUS Lifo_Push(LIFO_t *lifo_controller, Element_type data);
LIFO_STATUS Lifo_Pop(LIFO_t *lifo_controller, Element_type* data);

#endif
