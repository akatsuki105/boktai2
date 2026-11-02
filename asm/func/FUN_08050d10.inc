	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D22
	adds r1, r0, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
_08050D22:
	pop {r0}
	bx r0
	.align 2, 0
