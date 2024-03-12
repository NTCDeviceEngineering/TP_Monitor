/*
 * timers.h
 *
 *  Created on: Oct 7, 2013
 *      Author: User
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include <msp430.h>
#include <stdint.h>
#include "typedef.h"


#define RESET_ENC_DATA_TIMER	TA0CCR2 = TA0R + 0xFFFE

#define START_ENC_DATA_TIMER	TA0CCR2 = TA0R + 0xFFFE; TA0CCTL2 = CCIE


void initTimers(void);
void startEncDataTimer();
void resetEncDataTimer();

extern bool_t secondCountFlag;


#endif /* TIMERS_H_ */
