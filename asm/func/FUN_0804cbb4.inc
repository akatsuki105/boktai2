	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CBC6
	movs r1, #0
	strb r1, [r2]
_0804CBC6:
	pop {r1}
	bx r1
	.align 2, 0
