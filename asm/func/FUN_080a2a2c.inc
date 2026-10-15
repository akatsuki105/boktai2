	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x50]
	adds r0, r2, #0
	adds r0, #0x7c
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0
