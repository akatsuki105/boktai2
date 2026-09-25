	adds r1, r0, #0
	adds r1, #0x48
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #8
	adds r0, #0x8e
	strh r1, [r0]
	bx lr
