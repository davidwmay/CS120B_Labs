/*
 * dmay004_lab3_part1.c
 *
 * Created: 4/8/2019 9:56:05 AM
 * Author : ucrcse
 */ 

#include <avr/io.h>


unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main() {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	

	
	while (1) {
		for (int i = 0; i < 8; ++i) {
			if (GetBit(PINA, i)) {
				
			}
		}
	}
}

