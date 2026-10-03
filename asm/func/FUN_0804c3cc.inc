	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C3DE
	movs r1, #0
	strb r1, [r2]
_0804C3DE:
	pop {r1}
	bx r1
	.align 2, 0
