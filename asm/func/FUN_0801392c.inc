	push {lr}
	ldrb r2, [r1]
	cmp r2, #0
	beq _0801393A
	movs r0, #1
	rsbs r0, r0, #0
	b _0801394E
_0801393A:
	str r2, [r1, #0x64]
	ldr r2, [r0, #0x1c]
	str r2, [r1, #0x68]
	cmp r2, #0
	beq _08013946
	str r1, [r2, #0x64]
_08013946:
	str r1, [r0, #0x1c]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0801394E:
	pop {r1}
	bx r1
	.align 2, 0
