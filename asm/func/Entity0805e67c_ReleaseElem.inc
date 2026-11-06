	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	adds r6, r2, #0
	adds r1, #0xc4
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	adds r2, r3, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r3, r1
	bl ParticleShadow_Hide
	lsls r4, r6
	ldr r1, [r5, #0x18]
	bics r1, r4
	str r1, [r5, #0x18]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
