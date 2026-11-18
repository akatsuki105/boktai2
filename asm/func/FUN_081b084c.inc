	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xd0
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _081B0874 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B0878
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B087A
	.align 2, 0
_081B0874: .4byte 0x0000046D
_081B0878:
	movs r0, #0
_081B087A:
	cmp r0, #0
	beq _081B08B6
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B08A4
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081B08A4:
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	movs r1, #0
	strh r0, [r4]
	ldr r3, _081B0988 @ =0x0000046E
	adds r0, r7, r3
	strb r1, [r0]
_081B08B6:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	mov sb, r2
	cmp r6, #0x11
	bgt _081B08F6
	ldrh r3, [r5, #8]
	cmp r3, #0
	bne _081B08F6
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081B08F6
	cmp r2, #1
	beq _081B08F6
	strh r3, [r5, #0xe]
_081B08F6:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081B0968
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B0968
	ldr r2, _081B098C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _081B0990 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _081B0994 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B0998 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B099C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl EmitSmoke
_081B0968:
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081B09A0
	asrs r0, r0, #2
	b _081B09A6
	.align 2, 0
_081B0988: .4byte 0x0000046E
_081B098C: .4byte 0xFFFF0000
_081B0990: .4byte 0x0000FFFF
_081B0994: .4byte 0x030046B8
_081B0998: .4byte 0x000003FF
_081B099C: .4byte 0x0203B400
_081B09A0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B09A6:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081B09C6
	asrs r0, r0, #2
	b _081B09CC
_081B09C6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B09CC:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081B09D6
	movs r3, #0xc8
	b _081B09E0
_081B09D6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081B09E0
	adds r3, r0, #0
_081B09E0:
	cmp r2, #0xc8
	ble _081B09E8
	movs r2, #0xc8
	b _081B09F2
_081B09E8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081B09F2
	adds r2, r0, #0
_081B09F2:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081B0A16
	cmp r2, #0
	bne _081B0A16
	movs r0, #1
	b _081B0A18
_081B0A16:
	movs r0, #0
_081B0A18:
	cmp r0, #0
	bne _081B0A20
	bl _081B1958
_081B0A20:
	ldr r6, _081B0A7C @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B0A2E
	bl _081B1958
_081B0A2E:
	ldr r1, _081B0A80 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	mov r8, r2
	mov r3, r8
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _081B0A84 @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	mov r5, sb
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r3, [r5]
	ands r3, r0
	str r3, [r5]
	ldr r1, _081B0A88 @ =0x0000049C
	adds r0, r7, r1
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xc
	ands r4, r0
	str r2, [sp, #0xa8]
	cmp r4, #0
	beq _081B0A8C
	movs r0, #2
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081B1958
	.align 2, 0
_081B0A7C: .4byte 0x0000046E
_081B0A80: .4byte 0x0000046B
_081B0A84: .4byte 0xFFFFFEDF
_081B0A88: .4byte 0x0000049C
_081B0A8C:
	movs r0, #8
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B0B18
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _081B0AFC @ =0x00000469
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _081B0B00 @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _081B0B04 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	mov r5, r8
	strb r5, [r0]
	ldr r2, _081B0B08 @ =FUN_081afeb4
	movs r1, #0x14
	adds r3, #1
	adds r0, r7, r3
	strb r5, [r0]
	ldr r5, _081B0B0C @ =0x0000046B
	adds r0, r7, r5
	strb r6, [r0]
	ldr r6, _081B0B10 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r4, _081B0B14 @ =0x00000482
	adds r0, r7, r4
	mov r5, r8
	strh r5, [r0]
	bl _081B1958
	.align 2, 0
_081B0AFC: .4byte 0x00000469
_081B0B00: .4byte 0x0000046A
_081B0B04: .4byte 0x00000484
_081B0B08: .4byte FUN_081afeb4
_081B0B0C: .4byte 0x0000046B
_081B0B10: .4byte 0x00000553
_081B0B14: .4byte 0x00000482
_081B0B18:
	movs r2, #0x80
	ands r1, r2
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081B0B26
	b _081B123C
_081B0B26:
	orrs r3, r2
	str r3, [r5]
	movs r0, #4
	ldr r6, _081B0B88 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _081B0B8C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xc0]
	str r4, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r5, #0
	blt _081B0B82
	cmp r1, #0
	blt _081B0B82
	ldr r0, _081B0B90 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081B0B82
	ldr r0, _081B0B94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0B98
_081B0B82:
	movs r4, #0
	b _081B0BA6
	.align 2, 0
_081B0B88: .4byte 0x00000222
_081B0B8C: .4byte 0x03002BE0
_081B0B90: .4byte 0x030046A8
_081B0B94: .4byte 0x030046AC
_081B0B98:
	ldr r0, _081B0BB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081B0BA6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B0BBC
	adds r0, #4
	b _081B0BC8
	.align 2, 0
_081B0BB8: .4byte 0x030046A4
_081B0BBC:
	ldr r0, _081B0BDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B0BC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0BE0
	cmp r2, #2
	beq _081B0BE4
	b _081B0BE8
	.align 2, 0
_081B0BDC: .4byte 0x030046A4
_081B0BE0:
	ldrb r0, [r6, #4]
	b _081B0BE6
_081B0BE4:
	ldrb r0, [r6]
_081B0BE6:
	subs r1, r1, r0
_081B0BE8:
	strh r1, [r6, #2]
	ldr r0, _081B0BFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B0C00
	movs r0, #1
	b _081B0C02
	.align 2, 0
_081B0BFC: .4byte 0x030047A4
_081B0C00:
	movs r0, #0
_081B0C02:
	cmp r0, #0
	beq _081B0C38
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081B0C14
	b _081B1148
_081B0C14:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B0C20
	adds r2, r0, #0
_081B0C20:
	cmp r2, #0
	bge _081B0C26
	b _081B1148
_081B0C26:
	ldr r1, _081B0C34 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B0C80
	.align 2, 0
_081B0C34: .4byte 0x03002BE0
_081B0C38:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B0C64
	cmp r1, #0
	blt _081B0C64
	ldr r0, _081B0C68 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0C64
	ldr r0, _081B0C6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0C70
_081B0C64:
	movs r5, #0
	b _081B0C7E
	.align 2, 0
_081B0C68: .4byte 0x030046A8
_081B0C6C: .4byte 0x030046AC
_081B0C70:
	ldr r0, _081B0CB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B0C7E:
	movs r2, #0
_081B0C80:
	ldr r6, _081B0CBC @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B0CA0
	ldr r1, _081B0CC0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B0CA0
	b _081B1088
_081B0CA0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081B0CC4
	movs r0, #0
	b _081B1162
	.align 2, 0
_081B0CB8: .4byte 0x030046A4
_081B0CBC: .4byte 0x00000256
_081B0CC0: .4byte 0x03002BE0
_081B0CC4:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r3, [sp, #0xc0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081B0D7C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B0D64 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x28]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081B0D68 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B0D6C @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x30]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x34]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	mov r1, sb
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081B0D70 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B0D74 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _081B0D78 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x28]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x34]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B0F46
	.align 2, 0
_081B0D64: .4byte 0x0000046D
_081B0D68: .4byte 0x0000046B
_081B0D6C: .4byte 0x00000553
_081B0D70: .4byte 0x00000469
_081B0D74: .4byte 0x00000484
_081B0D78: .4byte 0x0000046C
_081B0D7C:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B0E3C @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B0E40 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x38]
	movs r6, #0
	strb r6, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x44]
	strh r2, [r5]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x48]
	movs r3, #0
	strb r3, [r6]
	ldr r4, _081B0E44 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r6, _081B0E48 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081B0E4C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x4c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x4c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x3c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x40]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x44]
	str r4, [sp, #0xac]
	mov r5, ip
	cmp r5, #0
	blt _081B0E38
	cmp r1, #0
	blt _081B0E38
	ldr r0, _081B0E50 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081B0E38
	ldr r0, _081B0E54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0E58
_081B0E38:
	movs r4, #0
	b _081B0E68
	.align 2, 0
_081B0E3C: .4byte 0x0000046D
_081B0E40: .4byte 0x0000046B
_081B0E44: .4byte 0x00000469
_081B0E48: .4byte 0x0000046A
_081B0E4C: .4byte 0x00000484
_081B0E50: .4byte 0x030046A8
_081B0E54: .4byte 0x030046AC
_081B0E58:
	ldr r0, _081B0E78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, ip
	adds r4, r0, r6
_081B0E68:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B0E7C
	adds r0, #4
	b _081B0E88
	.align 2, 0
_081B0E78: .4byte 0x030046A4
_081B0E7C:
	ldr r0, _081B0E9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B0E88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0EA0
	cmp r2, #2
	beq _081B0EA6
	b _081B0EAC
	.align 2, 0
_081B0E9C: .4byte 0x030046A4
_081B0EA0:
	ldr r2, [sp, #0x4c]
	ldrb r0, [r2, #4]
	b _081B0EAA
_081B0EA6:
	ldr r3, [sp, #0x4c]
	ldrb r0, [r3]
_081B0EAA:
	subs r1, r1, r0
_081B0EAC:
	ldr r4, [sp, #0x4c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B0ED8
	cmp r1, #0
	blt _081B0ED8
	ldr r0, _081B0EDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0ED8
	ldr r0, _081B0EE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0EE4
_081B0ED8:
	movs r4, #0
	b _081B0EF2
	.align 2, 0
_081B0EDC: .4byte 0x030046A8
_081B0EE0: .4byte 0x030046AC
_081B0EE4:
	ldr r0, _081B0F08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B0EF2:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B0F0C
	adds r0, #4
	b _081B0F18
	.align 2, 0
_081B0F08: .4byte 0x030046A4
_081B0F0C:
	ldr r0, _081B0F2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B0F18:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B0F30
	cmp r3, #2
	beq _081B0F34
	b _081B0F38
	.align 2, 0
_081B0F2C: .4byte 0x030046A4
_081B0F30:
	ldrb r0, [r5, #4]
	b _081B0F36
_081B0F34:
	ldrb r0, [r5]
_081B0F36:
	subs r2, r2, r0
_081B0F38:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B0F46:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x50]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B0F70 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B1050
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B0F74
	movs r0, #1
	b _081B0F76
	.align 2, 0
_081B0F70: .4byte 0x00000482
_081B0F74:
	movs r0, #0
_081B0F76:
	ldr r3, _081B1060 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B1050
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B1064 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B1068 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B106C @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B1070 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B1074 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B1078 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B107C @ =0x030046B8
	adds r2, r5, #0
_081B0FBE:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B1080 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B1084 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B0FE2
	adds r3, #1
	cmp r3, #3
	ble _081B0FBE
	adds r0, r5, #0
_081B0FE2:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x50
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B1050:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B1162
	.align 2, 0
_081B1060: .4byte 0x00000482
_081B1064: .4byte 0x0000054F
_081B1068: .4byte 0x0000054C
_081B106C: .4byte 0x0000054E
_081B1070: .4byte 0x00000541
_081B1074: .4byte 0x000005BC
_081B1078: .4byte 0x00000542
_081B107C: .4byte 0x030046B8
_081B1080: .4byte 0x000003FF
_081B1084: .4byte 0x0203B400
_081B1088:
	add r6, sp, #0x18
	ldr r0, _081B10C8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081B10CC
	adds r0, #4
	b _081B10D8
	.align 2, 0
_081B10C8: .4byte 0x030046A4
_081B10CC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B10D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B1110 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B1118
	ldr r0, _081B1114 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B1142
	.align 2, 0
_081B1110: .4byte 0x000004A4
_081B1114: .4byte 0xFFFFFDFF
_081B1118:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B1138
	cmp r0, #2
	beq _081B1134
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B1134:
	movs r0, #1
	b _081B1144
_081B1138:
	ldr r0, _081B1158 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B1142:
	movs r0, #0
_081B1144:
	cmp r0, #0
	bne _081B1160
_081B1148:
	ldr r3, _081B115C @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B1162
	.align 2, 0
_081B1158: .4byte 0xFFFFFDFF
_081B115C: .4byte 0x000005C4
_081B1160:
	movs r0, #1
_081B1162:
	cmp r0, #0
	bne _081B11D2
	ldr r4, _081B1198 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B11A0
	ldr r0, _081B119C @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B11CA
	.align 2, 0
_081B1198: .4byte 0x000004A4
_081B119C: .4byte 0xFFFFFDFF
_081B11A0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B11C0
	cmp r0, #2
	beq _081B11BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B11BC:
	movs r0, #1
	b _081B11CC
_081B11C0:
	ldr r0, _081B1228 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B11CA:
	movs r0, #0
_081B11CC:
	cmp r0, #0
	bne _081B11D2
	b _081B18E8
_081B11D2:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081B122C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081B1230 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B1234 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081B1238 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081B1958
	.align 2, 0
_081B1228: .4byte 0xFFFFFDFF
_081B122C: .4byte 0x0000046D
_081B1230: .4byte 0x0000046B
_081B1234: .4byte 0x0000046A
_081B1238: .4byte 0x00000484
_081B123C:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _081B1298 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r0, #0x10
	orrs r3, r0
	mov r0, sb
	str r3, [r0]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r3, r7, r1
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r5, #0
	blt _081B1294
	cmp r1, #0
	blt _081B1294
	ldr r0, _081B129C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081B1294
	ldr r0, _081B12A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B12A4
_081B1294:
	movs r4, #0
	b _081B12B2
	.align 2, 0
_081B1298: .4byte 0x03002BE0
_081B129C: .4byte 0x030046A8
_081B12A0: .4byte 0x030046AC
_081B12A4:
	ldr r0, _081B12C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081B12B2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B12C8
	adds r0, #4
	b _081B12D4
	.align 2, 0
_081B12C4: .4byte 0x030046A4
_081B12C8:
	ldr r0, _081B12E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B12D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B12EC
	cmp r2, #2
	beq _081B12F0
	b _081B12F4
	.align 2, 0
_081B12E8: .4byte 0x030046A4
_081B12EC:
	ldrb r0, [r6, #4]
	b _081B12F2
_081B12F0:
	ldrb r0, [r6]
_081B12F2:
	subs r1, r1, r0
_081B12F4:
	strh r1, [r6, #2]
	ldr r0, _081B1308 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B130C
	movs r0, #1
	b _081B130E
	.align 2, 0
_081B1308: .4byte 0x030047A4
_081B130C:
	movs r0, #0
_081B130E:
	cmp r0, #0
	beq _081B1344
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081B1320
	b _081B1860
_081B1320:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B132C
	adds r2, r0, #0
_081B132C:
	cmp r2, #0
	bge _081B1332
	b _081B1860
_081B1332:
	ldr r1, _081B1340 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B138C
	.align 2, 0
_081B1340: .4byte 0x03002BE0
_081B1344:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B1370
	cmp r1, #0
	blt _081B1370
	ldr r0, _081B1374 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B1370
	ldr r0, _081B1378 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B137C
_081B1370:
	movs r5, #0
	b _081B138A
	.align 2, 0
_081B1374: .4byte 0x030046A8
_081B1378: .4byte 0x030046AC
_081B137C:
	ldr r0, _081B13C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B138A:
	movs r2, #0
_081B138C:
	ldr r6, _081B13C8 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B13AC
	ldr r1, _081B13CC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B13AC
	b _081B17A0
_081B13AC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	cmp r0, #0
	beq _081B13D0
	movs r0, #0
	b _081B187A
	.align 2, 0
_081B13C4: .4byte 0x030046A4
_081B13C8: .4byte 0x00000256
_081B13CC: .4byte 0x03002BE0
_081B13D0:
	ldr r3, _081B1474 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xc0]
	cmp r6, #0
	beq _081B1490
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B1478 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081B147C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B1480 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x60]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x64]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081B1484 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B1488 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x54]
	str r6, [r1]
	ldr r6, _081B148C @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x58]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x64]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B165E
	.align 2, 0
_081B1474: .4byte 0x00000222
_081B1478: .4byte 0x0000046D
_081B147C: .4byte 0x0000046B
_081B1480: .4byte 0x00000553
_081B1484: .4byte 0x00000469
_081B1488: .4byte 0x00000484
_081B148C: .4byte 0x0000046C
_081B1490:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B1550 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B1554 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r2, #0
	strb r2, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x74]
	strh r6, [r5]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B1558 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _081B155C @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081B1560 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081B1564 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x7c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x7c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x6c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x70]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x74]
	str r4, [sp, #0xac]
	mov r5, sl
	cmp r5, #0
	blt _081B154C
	cmp r1, #0
	blt _081B154C
	ldr r0, _081B1568 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081B154C
	ldr r0, _081B156C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B1570
_081B154C:
	movs r4, #0
	b _081B1580
	.align 2, 0
_081B1550: .4byte 0x0000046D
_081B1554: .4byte 0x0000046B
_081B1558: .4byte 0x00000469
_081B155C: .4byte 0x0000046A
_081B1560: .4byte 0x00000484
_081B1564: .4byte 0x0000046C
_081B1568: .4byte 0x030046A8
_081B156C: .4byte 0x030046AC
_081B1570:
	ldr r0, _081B1590 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sl
	adds r4, r0, r6
_081B1580:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B1594
	adds r0, #4
	b _081B15A0
	.align 2, 0
_081B1590: .4byte 0x030046A4
_081B1594:
	ldr r0, _081B15B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B15A0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B15B8
	cmp r2, #2
	beq _081B15BE
	b _081B15C4
	.align 2, 0
_081B15B4: .4byte 0x030046A4
_081B15B8:
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2, #4]
	b _081B15C2
_081B15BE:
	ldr r3, [sp, #0x7c]
	ldrb r0, [r3]
_081B15C2:
	subs r1, r1, r0
_081B15C4:
	ldr r4, [sp, #0x7c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B15F0
	cmp r1, #0
	blt _081B15F0
	ldr r0, _081B15F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B15F0
	ldr r0, _081B15F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B15FC
_081B15F0:
	movs r4, #0
	b _081B160A
	.align 2, 0
_081B15F4: .4byte 0x030046A8
_081B15F8: .4byte 0x030046AC
_081B15FC:
	ldr r0, _081B1620 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B160A:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B1624
	adds r0, #4
	b _081B1630
	.align 2, 0
_081B1620: .4byte 0x030046A4
_081B1624:
	ldr r0, _081B1644 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B1630:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B1648
	cmp r3, #2
	beq _081B164C
	b _081B1650
	.align 2, 0
_081B1644: .4byte 0x030046A4
_081B1648:
	ldrb r0, [r5, #4]
	b _081B164E
_081B164C:
	ldrb r0, [r5]
_081B164E:
	subs r2, r2, r0
_081B1650:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B165E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x80]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B1688 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B1768
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B168C
	movs r0, #1
	b _081B168E
	.align 2, 0
_081B1688: .4byte 0x00000482
_081B168C:
	movs r0, #0
_081B168E:
	ldr r3, _081B1778 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B1768
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B177C @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B1780 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B1784 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B1788 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B178C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B1790 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B1794 @ =0x030046B8
	adds r2, r5, #0
_081B16D6:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B1798 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B179C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B16FA
	adds r3, #1
	cmp r3, #3
	ble _081B16D6
	adds r0, r5, #0
_081B16FA:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x80
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B1768:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B187A
	.align 2, 0
_081B1778: .4byte 0x00000482
_081B177C: .4byte 0x0000054F
_081B1780: .4byte 0x0000054C
_081B1784: .4byte 0x0000054E
_081B1788: .4byte 0x00000541
_081B178C: .4byte 0x000005BC
_081B1790: .4byte 0x00000542
_081B1794: .4byte 0x030046B8
_081B1798: .4byte 0x000003FF
_081B179C: .4byte 0x0203B400
_081B17A0:
	add r6, sp, #0x20
	ldr r0, _081B17E0 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081B17E4
	adds r0, #4
	b _081B17F0
	.align 2, 0
_081B17E0: .4byte 0x030046A4
_081B17E4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B17F0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B1828 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B1830
	ldr r0, _081B182C @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B185A
	.align 2, 0
_081B1828: .4byte 0x000004A4
_081B182C: .4byte 0xFFFFFDFF
_081B1830:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B1850
	cmp r0, #2
	beq _081B184C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B184C:
	movs r0, #1
	b _081B185C
_081B1850:
	ldr r0, _081B1870 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B185A:
	movs r0, #0
_081B185C:
	cmp r0, #0
	bne _081B1878
_081B1860:
	ldr r3, _081B1874 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B187A
	.align 2, 0
_081B1870: .4byte 0xFFFFFDFF
_081B1874: .4byte 0x000005C4
_081B1878:
	movs r0, #1
_081B187A:
	cmp r0, #0
	bne _081B1900
	ldr r4, _081B18B0 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B18B8
	ldr r0, _081B18B4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B18E2
	.align 2, 0
_081B18B0: .4byte 0x000004A4
_081B18B4: .4byte 0xFFFFFDFF
_081B18B8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B18D8
	cmp r0, #2
	beq _081B18D4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B18D4:
	movs r0, #1
	b _081B18E4
_081B18D8:
	ldr r0, _081B18F8 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B18E2:
	movs r0, #0
_081B18E4:
	cmp r0, #0
	bne _081B1900
_081B18E8:
	ldr r4, _081B18FC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B1958
	.align 2, 0
_081B18F8: .4byte 0xFFFFFDFF
_081B18FC: .4byte 0x000005C4
_081B1900:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081B1968 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081B196C @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081B1970 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B1974 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081B1978 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081B1958:
	add sp, #0xd0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B1968: .4byte 0x0000046D
_081B196C: .4byte 0x0000046B
_081B1970: .4byte 0x00000469
_081B1974: .4byte 0x0000046A
_081B1978: .4byte 0x00000484
