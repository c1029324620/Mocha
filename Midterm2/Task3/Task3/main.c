/*
 * Task3.c
 *
 * Created: 4/8/2020 1:50:39 PM
 * Author : c1029
 */ 

#define F_CPU 16000000UL
#define BAUD 9600
#include <avr/io.h>
#include <util/setbaud.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int Flag = 0;
unsigned long  revTick = 0;  
unsigned long  Capt2 = 0;
unsigned long  Capt3 = 0;
unsigned long  Capt4 = 0;
//uint32_t T1Ovs1 = 0;
//uint32_t T1Ovs2 = 0;
//uint32_t T1Ovs3 = 0;
//uint32_t T10vs4 = 0;
unsigned overflow_cnt= 0;
int speed = 0;

unsigned long PulseWidth, Period;
volatile float DutyCycle;

unsigned int adc_value;


void USART_init(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);		//8-bit data
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);		//enable receiver and transmitter
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

void adc_read()
{
	ADCSRA |= (1 << ADSC);		//enable start conversion
	while(ADCSRA & (1<< ADSC));	//wait
	adc_value = ADCH;	// potentiometer value stored in adc_value
}

void display_adc()
{
	adc_read();
	char array1[32];
	sprintf(array1,"%i", adc_value);			//convert int to string
	USART_tx_string("ADC Value: ");		//print
	USART_tx_string(array1);
	USART_tx_string("\n");
}

void display_duty()
{
	char array1[32];
	sprintf(array1,"%f", DutyCycle);			//convert int to string
	USART_tx_string("Duty Cycle: ");		//print
	USART_tx_string(array1);
	USART_tx_string("\n");
}
void display_period()
{
	char array1[32];
	sprintf(array1,"%lu", Period);			//convert int to string
	USART_tx_string("Period: ");		//print
	USART_tx_string(array1);
	USART_tx_string("\n");
}

void display_pulse()
{
	char array1[32];
	sprintf(array1,"%lu", PulseWidth);			//convert int to string
	USART_tx_string("Pulsewidth: ");		//print
	USART_tx_string(array1);
	USART_tx_string("\n");
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


void init_timer1()
{
	DDRB &= ~(1<<DDB0);
	PORTB |= (0<<DDB0);
	TCNT1 = 0;
	TCCR1A = 0;
	TCCR1B = (0<<ICNC1) | (1<<ICES1);		//RISING EDGE CAPTURE.
	TCCR1C = 0;
	TIFR1 =(1<<ICF1)|(1<<TOV1);// clear pending
	TIMSK1 = (1<<ICIE1)|(1<<TOIE1);// and enable
}

void start_timer1()
{
	//Start timer without prescaller
	TCCR1B|=(1<< CS10);
}

void timer0_pwm()
{
	DDRD |= (1<<DDD6);
	TCNT0 = 0;
	adc_read();
	OCR0A = adc_value;	
	PORTD|=(1<<DDD5);// CW Direction Set
	PORTD&=~(1<<DDD4);// CW Direction Set
	TCCR0A |= (1<< COM0A1) | (1<<WGM01) | (1<< WGM00); //non-inverting and fast PWM
	TCCR0B |= (1<< CS00) |(1<<CS02);	//prescaler to 1024
}

void speed_rpm()
{
	speed = (1/(Period* 0.0000000625)) * 60 /120L;
}

void display_speed()
{
	char array1[20];
	sprintf(array1,"%i", speed);			//convert int to string
	USART_tx_string("Speed: ");		//print
	USART_tx_string(array1);
	USART_tx_string(" rpm\n");
}

int main(void)
{
	init_adc();
	timer0_pwm();
	USART_init();
	init_timer1();
	start_timer1();
	sei();
    /* Replace with your application code */
	//USART_tx_string("Connected\n");
    while (1) 
    {
		adc_read();				//update adc value
		OCR0A = adc_value;		//set speed.
		if(Flag == 4)
		{
			Period= ((Capt3 - revTick + Capt4 - Capt2) / 2);  //get the average period
			PulseWidth = (Capt2 - revTick + Capt4 - Capt3) / 2;	//get the average pulse width
			DutyCycle = PulseWidth/(float)Period;
			Flag = 0;
			display_duty();
			display_pulse();
			speed_rpm();		//calculate speed in rpm.
			display_period();
			display_speed();
			TCNT1 = 0;
			overflow_cnt = 0;
			_delay_ms(2000);		//delay for printing result to terminal
			TIMSK1|=(1<<ICIE1)|(1<<TOIE1);
    }
}
}

//capture ISR
ISR(TIMER1_CAPT_vect)
{
	//2x encoding
	if(Flag == 0)
	{
		revTick = ICR1 + overflow_cnt * 65536;
		//TCNT1=0;// restart timer for next revolution
		//T1Ovs1=overflow_cnt;
		TCCR1B&=~(1<<ICES1);	//switch to falling edge
	}
	if(Flag == 1)
	{
		Capt2 = ICR1 + overflow_cnt * 65536; 
		TCCR1B|=(1<<ICES1);		//switch back to rising edge
		//T1Ovs2=overflow_cnt;
	}
	if(Flag ==2)
	{
		Capt3 = ICR1 + overflow_cnt * 65536;
		TCCR1B&=~(1<<ICES1);	//switch to falling edge
		//T1Ovs3 = overflow_cnt;
	}
	if(Flag == 3)
	{
		Capt4 = ICR1 + overflow_cnt * 65536;
		//T10vs4 = overflow_cnt;
		TIMSK1&=~((1<<ICIE1)|(1<<TOIE1));	//stop input capture and overflow interrupt.
	}
	Flag++;
}

ISR(TIMER1_OVF_vect)
{
	overflow_cnt++;
}
