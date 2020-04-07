/*
 * DA4BT1.c
 *
 * Created: 4/6/2020 12:33:28 PM
 * Author : c1029
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>

unsigned int adc_value;

void adc_int()
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

void adc_read()
{
		ADCSRA |= (1 << ADSC);		//enable start conversion
		while(ADCSRA & (1<< ADSC));	//wait
		adc_value = ADCH;	// potentiometer value stored in adc_value
}


//control delay by timer0 in CTC mode
void my_delay()
{
	OCR0A = adc_value;
	int cycle = 100;
	while(cycle != 0)
	{
		cycle--;
		while((TIFR0 & 0x02) == 0);
		TIFR0 = 1<<OCIE0A;
	}
}

int main(void)
{
    /* Replace with your application code */	adc_int();
	TCCR0A |= (1<<WGM01); //CTC mode
	TCCR0B |= (0<< WGM02)|(1<<CS02) |(1<<CS00);	//prescaler of 1024
	TCNT0 = 0x00;
	PORTC |=  (1<<0);	   //Pull Up Resistor Activated PC0
	DDRD = 0xF0;           //make PORTD upper pins as output
    while (1) 
    {
		//counter-clockwise and full step
		PORTD=0x90;
		adc_read();			//read potentiometer value
		my_delay();			//set the potentiometer value as OCRA value
		PORTD=0x30;
		adc_read();
		my_delay();
		PORTD=0x60;
		adc_read();
		my_delay();
		PORTD=0xC0;
		adc_read();
		my_delay();
    }
}

