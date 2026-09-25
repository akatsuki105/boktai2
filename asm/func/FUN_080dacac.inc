	adds r3, r2, #0
	adds r3, #0x40
	ldrh r1, [r3]
	movs r0, #2
	orrs r0, r1
	strh r0, [r3]
	adds r2, #0x52
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	bx lr
