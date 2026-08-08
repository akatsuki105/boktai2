	adds r3, r0, #0
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #8]
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1, #8]
	ands r0, r2
	str r0, [r1, #8]
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	bx lr
