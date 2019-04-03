/*
 * dmay004_lab1_part2.c
 *
 * Created: 4/3/2019 10:13:02 AM
 * Author : ucrcse
 */ 


#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
	
	while(1) {
		tmpB = PINA & 0x01;
		tmpA = PINA & 0x02;
		if ((tmpB == 0x01) & (tmpA == 0x00)) {
			tmpA = 0x01;
		} else {
			tmpA = 0x00;
		}
		PORTB = tmpA;
	}
	return 0;
}