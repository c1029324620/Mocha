/*
 * DA2B_C.c
 *
 * Created: 2/27/2020 12:33:59 PM
 * Author : c1029
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util//delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB |= (1 << 2); //set PORTB.2 as output.
	PORTB |= (1 << 2);
	
	DDRC &= (0 << 3); //set PORTC.3 as input.
	PORTC |= (1 << 3); //enable pull-up
	
	EICRA = 0x02; //make INT0 falling edge triggered
	EIMSK = (1<<INT0);	//enable external interrupt 0
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(INT0_vect)
{
	
	PORTB &= ~(1 << 2);		//turn LED on
	_delay_ms(2000);		//for 2 seconds
	PORTB |= (1<< 2);		//then turn it off
}

