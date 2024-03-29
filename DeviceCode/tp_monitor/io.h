/*
 * io.h
 *
 *  Created on: Oct 7, 2013
 *      Author: IK
 */

#ifndef IO_H_
#define IO_H_

#include <msp430.h>
#include <stdint.h>


//PORT 1

// RED LED
#define RED_LED_BIT  		BIT0
#define RED_LED_PORT		P1OUT
#define RED_LED_ON			(RED_LED_PORT &= ~RED_LED_BIT)
#define RED_LED_OFF		    (RED_LED_PORT |= RED_LED_BIT)
#define RED_LED_TOGGLE  	(RED_LED_PORT ^= RED_LED_BIT)

// left GREEN LED

#define L_GREEN_LED_BIT  		BIT4
#define L_GREEN_LED_PORT		P4OUT
#define L_GREEN_LED_ON			(L_GREEN_LED_PORT |= L_GREEN_LED_BIT)
#define L_GREEN_LED_OFF			(L_GREEN_LED_PORT &= ~L_GREEN_LED_BIT)
#define L_GREEN_LED_TOGGLE  	(L_GREEN_LED_PORT ^= L_GREEN_LED_BIT)


// right GREEN LED

#define R_GREEN_LED_BIT  		BIT5
#define R_GREEN_LED_PORT		P4OUT
#define R_GREEN_LED_ON			(R_GREEN_LED_PORT |= R_GREEN_LED_BIT)
#define R_GREEN_LED_OFF			(R_GREEN_LED_PORT &= ~R_GREEN_LED_BIT)
#define R_GREEN_LED_TOGGLE  	(R_GREEN_LED_PORT ^= R_GREEN_LED_BIT)


// ENCODER DEFINITIONS
// ENCODER 1
#define ENCODER_1_A_BIT  		BIT1
#define ENCODER_1_A_PORT		P2IN
#define IS_ENCODER_1_A_ACTIVE	((ENCODER_1_A_PORT) & (ENCODER_1_A_BIT))
#define ENABLE_ENC_1_A 			P2IES &= ~ENCODER_1_A_BIT;  P2IFG &= ~ENCODER_1_A_BIT; P2IE |= ENCODER_1_A_BIT
#define DISABLE_ENC_1_A			P2IE &= ~ENCODER_1_A_BIT

#define ENCODER_1_B_BIT  		BIT2
#define ENCODER_1_B_PORT		P2IN
#define IS_ENCODER_1_B_ACTIVE	((ENCODER_1_B_PORT) & (ENCODER_1_B_BIT))
#define ENABLE_ENC_1_B 			P2IES &= ~ENCODER_1_B_BIT;  P2IFG &= ~ENCODER_1_B_BIT; P2IE |= ENCODER_1_B_BIT
#define DISABLE_ENC_1_B			P2IE &= ~ENCODER_1_B_BIT

#define ENCODER_1_POWER_BIT  	BIT3
#define ENCODER_1_POWER_PORT	P2OUT
#define ENCODER_1_ON			(ENCODER_1_POWER_PORT |= ENCODER_1_POWER_BIT)
#define ENCODER_1_OFF			(ENCODER_1_POWER_PORT &= ~ENCODER_1_POWER_BIT)

// ENCODER 2
#define ENCODER_2_A_BIT  		BIT6
#define ENCODER_2_A_PORT		P2IN
#define IS_ENCODER_2_A_ACTIVE	((ENCODER_2_A_PORT) & (ENCODER_2_A_BIT))
#define ENABLE_ENC_2_A 			P2IES &= ~ENCODER_2_A_BIT;  P2IFG &= ~ENCODER_2_A_BIT; P2IE |= ENCODER_2_A_BIT
#define DISABLE_ENC_2_A			P2IE &= ~ENCODER_2_A_BIT

#define ENCODER_2_B_BIT  		BIT7
#define ENCODER_2_B_PORT		P2IN
#define IS_ENCODER_2_B_ACTIVE	((ENCODER_2_B_PORT) & (ENCODER_2_B_BIT))
#define ENABLE_ENC_2_B 			P2IES &= ~ENCODER_2_B_BIT;  P2IFG &= ~ENCODER_2_B_BIT; P2IE |= ENCODER_2_B_BIT
#define DISABLE_ENC_2_B			P2IE &= ~ENCODER_2_B_BIT

#define ENCODER_2_POWER_BIT  	BIT4
#define ENCODER_2_POWER_PORT	P2OUT
#define ENCODER_2_ON			(ENCODER_2_POWER_PORT |= ENCODER_2_POWER_BIT)
#define ENCODER_2_OFF			(ENCODER_2_POWER_PORT &= ~ENCODER_2_POWER_BIT)


#define PIR_1_BIT  				BIT3
#define PIR_1_PORT				P1IN
#define IS_PIR_1_ACTIVE			((PIR_1_PORT) & (PIR_1_BIT))


#define PIR_2_BIT  				BIT4
#define PIR_2_PORT				P1IN
#define IS_PIR_2_ACTIVE			((PIR_2_PORT) & (PIR_2_BIT))

// POWER CHECK
#define POWER_CHECK_BIT  		BIT1
#define POWER_CHECK_PORT		P1IN
#define IS_POWER_PRESENT	    ((POWER_CHECK_PORT) & (POWER_CHECK_BIT))


// DOOR CHECK // if door high -> encoder 2 active
#define DOOR_BIT  				BIT6
#define DOOR_PORT				P1IN
#define IS_DOOR_HIGH			((DOOR_PORT) & (DOOR_BIT))



void initIO(void);


#endif /* IO_H_ */
