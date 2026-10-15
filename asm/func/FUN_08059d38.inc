	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r5, #0xbc
	ldr r3, [r5]
	movs r4, #1
	orrs r3, r4
	str r3, [r5]
	adds r1, #0x6c
	ldrh r5, [r1, #6]
	movs r3, #4
	orrs r3, r5
	strh r3, [r1, #6]
	lsls r4, r2
	ldr r1, [r6, #0x18]
	bics r1, r4
	str r1, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
