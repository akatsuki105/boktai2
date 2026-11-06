	lsls r3, r2, #3
	adds r3, r3, r2
	lsls r3, r3, #3
	adds r3, r3, r2
	lsls r3, r3, #2
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r3
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr
