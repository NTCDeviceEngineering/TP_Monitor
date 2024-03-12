/*
 * clock.c
 *
 *  Created on: Nov 18, 2013
 *      Author: IK
  *  NOTE: this file includes portions of the code
 *  from several files from TI provided as clock
 *  examples and created by:
 *  Bhargavi Nisarga ,Texas Instruments Inc., April 2009
 *  and for those portions following applies:
 *
 * *******************************************************************************
 * --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **************************************************************************************
 */


#include "clock.h"


void initClock()
{
	  P5SEL |= BIT4+BIT5;                       // Port select XT1
	  UCSCTL6 &= ~(XT1OFF);                     // XT1 On
	  UCSCTL6 |= XCAP_3;                        // Internal load cap

	  // Loop until XT1 fault flag is cleared
	  do
	  {
	    UCSCTL7 &= ~XT1LFOFFG;                  // Clear XT1 fault flags
	  }while (UCSCTL7&XT1LFOFFG);               // Test XT1 fault flag

	  // Initialize DCO to 12MHz
	  __bis_SR_register(SCG0);      // Disable the FLL control loop
	  UCSCTL0 = 0x0000;            	// Set lowest possible DCOx, MODx
	  UCSCTL1 = DCORSEL_5;   		// Select DCO range 24MHz operation
	  UCSCTL2 = FLLD_1 + 366;      	// Set DCO Multiplier for 12MHz
	  	  	  	  	  	  	  	  	// (N + 1) * FLLRef = Fdco
	  	  	  	  	  	  	  	  	// (732 + 1) * 32768 = 24MHz
	  	  	  	  	  	  	  	  	// Set FLL Div = fDCOCLK/2


	  __bic_SR_register(SCG0);                  // Enable the FLL control loop

	  // Worst-case settling time for the DCO when the DCO range bits have been
	  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
	  // UG for optimization.
	  // 32 x 32 x 12 MHz / 32,768 Hz = 76563 = MCLK cycles for DCO to settle
	  __delay_cycles(375000);

	  // Loop until XT1,XT2 & DCO fault flag is cleared
	  do
	  {
	    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);
	                                            // Clear XT2,XT1,DCO fault flags
	    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
	  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag


	  UCSCTL4 |= (SELA__XT1CLK + SELS__DCOCLK + SELM__DCOCLK);
}
