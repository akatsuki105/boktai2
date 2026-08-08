	ldrh r3, [r1]
	strh r3, [r0, #0xc]
	ldrh r3, [r1, #2]
	strh r3, [r0, #0xe]
	ldrh r1, [r1, #4]
	strh r1, [r0, #0x10]
	strh r2, [r0, #8]
	bx lr
