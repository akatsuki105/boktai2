	movs r2, #0
	strb r1, [r0, #1]
	str r2, [r0, #4]
	movs r1, #1
	strb r1, [r0, #2]
	bx lr
