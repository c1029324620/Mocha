/*
 * DA2CT1.c
 *
 * Created: 3/4/2020 7:43:16 PM
 * Author : c1029
 */ 
#define F_CPU 16000000UL		//1/16M = 62.5ns for one clock
#include <avr/io.h>

void on_2sec()
{
	int cycle = 122;				//2sec/62.5ns/1024/255 = 122 cycles
	while(cycle != 0)
	{
		cycle--;
		while((TIFR0 & 0x01) == 0);  //if overflow is set, clear it with reset to 1.
		TIFR0 = 1<<TOV0;
	}
	
}

void on_412()
{
	int cycle = 25;					//412ms/62.5ns/1024 = 6437.5 clocks to overflow
	PORTB |= (1<<3);					//6438/255 = 25 cycles
	while(cycle != 0)
	{
		if(!(PINC &(1<< PINC3)))	//if PINC.3 is pressed.
		{
			PORTB = 0x08;		//Turn LED on
			on_2sec();				//delay for 2 second.
			PORTB |=(1<<2);			//Turn LED off.
		}
		cycle--;
		while((TIFR0 & 0x01) == 0);	//if overflow is set, clear it with reset to 1.
		TIFR0 |= 1<<TOV0;			
	}
}

void off_338()
{
	int cycle = 20;			//338ms/62.5ns/1024 = 5281.25 clocks to overflow
	PORTB &=~(1<<3);			//5281.25/255 = 20 cycles 
	while(cycle != 0)
	{
		if(!(PINC &(1<< PINC3)))	//if PINC.3 is pressed.
		{
			PORTB = 0x08;		//Turn LED on.
			on_2sec();				//delay for 2 second.
			PORTB |=(1<<2);			//Turn LED off.
		}
		cycle--;
		while((TIFR0 & 0x01) == 0);
		TIFR0 = 1<<TOV0;		//clear overflow flag
	}
}

int main(void)
{
	DDRC &= ~(1<<3);	//set PORTC.3 as input
	DDRB = 0x0C;	//set PORTB.3 and PORTB.2 as output
	PORTC |= (1<<3); //active pull-up resistor for pushbutton
	PORTB |= (1<<2);	//pull-up resistor for LED
	
	
    /* Replace with your application code */
    while (1) 
    {
		TCCR0A = 0x00;		//normal mode operation
		TCCR0B = 0x05;		//prescaler of 1024
		TCNT0 = 0X00;
		on_412();			//hold PORTB.3 HIGH for 412ms
		off_338();			//hold PORTB.3 LOW for 338ms
    }
}

