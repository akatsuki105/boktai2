	ldr r1, [r0, #0x30]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x30]
	adds r3, r0, #0
	adds r3, #0x90
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	adds r3, #0x60
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xcc
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x8a
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xba
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xc6
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bx lr
