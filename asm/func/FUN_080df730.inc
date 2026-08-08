	adds r3, r2, #0
	movs r0, #0xd7
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #2
	strb r0, [r1]
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #0xf4
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	bx lr
	.align 2, 0
