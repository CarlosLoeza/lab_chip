/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	Demo link: https://www.youtube.com/watch?v=KNp_WaEt0Es
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char led = 0x00;
    unsigned char button = 0x00;

    /* Insert your solution below */
    while (1) {
	// if PA0 is 1, set PB1PB0=01
	// read inputs
	button = ~PINA & 0x0F;
	// if PA1PA0 = 01 or PA1PA0 = 10
	//   set PC6PC5 to 11
	if(button == 1 || button == 2){
	    led = 0x60;	//sets C to 11bbbbbb
	}
	
	// else if PA1PA0 = 11 or PA2PA1PA0 = 100
	//   set PC6PC5PC4 to 111  
	else if (button == 3 || button == 4){
	    led = 0x70;	//sets B to 111bbbbb
	}

	// else if PA2PA1PA0 = 101 or PA2PA1PA0 = 110
	//   set PC6PC5PC4PC3 to 0001
	else if (button == 5 || button == 6){
	    led = 0x38;
	}

	// else if PA3PA2PA1PA0 = 0101 or PA3PA2PA1PA0 = 1000 or PA3PA2PA1PA0 = 1001
	//   set PC6PC5PC4PC3 to 000 0100
	else if (button == 7 || button == 8 || button == 9){
	    led = 0x3C;
	}

	// else if  PA3PA2PA1PA0 = 1010 or PA3PA2PA1PA0 = 1011 or PA3PA2PA1PA0 = 1100
	//   set PC6PC5PC4PC3 to 000 0010
	else if(button == 10 || button == 11 || button == 12){
	    led = 0x3E;
	}

	// else if  PA3PA2PA1PA0 = 1101 or PA3PA2PA1PA0 = 1110 or PA3PA2PA1PA0 = 1111
	//
	else if(button == 13 || button == 14 || button == 15){
	    led = 0x3F;
	}

	else
	    led = 0x40;

	PORTC = led;
    }
    return 1;
}
