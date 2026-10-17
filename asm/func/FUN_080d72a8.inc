	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	bl Mover_ApplyMove
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D72CE
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _080D72EC
_080D72CE:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	ldr r0, _080D7304 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r4, #0
	adds r1, #0x2c
	movs r2, #0
	bl Hitbox_SetPos
_080D72EC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D7308
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080D7314
	.align 2, 0
_080D7304: .4byte 0x0000FFFB
_080D7308:
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080D7314:
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D7330
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080D733A
_080D7330:
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080D733A:
	str r1, [r0]
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2e]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _080D7370 @ =0x000003F6
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D7370: .4byte 0x000003F6
