	movs r3, #0x84
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xec
	movs r1, #0
	strh r1, [r0]
	bx lr
