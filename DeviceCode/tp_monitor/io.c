/*
 * io.c
 *
 *  Created on: Oct 7, 2013
 *      Author: IK
 */


#include "io.h"

void turnOffDevices(void);

void initIO(void)
{
	turnOffDevices();

	// set port 1 outputs
    P1DIR |= (RED_LED_BIT);

    // set port 2 outputs
     P2DIR |= (ENCODER_1_POWER_BIT + ENCODER_2_POWER_BIT);

    // set port 1 outputs
    //P3DIR |= (GREEN_LED_BIT);

     // set port 4 outputs
     P4DIR |= (L_GREEN_LED_BIT + R_GREEN_LED_BIT);
}

void turnOffDevices(void)
{
	//GREEN_LED_OFF;
	RED_LED_OFF;
	ENCODER_1_OFF;
	ENCODER_2_OFF;
}



