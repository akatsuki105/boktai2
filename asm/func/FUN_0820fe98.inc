	str r1, [r0, #0x1c]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
