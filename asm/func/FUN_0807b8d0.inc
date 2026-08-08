	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x2c]
	str r2, [r0, #0x30]
	bx lr
	.align 2, 0
