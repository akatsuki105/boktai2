	movs r1, #0
	strb r1, [r0]
	strh r1, [r0, #2]
	movs r1, #0xa
	strb r1, [r0, #1]
	ldr r1, [r0, #0x10]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x10]
	bx lr
