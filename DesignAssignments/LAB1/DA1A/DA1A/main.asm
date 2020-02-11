;
; main.asm
;
; Created: 2/10/2020 9:47:52 PM
; Author : c1029
;


; Replace with your application code
.include "m328pdef.inc"
.org	0x00
.cseg
start:
	;initialize the multiplicand with value of 0x5432FFFF
	ldi r16, 0xFF
	ldi r17, 0xFF
	ldi r18, 0x32
	ldi r19, 0x54

	;initialize the multiplier with value of 0x0010FF99
	ldi r20, 0x99
	ldi r21, 0xFF
	ldi r22, 0x10
	ldi r23, 0x00

	cpi r20, 0x00	;if the lowest word is zeron, jump if it is, and borrow from next higher reigers
	breq borrow
LP_add:
	add r24, r16	; r24 = r24 + r16
	adc r25, r17	; add with carry
	adc r26, r18	; add with carry
	adc r27, r19	; add with carry
	brcc LP_r20		; if there is no carry, jump to LP_r20, which will decrement the r20 register.
	inc r28			; add the carry to the r28 register
	cpi r28, 0x00	; compare r28 with 0x00, in other word, if r28 become larger than 0xFF or there is carry produced
	brne LP_r20	    ; jump to LP_r20 if there is no carry
	inc r29			; increment r29 when there is carry
	cpi r29, 0x00	; if a carry is produced
	brne LP_r20		; jump to LP_r20 if there is no carry
	inc r30			; increment r30 when there is carry
	cpi r30, 0x00	; if a carry is produced
	brne LP_r20		; jump if there is no carry
	inc r31			; increment r31 if there is a carry.

LP_r20:
	dec r20			; decrement the r20
	brne LP_add		; jump if r20 equal to zero
borrow:	
	dec r21			; borrow from r21, and decrement the r21, 
	cpi r21, 0xFF	; if r21 is equal to 0xFF implies that no more borrow from r21,
	brne LP_add		; jump to LP_add 
	
	dec r22			; borrow from r22, and decrement the r22, if it is equal to 0xff, no more borrow are allow
	cpi r22, 0xFF
	brne LP_add
	
	dec r23			; no more borrows are allow when r23 is equal to 0xFF
	cpi r23, 0xFF
	brne LP_add
	
DONE:
	jmp DONE		; program end