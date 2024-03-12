/*
 * uart.c
 *
 *  Created on: Nov 21, 2013
 *      Author: IK
 */

#include "uart.h"

uint8_t rxBuffer[10];
uint8_t rxIndex=0;
bool_t dataReady = FALSE;
bool_t startOfFrameDetected = FALSE;

uint8_t *txDataPtr;
uint8_t txDataLength;
uint8_t txCounter;
bool_t txBusy = FALSE;

void initUart()
{
	  P3SEL = BIT3+BIT4;                        // select uart function for 3.3 and 3.4

	  UCA0CTL1 |= UCSWRST;
	  UCA0CTL1 |= UCSSEL__SMCLK;
	  UCA0BR0 = 0xE2;                           // 9600 @ 12MHz
	  UCA0BR1 = 0x04;
	  UCA0MCTL |= UCBRS_0 + UCBRF_0;
	  UCA0CTL1 &= ~UCSWRST;
	  UCA0IE |= UCRXIE;

}


void sendMessage(uint8_t *data, uint8_t length)
{
	txDataPtr = data;
	txDataLength = length;
	txCounter = 0;
	txBusy = TRUE;
	UCA0IE |= UCTXIE;
}


#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
  switch(__even_in_range(UCA0IV,4))
  {
  case 0:break;

  case 2:                                   // RX

	  rxBuffer[rxIndex] = UCA0RXBUF;

	  if((rxIndex == 0 ) && (rxBuffer[0] == 0x7F) && ( startOfFrameDetected == FALSE))
	  {
		  startOfFrameDetected = TRUE;
		  rxIndex++;
	  }
	  else if ((rxIndex >= 1) && (startOfFrameDetected == TRUE))
	  {
		  rxIndex = 0;
		  startOfFrameDetected = FALSE;
		  dataReady = TRUE;
	  }
	  else if (startOfFrameDetected == TRUE)
	  {
		  rxIndex++;
	  }
	  else
	  {
		  rxIndex = 0;
		  startOfFrameDetected = FALSE;
	  }

    break;

  case 4:	                                // TX

	  UCA0TXBUF = *txDataPtr++;
	  if(txCounter++ >= txDataLength)
	  {
		  UCA0IE &= ~UCTXIE;
		  txBusy = FALSE;
	  }
	  break;

  default: break;
  }
}

uint8_t getDataRx()
{
	return rxBuffer[1];
}

