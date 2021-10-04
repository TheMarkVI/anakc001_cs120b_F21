/*	Author: Artip Nakchinda
 *  Partner(s) Name: n/a
 *	Lab Section: n/a
 *	Assignment: Lab 2 - Intro to AVR Toolchain
 *	Exercise Description: Exercise 3
 *      - Extend from Exercise 2
 *      - still write the available spaces number, but only to PC3-0
 *      - Set PC7 = 1 if lot is full
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
    unsigned char tempA = 0x00;

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
        
        if(cntAvail == 0x00) {
            PORTC = 0x80;
        }
        cntAvail = 0x00;
    }
    return 1;
}