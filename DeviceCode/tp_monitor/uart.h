/*
 * uart.h
 *
 *  Created on: Nov 21, 2013
 *      Author: IK
 */

#ifndef UART_H_
#define UART_H_

#include <msp430.h>
#include <stdint.h>
#include "typeDef.h"


void initUart();
uint8_t getDataRx();
void sendMessage(uint8_t *, uint8_t);

extern bool_t dataReady;
extern bool_t txBusy;

#endif /* UART_H_ */
