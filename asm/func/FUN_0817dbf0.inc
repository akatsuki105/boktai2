	ldr r0, [r0, #0x44]
	adds r0, #0x20
	str r1, [r0, #0x48]
	strh r2, [r0, #0x3a]
	bx lr
	.align 2, 0
