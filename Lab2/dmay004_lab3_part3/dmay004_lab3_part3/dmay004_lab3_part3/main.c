/*	Partner 1 Name & E-mail: David May; dmay004@ucr.edu
 *	Partner 2 Name & E-mail: 
 *	Lab Section: 026
 *	Assignment: Lab 3  Exercise 3
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}


int main() {
	DDRA = 0x00; PORTA = 0xFF; // output, set depending on PORTC values
	DDRC = 0xFF; PORTC = 0x00; // input, check to find fuel level 
	unsigned char tmpOutput = 0x00;
	unsigned char tmpSeatBelt = 0x00;
	unsigned char tmpIgnition = 0x00;
	unsigned char tmpDriver = 0x00;
	
		
	while (1) {
		tmpOutput = 0x00;
		
		tmpSeatBelt = PINA & 0x40;
		tmpIgnition = PINA & 0x10;
		tmpDriver = PINA & 0x20;
		
		if (GetBit(tmpIgnition, 0) && GetBit(tmpDriver, 0) && (!GetBit(tmpSeatBelt, 0))) {
			SetBit(tmpOutput, 7, 1);
		}
		
		if (PINA >= 13 && PINA <= 15) {
			//light 5-0
			tmpOutput = SetBit(tmpOutput, 5, 1);
			tmpOutput = SetBit(tmpOutput, 4, 1);
			tmpOutput = SetBit(tmpOutput, 3, 1);
			tmpOutput = SetBit(tmpOutput, 2, 1);
			tmpOutput = SetBit(tmpOutput, 1, 1);
			tmpOutput = SetBit(tmpOutput, 0, 1);
		} else if (PINA >= 10 && PINA <= 15) {
			//light 5-1
			tmpOutput = SetBit(tmpOutput, 5, 1);
			tmpOutput = SetBit(tmpOutput, 4, 1);
			tmpOutput = SetBit(tmpOutput, 3, 1);
			tmpOutput = SetBit(tmpOutput, 2, 1);
			tmpOutput = SetBit(tmpOutput, 1, 1);
 		} else if (PINA >= 7 && PINA <= 15) {
			//light 5-2
			tmpOutput = SetBit(tmpOutput, 5, 1);
			tmpOutput = SetBit(tmpOutput, 4, 1);
			tmpOutput = SetBit(tmpOutput, 3, 1);
			tmpOutput = SetBit(tmpOutput, 2, 1);
		} else if (PINA >= 5 && PINA <= 15) {
			//light 5-3
			tmpOutput = SetBit(tmpOutput, 5, 1);
			tmpOutput = SetBit(tmpOutput, 4, 1);
			tmpOutput = SetBit(tmpOutput, 3, 1);
		} else {
			tmpOutput = SetBit(tmpOutput, 6, 1);
			
			if (PINA >= 3) {
				//light 5-4
				tmpOutput = SetBit(tmpOutput, 5, 1);
				tmpOutput = SetBit(tmpOutput, 4, 1);			
			} else if (PINA >= 1 && PINA <= 15) {
				//light 5
				tmpOutput = SetBit(tmpOutput, 5, 1);
			}
			
		}
		
		PORTC = tmpOutput;
	}
	
	return 0;
}