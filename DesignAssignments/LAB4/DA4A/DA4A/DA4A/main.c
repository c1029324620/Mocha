/*
 * DA4A.c
 *
 * Created: 3/30/2020 12:54:04 PM
 * Author : c1029
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

unsigned int adc_value;

void read_adc()
{
	ADCSRA |= (1 << ADSC);		//enable start conversion
	while(ADCSRA & (1<< ADSC));	//wait
	adc_value = ADC;	// potentiometer value stored in adc_value
}

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


int main(void)
{
    /* Replace with your application code */
	init_adc();
	
	DDRC |= (0<<DDRC1);	//pinc.1 as input
	PORTC |= (1 << 1); //pull=up resistor
	PCICR |= (1<<PCIE1); //pin change interrupt
	PCMSK1 |= (1<<PCINT9); 
	sei();
	 
	DDRB |= (1<< DDRB1);	//Port B.1 as output
	ICR1 = 0xffff;
	TCCR1A = (1<<COM1A1) | (1<<COM1B1) | (1<<WGM11);		//non-inverting 
    TCCR1B = (1<< WGM12) | (1<<WGM13);	//Fast PWM using ICR1 as TOP
	TCCR1B = (1<< CS10);	// no prescaler.
	while(1)
	{
		read_adc();
		if((adc_value >= 62258) && (adc_value < 65535))	//95% of PWM value
		{
			OCR1A = 62258;
			_delay_ms(20);
		}
		else if((adc_value < 62257) && (adc_value >= 3277))
		{
			OCR1A = adc_value;
			_delay_ms(20);
		}
		else
		OCR1A = 0x00;		//minimum speed at less than 5% of PWM value.
	}
	return 0;
}

ISR(PCINT1_vect)
{
	DDRC ^=(1<<2);
}


