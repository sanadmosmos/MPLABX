#include <xc.h>
#include "timer.h"

void timer_init(int width)
{
    T2CON = 0;
    PR2 = width;
    
    IPC2bits.T2IP = 1;
    IEC0bits.T2IE = 1;
    IFS0bits.T2IF = 0;
    
    T2CONbits.TCKPS = 0b011;
    T2CONbits.ON = 1;
}