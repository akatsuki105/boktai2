	movs r2, #0xc2
	lsls r2, r2, #2
	adds r0, r0, r2
	str r1, [r0]
	bx lr
	.align 2, 0
