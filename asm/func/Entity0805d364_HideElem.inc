	push {lr}
	adds r3, r1, #0
	adds r2, r3, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	subs r2, #0x60
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r3, r1
	bl ParticleShadow_Hide
	pop {r1}
	bx r1
