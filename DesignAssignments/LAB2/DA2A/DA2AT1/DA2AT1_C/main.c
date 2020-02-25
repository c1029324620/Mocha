/*
 * DA2AT1_C.c
 *
 * Created: 2/22/2020 1:02:46 AM
 * Author : c1029
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xff; //set PORTB as output
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1 << 3);  //set bit 3 in PORTB to HIGH.
		_delay_ms(413);	//wait for 0.4125 sec.
		PORTB &= ~(1 << 3);	//set bit 3 in PORTB to LOW.
		_delay_ms(338); //wait for delay of 0.3375 sec
    }
}

