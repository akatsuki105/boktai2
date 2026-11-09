	adds r3, r0, #0
	adds r3, #0xfa
	movs r2, #0
	strb r1, [r3]
	adds r0, #0xfb
	strb r2, [r0]
	bx lr
	.align 2, 0
