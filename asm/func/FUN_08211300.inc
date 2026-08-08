	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xa8
	adds r0, #0x26
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	strh r0, [r2, #0x20]
	adds r0, r3, #0
	adds r0, #0x27
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	strh r0, [r2, #0x22]
	bx lr
	.align 2, 0
