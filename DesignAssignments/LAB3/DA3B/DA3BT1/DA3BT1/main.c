/*
 * DA3BT1.c
 *
 * Created: 3/13/2020 12:16:44 PM
 * Author : c1029
 */ 
#define F_CPU 16000000UL
#define BAUD 9600
#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

volatile uint8_t overflow_cnt;
volatile uint8_t temp;

void USART_init(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);		//8-bit data
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);	//enable transmitter
}

void set_inter()
{
	TCCR0A = 0x00;		//normal mode
	TCCR0B = 0x05;		//prescaler 1024
	TCNT0 = 0x00;
	TIMSK0 = (1<< TOIE0);		//enable timer interrupt
	sei();			//enable global interrupt
}

void adc_int(void)
{
	ADMUX = (0 << REFS1) | (1 << REFS0) | (0 << ADLAR) | (0 << MUX3) | (1 << MUX2) | (0<< MUX1) | (0 << MUX0);
	ADCSRA = (1 << ADEN) | (0 << ADSC) | (0 << ADATE) | (0 << ADIF) | (0 << ADIE) | (1<< ADPS2) | (1 << ADPS1) | (1<<ADPS0); 
}
void USART_tx_string(char* data)
{
	while((*data !='\0'))
	{
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = *data;
		data++;
	}
}

void adc_read(void)
{
	ADCSRA |= (1 << ADSC);		//enable start conversion
	while(ADCSRA & (1<< ADSC));	//wait 
	temp = ADC;	// LM35 value stored in temp.
}

int main(void)
{
    /* Replace with your application code */
	USART_init();
	adc_int();
	set_inter();
	int celsius;
	char array1[20], array2[20];
    while (1) 
    {
		if (overflow_cnt == 31)
		{
			adc_read();			//Call Read Function
			celsius = (temp - 32) * 5 / 9;		//convert to celsius
			
			sprintf(array1,"%i", temp);			//convert the number into a string type
			sprintf(array2, "%i", celsius);

			//Prints temperature value
			USART_tx_string("Temperature: ");
			USART_tx_string(array1);
			USART_tx_string(" Fahrenheit or ");
			USART_tx_string(array2);
			USART_tx_string(" Celsius.");
			USART_tx_string("\n");
			overflow_cnt = 0;
		}
	}
}

ISR(TIMER0_OVF_vect)
{
	overflow_cnt++;
}

