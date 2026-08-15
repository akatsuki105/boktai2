	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r0, [r6, #0x18]
	adds r1, r6, #0
	adds r1, #8
	bl FUN_0823280c
	strh r4, [r6, #0x1c]
	strh r5, [r6, #0x1e]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
