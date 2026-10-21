	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl Entity71BA_IsPlayerAtHeight
	adds r5, r0, #0
	cmp r5, #0
	beq _080A05D0
	adds r0, r4, #0
	bl Entity71BA_IsPlayerOnTile
	cmp r0, #0
	beq _080A0580
	adds r0, r4, #0
	bl IsPlayerSmall
	cmp r0, #0
	beq _080A053E
	adds r0, r4, #0
	movs r1, #0x40
	bl Entity71BA_ClampPlayer
	b _080A05E0
_080A053E:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	ldrb r1, [r4, #0x1c]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080A055C
	ldrh r1, [r4, #0x2a]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4, #0x2a]
	b _080A056E
_080A055C:
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
	ldr r0, _080A057C @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a334
_080A056E:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _080A05E0
	movs r1, #0
	bl VM_ExecByID
	b _080A05E0
	.align 2, 0
_080A057C: .4byte 0x03002BE0
_080A0580:
	adds r0, r4, #0
	bl IsPlayerSmall
	cmp r0, #0
	beq _080A05BC
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080a0104
	cmp r0, #0
	beq _080A05BC
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A05B8 @ =0x0000082A
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A05E0
	.align 2, 0
_080A05B8: .4byte 0x0000082A
_080A05BC:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	movs r0, #0
	strb r0, [r4, #0x1d]
	b _080A05E0
_080A05D0:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
_080A05E0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
