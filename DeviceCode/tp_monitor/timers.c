/*
 * timers.c
 *
 *  Created on: Oct 7, 2013
 *      Author: IK
 */

#include "timers.h"
#include "io.h"
#include "mainProc.h"
#include "encoder.h"

bool_t secondCountFlag = FALSE;

void initTimers(void)
{
	// init timer A0

	TA0CCR0 = 0xFFFF;
	TA0CTL = TASSEL_1 + MC_2;
	//TA0CCTL0 = CCIE;

	TA0CCR1 = 0x8000;
	TA0CCTL1 = CCIE;

	// init timer A1
	TA1CCR0 = 0xffff;
	TA1CTL = TASSEL_2 + MC_2;

	TA1CCR1 = 60000;
	TA1CCTL1 = CCIE;
}


#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A1 (void)
{
	switch(TA0IV)
	{
		case 2:				// CCR1

			secondCountFlag = TRUE;
			TA0CCR1 += 0x8000;
			break;

		case 4:				// CCR2

			setEncData();
			TA0CCTL2 &= ~CCIE;

			break;

		case 10:			// overflow

			break;
	}


}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A10 (void)
{
	//TA1CCR0 += 12000;
}

#pragma vector=TIMER1_A1_VECTOR
__interrupt void Timer_A11 (void)
{
	switch(TA1IV)
		{
			case 2:				// CCR1

				procFlag = TRUE;
				TA1CCR1 += 60000;
				break;

			case 4:				// CCR2

				break;

			case 10:			// overflow

				break;
		}
}

void startEncDataTimer()
{
	TA0CCR2 = TA0R + 0xFFFE;
	TA0CCTL2 = CCIE;
}

void resetEncDataTimer()
{
	TA0CCR2 = TA0R + 0xFFFE;
}
