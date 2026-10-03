	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _0804FC02
	adds r1, r0, #0
	adds r1, #0x34
	movs r0, #1
	strb r0, [r1]
_0804FC02:
	pop {r0}
	bx r0
	.align 2, 0
