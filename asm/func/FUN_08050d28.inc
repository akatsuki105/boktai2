	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D3A
	adds r1, r0, #0
	adds r1, #0x2e
	movs r0, #1
	strb r0, [r1]
_08050D3A:
	pop {r0}
	bx r0
	.align 2, 0
