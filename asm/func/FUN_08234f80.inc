	lsls r2, r2, #0x18
	lsrs r2, r2, #0x15
	adds r2, r2, r1
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r0, #4]
	bx lr
