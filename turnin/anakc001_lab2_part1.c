/*	Author: Artip Nakchinda
 *  Partner(s) Name: n/a
 *	Lab Section: n/a
 *	Assignment: Lab 2 - Intro to AVR Toolchain
 *	Exercise Description: Exercise 1 - Garage open at night
 *      - Garage door sensor connects to PA0 (1 = door open)
 *      - Light sensor connects to PA1 (1 = light is sensed)
 *      - Write a program that illuminates an LED connected to PB0 (1 = illuminate)
 *          if garage is open at night
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0XFF; // Configure port a's 8 pins at inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port b's 8 pins as outputs, initialize
    
    unsigned char tempA = 0x00; // temp variable to hold val of A
    unsigned char tempB = 0x00; // temp variable to hold val of B

    /* Insert your solution below */
    while (1) {
        // 1: Read input
        tempA = PINA & 0x01;
        tempB = PINA & 0x02;

        // 2: Perform computation
        if(tempA == 0x01 && tempB == 0x00) { // pin 0x01 (A0). pin 0x02 (A1)
                                            // if A0 == 0x01 AND A1 == 0x00, then PB0 = 1
            PORTB = 0x01; // LED on
        }
        else {
            PORTB = 0x00; // LED off
        }
        // Just need one 'if' case. 
        // The rest of the cases do not have the LED illuminating (PB0 = 0)
    }
    return 1;
}
