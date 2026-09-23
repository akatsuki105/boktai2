	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [sp, #0xc]
	str r0, [sp]
	adds r0, r4, #0
	bl TextRenderer_SetRect
	adds r0, r4, #0
	bl FUN_08049640
	adds r0, r4, #0
	bl FUN_08049668
	movs r0, #0
	strb r0, [r4, #0xa]
	strb r0, [r4, #0xb]
	ldrb r1, [r4, #9]
	strb r1, [r4, #0xc]
	strb r0, [r4, #0x13]
	strb r0, [r4, #0xd]
	str r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	str r0, [r4, #0x28]
	movs r1, #0xff
	strb r1, [r4, #0x15]
	movs r1, #1
	strb r1, [r4, #0x14]
	str r0, [r4, #0x18]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
