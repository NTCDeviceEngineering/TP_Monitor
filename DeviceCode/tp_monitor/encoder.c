/*
 * encoder.c
 *
 *  Created on: Feb 26, 2014
 *      Author: IK
 */

#include "encoder.h"
#include "timers.h"

volatile int32_t encoder1Count = 0;
volatile int32_t encoder2Count = 0;

uint32_t motionData = 0;

bool_t dataFromEnc1	= 		FALSE;
bool_t dataFromEnc2	= 		FALSE;
bool_t newEncDataReady = 	FALSE;
bool_t motionDirectionCCW = FALSE;
bool_t motionDataActive = 	FALSE;



#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
	switch (__even_in_range(P2IV, 0x10))
	{

		case 0x4:

			if(!(IS_ENCODER_1_B_ACTIVE))
			{
				encoder1Count--;

				if(motionDataActive == TRUE)
				{
					RESET_ENC_DATA_TIMER;
				}
				else
				{
					motionDataActive = TRUE;
					START_ENC_DATA_TIMER;
				}
			}

			P2IFG &= ~BIT1;
			break;

		case 0x6:

			if(!(IS_ENCODER_1_A_ACTIVE))
			{
				encoder1Count++;

				if(motionDataActive == TRUE)
				{
					RESET_ENC_DATA_TIMER;
				}
				else
				{
					motionDataActive = TRUE;
					START_ENC_DATA_TIMER;
				}
			}

			P2IFG &= ~BIT2;
			break;


		case 0x0E:

			if(!(IS_ENCODER_2_B_ACTIVE))
			{
				encoder2Count--;

				if(motionDataActive == TRUE)
				{
					RESET_ENC_DATA_TIMER;
				}
				else
				{
					motionDataActive = TRUE;
					START_ENC_DATA_TIMER;
				}
			}

			P2IFG &= ~BIT6;
			break;

		case 0x10:

			if(!(IS_ENCODER_2_A_ACTIVE))
			{
				encoder2Count++;

				if(motionDataActive == TRUE)
				{
					RESET_ENC_DATA_TIMER;
				}
				else
				{
					motionDataActive = TRUE;
					START_ENC_DATA_TIMER;
				}
			}

			P2IFG &= ~BIT7;
			break;
	}

}

void setEncData()
{

	newEncDataReady = TRUE;
	motionDataActive = FALSE;

	if(encoder1Count!=0)
	{
		dataFromEnc1= TRUE;
		dataFromEnc2= FALSE;

		if (encoder1Count>0)
		{
			motionDirectionCCW = TRUE;
			motionData = encoder1Count;
		}
		else
		{
			motionDirectionCCW = FALSE;
			motionData = -encoder1Count;
		}

 		encoder1Count = 0;
	}
	else if(encoder2Count!=0)
	{
		dataFromEnc2= TRUE;
		dataFromEnc1= FALSE;

		if (encoder2Count>0)
		{
			motionDirectionCCW = TRUE;
			motionData = encoder2Count;
		}
		else
		{
			motionDirectionCCW = FALSE;
			motionData = -encoder2Count;
		}

		encoder2Count = 0;
	}
	else
	{
		newEncDataReady = FALSE;
		dataFromEnc1= FALSE;
		dataFromEnc2= FALSE;
	}
}

void setEncoder()
{
	if(!(IS_DOOR_HIGH))
	{
		ENCODER_2_ON;
		__delay_cycles(12000);
		ENABLE_ENC_2_B;
		ENABLE_ENC_2_A;
	}
	else
	{
		ENCODER_1_ON;
		__delay_cycles(12000);
		ENABLE_ENC_1_B;
		ENABLE_ENC_1_A;
	}
}

WRITE_RESULT writeEncData(uint32_t wAddress, uint32_t timeStamp)
{
	static uint8_t wType;
	static uint8_t lByte;
	WRITE_RESULT wResult;

	if(dataFromEnc1 == TRUE)
	{
		wType = TYPE_MOTION_1;
	}
	else if(dataFromEnc2 == TRUE)
	{
		wType = TYPE_MOTION_2;
	}
	else
	{
		wType = TYPE_ERROR;
	}

	if(motionDirectionCCW == TRUE)
	{
		lByte = MOTION_CCW;
	}
	else
	{
		lByte = MOTION_CW;
	}

	wResult = writeRecord(wAddress, timeStamp, wType ,motionData, lByte);


	newEncDataReady = FALSE;

	return wResult;
}
