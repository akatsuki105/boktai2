	movs r1, #0x80
	lsls r1, r1, #0x11
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
