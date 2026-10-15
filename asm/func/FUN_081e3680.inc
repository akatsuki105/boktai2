	adds r3, r0, #0
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x40
	strh r0, [r1]
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0x68
	strh r2, [r0]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x48
	strh r0, [r1]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r3, r1
	strh r2, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #0x50
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xaa
	strh r2, [r0]
	subs r1, #0x60
	movs r0, #0x58
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4a
	strh r2, [r0]
	ldr r0, [r3, #0x30]
	subs r2, #0x6a
	ands r0, r2
	str r0, [r3, #0x30]
	adds r1, #0x48
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	bx lr
