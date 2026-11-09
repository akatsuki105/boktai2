	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	str r0, [sp]
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0815D23E
	movs r0, #1
	b _0815D6BE
_0815D23E:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r1, #0xbc
	lsls r1, r1, #1
	add r1, r8
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	bne _0815D254
	b _0815D6BC
_0815D254:
	movs r6, #0x97
	lsls r6, r6, #3
	add r6, r8
	movs r0, #0xf6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0815D268
	b _0815D6BC
_0815D268:
	mov r0, r8
	movs r1, #6
	bl EnemyTargetManager_Claim
	adds r4, r0, #0
	cmp r4, #0
	bne _0815D278
	b _0815D6BC
_0815D278:
	movs r5, #0x80
	lsls r5, r5, #5
	movs r1, #0xc0
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r5
	str r1, [sp, #0x18]
	cmp r0, #0
	beq _0815D29C
	ldr r0, [r6]
	bl EnemyTargetManager_Release
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	bics r0, r5
	strh r0, [r1]
	str r7, [r6]
_0815D29C:
	movs r1, #0xec
	lsls r1, r1, #1
	add r1, r8
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #6]
	str r0, [sp, #4]
	ldr r2, _0815D2F0 @ =0x00000222
	add r2, r8
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xfc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0815D2C8
	b _0815D620
_0815D2C8:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r4, _0815D2F4 @ =0x00000256
	add r4, r8
	ldrh r6, [r4]
	mov r5, r8
	adds r5, #8
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	str r4, [sp, #0x10]
	str r5, [sp, #0xc]
	cmp r0, #0
	beq _0815D2F8
	adds r0, #4
	b _0815D304
	.align 2, 0
_0815D2F0: .4byte 0x00000222
_0815D2F4: .4byte 0x00000256
_0815D2F8:
	ldr r0, _0815D318 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D304:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815D31C
	cmp r3, #2
	beq _0815D320
	b _0815D324
	.align 2, 0
_0815D318: .4byte 0x030046A4
_0815D31C:
	ldrb r0, [r5, #4]
	b _0815D322
_0815D320:
	ldrb r0, [r5]
_0815D322:
	subs r2, r2, r0
_0815D324:
	mov sb, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815D336
	adds r0, #4
	b _0815D342
_0815D336:
	ldr r0, _0815D354 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D342:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r2, r8
	ldrb r0, [r2, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0815D358
	asrs r0, r0, #6
	b _0815D35E
	.align 2, 0
_0815D354: .4byte 0x030046A4
_0815D358:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0815D35E:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0815D3A6
	cmp r1, #1
	bgt _0815D370
	cmp r1, #0
	beq _0815D37A
	b _0815D484
_0815D370:
	cmp r1, #2
	beq _0815D3EC
	cmp r1, #3
	beq _0815D418
	b _0815D484
_0815D37A:
	adds r4, r6, #1
	movs r5, #0
	ldr r0, [sp, #8]
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r0, r0, r1
	mov sl, r0
_0815D388:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D3A2
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0815D388
_0815D3A2:
	subs r5, r4, #1
	b _0815D492
_0815D3A6:
	ldr r1, _0815D3E8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
	ldr r0, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r0, r0, r2
	mov sl, r0
_0815D3BE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D45C
	ldr r0, _0815D3E8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0815D3BE
	subs r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D3E8: .4byte 0x030046A4
_0815D3EC:
	subs r4, r6, #1
	movs r5, #0
	ldr r2, [sp, #8]
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r2, r2, r0
	mov sl, r2
_0815D3FA:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D414
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0815D3FA
_0815D414:
	adds r5, r4, #1
	b _0815D492
_0815D418:
	ldr r1, _0815D458 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
	ldr r0, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r0, r0, r2
	mov sl, r0
_0815D430:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D470
	ldr r0, _0815D458 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0815D430
	adds r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D458: .4byte 0x030046A4
_0815D45C:
	ldr r1, _0815D46C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D46C: .4byte 0x030046A4
_0815D470:
	ldr r1, _0815D480 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D480: .4byte 0x030046A4
_0815D484:
	ldr r0, [sp, #0x10]
	ldrh r5, [r0]
	ldr r1, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r1, r2
	mov sl, r1
_0815D492:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _0815D514
	mov r6, sl
	ldr r1, _0815D4D8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815D4D8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815D4DC
	adds r0, #4
	b _0815D4E8
	.align 2, 0
_0815D4D8: .4byte 0x030046A4
_0815D4DC:
	ldr r1, _0815D50C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815D4E8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r2, [sp, #8]
	ldr r1, _0815D510 @ =0x000006E2
	adds r0, r2, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0815D570
	movs r0, #0
	b _0815D572
	.align 2, 0
_0815D50C: .4byte 0x030046A4
_0815D510: .4byte 0x000006E2
_0815D514:
	mov r6, sl
	ldr r1, _0815D550 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815D550 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815D554
	adds r0, #4
	b _0815D560
	.align 2, 0
_0815D550: .4byte 0x030046A4
_0815D554:
	ldr r1, _0815D5D0 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815D560:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
_0815D570:
	movs r0, #1
_0815D572:
	cmp r0, #0
	beq _0815D620
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815D5FC
	ldr r0, _0815D5D4 @ =0x0000025E
	add r0, r8
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	cmp r0, r1
	beq _0815D602
	ldr r0, _0815D5D8 @ =0x000004A4
	add r0, r8
	ldr r5, [r0]
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _0815D5DC
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815D5DC
	cmp r0, #2
	beq _0815D5E6
	mov r0, r8
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0815D5E6
	.align 2, 0
_0815D5D0: .4byte 0x030046A4
_0815D5D4: .4byte 0x0000025E
_0815D5D8: .4byte 0x000004A4
_0815D5DC:
	ldr r0, _0815D5F4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x18]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0815D5E6:
	ldr r0, _0815D5F8 @ =0x0000025E
	add r0, r8
	mov r1, sp
	ldrh r1, [r1, #4]
	strh r1, [r0]
	b _0815D602
	.align 2, 0
_0815D5F4: .4byte 0xFFFFFDFF
_0815D5F8: .4byte 0x0000025E
_0815D5FC:
	mov r0, r8
	bl Enemy_Alert
_0815D602:
	movs r0, #0x80
	movs r2, #0xc1
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #1
	b _0815D6BE
_0815D620:
	ldr r0, _0815D6A0 @ =0x00000544
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _0815D6BC
	movs r3, #0x80
	ldr r1, [sp, #0x14]
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _0815D6BC
	ldr r0, [sp]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _0815D6A4 @ =0xFFFBFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0815D6A8 @ =0xFFFFFBFF
	ldr r2, [sp, #0x18]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0815D6AC @ =0x00000542
	add r1, r8
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, [sp, #0x14]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r1, _0815D6B0 @ =0x00000202
	add r1, r8
	movs r0, #0xb4
	strh r0, [r1]
	adds r0, #0x4c
	movs r2, #0xc1
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0815D6B4 @ =0x000001DF
	add r0, r8
	ldrb r3, [r0]
	mov r0, r8
	movs r1, #0
	movs r2, #1
	bl Enemy_SetEmote
	ldr r0, [sp]
	ldr r1, _0815D6B8 @ =0x000006F4
	adds r2, r0, r1
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _0815D6BE
	.align 2, 0
_0815D6A0: .4byte 0x00000544
_0815D6A4: .4byte 0xFFFBFFFF
_0815D6A8: .4byte 0xFFFFFBFF
_0815D6AC: .4byte 0x00000542
_0815D6B0: .4byte 0x00000202
_0815D6B4: .4byte 0x000001DF
_0815D6B8: .4byte 0x000006F4
_0815D6BC:
	movs r0, #0
_0815D6BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
