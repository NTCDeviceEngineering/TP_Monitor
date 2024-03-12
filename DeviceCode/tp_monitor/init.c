/*
 * init.c
 *
 *  Created on: Oct 7, 2013
 *      Author: User
 */

#include "init.h"
#include "io.h"
#include "adc.h"
#include "timers.h"
#include "uart.h"

void initMSP()
{
	 WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	_disable_interrupts();

	initClock();
	initIO();
	initADC();
	initTimers();
	initUart();

	_enable_interrupts();
}

