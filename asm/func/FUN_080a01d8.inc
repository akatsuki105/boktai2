	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl Entity71BA_IsPlayerAtHeight
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0250
	adds r0, r4, #0
	bl Entity71BA_IsPlayerOnTile
	cmp r0, #0
	beq _080A0228
	adds r0, r4, #0
	bl FUN_080a0140
	adds r5, r0, #0
	cmp r5, #0
	bne _080A0228
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
	ldr r0, _080A0224 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a334
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _080A0260
	movs r1, #0
	bl VM_ExecByID
	b _080A0260
	.align 2, 0
_080A0224: .4byte 0x03002BE0
_080A0228:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A024C @ =0x0000082A
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A0260
	.align 2, 0
_080A024C: .4byte 0x0000082A
_080A0250:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
_080A0260:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
