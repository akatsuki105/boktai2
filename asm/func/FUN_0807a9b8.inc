	adds r2, r0, #0
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
