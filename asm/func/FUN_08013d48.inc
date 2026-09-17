	push {lr}
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq _08013D56
	movs r0, #1
	rsbs r0, r0, #0
	b _08013D6A
_08013D56:
	str r2, [r1, #0x4c]
	ldr r2, [r0, #0x18]
	str r2, [r1, #0x50]
	cmp r2, #0
	beq _08013D62
	str r1, [r2, #0x4c]
_08013D62:
	str r1, [r0, #0x18]
	movs r0, #1
	strb r0, [r1, #2]
	movs r0, #0
_08013D6A:
	pop {r1}
	bx r1
	.align 2, 0
