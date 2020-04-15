/*
 * Task4.c
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
int Flag_2 = 0;
unsigned long Cpa1 = 0;  
unsigned long Capt2 = 0;
unsigned long Capt3 = 0;
unsigned long Capt4 = 0;
unsigned long Capt5 = 0;
unsigned long Capt6 = 0;
unsigned long Capt7 = 0;
unsigned long Capt8 = 0;
unsigned overflow_cnt= 0;
unsigned overflow_cnt_2 = 0;
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
	DDRB &= ~(1<<DDB0);		//PB0 as input for timer1 input capture
	PORTB |= (0<<DDB0);		
	TCNT1 = 0;
	TCCR1A = 0;
	TCCR1B = (0<<ICNC1) | (1<<ICES1);		//RISING EDGE CAPTURE.
	TCCR1C = 0;
	TIFR1 =(1<<ICF1)|(1<<TOV1);// clear pending
	TIMSK1 = (1<<ICIE1)|(1<<TOIE1);// enable interrupt
}

void init_timer3()
{
	DDRE &= ~(1<<DDE2);			//PE2 as input for timer3 input capture
	PORTE |= (0<<2);
	TCNT3 = 0;
	TCCR3A = 0;
	TCCR3B = (0<<ICNC3) | (1<<ICES3);		//rising edge capture.
	TCCR3C = 0;
	TIFR3 = (1<<ICF3) |(1<<TOV3); //clear pending
	TIMSK3 = (1<<ICIE3)|(1<<TOIE3);	 //enable interrupt
}

void start_timer1()
{
	//Start timer without prescaller
	TCCR1B|=(1<< CS10);
}

void start_timer3()
{
	TCCR3B |=(1<<CS30);	//start timer3 without prescaller
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
	USART_init();
	init_timer1();
	init_timer3();
	start_timer1();
	start_timer3();
	timer0_pwm();
	sei();
	unsigned long period_1 = 0, period_2 = 0;
	unsigned long PulseWidth_1 = 0, PulseWidth_2 = 0;
	volatile float DutyCycle_1, DutyCycle_2;
    /* Replace with your application code */
	//USART_tx_string("Connected\n");
    while (1) 
    {
		adc_read();				//update adc value
		OCR0A = adc_value;		//set speed.
		if(Flag == 4)	//Ch.A finish capturing
		{
			period_1 =((Capt3 - Cpa1 + Capt4 - Capt2) / 2);  //get the average period
			PulseWidth_1 = (Capt2 - Cpa1 + Capt4 - Capt3) / 2;	//get the average pulse width
			DutyCycle_1 = PulseWidth_1/(float)period_1;
			Flag++;
		 }
		 if(Flag_2 == 4) //Ch.B finish capturing
		 {
			period_2 =((Capt7 - Capt5 + Capt8 - Capt6) / 2);  //get the average period
			PulseWidth_2 = (Capt6 - Capt5 + Capt8 - Capt7) / 2;	//get the average pulse width
			DutyCycle_2 = PulseWidth_2/(float)period_2;
			Flag_2++;
		 }
		 if(Flag == 5 && Flag_2 == 5)
		 {
			DutyCycle = (DutyCycle_1 + DutyCycle_2)/2; 
			Period = (period_1 + period_2) /2;
			PulseWidth = (PulseWidth_1 + PulseWidth_2) /2;
			display_duty();
			display_pulse();
			speed_rpm();		//calculate speed in rpm.
			display_period();
			display_speed();
			Flag = 0;
			Flag_2 = 0;
			TCNT1 = 0;
			TCNT3 = 0;
			overflow_cnt = 0;
			overflow_cnt_2 = 0;
			_delay_ms(2000);		//delay for printing result to terminal
			TIMSK1|=(1<<ICIE1)|(1<<TOIE1);		
			TIMSK3|=(1<<ICIE3)|(1<<TOIE3);		//restart interrupt.	 
		 }
	}
}

//capture ISR
ISR(TIMER1_CAPT_vect)
{
	//4x encoding
	if(Flag == 0)
	{
		Cpa1 = ICR1 + overflow_cnt * 65536;
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

ISR(TIMER3_CAPT_vect)
{
	//4x encoding
	if(Flag_2 == 0)
	{
		Capt5 = ICR3 + overflow_cnt_2 * 65536;
		TCCR3B&=~(1<<ICES3);	//switch to falling edge
	}
	if(Flag_2 == 1)
	{
		Capt6 = ICR3 + overflow_cnt_2 * 65536;
		TCCR3B|=(1<<ICES3);		//switch back to rising edge
	}
	if(Flag_2 ==2)
	{
		Capt7 = ICR3 + overflow_cnt_2 * 65536;
		TCCR3B&=~(1<<ICES3);	//switch to falling edge
	}
	if(Flag_2 == 3)
	{
		Capt8 = ICR3 + overflow_cnt_2 * 65536;
		TIMSK3&=~((1<<ICIE3)|(1<<TOIE3));	//stop input capture and overflow interrupt.
	}
	Flag_2++;
}
ISR(TIMER3_OVF_vect)
{
	overflow_cnt_2++;
}
ISR(TIMER1_OVF_vect)
{
	overflow_cnt++;
}