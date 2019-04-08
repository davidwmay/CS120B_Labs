/*
 * dmay004_lab3_part2.c
 *
 * Created: 4/8/2019 10:29:01 AM
 * Author : ucrcse
 */ 

#include <avr/io.h>



int main() {
	DDRA = 0x00; PORTA = 0xFF; // output, set depending on PORTC values
	DDRC = 0xFF; PORTC = 0x00; // input, check to find fuel level 
	unsigned char tmpB = 
	unsigned char tmpC = 0x00;
	
	while (1) {
		
	}
	
	return 0;
}
