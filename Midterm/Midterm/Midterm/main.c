/*
 * Midterm.c
 *
 * Created: 3/20/2020 10:57:17 AM
 * Author : c1029
 */ 

#define F_CPU 16000000UL
#define BAUD 9600
#include <avr/io.h>
#include <util/setbaud.h>
#include <stdlib.h>
#include <stdio.h>
#include <util\delay.h>
#include <time.h>
#include <avr/interrupt.h>

volatile uint8_t temp;

void USART_init(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);		//8-bit data
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);		//enable receiver and transmitter
}

void adc_int(void)
{
	//setup and enable ADC
	ADMUX = (0 << REFS1) | //reference selection bits
			(1 << REFS0) |	//AVcc-external cap at AREF
			(0 << ADLAR) | //ADC left adjust result
			(1 << MUX2)  |	//analog chanel selection bits
			(0 << MUX1)  |	// ADC4(PC4)
			(0 << MUX0);
	ADCSRA = (1 << ADEN) |	// ADC enable
			 (0 << ADSC) | // ADC start conversion
			 (0 << ADATE) | // ADC auto trigger enable
			 (0 << ADIF) | // ADC interrupt flag
			 (0 << ADIE) | // ADC interrupt Enable
			 (1 << ADPS2) | // ADC prescaler select bits
			 (0 << ADPS1) |
			 (1 << ADPS0);
}

void adc_read(void)
{
	ADCSRA |= (1 << ADSC);		//enable start conversion
	while(ADCSRA & (1<< ADSC));	//wait
	temp = ADC;	// LM35 value stored in temp.
}

//send some data to the serial port
void USART_tx_string(char* data)
{
	while((*data !='\0'))
	{
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = *data;
		data++;
	}
}

char USART_Receiver()
{
	//wait for data to be received 
	while(!(UCSR0A & (1<< RXC0)));
	//get and return received data from buffer
	return UDR0;
	
}

void display_help()
{
		USART_tx_string("***'t' display temperature in Celsius.\n");
		USART_tx_string("***'T' display temperature in Farenthide.\n");
		USART_tx_string("***'o' turns ON LED at PB5.\n***'O' turns OFF the LED at PB5.\n");
		USART_tx_string("***'s' sends a string to the terminal.\n");
		USART_tx_string("***'i' sends an integer to the terminal.\n");
		USART_tx_string("Press 'h' key to display again the help table.\n");
}

void display_tem_c()
{
	adc_read();
	char array1[20];
	int celsius = (temp - 32) * 5 / 9;		//convert to celsius
	sprintf(array1,"%i", celsius );			//convert int to string
	USART_tx_string("Temperature: ");		//print
	USART_tx_string(array1);
	USART_tx_string(" C\n");
}

void display_tem_t()
{
	adc_read();
	char array1[20];
	sprintf(array1,"%i", temp);			//convert int to string
	USART_tx_string("Temperature: ");	//print
	USART_tx_string(array1);
	USART_tx_string(" F\n");
}

void turn_on()
{
	PORTB &= ~(1 << 5);  //Turn LED on
}

void turn_off()
{
	PORTB |= (1 << 5);	//Turn LED off
}

void send_str()
{
	USART_tx_string("Hello World!\n");		//send "Hello World" to terminal
}

void my_delay_ms(int n) {
	while(n--) {
		_delay_ms(1);
	}
}

void send_int()
{
	int delay = (rand() % 3 + 1) * 1000;		//generate random numbers of 1000, 2000, 3000 for delay in ms
	char array1[20];
	sprintf(array1, "%i", delay);
	USART_tx_string(array1);
	USART_tx_string("\n");
	turn_on();
	my_delay_ms(delay);
	turn_off();
	my_delay_ms(delay);
}
int main(void)
{
	srand(time(NULL));
    /* Replace with your application code */
	USART_init();		//initialized USART module
	adc_int();			//initialized ADC module
	DDRB |= (1 << 5); //set PORTB.5 as output
	PORTB |= (1 << 5);	//pull up;
	display_help();
    while (1) 
    {
		switch(USART_Receiver())
		{
			case 'h':
				display_help();			//display help table
			break;
			case 't':
				display_tem_c();		//display temperature in C
			break;
			case 'T':
				display_tem_t();		//display temperature in F
			break;
			case 'o':		
				turn_on();				//turn on LED
			break;
			case 'O':
				turn_off();				//turn off LED
			break;
			case 's':
				send_str();				//send string
			break;
			case 'i':
				send_int();				//send integer, and blink LED
			break;
			default:
			break;
		}
    }
}

