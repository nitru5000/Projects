#ifndef _FIFO_H_
#define _FIFO_H_


#define element_type unsigned int
#define width 5
element_type G_buffer[width];

typedef struct {
    element_type *base;
    element_type *head;
    element_type *tail;
    unsigned int count;
    unsigned int length;
} FIFO_t;

typedef enum
{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_STATUS;

FIFO_STATUS FIFO_Init(FIFO_t *fifo_controller, element_type* buffer, unsigned int length);

FIFO_STATUS FIFO_Enqueue(FIFO_t *fifo_controller, element_type data);

FIFO_STATUS FIFO_Dequeue(FIFO_t *fifo_controller, element_type* data);

FIFO_STATUS FIFO_Print(FIFO_t *fifo_controller);
#endif
