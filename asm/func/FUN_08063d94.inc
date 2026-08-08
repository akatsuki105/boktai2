	movs r1, #0xd7
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r0, r0, #3
	bx lr
