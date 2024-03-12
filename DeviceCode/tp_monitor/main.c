/*
 * 		main.c
 *
 * 		Author(s):	IK
 */


//*********************************************************************************
// todo:
//
//	Implement low power mode to save some power
//  One way: when encoders power off reduce scan rate to 100-200 ms and sleep in between
//  Other way: when encoders power off enable interupts on PIR and wait for activity in sleep.
//
//*********************************************************************************
#include <msp430.h> 
#include "init.h"
#include "io.h"
#include "settings.h"
#include "mainProc.h"
#include "flash.h"
#include <stdint.h>


uint8_t powerFilter = 0;

int main(void) {

	initMSP();
	RED_LED_ON;
	__delay_cycles(12000000);
	//WDTCTL = WDT_ARST_250;
	RED_LED_OFF;

#ifdef DEBUG_CODE
	L_GREEN_LED_ON;
	__delay_cycles(6000000);
	R_GREEN_LED_ON;
	__delay_cycles(6000000);
	L_GREEN_LED_OFF;
	__delay_cycles(6000000);
	R_GREEN_LED_OFF;
#endif

	checkPowerupAddress();

	while(1)
	{
		if(procFlag == TRUE)
		{
			procFlag = FALSE;

			WDTCTL = WDT_ARST_250;

			if(IS_POWER_PRESENT)
			{
				powerFilter = 0;
				updateMP();
			}
			else
			{
				L_GREEN_LED_ON;
			}

		}
	}
}
