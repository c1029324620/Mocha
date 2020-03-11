/*
 * DA3AT1.c
 *
 * Created: 3/9/2020 8:21:24 PM
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

void USART_init(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);		//8-bit data
	UCSR0B = _BV(TXEN0);		//enable transmitter
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

int main(void)
{	
	srand(time(NULL));			//random number generator seed
	char String[] = "Hello World!!";	//string
	char array1[16];			//used for converting integer to string
	char array2[16];			//used for converting float to string
	USART_init();			//initialized USART
    while (1) 
    {
		int rand_num = rand();			//assign random integer number
		itoa(rand_num, array1, 10);		//convert to string
		float float_point = rand_num * 0.5;		//assign random floating point number
		sprintf(array2,"%f", float_point);		//convert to string
		//send strings to serial port and print.
		USART_tx_string(String);
		USART_tx_string(" ");
		
		USART_tx_string(array1);
		USART_tx_string(" ");
		
		USART_tx_string(array2);
		USART_tx_string("\n");
		
		_delay_ms(1000);
    }
}
