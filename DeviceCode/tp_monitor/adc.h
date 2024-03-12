/*
 * adc.h
 *
 *  Created on: Mar 3, 2014
 *      Author: IVAN_Development
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <msp430.h>
#include "typeDef.h"

#define LOW_BATT_LEVEL	3230

uint16_t getBatteryVoltage();
void startBatteryCheck();
void initADC();

extern bool_t batteryDataReady;

#endif /* ADC_H_ */
