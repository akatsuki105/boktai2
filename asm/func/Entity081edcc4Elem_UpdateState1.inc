	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r1, #0
	adds r1, #0xd3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081ED6F6
	movs r0, #0
	strb r0, [r1]
_081ED6F6:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r0]
	str r0, [sp, #0x1c]
	cmp r1, #0
	beq _081ED70A
	subs r0, r1, #1
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
	b _081EDA44
_081ED70A:
	adds r0, r7, #0
	adds r0, #0x70
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r2, #0
	blt _081ED734
	cmp r1, #0
	blt _081ED734
	ldr r0, _081ED738 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081ED734
	ldr r0, _081ED73C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081ED740
_081ED734:
	movs r0, #0
	b _081ED74E
	.align 2, 0
_081ED738: .4byte 0x030046A8
_081ED73C: .4byte 0x030046AC
_081ED740:
	ldr r0, _081ED794 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081ED74E:
	adds r5, r7, #0
	adds r5, #0xd4
	strh r0, [r5]
	adds r4, r7, #0
	adds r4, #0x78
	movs r2, #0
	ldrsh r0, [r4, r2]
	adds r6, r7, #0
	adds r6, #0x7c
	movs r3, #0
	ldrsh r1, [r6, r3]
	bl ArcTan2_8
	mov sl, r0
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x74]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldrh r0, [r4]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	ldrh r4, [r5]
	mov r5, r8
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED798
	adds r0, #4
	b _081ED7A4
	.align 2, 0
_081ED794: .4byte 0x030046A4
_081ED798:
	ldr r0, _081ED7B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED7A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED7BC
	cmp r2, #2
	beq _081ED7C0
	b _081ED7C4
	.align 2, 0
_081ED7B8: .4byte 0x030046A4
_081ED7BC:
	ldrb r0, [r5, #4]
	b _081ED7C2
_081ED7C0:
	ldrb r0, [r5]
_081ED7C2:
	subs r1, r1, r0
_081ED7C4:
	adds r2, r7, #0
	adds r2, #0x72
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #0x74
	ldrh r0, [r6]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r3, r8
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	adds r6, r2, #0
	mov sb, r1
	cmp r4, #0
	blt _081ED800
	cmp r3, #0
	blt _081ED800
	ldr r0, _081ED804 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081ED800
	ldr r0, _081ED808 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _081ED80C
_081ED800:
	movs r5, #0
	b _081ED81A
	.align 2, 0
_081ED804: .4byte 0x030046A8
_081ED808: .4byte 0x030046AC
_081ED80C:
	ldr r0, _081ED848 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r4
_081ED81A:
	adds r4, r7, #0
	adds r4, #0x80
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r0, r7, #0
	mov r1, sl
	adds r2, r5, #0
	bl FUN_081eb348
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081ED84C
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [r7, #0x70]
	str r1, [r7, #0x74]
	b _081ED88E
	.align 2, 0
_081ED848: .4byte 0x030046A4
_081ED84C:
	mov r4, r8
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED85E
	adds r0, #4
	b _081ED86A
_081ED85E:
	ldr r0, _081ED880 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED86A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED884
	cmp r2, #2
	beq _081ED888
	b _081ED88C
	.align 2, 0
_081ED880: .4byte 0x030046A4
_081ED884:
	ldrb r0, [r4, #4]
	b _081ED88A
_081ED888:
	ldrb r0, [r4]
_081ED88A:
	subs r1, r1, r0
_081ED88C:
	strh r1, [r6]
_081ED88E:
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x74]
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	ldr r2, _081ED8C4 @ =0xFFFF0000
	ldrh r1, [r6]
	lsls r1, r1, #0x10
	mov r3, r8
	ldrh r0, [r3]
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sb
	ldrh r1, [r0]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r1, sl
	asrs r0, r1, #6
	cmp r0, #1
	beq _081ED914
	cmp r0, #1
	bgt _081ED8C8
	cmp r0, #0
	beq _081ED8D2
	b _081ED944
	.align 2, 0
_081ED8C4: .4byte 0xFFFF0000
_081ED8C8:
	cmp r0, #2
	beq _081ED8D2
	cmp r0, #3
	beq _081ED914
	b _081ED944
_081ED8D2:
	ldr r2, _081ED904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081ED908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081ED90C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x78
	bl Mod
	add r1, sp, #0xc
	ldrh r1, [r1, #4]
	subs r1, #0x3c
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081ED910 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	b _081ED944
	.align 2, 0
_081ED904: .4byte 0x030046B8
_081ED908: .4byte 0x000003FF
_081ED90C: .4byte 0x0203B400
_081ED910: .4byte 0xFFFF0000
_081ED914:
	ldr r2, _081ED9BC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081ED9C0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081ED9C4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x78
	bl Mod
	add r1, sp, #0xc
	ldrh r1, [r1]
	subs r1, #0x3c
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081ED9C8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
_081ED944:
	adds r0, r7, #0
	adds r0, #0xd2
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #2
	bne _081ED9CC
	movs r5, #0
	movs r0, #0xd0
	adds r0, r0, r7
	mov sb, r0
_081ED958:
	lsls r3, r5, #6
	movs r0, #0x54
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r1, #1
	movs r2, #0
	bl Entity081eee80_Spawn
	adds r5, #1
	cmp r5, #3
	ble _081ED958
	movs r5, #0
	movs r1, #1
	mov r8, r1
	movs r6, #0
_081ED97E:
	lsls r4, r5, #6
	movs r0, #0x22
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0xc
	movs r1, #1
	movs r2, #8
	adds r3, r4, #0
	bl Entity081eee80_Spawn
	movs r0, #0x40
	str r0, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0xc
	movs r1, #1
	movs r2, #0xe
	adds r3, r4, #0
	bl Entity081eee80_Spawn
	adds r5, #1
	cmp r5, #1
	ble _081ED97E
	movs r0, #8
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
	b _081EDA12
	.align 2, 0
_081ED9BC: .4byte 0x030046B8
_081ED9C0: .4byte 0x000003FF
_081ED9C4: .4byte 0x0203B400
_081ED9C8: .4byte 0xFFFF0000
_081ED9CC:
	mov r3, sl
	ldrb r2, [r3]
	add r0, sp, #0xc
	movs r1, #2
	bl FUN_081eb178
	cmp r0, #0
	blt _081EDA3C
	add r0, sp, #0x14
	mov r1, sl
	ldrb r2, [r1]
	add r1, sp, #0xc
	bl Entity081edcc4_CanReach
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081EDA3C
	ldr r2, _081EDA30 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081EDA34 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081EDA38 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #3
	ldr r3, [sp, #0x1c]
	strh r0, [r3]
	movs r0, #0xd0
	adds r0, r0, r7
	mov sb, r0
_081EDA12:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	beq _081EDA3C
	subs r0, #1
	strh r0, [r1]
	mov r2, sl
	ldrb r0, [r2]
	cmp r0, #2
	beq _081EDA44
	movs r0, #0xf1
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081EDA44
	.align 2, 0
_081EDA30: .4byte 0x030046B8
_081EDA34: .4byte 0x000003FF
_081EDA38: .4byte 0x0203B400
_081EDA3C:
	adds r1, r7, #0
	adds r1, #0xd7
	movs r0, #2
	strb r0, [r1]
_081EDA44:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
