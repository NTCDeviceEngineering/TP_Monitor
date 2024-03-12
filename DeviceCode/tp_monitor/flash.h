/*
 * flash.h
 *
 *  Created on: Nov 18, 2013
 *      Author: IK
 */

#ifndef FLASH_H_
#define FLASH_H_

#include <stdint.h>
#include <msp430.h>
#include "typeDef.h"

typedef enum {
	WRITE_SUCCESS,
	WRITE_LOCATION_FULL,
	WRITE_FAIL_VERIFY
}WRITE_RESULT;

// write types
#define TYPE_MOTION_1	0xF0
#define TYPE_MOTION_2	0xF1
#define TYPE_PIR		0xF2
#define TYPE_BATT_LEVEL	0xF4
#define TYPE_POWER_UP	0xF8
#define TYPE_ERROR		0x00

// further description
// motion
#define MOTION_CCW		0x00
#define MOTION_CW		0x01
// PIR
#define PIR_1			0xF000
#define PIR_2			0xF001

void flashWrite();
WRITE_RESULT writeRecord(uint32_t, uint32_t, uint8_t, uint16_t, uint8_t );

void checkPowerupAddress();
bool_t checkLocation(uint32_t address2Check);

uint32_t findFirstMemLocation();
void startDataDump();
void eraseData();


#endif /* FLASH_H_ */
