/* 
 * File:   pwm.h
 * Author: sanada
 *
 * Created on 2017/09/08, 14:36
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

void pwm_init();

void pwm(int val, int rp);


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

