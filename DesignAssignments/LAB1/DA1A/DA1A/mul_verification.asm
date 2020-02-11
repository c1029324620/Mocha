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

	mul r16, r20	;r1:r0 = r16 * r20.
	mov r24, r0		;move result into r25:r24
	mov r25, r1

	mul r17, r20	;r1:r0 = r16 * r20
	add r25, r0		;combine products
	adc r26, r1		;add with carry
	adc r27, r2		; add zero and with carrry

	mul r18, r20	;r1:r0 = r16 * r20
	add r26, r0		;combine products
	adc r27, r1		;add with carry
	adc r28, r2		;add zero and with carry

	mul r19, r20	
	add r27, r0		;combine products
	adc r28, r1		;add with carry
	adc r29, r2		;add zero and with carry

	mul r16, r21
	add r25, r0
	adc r26, r1
	adc r27, r2		; adding carry with zero 
	
	mul r17, r21	
	add r26, r0		;combine products
	adc r27, r1	
	adc r28, r2

	mul r18, r21	
	add r27, r0		;combine products
	adc r28, r1		
	adc r29, r2

	mul r19, r21	
	add r28, r0		;combine products
	adc r29, r1
	adc r30, r2

	mul r16, r22
	add r26, r0		;combine products
	adc r27, r1
	adc r28, r2

	mul r17, r22
	add r27, r0		;combine products
	adc r28, r1
	adc r29, r2

	mul r18, r22
	add r28, r0		;combine products
	adc r29, r1
	adc r30, r2

	mul r19, r22
	add r29, r0		;combine products
	adc r30, r1
	adc r31, r2

	mul r16, r23
	add r27, r0		;combine products
	adc r28, r1
	adc r29, r2

	mul r17, r23
	add r28, r0		;combine products
	adc r29, r1
	adc r30, r2

	mul r18, r23
	add r29, r0		;combine products
	adc r30, r1
	adc r31, r2

	mul r19, r23
	add r30, r0		;combine products
	adc r31, r1

DONE:
	jmp DONE	;program ends