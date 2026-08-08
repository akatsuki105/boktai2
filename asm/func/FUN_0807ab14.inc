	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	subs r1, #0x9a
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08063220
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r5, [r0]
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0
	bl FUN_08060b84
	pop {r4, r5}
	pop {r0}
	bx r0
