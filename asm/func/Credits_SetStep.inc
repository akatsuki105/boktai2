	movs r2, #0
	strb r1, [r0, #0x18]
	movs r1, #1
	strb r1, [r0, #0x19]
	str r2, [r0, #0x20]
	bx lr
