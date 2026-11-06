	movs r0, #0x8f
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x91
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
