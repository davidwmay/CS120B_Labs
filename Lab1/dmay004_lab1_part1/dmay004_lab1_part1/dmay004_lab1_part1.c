

/*
 * Name/Email: David May, dmay004@ucr.edu
 * Lab Section: 026
 * Assignment: Lab 1 Exercise 1
 *
 * Created: 4/3/2019 9:47:58 AM
 * I acknowledge all content contained herein, excluding template or example code, is my own original work.
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
		
	while(1) {
		tempA = PINA & 0x01;
		if (tmpA == 0x01) {
			tmpB = (tmpB & 0xFC) | 0x01;
		} else {
			tmpB = (tmpB & 0xFC) | 0x02;
		}
		PORTB = tmpB;
	}
	return 0;
}

