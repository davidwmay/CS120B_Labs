/*
 * Name/Email: David May, dmay004@ucr.edu
 * Lab Section: 026
 * Assignment: Lab 1 Exercise 2
 *
 * I acknowledge all content contained herein, excluding template or example code, is my own original work.
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmp1 = 0x00;
	unsigned char tmp2 = 0x00;
	unsigned char tmp3 = 0x00;
	unsigned char tmp4 = 0x00;
	unsigned char cntAvail = 0x00;
	
	while(1) {
		cntAvail = 0x00;
		tmp1 = PINA & 0x01;
		tmp2 = PINA & 0x02;
		tmp3 = PINA & 0x04;
		tmp4 = PINA & 0x08;
		if (tmp1 == 0x00) {
			cntAvail = cntAvail + 0x01;
		}
		if (tmp2 == 0x00) {
			cntAvail = cntAvail + 0x01;
		}
		if (tmp3 == 0x00) {
			cntAvail = cntAvail + 0x01;
		}
		if (tmp4 == 0x00) {
			cntAvail = cntAvail + 0x01;
		}
		if (cntAvail == 0x00) {
			cntAvail = cntAvail + 0x80;
		}
	PORTC = cntAvail;
	}
	return 0;
}
