	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #8]
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r6, r1, #6
	adds r0, r6, #2
	str r0, [sp, #0xc]
	movs r0, #3
	ldr r1, [sp, #0xc]
	ands r1, r0
	str r1, [sp, #0xc]
	movs r2, #0
	str r2, [sp, #0x10]
_0810521A:
	ldr r3, [sp, #0xc]
	cmp r6, r3
	bne _08105222
	b _08105580
_08105222:
	cmp r6, #1
	beq _0810524C
	cmp r6, #1
	bgt _08105230
	cmp r6, #0
	beq _0810523A
	b _081052A0
_08105230:
	cmp r6, #2
	beq _0810526C
	cmp r6, #3
	beq _08105280
	b _081052A0
_0810523A:
	ldr r0, [sp, #8]
	ldr r2, _08105248 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	adds r7, r0, #1
	mov r8, r1
	b _081052AA
	.align 2, 0
_08105248: .4byte 0x00000256
_0810524C:
	ldr r3, [sp, #8]
	ldr r0, _08105264 @ =0x00000256
	adds r1, r3, r0
	ldr r2, _08105268 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r2, [r1]
	adds r7, r0, r2
	mov r8, r1
	b _081052AA
	.align 2, 0
_08105264: .4byte 0x00000256
_08105268: .4byte 0x030046A4
_0810526C:
	ldr r3, [sp, #8]
	ldr r0, _0810527C @ =0x00000256
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r7, r0, #1
	mov r8, r1
	b _081052AA
	.align 2, 0
_0810527C: .4byte 0x00000256
_08105280:
	ldr r2, [sp, #8]
	ldr r3, _08105298 @ =0x00000256
	adds r1, r2, r3
	ldrh r2, [r1]
	ldr r3, _0810529C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	mov r8, r1
	b _081052AA
	.align 2, 0
_08105298: .4byte 0x00000256
_0810529C: .4byte 0x030046A4
_081052A0:
	ldr r1, [sp, #8]
	ldr r2, _081052BC @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	mov r8, r0
_081052AA:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081052C0
	adds r0, #4
	b _081052CC
	.align 2, 0
_081052BC: .4byte 0x00000256
_081052C0:
	ldr r3, _081052E8 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081052CC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x14]
	mov r0, r8
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081052EC
	adds r0, #4
	b _081052F8
	.align 2, 0
_081052E8: .4byte 0x030046A4
_081052EC:
	ldr r1, _08105310 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081052F8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x18]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105314
	adds r0, #4
	b _08105320
	.align 2, 0
_08105310: .4byte 0x030046A4
_08105314:
	ldr r2, _08105360 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105320:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x1c]
	mov sl, sp
	ldr r5, _08105360 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105364
	adds r0, #4
	b _0810536E
	.align 2, 0
_08105360: .4byte 0x030046A4
_08105364:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810536E:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r3, sl
	strh r1, [r3, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105394
	adds r0, #4
	b _081053A0
_08105394:
	ldr r2, _081053B8 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081053A0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081053BC
	cmp r2, #2
	beq _081053C0
	b _081053C4
	.align 2, 0
_081053B8: .4byte 0x030046A4
_081053BC:
	ldrb r0, [r4, #4]
	b _081053C2
_081053C0:
	ldrb r0, [r4]
_081053C2:
	subs r1, r1, r0
_081053C4:
	str r1, [sp, #0x20]
	mov r0, r8
	ldrh r5, [r0]
	mov sl, sp
	ldr r1, _08105408 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _08105408 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810540C
	adds r0, #4
	b _08105418
	.align 2, 0
_08105408: .4byte 0x030046A4
_0810540C:
	ldr r3, _08105444 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105418:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r0, sl
	strh r1, [r0, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	mov r2, sl
	strh r0, [r2, #4]
	mov r3, r8
	ldrh r4, [r3]
	mov r5, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08105448
	adds r0, #4
	b _08105454
	.align 2, 0
_08105444: .4byte 0x030046A4
_08105448:
	ldr r1, _0810546C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105454:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08105470
	cmp r2, #2
	beq _08105474
	b _08105478
	.align 2, 0
_0810546C: .4byte 0x030046A4
_08105470:
	ldrb r0, [r5, #4]
	b _08105476
_08105474:
	ldrb r0, [r5]
_08105476:
	subs r1, r1, r0
_08105478:
	ldr r0, [sp, #0x20]
	subs r2, r0, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	ldr r1, [sp, #0x20]
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x1c]
	ands r3, r0
	cmp r3, #0
	bne _08105580
	cmp r2, #0
	beq _0810557A
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _081054B6
	cmp r6, #1
	bne _081054B0
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _081054CC
	movs r0, #0x80
	lsls r0, r0, #1
	b _081054DA
_081054B0:
	cmp r6, #3
	bne _08105580
	b _081054D6
_081054B6:
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _081054DE
	cmp r6, #0
	bne _081054D2
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _081054CC
	movs r0, #0x80
	lsls r0, r0, #1
	b _081054DA
_081054CC:
	cmp r1, #0
	beq _081054DE
	b _08105580
_081054D2:
	cmp r6, #2
	bne _08105580
_081054D6:
	ldr r3, [sp, #0x18]
	ldr r0, _081054F4 @ =0xFFFFFF00
_081054DA:
	cmp r1, r0
	bne _08105580
_081054DE:
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bne _08105504
	cmp r6, #1
	bne _081054F8
	ldr r3, [sp, #0x14]
	cmp r3, #1
	bne _08105514
	movs r0, #0x80
	lsls r0, r0, #1
	b _08105530
	.align 2, 0
_081054F4: .4byte 0xFFFFFF00
_081054F8:
	cmp r6, #3
	bne _08105580
	ldr r0, [sp, #0x14]
	cmp r0, #1
	beq _0810552E
	b _0810553C
_08105504:
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _0810554C
	cmp r6, #0
	bne _08105524
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _0810551E
_08105514:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08105540
	b _08105580
_0810551E:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08105530
_08105524:
	cmp r6, #2
	bne _08105580
	ldr r3, [sp, #0x14]
	cmp r3, #2
	bne _0810553C
_0810552E:
	ldr r0, _08105538 @ =0xFFFFFF00
_08105530:
	cmp r1, r0
	beq _08105540
	b _08105580
	.align 2, 0
_08105538: .4byte 0xFFFFFF00
_0810553C:
	cmp r1, #0
	bne _08105580
_08105540:
	ldr r0, [sp, #0x18]
	cmp r0, #2
	bne _0810554C
	ldr r1, [sp, #0x14]
	cmp r1, #2
	beq _08105558
_0810554C:
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _0810556A
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _0810556A
_08105558:
	adds r0, r2, #0
	cmp r2, #0
	bge _08105560
	rsbs r0, r2, #0
_08105560:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _0810557A
	b _08105580
_0810556A:
	adds r0, r2, #0
	cmp r0, #0
	bge _08105572
	rsbs r0, r0, #0
_08105572:
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0xff
	bgt _0810557C
_0810557A:
	adds r1, r7, #0
_0810557C:
	cmp r1, #0
	bge _08105588
_08105580:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _0810558C
_08105588:
	adds r0, r6, #0
	b _0810559C
_0810558C:
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	cmp r2, #3
	bgt _08105598
	b _0810521A
_08105598:
	movs r0, #1
	rsbs r0, r0, #0
_0810559C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
