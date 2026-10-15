	str r1, [r0, #0x78]
	adds r0, #0x76
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
