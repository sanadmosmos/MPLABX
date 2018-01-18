/* 
 * File:   uart.h
 * Author: sanada
 *
 * Created on 2017/09/08, 14:33
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif


void uart_init(int baudrate);

unsigned char Getnum1();

void Put1(unsigned char data);

void Puts1(unsigned char *data);


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

