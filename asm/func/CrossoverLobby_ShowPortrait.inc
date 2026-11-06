	ldr r2, [r1, #0x30]
	movs r3, #2
	rsbs r3, r3, #0
	ands r2, r3
	str r2, [r1, #0x30]
	bx lr
