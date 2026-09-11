	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	bne _080A9F02
	ldr r0, [r4, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r4, #0x20]
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, [r4, #0x18]
	ldr r2, _080A9F60 @ =0x00000366
	adds r0, r3, r2
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A9F02
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, #1
	strb r0, [r4, #0x1c]
_080A9F02:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A9F34
	ldr r0, [r4, #0x18]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r1, [r4, #0x22]
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, [r4, #0x18]
	ldr r2, _080A9F64 @ =0x0000036A
	adds r0, r3, r2
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A9F34
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, #1
	strb r0, [r4, #0x1d]
_080A9F34:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A9F58
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A9F58
	ldr r0, _080A9F68 @ =0x00000259
	bl sound_08240740
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _080A9F52
	movs r1, #0
	bl Script_ExecById
_080A9F52:
	adds r0, r4, #0
	bl KillEntity
_080A9F58:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9F60: .4byte 0x00000366
_080A9F64: .4byte 0x0000036A
_080A9F68: .4byte 0x00000259
