	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
