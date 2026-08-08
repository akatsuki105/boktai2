	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	adds r1, r3, #1
	movs r2, #0xff
	ands r1, r2
	str r1, [r0]
	adds r0, r3, #0
	bx lr
