	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r6, r1, r0
	subs r3, #0xe
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #0x10
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	mov r8, r1
	subs r3, #0xe
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #0x10
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl ArcTan2_8
	adds r7, r0, #0
	cmp r6, #0
	bne _080C4AD0
	cmp r4, #0
	beq _080C4B1C
_080C4AD0:
	adds r1, r6, #0
	cmp r6, #0
	bge _080C4AD8
	rsbs r1, r6, #0
_080C4AD8:
	adds r0, r4, #0
	cmp r4, #0
	bge _080C4AE0
	rsbs r0, r4, #0
_080C4AE0:
	cmp r1, r0
	ble _080C4B00
	lsls r0, r6, #0xc
	ldr r3, _080C4AFC @ =gSineTable
	adds r1, r7, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	b _080C4B10
	.align 2, 0
_080C4AFC: .4byte gSineTable
_080C4B00:
	lsls r0, r4, #0xc
	ldr r2, _080C4B18 @ =gSineTable
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
_080C4B10:
	bl Div
	adds r2, r0, #0
	b _080C4B20
	.align 2, 0
_080C4B18: .4byte gSineTable
_080C4B1C:
	movs r2, #0xc0
	lsls r2, r2, #2
_080C4B20:
	movs r0, #0xa0
	lsls r0, r0, #2
	cmp r8, r0
	ble _080C4B3A
	ldr r0, _080C4B48 @ =0xFFFFFD80
	add r0, r8
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r2, r0
	ble _080C4B3A
	adds r2, r0, #0
_080C4B3A:
	ldr r0, _080C4B4C @ =0x000002FF
	cmp r2, r0
	ble _080C4B50
	movs r3, #0
	str r3, [sp, #0x1c]
	b _080C4B5E
	.align 2, 0
_080C4B48: .4byte 0xFFFFFD80
_080C4B4C: .4byte 0x000002FF
_080C4B50:
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r0, r1, r2
	lsls r0, r0, #8
	bl Div
	str r0, [sp, #0x1c]
_080C4B5E:
	ldr r1, _080C4B90 @ =0x000008F4
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _080C4B9C
	ldr r3, _080C4B94 @ =0x000008F5
	adds r2, r5, r3
	ldrb r0, [r2]
	cmp r0, #7
	bhi _080C4BC0
	ldr r0, _080C4B98 @ =0x000008F6
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C4BC0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r0, #0
	strb r0, [r1]
	b _080C4BC0
	.align 2, 0
_080C4B90: .4byte 0x000008F4
_080C4B94: .4byte 0x000008F5
_080C4B98: .4byte 0x000008F6
_080C4B9C:
	ldr r1, _080C4BEC @ =0x000008F5
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C4BC0
	ldr r0, _080C4BF0 @ =0x000008F6
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C4BC0
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	strb r3, [r1]
_080C4BC0:
	movs r7, #0
	adds r1, r5, #0
	adds r1, #0x98
	str r1, [sp, #0x20]
	add r2, sp, #0x14
	mov r8, r2
	ldr r3, _080C4BF4 @ =0xFFFF0000
	mov sl, r3
	add r0, sp, #0xc
	mov sb, r0
_080C4BD4:
	movs r0, #0x98
	muls r0, r7, r0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r6, r5, r0
	cmp r7, #0
	bne _080C4BF8
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	b _080C4C02
	.align 2, 0
_080C4BEC: .4byte 0x000008F5
_080C4BF0: .4byte 0x000008F6
_080C4BF4: .4byte 0xFFFF0000
_080C4BF8:
	cmp r7, #4
	bne _080C4C0C
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r5, r3
_080C4C02:
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	b _080C4CF0
_080C4C0C:
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r7, r2
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4C34
	asrs r0, r0, #2
	b _080C4C3A
_080C4C34:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4C3A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r3, _080C4C6C @ =0x000002FA
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	muls r2, r7, r2
	subs r3, #0x10
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4C70
	asrs r0, r0, #2
	b _080C4C76
	.align 2, 0
_080C4C6C: .4byte 0x000002FA
_080C4C70:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4C76:
	lsls r2, r0, #0x10
	ldr r1, _080C4CAC @ =0x0000FFFF
	ldr r0, [sp, #0xc]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r7, r2
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4CB0
	asrs r0, r0, #2
	b _080C4CB6
	.align 2, 0
_080C4CAC: .4byte 0x0000FFFF
_080C4CB0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4CB6:
	adds r3, r0, #0
	ldr r2, _080C4CD4 @ =gSineTable
	lsls r0, r7, #5
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x1c]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C4CD8
	asrs r0, r0, #0xc
	b _080C4CDE
	.align 2, 0
_080C4CD4: .4byte gSineTable
_080C4CD8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4CDE:
	subs r1, r3, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sb
	ldr r0, [r3, #4]
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
_080C4CF0:
	adds r4, r6, #0
	adds r4, #0x97
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C4D42
	ldr r2, _080C4D70 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C4D74 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080C4D78 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	subs r0, #0xa
	mov r1, sb
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0xc]
	mov r3, sl
	ands r1, r3
	orrs r1, r2
	str r1, [sp, #0xc]
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_080C4D42:
	movs r3, #0x8f
	lsls r3, r3, #4
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	lsls r1, r7, #6
	adds r0, r0, r1
	movs r2, #0xff
	adds r3, #5
	adds r1, r5, r3
	ldrb r3, [r1]
	ldr r1, _080C4D7C @ =gSineTable
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080C4D80
	asrs r0, r0, #0xc
	b _080C4D86
	.align 2, 0
_080C4D70: .4byte 0x030046B8
_080C4D74: .4byte 0x000003FF
_080C4D78: .4byte 0x0203B400
_080C4D7C: .4byte gSineTable
_080C4D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4D86:
	mov r2, sb
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	mov r3, sl
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r2, [r0]
	add r4, sp, #0xc
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
	cmp r7, #1
	ble _080C4E30
	subs r1, r7, #1
	movs r0, #0x98
	muls r1, r0, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #2
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r3, #0
	bne _080C4DDA
	movs r0, #0x40
	b _080C4DE2
_080C4DDA:
	lsls r0, r0, #6
	adds r1, r3, #0
	bl Div
_080C4DE2:
	cmp r0, #0x17
	ble _080C4E0C
	adds r1, r6, #0
	adds r1, #0x95
	ldrb r2, [r1]
	cmp r2, #1
	bne _080C4E30
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r2, [sp]
	str r0, [sp, #4]
	movs r3, #4
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	b _080C4E30
_080C4E0C:
	adds r1, r6, #0
	adds r1, #0x95
	ldrb r2, [r1]
	cmp r2, #0
	bne _080C4E30
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C4E30:
	adds r0, r6, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C4E40
	adds r0, r6, #0
	bl SpriteHolder_AdvanceAnim
_080C4E40:
	adds r7, #1
	cmp r7, #4
	bgt _080C4E48
	b _080C4BD4
_080C4E48:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080C4E70
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #2
	bl SpriteHolder_SetPriority
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	bl SpriteHolder_SetPriority
	b _080C4E88
_080C4E70:
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	bl SpriteHolder_SetPriority
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #1
	bl SpriteHolder_SetPriority
_080C4E88:
	movs r7, #0
	movs r6, #0
_080C4E8C:
	movs r0, #0x98
	muls r0, r7, r0
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r4, r5, r0
	ldr r2, _080C4EC4 @ =0x000004BC
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	cmp r7, #2
	bne _080C4EC8
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #8
	add r1, sp, #0x14
	strh r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, #0x10
	strh r0, [r3, #2]
	ldrh r0, [r3, #4]
	adds r0, #8
	strh r0, [r3, #4]
	b _080C4EE0
	.align 2, 0
_080C4EC4: .4byte 0x000004BC
_080C4EC8:
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #8
	add r1, sp, #0x14
	strh r0, [r1]
	mov r2, r8
	ldrh r0, [r2, #2]
	subs r0, #0x10
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	subs r0, #8
	strh r0, [r2, #4]
_080C4EE0:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r2, [r0]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _080C4F20 @ =0x000004C5
	adds r0, r5, r3
	ldrb r2, [r0]
	cmp r2, #1
	bne _080C4F24
	adds r1, r4, #0
	adds r1, #0x95
	ldrb r0, [r1]
	cmp r0, #1
	beq _080C4F4E
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	adds r1, #1
	str r2, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	b _080C4F4E
	.align 2, 0
_080C4F20: .4byte 0x000004C5
_080C4F24:
	adds r2, r4, #0
	adds r2, #0x95
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C4F4E
	strb r6, [r2]
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	ldrb r0, [r2]
	adds r1, r1, r0
	movs r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C4F4E:
	ldr r1, _080C4FB4 @ =0x000008F4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C4F5E
	adds r0, r4, #0
	bl SpriteHolder_AdvanceAnim
_080C4F5E:
	adds r7, #1
	cmp r7, #2
	ble _080C4E8C
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	cmp r0, #0
	bge _080C4FC0
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r4, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl SpriteHolder_ClearFlags
	ldr r0, _080C4FB8 @ =0x0000071C
	adds r2, r5, r0
	ldr r3, [r2]
	ldr r1, _080C4FBC @ =0x00000554
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldr r1, [r2]
	ldrh r0, [r1, #4]
	adds r0, #0x80
	strh r0, [r1, #4]
	adds r0, r4, #0
	bl SpriteHolder_AdvanceAnim
	b _080C4FCC
	.align 2, 0
_080C4FB4: .4byte 0x000008F4
_080C4FB8: .4byte 0x0000071C
_080C4FBC: .4byte 0x00000554
_080C4FC0:
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #1
	bl SpriteHolder_SetFlags
_080C4FCC:
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080C5024
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r4, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl SpriteHolder_ClearFlags
	ldr r0, _080C5020 @ =0x00000684
	adds r2, r5, r0
	ldr r3, [r2]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r1, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	ldr r1, [r2]
	ldrh r0, [r1, #4]
	adds r0, #0x10
	strh r0, [r1, #4]
	adds r0, r4, #0
	bl SpriteHolder_AdvanceAnim
	b _080C5030
	.align 2, 0
_080C5020: .4byte 0x00000684
_080C5024:
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r1, #1
	bl SpriteHolder_SetFlags
_080C5030:
	movs r3, #0x8f
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080C5048
	movs r0, #0
	strh r0, [r1]
_080C5048:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
