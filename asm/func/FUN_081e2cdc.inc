	adds r3, r0, #0
	ldr r0, [r3, #0x30]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
	adds r2, r3, #0
	adds r2, #0x90
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x60
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x84
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xfc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xae
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xba
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bx lr
