	adds r2, r0, #0
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
