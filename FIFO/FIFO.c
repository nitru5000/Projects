/*
 * FIFO.c
 *
 *  Created on: Jan 1, 2025
 *      Author: Leno007
 */


#include "FIFO.h"
#include "stddef.h"
#include "stdio.h"

FIFO_STATUS FIFO_Init(FIFO_t *fifo_controller, element_type *buffer, unsigned int length)
{
    if (buffer == NULL)
        return FIFO_null;

    fifo_controller->base = buffer;
    fifo_controller->head = buffer;
    fifo_controller->tail = buffer;
    fifo_controller->length = length;
    fifo_controller->count = 0;

    return FIFO_no_error;
}

FIFO_STATUS FIFO_Enqueue(FIFO_t *fifo_controller, element_type data)
{
    if (!fifo_controller->base || !fifo_controller->head || !fifo_controller->tail)
        return FIFO_null;

    if (fifo_controller->count == fifo_controller->length)
        return FIFO_full;

    *(fifo_controller->head) = data;
    fifo_controller->count++;
    // check if fifo is full-------> return to beginning
    if (fifo_controller->head == fifo_controller->base + (fifo_controller->length * sizeof(element_type)))
        fifo_controller->head = fifo_controller->base;
    else
        fifo_controller->head++;

    return FIFO_no_error;
}

FIFO_STATUS FIFO_Dequeue(FIFO_t *fifo_controller, element_type *data)
{
    if (!fifo_controller->base || !fifo_controller->head || !fifo_controller->tail)
        return FIFO_null;
    // check is fifo is empty
    if (fifo_controller->count == 0)
        return FIFO_empty;

    *data = *(fifo_controller->tail);
    fifo_controller->count--;

    if (fifo_controller->tail == fifo_controller->base + (fifo_controller->length * sizeof(element_type)))
        fifo_controller->tail = fifo_controller->base;
    else
        fifo_controller->tail++;
    return FIFO_no_error;
}

 FIFO_STATUS FIFO_Print(FIFO_t *fifo_controller)
 {
    element_type *temp;
    int i;
    if (fifo_controller->count == 0)
    {
        printf("FIFO is empty\n");
        return FIFO_empty;
    }

    else
    {
        temp = fifo_controller->tail;
        printf("\n ======= FIFO Print =======\n");
        for (i = 0; i < fifo_controller->count; i++)
        {
            printf("\t %x \n ", *temp);
            temp++;
        }
        printf("===============\n");
    }
}
