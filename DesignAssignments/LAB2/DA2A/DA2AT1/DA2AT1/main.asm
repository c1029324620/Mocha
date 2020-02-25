;
; DA2AT1.asm
;
; Created: 2/21/2020 11:50:06 PM
; Author : c1029
;
; design a delay subroutine to generate waveform on PORTB.3 with 55% Duty Cycle and the period is 0.75s.

; Replace with your application code
start:
	ldi r16, 0xff	;r16 = 0xff, it will be used to set DDRB as output
	out DDRB, r16	;set DDRB as output
again:
	sbi PORTB, 3	;set bit 3 in PORTB high.
	rjmp delay_high		;jump to delay subroutine, should wait around 0.4s
high_delay_done:
	cbi PORTB, 3	;after 0.41 sec delay, make PORTB.3 Low
	rjmp delay_low
low_delay_done:
	rjmp again		;after 0,33 sec delay, set PORTB.3 High again, then we have generated a waveform.

; 0.4125s delay if it runs at 16 MHz
delay_high:
    ldi  r18, 34
    ldi  r19, 124
    ldi  r20, 86
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
	rjmp high_delay_done

; 0.3375 delay if it runs at 16 MHz
delay_low:
    ldi  r18, 28
    ldi  r19, 101
    ldi  r20, 233
L2: dec  r20
    brne L2
    dec  r19
    brne L2
    dec  r18
    brne L2

	rjmp low_delay_done

done:
	rjmp done