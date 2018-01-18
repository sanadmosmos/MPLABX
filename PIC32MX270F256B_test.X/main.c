#include <proc/p32mx270f256b.h>
#include <stdio.h>
#include <xc.h>
#include "config.h"
#include "define.h"
#include "uart.h"
#include "timer.h"
#include "pwm.h"

#pragma interrupt T2Handler IPL1AUTO vector 8
#pragma interrupt U1RXHandler IPL2AUTO vector 32

/* VARs ***********************************************************************/

int i = 0;
static unsigned char ch = 'a';


/* INTERRUPTs *****************************************************************/

void T2Handler()
{
    IFS0bits.T2IF = 0;
    
    i++;
}

void U1RXHandler()
{
    //LATBbits.LATB5 = 1;
    
    ch = Getnum1();
    Put1(ch);
    IFS1bits.U1RXIF = 0;
}

/* MAIN ***********************************************************************/

int main()
{
    /* IO CONFIG **************************************************************/
    
    TRISA = 0;
    TRISB = 0;
    PORTA = 0;
    PORTB = 0;
    ANSELA = 0;
    ANSELB = 0;
    
    // OC1
    TRISBbits.TRISB4 = 0;
    // U1RX
    TRISBbits.TRISB13 = 1;
    // U1TX
    TRISBbits.TRISB15 = 0;
    
    // input
    TRISBbits.TRISB7 = 1;
    // LED
    TRISBbits.TRISB5 = 0;
    
    
    /* RPx CONFIG *************************************************************/
    
    // RPB4 OC1
    RPB4R = 0b0101;
    // RPB15 U1TX
    RPB15Rbits.RPB15R = 0b0001;
    // RPB13 U1RX
    U1RXRbits.U1RXR = 0b0011;
    
    
    /* MODULE INITIALIZE ******************************************************/
    
    timer_init(1000);
    pwm_init();
    uart_init(BAUDRATE);
    
    INTCONbits.MVEC = 1;    // Multi Vector Enable
    __builtin_enable_interrupts();  // Interrupt Enable
    
    LATBbits.LATB5 = 0;
    
    while(1)
    {
        if(i >= 1000){
            i = 1;
            LATBbits.LATB5 = 0;//!LATBbits.LATB5;
        }
        /*
        LATBbits.LATB5 = 0;
        if (PORTBbits.RB7) {
            LATBbits.LATB5 = 1;
        }
        pwm(i,PR2);
        */
    }
    return 0;
}