	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	strb r5, [r4, #1]
	strb r5, [r4, #2]
	strb r5, [r4, #3]
	ldr r0, [r4, #0x24]
	movs r6, #1
	orrs r0, r6
	str r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x50
	bl ParticleShadow_Hide
	str r5, [r4, #0x20]
	strh r5, [r4, #6]
	strb r6, [r4, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
