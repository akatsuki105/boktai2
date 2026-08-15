	movs r2, #4
	ldrh r3, [r0, #2]
	orrs r2, r3
	strh r2, [r0, #2]
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x30]
	str r2, [r0, #0x34]
	movs r0, #1
	bx lr
