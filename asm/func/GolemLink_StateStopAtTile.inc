	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	mov sb, r6
	ldr r2, _081BBB00 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BBB04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BBB06
	.align 2, 0
_081BBB00: .4byte 0x0000046D
_081BBB04:
	movs r0, #0
_081BBB06:
	cmp r0, #0
	beq _081BBB48
	ldr r3, _081BBBBC @ =0x0000046E
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _081BBBC0 @ =0x000006C1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081BBBC4 @ =0x000006C2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r7, r3
	mov r5, sb
	ldr r1, [r5, #8]
	ldr r2, [r5, #0xc]
	str r1, [r0]
	str r2, [r0, #4]
	bl GolemLink_SnapToTileCenter
_081BBB48:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r5, r6, r1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BBBC8 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BBBCC @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x10]
	str r0, [sp, #0x14]
	cmp r1, #0
	bne _081BBBD4
	ldr r2, _081BBBD0 @ =0x000004B7
	adds r0, r6, r2
	mov r5, ip
	strb r5, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r0, _081BBBBC @ =0x0000046E
	adds r0, r0, r6
	mov r8, r0
	b _081BBC5A
	.align 2, 0
_081BBBBC: .4byte 0x0000046E
_081BBBC0: .4byte 0x000006C1
_081BBBC4: .4byte 0x000006C2
_081BBBC8: .4byte 0x085ADFA8
_081BBBCC: .4byte 0x0000025D
_081BBBD0: .4byte 0x000004B7
_081BBBD4:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _081BBC48 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r3, _081BBC4C @ =0x0000046E
	adds r3, r3, r6
	mov r8, r3
	cmp r1, ip
	bne _081BBC12
	ldrb r0, [r3]
	cmp r0, #0
	bne _081BBC12
	cmp r4, #1
	bne _081BBC04
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BBC60
_081BBC04:
	cmp r4, #0
	bne _081BBC12
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BBC60
_081BBC12:
	mov r0, ip
	strb r0, [r2]
	movs r1, #4
	mov sl, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081BBC26
	movs r3, #6
_081BBC26:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BBC50
	ldr r0, [r5, #8]
	mov r2, sl
	orrs r0, r2
	b _081BBC58
	.align 2, 0
_081BBC48: .4byte 0x000004B7
_081BBC4C: .4byte 0x0000046E
_081BBC50:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BBC58:
	str r0, [r5, #8]
_081BBC5A:
	movs r0, #0
	mov r3, r8
	strb r0, [r3]
_081BBC60:
	ldr r5, _081BBC80 @ =0x000006C1
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BBD20
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _081BBC8C
	cmp r0, #1
	bgt _081BBC84
	cmp r0, #0
	beq _081BBC9C
	b _081BBCAC
	.align 2, 0
_081BBC80: .4byte 0x000006C1
_081BBC84:
	cmp r0, #3
	beq _081BBC8C
	cmp r0, #5
	bne _081BBCAC
_081BBC8C:
	ldr r2, _081BBC98 @ =0x000006B6
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #0xc0
	b _081BBCB4
	.align 2, 0
_081BBC98: .4byte 0x000006B6
_081BBC9C:
	ldr r3, _081BBCA8 @ =0x000006B6
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x40
	b _081BBCB4
	.align 2, 0
_081BBCA8: .4byte 0x000006B6
_081BBCAC:
	ldr r5, _081BBCD0 @ =0x000006B6
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0x80
_081BBCB4:
	strh r0, [r1]
	ldr r0, _081BBCD0 @ =0x000006B6
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _081BBCD8
	ldr r2, _081BBCD4 @ =0x000006C1
	adds r0, r7, r2
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	strh r2, [r5]
	b _081BBEA0
	.align 2, 0
_081BBCD0: .4byte 0x000006B6
_081BBCD4: .4byte 0x000006C1
_081BBCD8:
	movs r0, #0
	ldrsh r3, [r5, r0]
	ldr r4, _081BBD18 @ =gSineTable
	ldr r1, _081BBD1C @ =0x000006C2
	adds r2, r7, r1
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	asrs r0, r0, #0x10
	ldrh r3, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #0x10
	ldrh r3, [r6, #0x14]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	b _081BBE20
	.align 2, 0
_081BBD18: .4byte gSineTable
_081BBD1C: .4byte 0x000006C2
_081BBD20:
	cmp r0, #1
	bne _081BBDEC
	add r3, sp, #8
	mov r4, sb
	adds r4, #8
	movs r5, #0xda
	lsls r5, r5, #3
	adds r2, r7, r5
	ldrh r0, [r2]
	mov r5, sb
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _081BBD60 @ =0x000006C5
	adds r0, r7, r1
	ldrb r0, [r0]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _081BBD9A
	cmp r0, #1
	bgt _081BBD64
	cmp r0, #0
	beq _081BBD6E
	b _081BBDC4
	.align 2, 0
_081BBD60: .4byte 0x000006C5
_081BBD64:
	cmp r0, #2
	beq _081BBD6E
	cmp r0, #3
	beq _081BBD9A
	b _081BBDC4
_081BBD6E:
	movs r0, #0
	strh r0, [r3, #4]
	add r0, sp, #8
	ldrh r2, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #8
	ble _081BBD86
	movs r0, #8
	mov r1, sb
	strh r0, [r1, #0x10]
	b _081BBDC4
_081BBD86:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BBD94
	mov r2, sb
	strh r1, [r2, #0x10]
	b _081BBDC4
_081BBD94:
	mov r5, sb
	strh r2, [r5, #0x10]
	b _081BBDC4
_081BBD9A:
	movs r0, #0
	strh r0, [r3]
	add r0, sp, #8
	ldrh r2, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #8
	ble _081BBDB2
	movs r0, #8
	mov r2, sb
	strh r0, [r2, #0x14]
	b _081BBDC4
_081BBDB2:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BBDC0
	mov r5, sb
	strh r1, [r5, #0x14]
	b _081BBDC4
_081BBDC0:
	mov r0, sb
	strh r2, [r0, #0x14]
_081BBDC4:
	movs r1, #0
	ldrsh r0, [r3, r1]
	add r1, sp, #8
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r3, r0, r1
	cmp r3, #0
	bne _081BBE20
	ldr r5, _081BBDE4 @ =0x000006C1
	adds r0, r7, r5
	movs r1, #2
	strb r1, [r0]
	ldr r1, _081BBDE8 @ =0x000006C3
	adds r0, r7, r1
	strb r3, [r0]
	b _081BBEA0
	.align 2, 0
_081BBDE4: .4byte 0x000006C1
_081BBDE8: .4byte 0x000006C3
_081BBDEC:
	ldr r3, _081BBE14 @ =0x000006C3
	adds r2, r7, r3
	ldrb r0, [r2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _081BBE20
	ldr r5, _081BBE18 @ =0x0000046B
	adds r0, r6, r5
	movs r1, #1
	strb r1, [r0]
	strb r3, [r2]
	ldr r1, _081BBE1C @ =0x000006B6
	adds r0, r7, r1
	strh r3, [r0]
	b _081BBEA0
	.align 2, 0
_081BBE14: .4byte 0x000006C3
_081BBE18: .4byte 0x0000046B
_081BBE1C: .4byte 0x000006B6
_081BBE20:
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	lsrs r0, r0, #7
	ldr r3, _081BBE48 @ =0x00000482
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _081BBE4C @ =0x0000A02F
	ldr r5, [sp, #0x10]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081BBE50
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BBE60
	.align 2, 0
_081BBE48: .4byte 0x00000482
_081BBE4C: .4byte 0x0000A02F
_081BBE50:
	ldr r1, _081BBE84 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BBE60
	movs r0, #1
	strh r0, [r2]
_081BBE60:
	ldr r3, [sp, #0x14]
	ldrb r0, [r3]
	cmp r0, #0
	bne _081BBE88
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081BBEA0
	.align 2, 0
_081BBE84: .4byte 0x00000482
_081BBE88:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081BBEA0:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
