	movs r1, #0
	str r1, [r0]
	str r1, [r0, #0x24]
	adds r1, r0, #0
	adds r1, #0x20
	str r1, [r0, #4]
	str r0, [r0, #0x20]
	bx lr
