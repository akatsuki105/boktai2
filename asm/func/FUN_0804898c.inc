	ldrb r1, [r0, #2]
	strb r1, [r0]
	ldrb r1, [r0, #1]
	adds r1, #2
	strb r1, [r0, #1]
	bx lr
