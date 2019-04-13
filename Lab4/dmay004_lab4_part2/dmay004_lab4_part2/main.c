/*	
 *	Partner 1 Name & E-mail: David May; dmay004@ucr.edu
 *	Partner 2 Name & E-mail: Erin Wong; ewong012@ucr.edu
 *	Lab Section: 026
 *	Assignment: Lab 4 Exercise 2
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States{start, increment, decrement, reset} state;

unsigned char incCheck = 0x00;
unsigned char decCheck = 0x00;

unsigned char tmpB = 0x00;
unsigned int checkRst = 0;
unsigned int checkRst2 = 0;
unsigned int rstCheck = 0;

void sequence() {
	incCheck = PINA & 0x01;
	decCheck = PINA & 0x02;

	switch (state) {
		case start:
		if (incCheck) {
			state = increment;
			checkRst = 1;
		} else if (decCheck) {
			state = decrement;
			checkRst2 = 1;
		} else {
			state = start;
		}
		break;

		case increment:
		if (checkRst2) {
			state = reset;
		} else if (incCheck) {
			state = increment;
		} else if (decCheck) {
			state = decrement;
		}
		break;

		case decrement:
		if (checkRst) {
			state = reset;
		} else if (incCheck) {
			state = increment;
		} else if (decCheck) {
			state = decrement;
		}
 		break;
		
		case reset:
		state = reset;
		break;
		
		default:
		state = start;
		break;
	}
	
	switch (state) {
		case start:
		tmpB = 0x07;
		break;
		
		case increment:
		if (tmpB == 9) {
			break;
		} else {
			tmpB += 0x01;
			break;
		}
		
		case decrement:
		if (tmpB == 0) {
			break;
		} else {
			tmpB -= 0x01;
			break;
		}
		
		case reset:
		tmpB = 0x00;
		break;
		
		default:
		break;
	}

	PORTB = tmpB;
}


int main() {
	/* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	tmpB = 0x00;
	incCheck = 0x00;
	decCheck = 0x00;
	rstCheck = 0;
	state = start;
	while (1) {
		sequence();
	}
	return 0;
}
