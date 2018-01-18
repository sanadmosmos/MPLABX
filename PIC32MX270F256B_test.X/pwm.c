#include <xc.h>
#include "pwm.h"

void pwm_init()
{
    OC1CON = 0;
    
    OC1CONbits.OCTSEL = 0;
    OC1CONbits.OC32 = 0;
    OC1CONbits.SIDL = 0;
    OC1CONbits.OCM = 0b110;
    OC1CONbits.ON = 1;
    
    OC1R  = 0; // recommend OC1R 0
    OC1RS = 0;  // set duty cycle   PRx / 2 = 50%
}

void pwm(int val, int rp)
{
    val = (val >= rp) ? rp : val;
    
    OC1RS = val;
}