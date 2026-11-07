	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0814FBBC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814FBC0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814FBC2
	.align 2, 0
_0814FBBC: .4byte 0x0000046C
_0814FBC0:
	movs r0, #0
_0814FBC2:
	cmp r0, #0
	beq _0814FC40
	ldr r4, _0814FC54 @ =FUN_0814caa0
	movs r3, #0xa
	ldr r2, _0814FC58 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814FC5C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl Enemy_SetEmote
	adds r0, r5, #0
	bl Enemy_RunScript
	ldr r2, _0814FC60 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0814FC24
	movs r0, #4
	ldr r1, _0814FC64 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0814FC24:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_0814FC40:
	ldr r1, _0814FC5C @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814FC68
	adds r0, r5, #0
	bl enemy_dog_0814a320
	b _0814FC72
	.align 2, 0
_0814FC54: .4byte FUN_0814caa0
_0814FC58: .4byte 0x0000046D
_0814FC5C: .4byte 0x0000046B
_0814FC60: .4byte 0x000001DF
_0814FC64: .4byte 0x00000222
_0814FC68:
	ldr r2, _0814FC78 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0814FC72:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814FC78: .4byte 0x00000484
