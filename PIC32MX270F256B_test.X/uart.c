#include <xc.h>
#include "uart.h"
#include "define.h"

/*
 * ---UART---
 * RPB4 can't use
 */
void uart_init(int baudrate)
{
    IEC1bits.U1RXIE = 1;
    IFS1bits.U1RXIF = 0;
    IPC8bits.U1IP = 2;
    
    U1MODE = 0;
    U1MODEbits.ON = 1;
    U1MODEbits.BRGH = 1;
    
    U1STA = 0;
    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;
    
    U1BRG = FCY / (4 * baudrate) - 1;
}

unsigned char Getnum1()
{
    while(U1STAbits.URXDA == 0);
    return U1RXREG;
}

void Put1(unsigned char data)
{
    while(U1STAbits.TRMT == 0);
    U1TXREG = data;
}

void Puts1(unsigned char *data)
{
    while(*data != '\0')
    {
        //while(U1STAbits.UTXBF);
        while(U1STAbits.TRMT == 0);
        U1TXREG = *data++;
    }
}