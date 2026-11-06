	ldr r2, [r1, #0x30]
	movs r3, #1
	orrs r2, r3
	str r2, [r1, #0x30]
	bx lr
	.align 2, 0
