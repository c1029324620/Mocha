;
; DA2B.asm
;
; Created: 2/27/2020 11:41:16 AM
; Author : c1029
;


; Replace with your application code

.include <m328pbdef.inc>
.org 0	;location for reset
	jmp MAIN
.org 0x02	;location for external interrupt 0
	jmp EX0_ISR
MAIN:
	ldi r20, HIGH(RAMEND)
	out SPH, r20
	ldi r20, LOW(RAMEND)
	out SPL, r20	;initialize stack

	cbi DDRC, 3		;set PORTC.3 as input 
	sbi PORTC, 3	;pull-up activated
	ldi r16, 0x04;set PORTB as output
	out DDRB, r16	;set PORTB.2 as output
	sbi PORTB, 2	;initially, set LED off
	ldi r20, 0x02	;make INT0 falling edge triggred
	STS EICRA, r20	
	ldi r20, 1<<INT0	;enable INT0
	out EIMSK, r20	;set the bit 0 in the external interrupt mask.
	sei
HERE:
	jmp HERE

EX0_ISR:
	cbi PORTB, 2	;this will turn LED on
delay_2sec:			;delay for 2 sec at 16M Hz
	ldi  r18, 163
    ldi  r19, 87
    ldi  r20, 3
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
	sbi PORTB, 2	;this will turn LED off again
	reti