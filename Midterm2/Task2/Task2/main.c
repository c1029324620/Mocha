/*
 * Task2.c
 *
 * Created: 4/8/2020 1:29:52 PM
 * Author : c1029
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

unsigned int adc_value;

void init_adc()
{
	ADMUX = (0<<REFS1) |	//AVref
	(1<<REFS0) |
	(1<<ADLAR) |	//Left justified
	(0<<MUX2)  |	//ADC0 channel 0
	(0<<MUX1)  |
	(0<<MUX0);
	ADCSRA = (1<<ADEN) |	//Enable ADC
	(0<<ADSC) |
	(0<<ADATE)|
	(0<<ADIF) |
	(0<<ADIE) |
	(1<<ADPS2)|	//prescaler of 128
	(1<<ADPS1)|
	(1<<ADPS0);
}

void read_adc()
{
	ADCSRA |= (1 << ADSC);		//enable start conversion
	while(ADCSRA & (1<< ADSC));	//wait
	adc_value = ADCH;	// potentiometer value stored in adc_value
}

int main(void)
{
	int Flag = 1;
	init_adc();
	DDRD |= (1<< DDRD4) | (1<< DDRD5) | (1<< DDRD6);	//make PD4,PD5, and PD6 as outputs.
	TCCR0A |= (1<< COM0A1) | (1<<WGM01) | (1<< WGM00); //non-inverting and fast PWM
	TCCR0B |= (1<< CS00);		//no prescaler.
	/* Replace with your application code */
	while (1)
	{
		read_adc();
		OCR0A = adc_value;		//duty cycle are based on the adc value read.
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

