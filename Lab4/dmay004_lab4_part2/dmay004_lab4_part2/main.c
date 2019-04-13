/*	Partner 1 Name & E-mail: David May; dmay004@ucr.edu
 *	Partner 2 Name & E-mail: Erin Wong; ewong012@ucr.edu
 *	Lab Section: 026
 *	Assignment: Lab 4 Exercise 2
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States{start, ON1, ON2} state;

unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;

void sequence(){
	tmpA = PINA & 0x01;

	switch (state){
		case start:
		state = ON1;
		break;
		
		case ON1:
		if(tmpA){
			state = ON2;
		}
		else if (!tmpA){
			state = ON1;
		}
		break;
		
		case ON2:
		if(tmpA){
			state = ON1;
		}
		else if(!tmpA){
			state = ON2;
		}
		break;
		
		default:
		state = start;
		break;
	}
	
	switch (state){
		case start:
		break;
		
		case ON1:
		tmpB = 0x01;
		break;
		
		case ON2:
		tmpB = 0x02;
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
	state = start;
	while (1)
	{
		sequence();
	}
	return 0;
}
