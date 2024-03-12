/*
 * mainProc.c
 *
 *  Created on: Nov 18, 2013
 *      Author: IK
 */

#include "mainProc.h"
#include "flash.h"
#include "io.h"
#include "adc.h"
#include "uart.h"
#include "encoder.h"
#include "settings.h"

void setEncoder();

// timeout intervals
#define BATTERY_INTERVAL		86400
//#define BATTERY_INTERVAL		10
#define PIR_INTERVAL			10
#define ENCODER_INTERVAL		300

//time stamps
uint32_t 			mainTimeStamp 		= 0;
static uint32_t 	encodeerTimeStamp 	= 0;
static uint32_t 	batteryTimeStamp 	= 0;
static uint32_t 	pirTimeStamp 	    = 0;

// system flags
static bool_t 		pir1activated		= FALSE;
static bool_t 		pir2activated		= FALSE;
static bool_t 		pir1enabled			= TRUE;
static bool_t 		pir2enabled			= TRUE;
static bool_t 		adcReadRequest		= FALSE;
bool_t 		battLow						= FALSE;


volatile bool_t 	procFlag 			= FALSE;
static bool_t doorPosition				= TRUE;

// data dump flag
bool_t 		startDataDumpFlag = FALSE;

uint16_t 	numOfRecords;

uint32_t currentAddress;
WRITE_RESULT writeResult;

uint8_t txBuffer[10];

TP_STATES tpMonStates = IDLE;

void updateMP()
{
	static bool_t 		encoderPowered 	= FALSE;
	static uint16_t 	batteryVoltage 	= 0;
	static uint8_t 		rxData 			= 0;

	if (secondCountFlag == TRUE)
	{
		secondCountFlag = FALSE;
		mainTimeStamp++;
	}

	if(dataReady == TRUE)
	{
		dataReady = FALSE;
		rxData = getDataRx();

		if (0x01 == rxData)
		{
			startDataDumpFlag = TRUE;
		}
		else if (0x10 == rxData)
		{
			eraseData();
		}
	}
	else if (startDataDumpFlag == TRUE)
	{
		//mpEnabled = FALSE;
		startDataDumpFlag = FALSE;
		startDataDump();
		//mpEnabled = TRUE;
	}
	else
	{
		//check if door changed position
		if(doorPosition != IS_DOOR_HIGH)
		{
			doorPosition = IS_DOOR_HIGH;
			encoderPowered = FALSE;
			ENCODER_1_OFF;
			ENCODER_2_OFF;
			DISABLE_ENC_1_A;
			DISABLE_ENC_1_B;
			DISABLE_ENC_2_A;
			DISABLE_ENC_2_B;
		}

		switch (tpMonStates)
		{
			case IDLE:

				tpMonStates = PIR_TIMEOUT;
				break;

			case PIR_TIMEOUT:

				if(mainTimeStamp > (pirTimeStamp + PIR_INTERVAL))
				{

					pirTimeStamp = mainTimeStamp;

					if(pir1activated == TRUE)
					{
						pir1activated = FALSE;
					}
					else
					{
						pir1enabled = TRUE;
					}

					if(pir2activated == TRUE)
					{
						pir2activated = FALSE;
					}
					else
					{
						pir2enabled = TRUE;
					}

				}

				tpMonStates = CHECK_PIR_1_SENSOR;

				break;

			case CHECK_PIR_1_SENSOR:

				if(IS_PIR_1_ACTIVE)
				{
#ifdef DEBUG_CODE
					L_GREEN_LED_ON;
#endif
					encodeerTimeStamp = mainTimeStamp;

					if(encoderPowered == FALSE)
					{
						encoderPowered = TRUE;
						setEncoder();
					}

					if( (pir1activated==FALSE) && (pir1enabled == TRUE) )
					{
						pir1activated = TRUE;

						if(pir1enabled == TRUE)
						{
							pir1enabled = FALSE;

							writeResult = writeRecord(currentAddress, mainTimeStamp, TYPE_PIR, PIR_1, 0xFF);

							if (writeResult == WRITE_FAIL_VERIFY) // if fails retry
							{
								currentAddress += 8;

								if (writeRecord(currentAddress, mainTimeStamp, TYPE_PIR, PIR_1, 0xFF) != WRITE_SUCCESS)
								{
									currentAddress = findFirstMemLocation();
								}
							}
						}
					}
				}
				else
				{
#ifdef DEBUG_CODE
					L_GREEN_LED_OFF;
#endif
				_nop();
				}
				tpMonStates = CHECK_PIR_2_SENSOR;

				break;

			case CHECK_PIR_2_SENSOR:

				if(IS_PIR_2_ACTIVE)
				{
#ifdef DEBUG_CODE
					R_GREEN_LED_ON;
#endif
					encodeerTimeStamp = mainTimeStamp;

					if(encoderPowered == FALSE)
					{
						encoderPowered = TRUE;
						setEncoder();
					}

					if(pir2activated==FALSE)
					{
						pir2activated = TRUE;

						if(pir2enabled == TRUE)
						{
							pir2enabled = FALSE;

							writeRecord(currentAddress, mainTimeStamp, TYPE_PIR, PIR_2, 0xFF);

							if (writeResult == WRITE_FAIL_VERIFY) // if fails retry
							{
								currentAddress += 8;

								if (writeRecord(currentAddress, mainTimeStamp, TYPE_PIR, PIR_2, 0xFF) != WRITE_SUCCESS)
								{
									currentAddress = findFirstMemLocation();
								}
							}
						}

					}
				}
				else
				{
#ifdef DEBUG_CODE
					R_GREEN_LED_OFF;
#endif
				_nop();
				}
				tpMonStates = CHECK_AD_TIMESTAMP;

				break;

			case CHECK_AD_TIMESTAMP:

				if((mainTimeStamp > (batteryTimeStamp + BATTERY_INTERVAL)) && (adcReadRequest == FALSE))
				{
					batteryTimeStamp = mainTimeStamp;
					adcReadRequest = TRUE;
				}

				if(adcReadRequest == TRUE)
				{
					tpMonStates = INIT_BATTERY_READ;
				}
				else if (encoderPowered == TRUE)
				{
					tpMonStates = CHECK_ENCODER;
				}
				else
				{
					tpMonStates = DONE;
				}
				break;

			case INIT_BATTERY_READ:

				if (encoderPowered == TRUE)
				{
					startBatteryCheck();
					tpMonStates = READ_BATTERY_VOLTAGE;
					adcReadRequest = FALSE;
				}
				else
				{
					tpMonStates = DONE;
				}

				break;

			case READ_BATTERY_VOLTAGE:

				if(batteryDataReady == TRUE)
				{
					batteryVoltage = getBatteryVoltage();

					if(batteryVoltage <= LOW_BATT_LEVEL)
					{
						battLow = TRUE;

						writeRecord(currentAddress, mainTimeStamp, TYPE_BATT_LEVEL, batteryVoltage, 0xFF);

						if (writeResult == WRITE_FAIL_VERIFY) // if fails retry
						{
							currentAddress += 8;

							if (writeRecord(currentAddress, mainTimeStamp, TYPE_BATT_LEVEL, batteryVoltage, 0xFF) != WRITE_SUCCESS)
							{
								currentAddress = findFirstMemLocation();
							}
						}
					}

					if (encoderPowered == TRUE)
					{
						tpMonStates = CHECK_ENCODER;
					}
					else
					{
						tpMonStates = DONE;
					}
				}

				break;

			case CHECK_ENCODER:

				if(newEncDataReady)
				{
					if(WRITE_FAIL_VERIFY == writeEncData(currentAddress, mainTimeStamp)) // if fails retry
					{
						currentAddress += 8;

						if(WRITE_FAIL_VERIFY == writeEncData(currentAddress, mainTimeStamp)) // if fails again get out and re-check current address
						{
							currentAddress = findFirstMemLocation();
						}
					}
				}

				tpMonStates = CHECK_FOR_ENCODER_TIMEOUT;

				break;

			case CHECK_FOR_ENCODER_TIMEOUT:

				if(mainTimeStamp > (encodeerTimeStamp + ENCODER_INTERVAL))
				{
					encoderPowered = FALSE;
					ENCODER_1_OFF;
					ENCODER_2_OFF;
					DISABLE_ENC_1_A;
					DISABLE_ENC_1_B;
					DISABLE_ENC_2_A;
					DISABLE_ENC_2_B;
				}

				tpMonStates = DONE;

				break;

			case DONE:

				tpMonStates = IDLE;
				break;

			default:
				tpMonStates = IDLE;
		}
	}


}


void setCurrentAddress(uint32_t newAddress)
{
	currentAddress = newAddress;
}

void resetMainProcess()
{
	numOfRecords = 0;

	mainTimeStamp       = 0;
	encodeerTimeStamp 	= 0;
	batteryTimeStamp 	= 0;
	pirTimeStamp 	    = 0;

	pir1activated		= FALSE;
	pir2activated		= FALSE;
	pir1enabled			= TRUE;
	pir2enabled			= TRUE;
	adcReadRequest		= FALSE;
	battLow				= FALSE;
}



