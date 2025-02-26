#include "FIFO.h"
#include "stdio.h"

void main(void)
{
    FIFO_t UART_fifo;
    unsigned data, temp;

    if (FIFO_Init(&UART_fifo, G_buffer, width) == FIFO_no_error)
        printf("FIFO intit --------> Done \n");

    // storing data into G_buffer
    for (data = 0; data < 7; data++)
    {
        printf("  FIFO_Enqueue (%d) \n", data);
        if (FIFO_Enqueue(&UART_fifo, data) == FIFO_no_error)
            printf("  FIFO_Enqueue-------> DONE \n");
        else
            printf(" FIFO_Enqueue-------> Failed\n ");
    }
    // printing data from G_buffer
    FIFO_Print(&UART_fifo);

    // removing data from G_buffer
    if (FIFO_Dequeue(&UART_fifo, &temp) == FIFO_no_error)
        printf("  FIFO_Dequeue-------> DONE \n");
    if (FIFO_Dequeue(&UART_fifo, &temp) == FIFO_no_error)
        printf("  FIFO_Dequeue-------> DONE \n");

    // printing remaining data from G_buffer
    FIFO_Print(&UART_fifo);
}
