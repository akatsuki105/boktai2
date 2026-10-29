	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	str r0, [sp, #0x44]
	adds r6, r0, #0
	adds r0, #0x48
	mov sb, r0
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r7, r6, r1
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r0, #0
	ble _0802B0EA
	adds r3, r0, #0
	mov r8, r3
	adds r4, r6, #0
	adds r4, #0x90
	movs r0, #0
	ldrsh r5, [r4, r0]
	adds r1, r5, r3
	adds r0, r6, #0
	bl Boss_SetHP
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r5, r0
	beq _0802B0E6
	ldr r2, [sp, #0x44]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r4, _0802B164 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0802B168 @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0x18]
	ldr r3, [sp, #0x44]
	adds r3, #0x50
	add r4, sp, #0x14
	str r4, [sp]
	movs r1, #1
	str r1, [sp, #4]
	mov r1, r8
	movs r2, #1
	bl CreateDamageNumber
_0802B0E6:
	movs r0, #0
	strh r0, [r7]
_0802B0EA:
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r3, [r2]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0802B112
	ldr r1, [sp, #0x44]
	adds r1, #0x90
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0802B10E
	movs r0, #1
	strh r0, [r1]
_0802B10E:
	movs r0, #0
	strh r0, [r2]
_0802B112:
	ldr r0, [sp, #0x44]
	bl FUN_08022ec0
	adds r0, r6, #0
	bl FUN_08028960
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	ldr r4, [sp, #0x44]
	adds r4, #0x98
	mov r8, r4
	cmp r0, #0
	beq _0802B13E
	movs r0, #4
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0802B13E:
	movs r0, #0xf2
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #4
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0802B16C
	ldrh r0, [r5, #6]
	orrs r0, r1
	strh r0, [r5, #6]
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	b _0802B18E
	.align 2, 0
_0802B164: .4byte 0xFFFF0000
_0802B168: .4byte 0x0000FFFF
_0802B16C:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r5, #6]
	ands r0, r1
	strh r0, [r5, #6]
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r1, r6, r4
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, sb
	ldrb r1, [r0, #5]
	ldr r2, _0802B1BC @ =0x00000226
	adds r0, r6, r2
	strb r1, [r0]
_0802B18E:
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r5, r6, r3
	movs r1, #0x80
	lsls r1, r1, #0xc
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0802B1C0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r5, #6]
	ands r0, r1
	strh r0, [r5, #6]
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	b _0802B1C8
	.align 2, 0
_0802B1BC: .4byte 0x00000226
_0802B1C0:
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
_0802B1C8:
	movs r1, #0xca
	lsls r1, r1, #1
	adds r5, r6, r1
	movs r1, #8
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0802B1FA
	movs r3, #0xc5
	lsls r3, r3, #2
	adds r1, r6, r3
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r4, sb
	ldrb r0, [r4, #5]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl Hitbox_Register
_0802B1FA:
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r5, r6, r3
	movs r1, #0x80
	lsls r1, r1, #0xd
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0802B23C
	add r4, sp, #0x1c
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08028138
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r1, sb
	ldrb r0, [r1, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _0802B274 @ =0x00000276
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl Hitbox_Register
_0802B23C:
	movs r1, #0x10
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0802B27C
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r6, r1
	bl AuxShadow_Hide
	ldr r1, _0802B278 @ =0xFFDFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r3, [sp, #0x44]
	adds r3, #0xab
	str r3, [sp, #0x54]
	b _0802B30A
	.align 2, 0
_0802B274: .4byte 0x00000276
_0802B278: .4byte 0xFFDFFFFF
_0802B27C:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	ldr r0, [sp, #0x44]
	adds r0, #0xab
	ldrb r1, [r0]
	str r0, [sp, #0x54]
	cmp r1, #0
	beq _0802B2CC
	movs r1, #0x80
	lsls r1, r1, #9
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0802B2B2
	movs r3, #0xed
	lsls r3, r3, #2
	adds r0, r6, r3
	bl AuxShadow_Hide
	b _0802B2BC
_0802B2B2:
	movs r4, #0xed
	lsls r4, r4, #2
	adds r0, r6, r4
	bl AuxShadow_Show
_0802B2BC:
	ldr r1, _0802B2C8 @ =0xFFDFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0802B30A
	.align 2, 0
_0802B2C8: .4byte 0xFFDFFFFF
_0802B2CC:
	ldr r3, _0802B2F0 @ =0x00000FD4
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802B2E4
	movs r1, #0x80
	lsls r1, r1, #9
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0802B2F4
_0802B2E4:
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r6, r1
	bl AuxShadow_Hide
	b _0802B2FE
	.align 2, 0
_0802B2F0: .4byte 0x00000FD4
_0802B2F4:
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r6, r2
	bl AuxShadow_Show
_0802B2FE:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r3, r8
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_0802B30A:
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802B326
	subs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0802B326:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _0802B37C
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B342
	b _0802B6DC
_0802B342:
	adds r0, r6, #0
	bl Ringo_GetPlttID
	adds r1, r0, #0
	cmp r1, #0
	bne _0802B35C
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r6, r2
	b _0802B36A
_0802B35C:
	ldr r0, _0802B378 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r6, r3
_0802B36A:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r6, r4
	b _0802B4BA
	.align 2, 0
_0802B378: .4byte 0x03003584
_0802B37C:
	adds r0, r6, #0
	bl FUN_08027f10
	adds r7, r0, #2
	adds r0, r6, #0
	bl FUN_08027f10
	adds r4, r0, #0
	adds r4, #0xc3
	adds r0, r6, #0
	bl Ringo_GetPlttID
	subs r0, #0xc1
	mov sb, r0
	ldr r0, _0802B400 @ =0x0000087C
	adds r0, r6, r0
	str r0, [sp, #0x48]
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	bne _0802B410
	ldr r0, _0802B404 @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0802B408 @ =0x0000087A
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r4, _0802B40C @ =0x00000878
	adds r7, r6, r4
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _0802B3FA
	b _0802B6DC
_0802B3FA:
	movs r0, #0x20
	b _0802B6DA
	.align 2, 0
_0802B400: .4byte 0x0000087C
_0802B404: .4byte 0x03003584
_0802B408: .4byte 0x0000087A
_0802B40C: .4byte 0x00000878
_0802B410:
	cmp r5, #1
	bne _0802B4C4
	lsls r1, r4, #5
	ldr r4, _0802B498 @ =0x03003584
	ldr r2, [r4]
	adds r1, r2, r1
	ldr r0, _0802B49C @ =0x0000087A
	adds r0, r0, r6
	mov sl, r0
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r3, _0802B4A0 @ =0x00000878
	adds r7, r6, r3
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0802B468
	b _0802B6DC
_0802B468:
	movs r0, #0
	strh r0, [r7]
	movs r0, #0xff
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	adds r0, r6, #0
	bl Ringo_GetPlttID
	mov r1, sl
	strh r0, [r1]
	adds r0, r6, #0
	bl Ringo_GetPlttID
	cmp r0, #0
	bne _0802B4A4
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x84
	lsls r3, r3, #3
	adds r0, r6, r3
	str r0, [r1]
	adds r0, r1, #0
	b _0802B4B4
	.align 2, 0
_0802B498: .4byte 0x03003584
_0802B49C: .4byte 0x0000087A
_0802B4A0: .4byte 0x00000878
_0802B4A4:
	lsls r0, r0, #5
	ldr r4, _0802B4C0 @ =0x03003584
	ldr r1, [r4]
	adds r1, r1, r0
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r0, r6, r2
	str r1, [r0]
_0802B4B4:
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
_0802B4BA:
	ldr r0, [r0]
	str r0, [r1]
	b _0802B6DC
	.align 2, 0
_0802B4C0: .4byte 0x03003584
_0802B4C4:
	cmp r5, #2
	bne _0802B534
	ldr r0, _0802B528 @ =0x03003584
	lsls r1, r4, #5
	ldr r0, [r0]
	adds r0, r0, r1
	mov ip, r0
	ldr r4, _0802B52C @ =0x00000878
	adds r5, r6, r4
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #0x20
	subs r3, r0, r1
	cmp r3, #0
	bge _0802B4E4
	rsbs r3, r3, #0
_0802B4E4:
	lsls r0, r7, #5
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r0, r6, r0
	ldr r2, _0802B530 @ =0x085AAC18
	movs r1, #5
	str r1, [sp]
	mov r1, ip
	bl BlendPltt
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r6, r2
	mov r3, sb
	lsls r0, r3, #5
	adds r0, r0, r4
	adds r0, r6, r0
	str r0, [r1]
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r6, r4
	str r0, [r1]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	bgt _0802B522
	b _0802B6DC
_0802B522:
	movs r0, #0
	strh r0, [r5]
	b _0802B6DC
	.align 2, 0
_0802B528: .4byte 0x03003584
_0802B52C: .4byte 0x00000878
_0802B530: .4byte 0x085AAC18
_0802B534:
	cmp r5, #3
	bne _0802B588
	ldr r0, _0802B57C @ =0x03003584
	ldr r2, [r0]
	movs r0, #0xcb
	lsls r0, r0, #5
	adds r1, r2, r0
	ldr r3, _0802B580 @ =0x0000087A
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r4, _0802B584 @ =0x00000878
	adds r7, r6, r4
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #6
	str r4, [sp]
	bl BlendPltt
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	b _0802B6C6
	.align 2, 0
_0802B57C: .4byte 0x03003584
_0802B580: .4byte 0x0000087A
_0802B584: .4byte 0x00000878
_0802B588:
	cmp r5, #4
	bne _0802B5F0
	ldr r0, _0802B5E4 @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r4, _0802B5E8 @ =0x0000087A
	adds r0, r6, r4
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r3, _0802B5EC @ =0x00000878
	adds r7, r6, r3
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #7
	str r4, [sp]
	bl BlendPltt
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	bgt _0802B5E0
	b _0802B6DC
_0802B5E0:
	movs r0, #0x80
	b _0802B6DA
	.align 2, 0
_0802B5E4: .4byte 0x03003584
_0802B5E8: .4byte 0x0000087A
_0802B5EC: .4byte 0x00000878
_0802B5F0:
	cmp r5, #5
	bne _0802B680
	ldr r0, _0802B65C @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r4, _0802B660 @ =0x0000087A
	adds r0, r6, r4
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	mov ip, r2
	lsls r0, r7, #5
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r0, r6, r0
	ldr r2, _0802B664 @ =0x00000878
	adds r7, r6, r2
	movs r2, #0
	ldrsh r3, [r7, r2]
	mov sl, r3
	str r5, [sp]
	mov r2, ip
	bl BlendPltt
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r6, r3
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r4
	adds r0, r6, r0
	str r0, [r1]
	adds r3, #0x60
	adds r1, r6, r3
	str r0, [r1]
	ldr r4, _0802B668 @ =0x0000087D
	adds r1, r6, r4
	ldrb r0, [r1]
	cmp r0, #0
	bne _0802B66C
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0802B6DC
	movs r0, #0x20
	strh r0, [r7]
	movs r0, #1
	strb r0, [r1]
	b _0802B6DC
	.align 2, 0
_0802B65C: .4byte 0x03003584
_0802B660: .4byte 0x0000087A
_0802B664: .4byte 0x00000878
_0802B668: .4byte 0x0000087D
_0802B66C:
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0802B6DC
	movs r0, #0
	strh r0, [r7]
	strb r0, [r1]
	b _0802B6DC
_0802B680:
	cmp r5, #6
	bne _0802B6DC
	ldr r0, _0802B744 @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0802B748 @ =0x0000087A
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	mov ip, r2
	lsls r0, r7, #5
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r0, r6, r0
	ldr r2, _0802B74C @ =0x00000878
	adds r7, r6, r2
	movs r2, #0
	ldrsh r3, [r7, r2]
	mov sl, r3
	str r5, [sp]
	mov r2, ip
	bl BlendPltt
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r6, r3
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r4
	adds r0, r6, r0
	str r0, [r1]
	adds r3, #0x60
_0802B6C6:
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _0802B6DC
	movs r0, #0x40
_0802B6DA:
	strh r0, [r7]
_0802B6DC:
	ldr r4, [sp, #0x54]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0802B76C
	movs r0, #0x80
	lsls r0, r0, #0xe
	mov r2, r8
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0802B75C
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r1, r0
	cmp r1, #0
	bne _0802B75C
	movs r1, #4
	ldr r0, _0802B750 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0802B75C
	movs r3, #0x88
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r1, [r2]
	cmp r1, #0
	bne _0802B724
	movs r0, #1
	strb r0, [r2]
	ldr r4, _0802B754 @ =0x00000884
	adds r0, r6, r4
	strh r1, [r0]
	ldr r2, _0802B758 @ =0x00000886
	adds r0, r6, r2
	strh r1, [r0]
_0802B724:
	adds r0, r6, #0
	bl FUN_08028388
	ldr r3, _0802B758 @ =0x00000886
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _0802B76C
	movs r0, #0x80
	strh r0, [r1]
	b _0802B76C
	.align 2, 0
_0802B744: .4byte 0x03003584
_0802B748: .4byte 0x0000087A
_0802B74C: .4byte 0x00000878
_0802B750: .4byte 0x03002BC0
_0802B754: .4byte 0x00000884
_0802B758: .4byte 0x00000886
_0802B75C:
	movs r4, #0x88
	lsls r4, r4, #4
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x20
	bl FUN_0823b880
_0802B76C:
	mov r8, r6
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x4c]
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r7, r6, r1
	adds r0, r6, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _0802B78C
	cmp r0, #0x36
	beq _0802B78C
	b _0802BA12
_0802B78C:
	ldr r0, [r7, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0802B798
	b _0802BB90
_0802B798:
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	movs r3, #0xa6
	lsls r3, r3, #4
	adds r5, r6, r3
	add r2, sp, #0x24
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802B7CA
	asrs r0, r0, #8
	b _0802B7D0
_0802B7CA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802B7D0:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802B7E2
	asrs r0, r0, #8
	b _0802B7E8
_0802B7E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802B7E8:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802B7FC
	asrs r0, r0, #8
	b _0802B802
_0802B7FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802B802:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0802B860 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r0, r8
	adds r0, #0xaf
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0802B86C
	ldr r1, _0802B864 @ =0x085AABBC
	ldr r3, _0802B868 @ =0x00000A16
	adds r2, r6, r3
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r3, [r7, #0x20]
	adds r0, r0, r3
	strh r0, [r7, #0x20]
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r7, #0x22]
	adds r0, r0, r1
	strh r0, [r7, #0x22]
	mov sb, r2
	b _0802B89C
	.align 2, 0
_0802B860: .4byte 0x030047C8
_0802B864: .4byte 0x085AABBC
_0802B868: .4byte 0x00000A16
_0802B86C:
	ldr r2, _0802B8E0 @ =0x085AABBC
	ldr r4, _0802B8E4 @ =0x00000A16
	adds r3, r6, r4
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r7, #0x20]
	subs r0, r0, r1
	strh r0, [r7, #0x20]
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #1
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r7, #0x22]
	adds r0, r0, r1
	strh r0, [r7, #0x22]
	mov sb, r3
_0802B89C:
	ldr r2, _0802B8E8 @ =0x00000A14
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r4, sb
	movs r3, #0
	ldrsh r2, [r4, r3]
	str r0, [sp, #0x50]
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r4, r6, r0
	cmp r1, r2
	bne _0802B8B8
	b _0802B9FA
_0802B8B8:
	ldr r1, [sp, #0x4c]
	ldrh r0, [r1, #0xc]
	cmp r0, #1
	beq _0802B8C2
	b _0802B9FA
_0802B8C2:
	cmp r2, #2
	beq _0802B8CE
	cmp r2, #5
	beq _0802B8CE
	cmp r2, #8
	bne _0802B9B0
_0802B8CE:
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802B8F0
	ldr r3, _0802B8EC @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r3
	movs r1, #0x20
	b _0802B8F8
	.align 2, 0
_0802B8E0: .4byte 0x085AABBC
_0802B8E4: .4byte 0x00000A16
_0802B8E8: .4byte 0x00000A14
_0802B8EC: .4byte 0xFFFF0000
_0802B8F0:
	ldr r3, _0802B9C4 @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r3
	ldr r1, _0802B9C8 @ =0x0000FFE0
_0802B8F8:
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r2, sp, #0x2c
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r1, _0802B9CC @ =0x0000FFFF
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x2c]
	adds r3, r2, #0
	mov r0, r8
	adds r0, #0xab
	ldrb r2, [r0]
	cmp r2, #0
	bne _0802B9A2
	ldr r4, _0802B9D0 @ =0x00000173
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0802B9D4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp, #0x4c]
	adds r1, #0x20
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #1
	mov sl, r2
	str r2, [sp, #8]
	ldr r4, _0802B9D8 @ =0x000008C4
	adds r2, r6, r4
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	adds r2, r3, #0
	movs r3, #0
	bl Player_HoldGrabbed
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x90
	movs r0, #0
	ldrsh r5, [r4, r0]
	mov r2, r8
	adds r1, r5, r2
	adds r0, r6, #0
	bl Boss_SetHP
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _0802B9A2
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r4, _0802B9C4 @ =0xFFFF0000
	ldr r1, [sp, #0x34]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0802B9CC @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0x34]
	add r2, sp, #0x34
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r3
	str r1, [r2, #4]
	adds r3, r6, #0
	adds r3, #0x50
	str r2, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r1, r8
	movs r2, #1
	bl CreateDamageNumber
_0802B9A2:
	adds r0, r6, #0
	bl FUN_08028a04
	movs r0, #0xd3
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0802B9B0:
	adds r0, r6, #0
	bl FUN_08028ec8
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, #1
	ble _0802B9DC
	adds r0, #2
	b _0802B9E2
	.align 2, 0
_0802B9C4: .4byte 0xFFFF0000
_0802B9C8: .4byte 0x0000FFE0
_0802B9CC: .4byte 0x0000FFFF
_0802B9D0: .4byte 0x00000173
_0802B9D4: .4byte 0x03002BE0
_0802B9D8: .4byte 0x000008C4
_0802B9DC:
	cmp r1, #1
	bne _0802B9E2
	adds r0, #1
_0802B9E2:
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r4, r6, r1
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0802B9FA:
	adds r0, r7, #0
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	mov r2, sb
	ldrh r0, [r2]
	ldr r3, [sp, #0x50]
	strh r0, [r3]
	ldr r4, [sp, #0x4c]
	ldrh r0, [r4, #0x14]
	strh r0, [r2]
	b _0802BB90
_0802BA12:
	cmp r0, #0x19
	beq _0802BA18
	b _0802BB90
_0802BA18:
	ldr r0, [r7, #8]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0802BA24
	b _0802BB40
_0802BA24:
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	movs r2, #0xa6
	lsls r2, r2, #4
	adds r5, r6, r2
	add r2, sp, #0x3c
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802BA56
	asrs r0, r0, #8
	b _0802BA5C
_0802BA56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802BA5C:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802BA6E
	asrs r0, r0, #8
	b _0802BA74
_0802BA6E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802BA74:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802BA88
	asrs r0, r0, #8
	b _0802BA8E
_0802BA88:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802BA8E:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0802BB10 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldr r2, _0802BB14 @ =0x085AABD0
	ldr r4, _0802BB18 @ =0x00000A16
	adds r3, r6, r4
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r7, #0x20]
	adds r0, r0, r4
	strh r0, [r7, #0x20]
	ldrh r1, [r7, #0x22]
	adds r1, #0x24
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #1
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	strh r0, [r7, #0x22]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r4, r6, r2
	cmp r0, #1
	bne _0802BB36
	adds r0, r6, #0
	bl FUN_08028ec8
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	cmp r1, #0
	beq _0802BB1E
	cmp r1, #1
	beq _0802BB0A
	cmp r1, #3
	bne _0802BB1C
_0802BB0A:
	adds r0, #1
	b _0802BB1E
	.align 2, 0
_0802BB10: .4byte 0x030047C8
_0802BB14: .4byte 0x085AABD0
_0802BB18: .4byte 0x00000A16
_0802BB1C:
	adds r0, #2
_0802BB1E:
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r4, r6, r1
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
_0802BB36:
	adds r0, r7, #0
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	b _0802BB90
_0802BB40:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, [r0]
	ldr r0, _0802BBD8 @ =0x00040001
	cmp r1, r0
	bne _0802BB90
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _0802BB88
	ldr r4, _0802BBDC @ =0x00000173
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0802BBE0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r1, r6, r4
	str r3, [sp]
	str r3, [sp, #4]
	str r2, [sp, #8]
	ldr r4, _0802BBE4 @ =0x000008C6
	adds r2, r6, r4
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl Player_HoldGrabbed
_0802BB88:
	movs r0, #0xef
	lsls r0, r0, #1
	bl PlaySound_0824078c
_0802BB90:
	adds r0, r6, #0
	bl Ringo_UpdateAuxSprites
	adds r0, r6, #0
	bl FUN_0802a2fc
	adds r0, r6, #0
	bl FUN_08029b40
	ldr r0, _0802BBE8 @ =0x00001044
	adds r1, r6, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _0802BC00
	subs r0, #1
	str r0, [r1]
	ldr r0, _0802BBEC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0802BBF0 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r2, r0, #0
	adds r2, #0x10
	cmp r2, #0x3f
	ble _0802BBC8
	movs r2, #0x40
_0802BBC8:
	ldr r3, _0802BBF4 @ =0x00001048
	adds r0, r6, r3
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, r2
	bls _0802BBF8
	subs r0, r1, #1
	b _0802BC16
	.align 2, 0
_0802BBD8: .4byte 0x00040001
_0802BBDC: .4byte 0x00000173
_0802BBE0: .4byte 0x03002BE0
_0802BBE4: .4byte 0x000008C6
_0802BBE8: .4byte 0x00001044
_0802BBEC: .4byte 0x030046A0
_0802BBF0: .4byte 0x00000942
_0802BBF4: .4byte 0x00001048
_0802BBF8:
	cmp r1, r2
	bhs _0802BC18
	adds r0, r1, #1
	b _0802BC16
_0802BC00:
	ldr r4, _0802BC10 @ =0x00001048
	adds r0, r6, r4
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0x3f
	bhi _0802BC14
	adds r0, r1, #1
	b _0802BC16
	.align 2, 0
_0802BC10: .4byte 0x00001048
_0802BC14:
	movs r0, #0x40
_0802BC16:
	str r0, [r3]
_0802BC18:
	ldr r1, _0802BC74 @ =0x03004460
	ldr r0, [r3]
	str r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [sp, #0x54]
	ldrb r0, [r1]
	ldr r4, [sp, #0x44]
	adds r4, #0xe0
	cmp r0, #0
	beq _0802BC4E
	ldr r2, _0802BC78 @ =0x0000018B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BC4E
	ldr r0, [r4]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0802BC4E
	adds r0, r6, #0
	bl FUN_08028c04
_0802BC4E:
	ldr r0, [sp, #0x44]
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	ldr r0, [sp, #0x44]
	adds r0, #0xb8
	str r1, [r0]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BC74: .4byte 0x03004460
_0802BC78: .4byte 0x0000018B
