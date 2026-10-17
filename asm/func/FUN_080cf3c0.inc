	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080CF400
	bl VM_GetValue
	ldr r2, _080CF3F8 @ =0x0000044C
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetValue
	ldr r2, _080CF3FC @ =0x0000044E
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	b _080CF412
	.align 2, 0
_080CF3F8: .4byte 0x0000044C
_080CF3FC: .4byte 0x0000044E
_080CF400:
	ldr r2, _080CF440 @ =0x0000044C
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
_080CF412:
	ldr r0, _080CF440 @ =0x0000044C
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CF43A
	cmp r1, #0
	blt _080CF43A
	ldr r0, _080CF444 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CF43A
	ldr r0, _080CF448 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CF44C
_080CF43A:
	movs r4, #0
	b _080CF45A
	.align 2, 0
_080CF440: .4byte 0x0000044C
_080CF444: .4byte 0x030046A8
_080CF448: .4byte 0x030046AC
_080CF44C:
	ldr r0, _080CF46C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CF45A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080CF470
	adds r0, #4
	b _080CF47C
	.align 2, 0
_080CF46C: .4byte 0x030046A4
_080CF470:
	ldr r0, _080CF490 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CF47C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CF494
	cmp r2, #2
	beq _080CF498
	b _080CF49C
	.align 2, 0
_080CF490: .4byte 0x030046A4
_080CF494:
	ldrb r0, [r5, #4]
	b _080CF49A
_080CF498:
	ldrb r0, [r5]
_080CF49A:
	subs r1, r1, r0
_080CF49C:
	ldr r2, _080CF538 @ =0x0000044E
	adds r0, r7, r2
	movs r4, #0
	strh r1, [r0]
	adds r5, r7, #0
	adds r5, #0x24
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080CF53C @ =0x0000044C
	adds r6, r7, r0
	ldrb r0, [r7, #0x18]
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	adds r2, r6, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r7, #0
	bl FUN_080cf15c
	adds r0, r7, #0
	bl FUN_080cf248
	ldr r1, _080CF540 @ =0x00000359
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, r7, #0
	adds r1, #0x88
	adds r0, r5, #0
	bl Mover_SetMainSprite
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r0, r4, #0
	adds r1, r6, #0
	bl Map_InitMoverTile
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl Mover_SetCollision
	ldr r1, _080CF544 @ =0xFFFF0000
	movs r0, #0x96
	lsls r0, r0, #0x11
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_0823b47c
	ldrh r1, [r7, #0x24]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #2
	bl EnemyTargetManager_Add
	ldr r2, _080CF548 @ =0x03002B68
	ldr r1, [r7, #0x18]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r2, [r7, #0x24]
	strh r2, [r1]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CF538: .4byte 0x0000044E
_080CF53C: .4byte 0x0000044C
_080CF540: .4byte 0x00000359
_080CF544: .4byte 0xFFFF0000
_080CF548: .4byte 0x03002B68
