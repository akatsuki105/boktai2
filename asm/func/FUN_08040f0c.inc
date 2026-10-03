	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	strb r3, [r4, #0x1b]
	adds r5, r4, #0
	adds r5, #0x5c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #7
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	bl Mover_Init
	adds r4, #0xa0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823b464
	movs r1, #4
	ldrh r2, [r5, #2]
	orrs r1, r2
	strh r1, [r5, #2]
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
