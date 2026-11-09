	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _0805EC02
	movs r0, #0
	strb r0, [r2, #2]
_0805EC02:
	ldr r0, [r2, #0x14]
	cmp r0, #0x32
	bne _0805EC16
	movs r0, #3
	movs r1, #0
	strb r0, [r2, #1]
	movs r0, #1
	strb r0, [r2, #2]
	str r1, [r2, #0x14]
	b _0805EC1A
_0805EC16:
	adds r0, #1
	str r0, [r2, #0x14]
_0805EC1A:
	pop {r0}
	bx r0
	.align 2, 0
