	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	strh r2, [r0]
	bx lr
