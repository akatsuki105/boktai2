	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl Entity71BA_IsPlayerAtHeight
	adds r5, r0, #0
	cmp r5, #0
	bne _080A036E
	b _080A0490
_080A036E:
	adds r0, r4, #0
	bl Entity71BA_IsPlayerOnTile
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0442
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A03BE
	ldr r2, _080A03A4 @ =0x03002BE0
	ldr r1, [r2]
	ldr r0, _080A03A8 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A03B0
	ldr r0, [r2]
	ldr r1, _080A03AC @ =0x000003BD
	adds r0, r0, r1
	movs r1, #7
	b _080A03B8
	.align 2, 0
_080A03A4: .4byte 0x03002BE0
_080A03A8: .4byte 0x000003F3
_080A03AC: .4byte 0x000003BD
_080A03B0:
	ldr r0, [r2]
	ldr r1, _080A0428 @ =0x000003BD
	adds r0, r0, r1
	movs r1, #1
_080A03B8:
	strb r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x22]
_080A03BE:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A03D0
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	movs r0, #0
	strb r0, [r4, #0x1d]
_080A03D0:
	adds r0, r4, #0
	movs r1, #0x28
	bl Entity71BA_ClampPlayer
	ldr r0, _080A042C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080A04B6
	ldr r0, _080A0430 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A03FC
	ldr r0, _080A0434 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A03FC
	movs r1, #1
_080A03FC:
	cmp r1, #0
	bne _080A04B6
	ldr r0, _080A042C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04B6
	cmp r0, #3
	beq _080A04B6
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0438
	adds r0, r2, #0
	movs r1, #7
	bl FUN_0807a44c
	b _080A04B6
	.align 2, 0
_080A0428: .4byte 0x000003BD
_080A042C: .4byte 0x03002BE0
_080A0430: .4byte 0x03002B8C
_080A0434: .4byte 0x03002B60
_080A0438:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_0807a44c
	b _080A04B6
_080A0442:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A0458
	ldr r0, _080A0484 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A0488 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A0458:
	adds r0, r4, #0
	bl FUN_080a0268
	cmp r0, #0
	bne _080A04A6
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A048C @ =0x0000080B
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A04B6
	.align 2, 0
_080A0484: .4byte 0x03002BE0
_080A0488: .4byte 0x000003F3
_080A048C: .4byte 0x0000080B
_080A0490:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A04A6
	ldr r0, _080A04C0 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A04C4 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A04A6:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
_080A04B6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A04C0: .4byte 0x03002BE0
_080A04C4: .4byte 0x000003F3
