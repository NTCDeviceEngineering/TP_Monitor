/*
 * flash.c
 *
 *  Created on: Nov 18, 2013
 *      Author: IK
 */

#include "flash.h"
#include "io.h"
#include "mainProc.h"
#include "uart.h"
#include "settings.h"

#define START_ADDRESS 	0x10008
#define POWER_INFO		0x10000

void setTimeStamp();

uint8_t txBuffer[10];

//
/*
 *Record format
 * "time stamp x 4 bytes, write type x 1 byte, info x 2 bytes, last byte x 1 byte"
 *
 */
WRITE_RESULT writeRecord(uint32_t writeAddress, uint32_t timeStamp, uint8_t typeWrite, uint16_t info2Bytes, uint8_t lastByte)
{
	static uint8_t *flashPointer;
	static uint8_t *temp;
	static uint8_t i;

	if (checkLocation(writeAddress) == TRUE)
	{
		flashPointer = (uint8_t *)writeAddress;

		_disable_interrupts();
		FCTL3 = FWKEY;
		FCTL1 = FWKEY+WRT;

		//write time stamp
		temp = (uint8_t *)&timeStamp;
		*flashPointer++ = *temp++;
		*flashPointer++ = *temp++;
		*flashPointer++ = *temp++;
		*flashPointer++ = *temp++;

		*flashPointer++ = typeWrite;

		temp = (uint8_t *)&info2Bytes;

		*flashPointer++ = *temp++;
		*flashPointer++ = *temp++;

		*flashPointer++ = lastByte;

		FCTL1 = FWKEY;
		FCTL3 = FWKEY+LOCK;
		_enable_interrupts();

		// verify write
		flashPointer = (uint8_t *)writeAddress;
		temp = (uint8_t *)&timeStamp;

		for(i=0; i<=3; i++)
		{
			if (*flashPointer++ != *temp++)
			{
				return WRITE_FAIL_VERIFY;
			}
		}

		if (*flashPointer++ != typeWrite)
		{
			return WRITE_FAIL_VERIFY;
		}

		temp = (uint8_t *)&info2Bytes;

		for(i=0; i<=1; i++)
		{
			if (*flashPointer++ != *temp++)
			{
				return WRITE_FAIL_VERIFY;
			}
		}

		if (*flashPointer++ != lastByte)
		{
			return WRITE_FAIL_VERIFY;
		}

		setCurrentAddress(writeAddress += 8);
		numOfRecords++;
		return WRITE_SUCCESS;
	}
	else
	{
		return WRITE_LOCATION_FULL;
	}
}

void writeFirstPowerup()
{
	    uint8_t *flashPointer;

		flashPointer = (uint8_t *)POWER_INFO;

		_disable_interrupts();
		FCTL3 = FWKEY;
		FCTL1 = FWKEY+WRT;

		*flashPointer = 0x00;

		FCTL1 = FWKEY;
		FCTL3 = FWKEY+LOCK;
		_enable_interrupts();
}


bool_t checkLocation(uint32_t address2Check)
{
	uint8_t i;

	uint8_t *tempPtr = (uint8_t *)address2Check;

	for (i=0; i <= 7; i++)
	{
		if (*tempPtr++ != 0xFF) // check if location empty
		{
			return FALSE;
		}
	}

	return TRUE;
}


void checkPowerupAddress()
{
	uint8_t *tempPtr = (uint8_t *)POWER_INFO;

	if (*tempPtr != 0xFF)	// not first power-up
	{
		setCurrentAddress(findFirstMemLocation());
	}
	else
	{
		writeFirstPowerup();
		setCurrentAddress(START_ADDRESS);

	}
}

uint32_t findFirstMemLocation()
{
	uint32_t i;
	uint8_t j;
	uint8_t *flashPointer;

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	for (i=START_ADDRESS; i <= 0x14440; i+=8)
	{
		flashPointer  = (uint8_t *)i;

		for(j=0; j <= 7; j++)
		{
			if(*(flashPointer+j) != 0xFF)
			{
				numOfRecords++;
				break;
			}
			else if (j==7)
			{
				setTimeStamp(i-8);
				writeRecord(i, mainTimeStamp, TYPE_POWER_UP, 0xFFFF, 0XFF);
				WDTCTL = WDT_ARST_250;
				return i+8;
			}
		}
	}
	return 0x14440;
}

void setTimeStamp(uint32_t lastGoodAddress)
{
	uint32_t tempTimeStamp;
	uint8_t *tempPtr = (uint8_t *)lastGoodAddress;

	tempTimeStamp = tempPtr[3];
	tempTimeStamp<<=8;
	tempTimeStamp |= tempPtr[2];
	tempTimeStamp<<=8;
	tempTimeStamp |= tempPtr[1];
	tempTimeStamp<<=8;
	tempTimeStamp |= tempPtr[0];
	mainTimeStamp = tempTimeStamp;
}

void startDataDump()
{
	uint8_t *tempPtr;
    uint16_t i;
    uint32_t  txAddress = 0;

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	txBuffer[0] = 0x7F;
	txBuffer[1] = 0x7F;
	tempPtr = (uint8_t *)(&numOfRecords);
	txBuffer[2] = *tempPtr++;
	txBuffer[3] = *tempPtr++;
	sendMessage(txBuffer, 9);

	__delay_cycles(132000);

	txAddress = START_ADDRESS;

	for(i=1; i <= numOfRecords; i++)
	{
		tempPtr = (uint8_t *)txAddress;

		txBuffer[1] = *tempPtr++;
		txBuffer[2] = *tempPtr++;
		txBuffer[3] = *tempPtr++;
		txBuffer[4] = *tempPtr++;
		txBuffer[5] = *tempPtr++;
		txBuffer[6] = *tempPtr++;
		txBuffer[7] = *tempPtr++;
	    txBuffer[8] = *tempPtr++;

	    sendMessage(txBuffer, 9);

		while(txBusy == TRUE);

		__delay_cycles(24000);

		txAddress +=8;
	}

	WDTCTL = WDT_ARST_1000;
}

void eraseData()
{
	  uint32_t i = 0;

	  WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	  uint8_t *Flash_ptr;
	  _disable_interrupts();

	  FCTL3 = FWKEY;

	  for(i=0; i<162; i++)
	  {
		   Flash_ptr = (uint8_t *)(POWER_INFO + (i*512));
		   FCTL1 = FWKEY + ERASE;
		   *Flash_ptr = 0;
		   while(BUSY & FCTL3);
#ifdef DEBUG_CODE
		   R_GREEN_LED_TOGGLE;
#endif
	  }

	  FCTL3 = FWKEY+LOCK;

	_enable_interrupts();

	resetMainProcess();

	checkPowerupAddress();

	WDTCTL = WDT_ARST_1000;
}
