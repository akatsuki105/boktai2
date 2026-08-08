	push {r4, lr}
	sub sp, #4
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x78
	adds r0, #0x98
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r2, [r1]
	adds r2, #4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #4
	str r1, [sp]
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, [r4, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x28]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
