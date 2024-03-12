/*
 * mainProc.h
 *
 *  Created on: Nov 18, 2013
 *      Author: IK
 */

#ifndef MAINPROC_H_
#define MAINPROC_H_

#include <stdint.h>
#include "typeDef.h"
#include "timers.h"


typedef enum {
	IDLE,
	PIR_TIMEOUT,
	CHECK_PIR_1_SENSOR,
	CHECK_PIR_2_SENSOR,
	CHECK_AD_TIMESTAMP,
	INIT_BATTERY_READ,
	READ_BATTERY_VOLTAGE,
	CHECK_ENCODER,
	CHECK_FOR_ENCODER_TIMEOUT,
	DONE}TP_STATES;

void updateMP();
void setCurrentAddress(uint32_t );
void resetMainProcess();

extern volatile bool_t 		procFlag;
extern uint32_t 	mainTimeStamp;
extern uint16_t 		numOfRecords;

#endif /* MAINPROC_H_ */
