	adds r3, r0, #0
	lsls r1, r1, #2
	adds r3, #0x84
	adds r3, r3, r1
	str r2, [r3]
	bx lr
