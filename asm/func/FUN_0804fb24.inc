	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _0804FB36
	adds r1, r0, #0
	adds r1, #0x33
	movs r0, #1
	strb r0, [r1]
_0804FB36:
	pop {r0}
	bx r0
	.align 2, 0
