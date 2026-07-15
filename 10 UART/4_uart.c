#include<stdio.h>

#define UART_TX_REG 0x00
#define UART_RX_REG 0x00
#define UART_BAUD 115200

int main(void){
    char txData = 'A';
    char rxData = 'A';

    printf("UART Baud Rate: %d\n", UART_BAUD);
    printf("Transmitted Data: %c\n", txData);
    printf("Recieved Data: %c\n", rxData);

    return 0;
}