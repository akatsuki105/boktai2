	push {lr}
	movs r2, #1
	str r2, [r0, #0x70]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_08022488
	pop {r0}
	bx r0
	.align 2, 0
