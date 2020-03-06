/*
 * DA2CT2.c
 *
 * Created: 3/4/2020 9:58:21 PM
 * Author : c1029
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t cycle_cnt;		//global variable modified by ISR.

int main(void)
{
	DDRC &= ~(1<<3);	//set PORTC.3 as input
	DDRB = 0x0C;	//set PORTB.3 and PORTB.2 as output
	PORTC |= (1<<3);	//active pull-up resistor for pushbutton
	PORTB |= (1<<2) | (1 << 3);	//pull-up resistor for LED and PORTB.3
	TCNT0 = 0x00;
	TCCR0A = 0x00;		//normal mode operation
	TCCR0B = 0x05;		//prescaler of 1024
	TIMSK0 = (1<<TOIE0);	//enable timer0 overflow interrupt
	sei();
    /* Replace with your application code */
    while (1) 
    {
		if(!(PINC & (1<<PINC3)))
		{
			cycle_cnt = 0;
			PORTB = 0x08;
			while(cycle_cnt < 123);
			PORTB |=(1<<2);
			cycle_cnt = 0;
		}
		if((cycle_cnt < 45) && (cycle_cnt >= 20))
		{
			PORTB |= (1 << 3);  //set PORTB.3 HIGH
		}
		if(cycle_cnt > 45)
		{
			PORTB &= ~(1<<3);
			cycle_cnt = 0;		//set PORTB.3 LOW
		}
    }
}

ISR(TIMER0_OVF_vect)
{
	cycle_cnt++;
}

