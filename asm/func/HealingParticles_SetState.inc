	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
