	ldrb r1, [r0, #6]
	strb r1, [r0, #7]
	movs r1, #0x40
	strh r1, [r0, #0xc]
	bx lr
	.align 2, 0
