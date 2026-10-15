	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r0, #0x18
	strb r0, [r2]
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, [r3, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x50]
	adds r0, r3, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0
