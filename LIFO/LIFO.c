#include <stdio.h>
#include "LIFO.h"

LIFO_STATUS Lifo_Init(LIFO_t *lifo_controller, Element_type *buffer, unsigned int length)
{   // check if buffer/lifo_controller is valid
    if ( buffer == NULL )
        return LIFO_null;
        
    lifo_controller->base   = buffer;
    lifo_controller->head   = buffer;
    lifo_controller->length = length;
    lifo_controller->count  = 0;

    return LIFO_no_error;

}

LIFO_STATUS Lifo_Push(LIFO_t *lifo_controller, Element_type data)
{
    if ( !lifo_controller->base || !lifo_controller->head)
        return LIFO_null;
    
    // check if lifo is full
    if (lifo_controller->count == lifo_controller->length)
        return LIFO_full;
        
    // add data to the top of the lifo
    *(lifo_controller->head) = data;
    lifo_controller->head++;
    lifo_controller->count++;

    return LIFO_no_error;
}

LIFO_STATUS Lifo_Pop(LIFO_t *lifo_controller, Element_type *data)
{
    if ( !lifo_controller->base || !lifo_controller->head)
        return LIFO_null;
    // check if lifo is empty
    if (lifo_controller->count == 0)
        return LIFO_empty;
        
    lifo_controller->head--;
    *data = *(lifo_controller->head);
    lifo_controller->count--;

    return LIFO_no_error;
}
