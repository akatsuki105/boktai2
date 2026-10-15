	adds r2, r0, #0
	adds r2, #0xac
	str r1, [r2]
	adds r0, #0x9a
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
