	movs r3, #0x98
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xee
	movs r1, #0
	strh r1, [r0]
	bx lr
