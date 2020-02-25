;
; DA2AT2.asm
;
; Created: 2/24/2020 8:02:35 PM
; Author : c1029
;
; connect a switch to PORTC.3 to poll for an event to turn on the LED at PORTB.2 for 2 sec.

; Replace with your application code
start:
	cbi DDRC, 3		;set PORTC.3 as input 
	ldi r16, 0x04;set PORTB as output
	out DDRB, r16	;set PORTB.2 as output
again:
	sbis PINC, 3	;becasue the push button is active high, if the button is push, then will set it low
	rjmp delay_2s	;jump to delay and will turn LED on
	sbi PORTB, 2	;set bit 2 in PORTB high will set LED off
	rjmp again		
delay_2s:
	cbi PORTB, 2	;this will turn LED on
	ldi  r18, 163
    ldi  r19, 87
    ldi  r20, 3
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
	rjmp again