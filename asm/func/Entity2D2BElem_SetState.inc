	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	movs r1, #1
	strb r1, [r0, #4]
	bx lr
