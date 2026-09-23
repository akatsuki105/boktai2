	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	bx lr
