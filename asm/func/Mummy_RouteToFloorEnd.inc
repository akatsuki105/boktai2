	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r2, _08128310 @ =0x000006FE
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081282EC
	b _081286B6
_081282EC:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	asrs r4, r0, #6
	movs r0, #3
	ands r4, r0
	ldr r3, _08128314 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	mov sb, r0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812831C
	adds r0, #4
	ldr r6, _08128318 @ =0x030046A4
	b _0812832C
	.align 2, 0
_08128310: .4byte 0x000006FE
_08128314: .4byte 0x00000256
_08128318: .4byte 0x030046A4
_0812831C:
	ldr r2, _08128358 @ =0x030046A4
	ldr r1, [r2]
	mov r5, sb
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	adds r6, r2, #0
_0812832C:
	ldrb r0, [r0]
	movs r1, #0xf
	mov sl, r1
	mov r2, sl
	ands r2, r0
	mov sl, r2
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r5, r1, #0
	muls r5, r0, r5
	cmp r4, #1
	beq _081283F2
	cmp r4, #1
	bgt _0812835C
	cmp r4, #0
	beq _0812836A
	b _08128584
	.align 2, 0
_08128358: .4byte 0x030046A4
_0812835C:
	cmp r4, #2
	bne _08128362
	b _08128472
_08128362:
	cmp r4, #3
	bne _08128368
	b _08128506
_08128368:
	b _08128584
_0812836A:
	mov r4, sb
	adds r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _08128384
	b _08128584
_08128384:
	mov r8, r6
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0812838C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812839C
	adds r0, #4
	b _081283A4
_0812839C:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081283A4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081283D0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081283BE
	adds r0, #4
	b _081283C6
_081283BE:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081283C6:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081283D4
_081283D0:
	movs r0, #0
	b _081283D6
_081283D4:
	movs r0, #1
_081283D6:
	cmp r0, #0
	bne _081283DC
	b _081284E6
_081283DC:
	adds r6, #4
	adds r4, #1
	adds r5, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r5, r0
	blt _0812838C
	b _08128584
_081283F2:
	mov r3, sb
	adds r4, r3, r1
	cmp r5, r4
	bgt _081283FC
	b _08128584
_081283FC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812840C
	adds r0, #4
	b _08128418
_0812840C:
	ldr r0, _08128434 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128418:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _08128450
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08128438
	adds r0, #4
	ldr r6, _08128434 @ =0x030046A4
	b _08128446
	.align 2, 0
_08128434: .4byte 0x030046A4
_08128438:
	ldr r2, _08128458 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	adds r6, r2, #0
_08128446:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0812845C
_08128450:
	movs r0, #0
	ldr r6, _08128458 @ =0x030046A4
	b _0812845E
	.align 2, 0
_08128458: .4byte 0x030046A4
_0812845C:
	movs r0, #1
_0812845E:
	cmp r0, #0
	beq _081284EA
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	cmp r5, r4
	bgt _081283FC
	b _08128584
_08128472:
	mov r4, sb
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	bge _08128484
	b _08128584
_08128484:
	mov r8, r6
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0812848C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812849C
	adds r0, #4
	b _081284A4
_0812849C:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081284A4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081284D0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081284BE
	adds r0, #4
	b _081284C6
_081284BE:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081284C6:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081284D4
_081284D0:
	movs r0, #0
	b _081284D6
_081284D4:
	movs r0, #1
_081284D6:
	cmp r0, #0
	beq _081284F6
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _0812848C
	b _08128584
_081284E6:
	subs r5, r4, #1
	b _08128586
_081284EA:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	subs r5, r4, r0
	b _08128586
_081284F6:
	adds r5, r4, #1
	b _08128586
_081284FA:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _08128586
_08128506:
	mov r2, sb
	subs r4, r2, r1
	cmp r4, #0
	blt _08128584
_0812850E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812851E
	adds r0, #4
	b _0812852A
_0812851E:
	ldr r0, _08128548 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812852A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _08128564
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812854C
	adds r0, #4
	ldr r6, _08128548 @ =0x030046A4
	b _0812855A
	.align 2, 0
_08128548: .4byte 0x030046A4
_0812854C:
	ldr r2, _0812856C @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	adds r6, r2, #0
_0812855A:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08128570
_08128564:
	movs r0, #0
	ldr r6, _0812856C @ =0x030046A4
	b _08128572
	.align 2, 0
_0812856C: .4byte 0x030046A4
_08128570:
	movs r0, #1
_08128572:
	cmp r0, #0
	beq _081284FA
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r4, r0
	cmp r4, #0
	bge _0812850E
_08128584:
	mov r5, sb
_08128586:
	ldr r1, _081285D0 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	bne _08128592
	b _081286B6
_08128592:
	mov sb, sp
	ldr r6, _081285D4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081285D8
	adds r0, #4
	b _081285E2
	.align 2, 0
_081285D0: .4byte 0x00000256
_081285D4: .4byte 0x030046A4
_081285D8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081285E2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r5, sb
	strh r0, [r5, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	ldrh r1, [r7, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r2, _0812861C @ =0x000004A4
	adds r0, r7, r2
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08128620
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	b _08128646
	.align 2, 0
_0812861C: .4byte 0x000004A4
_08128620:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08128640
	cmp r0, #2
	beq _0812863C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812863C:
	movs r0, #1
	b _08128650
_08128640:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
_08128646:
	ldr r1, _08128664 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08128650:
	adds r4, r0, #0
	cmp r4, #0
	beq _0812866C
	ldr r0, [sp, #8]
	ldr r2, _08128668 @ =0x000006FE
	adds r1, r0, r2
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #1
	b _081286B8
	.align 2, 0
_08128664: .4byte 0xFFFFFDFF
_08128668: .4byte 0x000006FE
_0812866C:
	ldr r1, _081286C8 @ =Enemy_ClearStateBegun
	ldr r3, _081286CC @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081286D0 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r2, _081286D4 @ =0x00000553
	adds r0, r7, r2
	strb r4, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081286D8 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _081286DC @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
_081286B6:
	movs r0, #0
_081286B8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081286C8: .4byte Enemy_ClearStateBegun
_081286CC: .4byte 0x0000046D
_081286D0: .4byte 0x0000046B
_081286D4: .4byte 0x00000553
_081286D8: .4byte 0x00000469
_081286DC: .4byte 0x0000046C
