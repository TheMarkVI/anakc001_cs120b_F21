/*	Author: Artip Nakchinda
 *  Partner(s) Name: n/a
 *	Lab Section: n/a
 *	Assignment: Lab 2 - Intro to AVR Toolchain
 *	Exercise Description: Exercise 2
 *      - Port A's pins 3 to 0, each connect to a parking space sensor,
 *      - 1 meaning a car is parked in the space, of a four-space parking lot
 *      - Write a program that outputs in binary on port C the number of available
 *          spaces (Hint: declare a variable "unsigned char cntavail;" you can assign a
 *                      number to a port as follows: PORTC = cntavail;)
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0XFF; // Configure port a's 8 pins at inputs
    DDRC = 0xFF; PORTC = 0x00; // configure C as outputs
    
    unsigned char tempA0 = 0x00; // temp variable to hold val of A
    unsigned char tempA1 = 0x00; // same temp as tempA0
    unsigned char tempA2 = 0x00; // same as the other temps
    unsigned char tempA3 = 0x00; 

    unsigned char cntAvail = 0x00;

    PORTC = cntAvail;
    
    /* Insert solution below */
    while (1) {
        // 1: Read input
        tempA0 = PINA & 0x01;
        tempA1 = PINA & 0x02;
        tempA2 = PINA & 0x04;
        tempA3 = PINA & 0x08;

        // 2: Perform computation

        if(tempA0 == 0x00) {
            cntAvail += 1;
        }
        if(tempA1 == 0x00) {
            cntAvail += 1;
        }
        if(tempA2 == 0x00) {
            cntAvail += 1;
        }
        if(tempA3 == 0x00) {
            cntAvail += 1;
        }
        
        // 3: Write to Output
        PORTC = cntAvail;
        cntAvail = 0x00;
    }
    return 1;
}