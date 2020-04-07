/*
 * DA4BT2.c
 *
 * Created: 4/6/2020 4:50:31 PM
 * Author : c1029
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util\delay.h>


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
	(0<<ADPS1)|
	(1<<ADPS0);
}

void adc_read()
{
	ADCSRA |= (1 << ADSC);		//enable start conversion
	while(ADCSRA & (1<< ADSC));	//wait
	adc_value = ADCH;	// potentiometer value stored in adc_value
}

int main(void)
{
   adc_int();			   //Initial ADC
   PORTC |=  (1<<0);	   //Pull Up Resistor Activated PC0
   
   //Configuration of Timer1
   TCCR1A |= (1<<COM1A1)|(1<<COM1B1);
   TCCR1A |= (1<<WGM11);			 //CTC Mode
   TCCR1B |= (1<<WGM12)|(1<<WGM13); //CTC Mode
   TCCR1B |= (1<<CS10) |(1<<CS11);  //Prescaler 64
   ICR1 = 4999;  //freq = 50Hz, Period = 20ms
   DDRB |= (1<<DDRB1);
   
   while (1)
   {
	   adc_read();
	   if(adc_value < 64)
	   {
		   OCR1A = 97;			//0 degree.
	   }
	   else if(adc_value >= 64 && adc_value < 128)
		{
			OCR1A = 316;		//90 degree.
		}
		else if(adc_value >= 126 && adc_value < 192)
		{
			OCR1A = 426;		//135 degree
		}
		else 
			OCR1A = 535;		//180 degree
   }
}

