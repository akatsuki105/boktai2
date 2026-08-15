	push {lr}
	adds r0, #0x20
	movs r1, #1
	bl FUN_08022488
	pop {r0}
	bx r0
	.align 2, 0
