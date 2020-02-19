;
; DA1B.asm
;
; Created: 2/11/2020 7:37:01 PM
; Author : c1029
;


; Replace with your application code
.include<m328pdef.inc>
.equ STARTADD = 0x0300
.equ DIVI7 = 0x0500		
.equ DIVI3 = 0x0600
.equ DIVI_BOTH = 0x700
.equ DIVI_NOT = 0x800

.def num = r20
.def denominator = r21

.cseg
.org 0x00
	ldi r17, 200	;r17 =200, used as counter to store 200 numbers
	ldi r16, 26		;starts at 26
	ldi ZL, LOW(STARTADD)	;load the low byte of Z with 0x00
	ldi ZH, HIGH(STARTADD)	;load the high byte of Z with 0x03
Store_LP:
	st	Z+, r16		;copy r16 to memory location Z, then increment the Z register
	inc r16		;increment the value to be stored
	dec r17		;decrement the counter
	brne Store_LP	;loop until counter = 0
	;finish storing

	;pointers point to memory locations that data should be stored.
	ldi r18, LOW(DIVI7)
	ldi r19, HIGH(DIVI7)
	ldi r22, LOW(DIVI3)
	ldi r23, HIGH(DIVI3)
	ldi r24, LOW(DIVI_BOTH)
	ldi r25, HIGH(DIVI_BOTH)
	ldi r26, LOW(DIVI_NOT)
	ldi r27, HIGH(DIVI_NOT)

	ldi r17, 200	; used as counter to check the 200 numbers.
	ldi ZL, LOW(STARTADD)	;start checking numbers
	ldi ZH, HIGH(STARTADD)
check_LP:
	ld	r16, Z+	;load value in memory address Z into r16
	mov	num, r16	;move r16 into num

	ldi denominator, 7	;set denominator to 7
check7_LP:
	sub num, denominator	;keet subtrac 7
	brcc check7_LP
	add num, denominator	;num is the remainder now
	brne set3_LP		;check if the remainder is zero, if not, check if the number is divisible by 3 or not
	breq set_both		; if it is zero, check if the number is divisible by both or not
set3_LP:
	mov num, r16	;reset num
	ldi denominator, 3	;set denominator to 3
check3_LP:
	sub num, denominator	;keep subtract 3
	brcc check3_LP
	add num, denominator
	brne store_not	;if the remainder is not zero, store the number as not divisible by both.
	mov YL, r22		;store to DIVI3
	mov YH, r23		; r23:r22 have the memory address that is for not divisible for both.
	st	Y, r16		;store the number into DIVI_NOT memory address.
	inc r22			;increment the memory address
	dec r17			; decrement the counter.
	breq done_checking	;if counter is equal to zero means we have done our checking, move to calculating sum.
	jmp check_LP
set_both:
	mov num, r16
	ldi denominator, 3
check_both:				;check if the number is divisible by both
	sub num, denominator
	brcc check_both
	add num, denominator
	brne store_7		
	;store into DIVI_BOTH
	mov YL, r24
	mov YH, r25
	st Y, r16
	inc r24
	dec r17
	breq done_checking
	jmp check_LP
store_not:
	mov YL, r26
	mov YH, r27
	st	Y, r16
	inc r26
	dec r17
	breq done_checking
	jmp	check_LP
store_7:
	mov YL, r18
	mov YH, r19
	st	Y, r16
	inc r18
	dec r17
	breq done_checking
	jmp check_LP
done_checking:
	;calculating the sum
	;sum for 0x500 is going to be stored at r18:r17:r16
	ldi ZL, LOW(DIVI7)
	ldi ZH, HIGH(DIVI7)
	;clear register 18:17:16
	clr r16
	clr r17
	clr r18
L1:
	ld	r29, Z+
	add r16, r29
	adc r17, r0	; add carry with zero register
	adc r18, r0	; add carry with zero register
	cpi r29, 0x00	;compare with 0x00, 0x00 implies the end of data.
	brne L1

	;sum for 0x600 is going to be stored at r21:r20:r19
	ldi ZL, LOW(DIVI3)
	ldi ZH, HIGH(DIVI3)
	clr r19
	clr r20
	clr r21
L2:
	ld r29, Z+
	add r19, r29
	adc r20, r0
	adc r21, r0
	cpi r29, 0x00
	brne L2

	;sum for 0x700 is going to be stored at r24:r23:r22
	ldi ZL, LOW(DIVI_BOTH)
	ldi ZH, HIGH(DIVI_BOTH)
	clr r22
	clr r23
	clr r24
L3:
	ld r29, Z+
	add r22, r29
	adc r23, r0
	adc r24, r0
	cpi r29, 0x00
	brne L3

	;sum for 0x800 is going to be stored at r27:r26:r25
	ldi ZL, LOW(DIVI_NOT)
	ldi ZH, HIGH(DIVI_NOT)
	clr r25
	clr r26
	clr r27	 	
L4:
	ld r29, Z+
	add r25, r29
	adc r26, r0
	adc r27, r0
	cpi r29, 0x00
	brne L4

DONE:
	jmp DONE

	
	