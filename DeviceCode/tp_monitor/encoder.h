/*
 * encoder.h
 *
 *  Created on: Feb 26, 2014
 *      Author: IK
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <msp430.h>
#include <stdint.h>
#include "io.h"
#include "typeDef.h"
#include "flash.h"


void setEncData();
void resetEncDataTimer();
void setEncoder();
WRITE_RESULT writeEncData(uint32_t wAddress, uint32_t timeStamp);

extern bool_t newEncDataReady;

extern bool_t motionDataActive;

#endif /* ENCODER_H_ */
