/*
 * DA2AT2_C.c
 *
 * Created: 2/24/2020 10:07:04 PM
 * Author : c1029
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= (1 << 2); //set PORTB.2 as output.
	PORTB |= (1 << 2);
	
	DDRC &= (0 << 3); //set PORTC.3 as input.
	PORTC |= (1 << 3); //enable pull-up
    /* Replace with your application code */
    while (1) 
    {
		if(!(PINC & (1 << PINC3)))  // if PINC.3 is pressed.
		{
			PORTB &= ~(1 << 2);
			_delay_ms(2000);
		}
		else
		{
			PORTB |= (1 << 2);
		}
    }
}

