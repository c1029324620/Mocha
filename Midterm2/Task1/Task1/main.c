/*
 * Task1.c
 *
 * Created: 4/8/2020 10:34:53 AM
 * Author : c1029
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int Flag;
	DDRD |= (1<< DDRD4) | (1<< DDRD5) | (1<< DDRD6);	//make PD4,PD5, and PD6 as outputs.	
	OCR0A = 128;		//50% duty cycle
	TCCR0A |= (1<< COM0A1) | (1<<WGM01) | (1<< WGM00); //non-inverting and fast PWM 
	TCCR0B |= (1<< CS00);		//no prescaler.
    /* Replace with your application code */
    while (1) 
    {
		if(Flag == 1)
		{
			PORTD|=(1<<DDD5);// CW Direction Set
			PORTD&=~(1<<DDD4);// CW Direction Set
			_delay_ms(5000);
			Flag = 0;
		}
		else
		{
			PORTD&=~(1<<DDD5);// CCW Direction Set
			PORTD|=(1<<DDD4);// CCW Direction Set
			_delay_ms(5000);
			Flag = 1;
		}
    }
}

