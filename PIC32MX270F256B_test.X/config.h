/* 
 * File:   config.h
 * Author: ??
 *
 * Created on 2017/03/13, 11:16
 */

#ifndef CONFIG_H
#define	CONFIG_H



#pragma config FNOSC = PRIPLL
#pragma config POSCMOD = HS
#pragma config FPLLIDIV = DIV_2

#pragma config FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1
#pragma config FPLLODIV = DIV_2

#pragma config FWDTEN = OFF
#pragma config ICESEL = ICS_PGx3



/*
// Configuration Bit settings
// DEVCFG3:
#pragma config IOL1WAY  = OFF           // Peripheral Pin Select Configuration
// DEVCFG2:
#pragma config FPLLODIV = DIV_2         // PLL Output Divider
#pragma config UPLLEN   = OFF           // USB PLL Enabled
#pragma config UPLLIDIV = DIV_2         // USB PLL Input Divider
#pragma config FPLLMUL  = MUL_20        // PLL Multiplier
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider
// DEVCFG1:
#pragma config FWDTEN   = OFF           // Watchdog Timer
#pragma config WDTPS    = PS1           // Watchdog Timer Postscale
#pragma config FCKSM    = CSDCMD        // Clock Switching & Fail Safe Clock Monitor
#pragma config FPBDIV   = DIV_1         // Peripheral Clock divisor
#pragma config OSCIOFNC = OFF           // CLKO Enable
#pragma config POSCMOD  = OFF           // Primary Oscillator
#pragma config IESO     = OFF           // Internal/External Switch-over
#pragma config FSOSCEN  = OFF           // Secondary Oscillator Enable (KLO was off)
#pragma config FNOSC    = FRCPLL        // Oscillator Selection
// DEVCFG0:
#pragma config CP       = OFF           // Code Protect
#pragma config BWP      = ON            // Boot Flash Write Protect
#pragma config PWP      = OFF           // Program Flash Write Protect
#pragma config ICESEL   = ICS_PGx3      // ICE/ICD Comm Channel Select
#pragma config JTAGEN   = OFF           // JTAG Enable
#pragma config DEBUG    = OFF           // Background Debugger Enable
*/


#pragma interrupt T2Handler IPL1AUTO
#pragma vector T2Handler 8

#pragma interrupt U1RXHandler IPL2AUTO
#pragma vector U1RXHandler 32

#endif	/* CONFIG_H */

