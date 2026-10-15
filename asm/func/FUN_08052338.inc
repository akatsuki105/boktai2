	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	beq _08052346
	movs r0, #0
	strb r0, [r1, #0x1d]
_08052346:
	pop {r0}
	bx r0
	.align 2, 0
