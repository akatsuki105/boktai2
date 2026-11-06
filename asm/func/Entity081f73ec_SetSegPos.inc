	lsls r3, r1, #3
	adds r3, r3, r1
	lsls r3, r3, #3
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	bx lr
	.align 2, 0
