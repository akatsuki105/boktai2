	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r2, #0
	movs r3, #0
	movs r0, #0xa
	strh r0, [r6, #0x20]
	movs r0, #0x64
	strh r0, [r6, #0x22]
	strb r2, [r6, #0x1d]
	str r3, [r6, #0x18]
	strb r1, [r6, #0x1f]
	ldr r0, _0805D348 @ =0x0000922E
	ldr r1, _0805D34C @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x40]
	ldr r0, _0805D350 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805D354 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _0805D358 @ =0x00004CA0
	adds r2, r2, r3
	ldr r3, _0805D35C @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x40
	bl BlendPltt
	adds r4, r6, #0
	adds r4, #0x44
	movs r5, #0
_0805D30A:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl RingoBat_Init
	adds r5, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0xf
	ble _0805D30A
	movs r5, #0
	ldrb r3, [r6, #0x1f]
	cmp r5, r3
	bge _0805D33C
	adds r1, r6, #0
	adds r1, #0x28
	ldr r2, _0805D360 @ =0x03002BE0
_0805D32E:
	ldm r2!, {r0}
	adds r0, #0x2c
	stm r1!, {r0}
	adds r5, #1
	ldrb r0, [r6, #0x1f]
	cmp r5, r0
	blt _0805D32E
_0805D33C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D348: .4byte 0x0000922E
_0805D34C: .4byte 0x00005BB7
_0805D350: .4byte 0x03003584
_0805D354: .4byte 0x00004C60
_0805D358: .4byte 0x00004CA0
_0805D35C: .4byte 0x00001688
_0805D360: .4byte 0x03002BE0
