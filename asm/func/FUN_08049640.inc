	movs r1, #0
	strb r1, [r0, #6]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r0, r3
	strb r1, [r2]
	strb r1, [r0, #7]
	bx lr
