	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr
