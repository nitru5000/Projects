#include "LIFO.h"
#include "stdio.h"
#include "stdlib.h"

Element_type buffer_1[5];
void main(void)
{
    LIFO_t I2c_lifo, uart_lifo;
    Element_type items, temp;

    /* push data to LIFO */
    Lifo_Init(&uart_lifo, buffer_1, 5);

    /* dynamic allocation */
    unsigned int *buffer_2 = (unsigned int *)malloc(5 * sizeof(unsigned int));
    Lifo_Init(&I2c_lifo, buffer_2, 5);

    for (items = 0; items < 7; items++)
    {
        if (Lifo_Push(&uart_lifo, items) == LIFO_no_error)
            printf("  UART_LIFO ADD %d \n", items);
    }
    printf(" ========================================= \n");
    /* pop data from LIFO */
    for (items = 0; items < 7; items++)
    {
        if (Lifo_Pop(&uart_lifo, &temp) == LIFO_no_error)
            printf("  UART_LIFO get %d \n", temp);
    }
}
