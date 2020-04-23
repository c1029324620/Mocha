/*
 * SPI_ShiftRegister.c
 *
 * Created: 4/2/2020 12:55:58 AM
 * Author : VenkatesanMuthukumar
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SHIFT_REGISTER DDRB
#define SHIFT_PORT PORTB
#define DATA (1<<PB3)     //MOSI (SI)
#define LATCH (1<<PB2)        //SS   (RCK)
#define CLOCK (1<<PB5)        //SCK  (SCK)

/* Note the mapping for Multifunctional shield 
Name		-  Board       -    Shield
DATA/MOSI		PB3	(11)		PB0 (8)
LATCH/SS		PB2	(10)		PD4 (4)
CLOCK/SCK		PB5	(13)		PD7 (7)
-/MISO			PB4	(12)		PB1	(9)		
*/

uint8_t adc_value;
/* Segment byte maps for numbers 0 to 9 */
const uint8_t SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99,
0x92, 0x82, 0xF8, 0X80, 0X90};
/* Byte maps to select digit 1 to 4 */
const uint8_t SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};

//initialized adc module
void adc_int(void)
{
	//setup and enable ADC
	ADMUX = (0 << REFS1) | //reference selection bits
	(1 << REFS0) |	//AVcc-external cap at AREF
	(0 << ADLAR) | //ADC left adjust result
	(1 << MUX2)  |	//analog channel selection bits
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
	adc_value = ADC;	// LM35 value stored in temp.
}

int main(void)
{
	adc_int();		//initialize the adc module
	while(1)
	{
			adc_read();
			SHIFT_REGISTER |= (DATA | LATCH | CLOCK); //Set control pins as outputs
			SHIFT_PORT &= ~(DATA | LATCH | CLOCK);        //Set control pins low
			SPCR0 = (1<<SPE) | (1<<MSTR);  //Start SPI as Master
			SHIFT_PORT &= ~LATCH;
			
			//Shift in some data
			SPDR0 = SEGMENT_MAP[adc_value % 10];        //This should light alternating LEDs
			//Wait for SPI process to finish
			while(!(SPSR0 & (1<<SPIF)));
			
			//Shift in some more data since I have two shift registers hooked up
			SPDR0 = 0xF8;        //This should light alternating LEDs
			//Wait for SPI process to finish
			while(!(SPSR0 & (1<<SPIF)));
			
			//Toggle latch to copy data to the storage register
			SHIFT_PORT |= LATCH;
			SHIFT_PORT &= ~LATCH;	
			
			SPDR0 = SEGMENT_MAP[adc_value /10];        //This should light alternating LEDs
			//Wait for SPI process to finish
			while(!(SPSR0 & (1<<SPIF)));
			
			//Shift in some more data since I have two shift registers hooked up
			SPDR0 = 0xF4;        //This should light alternating LEDs
			//Wait for SPI process to finish
			while(!(SPSR0 & (1<<SPIF)));
			
			//Toggle latch to copy data to the storage register
			SHIFT_PORT |= LATCH;
			SHIFT_PORT &= ~LATCH;
			
			SPDR0 = SEGMENT_MAP[adc_value /100];        //This should light alternating LEDs
			//Wait for SPI process to finish
			while(!(SPSR0 & (1<<SPIF)));
			
			//Shift in some more data since I have two shift registers hooked up
			SPDR0 = 0xF2;        //This should light alternating LEDs
			//Wait for SPI process to finish
			while(!(SPSR0 & (1<<SPIF)));
			
			//Toggle latch to copy data to the storage register
			SHIFT_PORT |= LATCH;
			SHIFT_PORT &= ~LATCH;
		//Loop forever
	}
}