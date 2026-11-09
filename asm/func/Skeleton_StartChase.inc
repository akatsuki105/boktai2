	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x74
	adds r7, r0, #0
	ldr r0, _0810ED04 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810ED08
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810ED0A
	.align 2, 0
_0810ED04: .4byte 0x0000046C
_0810ED08:
	movs r0, #0
_0810ED0A:
	cmp r0, #0
	bne _0810ED10
	b _0810F04C
_0810ED10:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
	ldr r2, _0810EDE8 @ =0x000001DF
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0810EDFC
	movs r0, #0x80
	lsls r0, r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	bne _0810ED48
	ldr r6, _0810EDEC @ =0x000004B7
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0x76
	beq _0810ED48
	b _0810EFE0
_0810ED48:
	mov r4, sp
	adds r4, #5
	adds r0, r7, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldr r1, _0810EDF0 @ =0x000004C1
	adds r0, r7, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	movs r2, #0x76
	adds r4, r1, #0
	orrs r4, r0
	ldr r6, _0810EDF4 @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810ED74
	b _0810EF26
_0810ED74:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r3, #0
	adds r2, #0x76
	ldr r3, _0810EDEC @ =0x000004B7
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810EDF8 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _0810EDB4
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810EDB4
	cmp r4, #1
	bne _0810EDA4
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810EDA4
	b _0810EFD2
_0810EDA4:
	cmp r4, #0
	bne _0810EDB4
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810EDB4
	b _0810EFD2
_0810EDB4:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0810EDC6
	movs r3, #6
_0810EDC6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	bne _0810EDDE
	b _0810EFC4
_0810EDDE:
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0810EFCC
	.align 2, 0
_0810EDE8: .4byte 0x000001DF
_0810EDEC: .4byte 0x000004B7
_0810EDF0: .4byte 0x000004C1
_0810EDF4: .4byte 0x0000025D
_0810EDF8: .4byte 0x0000046E
_0810EDFC:
	cmp r0, #6
	bne _0810EED4
	movs r0, #0x80
	lsls r0, r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	bne _0810EE24
	ldr r6, _0810EEC4 @ =0x000004B7
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0x78
	beq _0810EE24
	b _0810EFE0
_0810EE24:
	mov r4, sp
	adds r4, #6
	mov r5, sp
	adds r5, #7
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl Enemy_SetAnimFacing
	ldrb r3, [r4]
	ldr r1, _0810EEC8 @ =0x000004C1
	adds r0, r7, r1
	ldrb r1, [r5]
	ldrb r0, [r0]
	movs r2, #0x78
	adds r4, r1, #0
	orrs r4, r0
	ldr r6, _0810EECC @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810EF26
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r3, #0
	adds r2, #0x78
	ldr r3, _0810EEC4 @ =0x000004B7
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810EED0 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _0810EE90
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810EE90
	cmp r4, #1
	bne _0810EE80
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810EE80
	b _0810EFD2
_0810EE80:
	cmp r4, #0
	bne _0810EE90
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810EE90
	b _0810EFD2
_0810EE90:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0810EEA2
	movs r3, #6
_0810EEA2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	bne _0810EEBA
	b _0810EFC4
_0810EEBA:
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0810EFCC
	.align 2, 0
_0810EEC4: .4byte 0x000004B7
_0810EEC8: .4byte 0x000004C1
_0810EECC: .4byte 0x0000025D
_0810EED0: .4byte 0x0000046E
_0810EED4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r3, r7
	mov sb, r3
	cmp r0, #7
	beq _0810EEE2
	b _0810F008
_0810EEE2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0810EEFC
	ldr r6, _0810EF40 @ =0x000004B7
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0x7a
	bne _0810EFE0
_0810EEFC:
	add r4, sp, #8
	mov r5, sp
	adds r5, #9
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl Enemy_SetAnimFacing
	ldrb r3, [r4]
	ldr r1, _0810EF44 @ =0x000004C1
	adds r0, r7, r1
	ldrb r1, [r5]
	ldrb r0, [r0]
	movs r2, #0x7a
	adds r4, r1, #0
	orrs r4, r0
	ldr r6, _0810EF48 @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810EF50
_0810EF26:
	ldr r1, _0810EF40 @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _0810EF4C @ =0x0000046E
	adds r6, r7, r2
	b _0810EFCE
	.align 2, 0
_0810EF40: .4byte 0x000004B7
_0810EF44: .4byte 0x000004C1
_0810EF48: .4byte 0x0000025D
_0810EF4C: .4byte 0x0000046E
_0810EF50:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r3, #0
	adds r2, #0x7a
	ldr r3, _0810EFBC @ =0x000004B7
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810EFC0 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _0810EF8C
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810EF8C
	cmp r4, #1
	bne _0810EF7E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810EFD2
_0810EF7E:
	cmp r4, #0
	bne _0810EF8C
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810EFD2
_0810EF8C:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0810EF9E
	movs r3, #6
_0810EF9E:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0810EFC4
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0810EFCC
	.align 2, 0
_0810EFBC: .4byte 0x000004B7
_0810EFC0: .4byte 0x0000046E
_0810EFC4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0810EFCC:
	str r0, [r5, #8]
_0810EFCE:
	movs r0, #0
	strb r0, [r6]
_0810EFD2:
	ldr r3, _0810EFDC @ =0x0000046B
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _0810F008
	.align 2, 0
_0810EFDC: .4byte 0x0000046B
_0810EFE0:
	ldr r3, _0810F128 @ =FUN_080f3cdc
	movs r2, #0xa
	ldr r6, _0810F12C @ =0x0000046D
	adds r1, r7, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810F130 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
_0810F008:
	ldr r3, _0810F134 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	bl Enemy_RunScript
	ldr r4, _0810F134 @ =0x000001DF
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _0810F034
	movs r0, #4
	ldr r6, _0810F138 @ =0x00000222
	adds r2, r7, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810F034:
	movs r0, #0x80
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _0810F13C @ =0x0000024E
	adds r0, r7, r4
	strh r1, [r0]
_0810F04C:
	ldr r6, _0810F130 @ =0x0000046B
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810F058
	b _0810F660
_0810F058:
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x14]
	movs r1, #0
	ldr r2, [sp, #0x14]
	strb r1, [r2]
	ldr r3, _0810F140 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r1, [r3]
	ldr r4, _0810F144 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r0, [r4]
	adds r6, #0x19
	adds r6, r7, r6
	str r6, [sp, #0x20]
	str r1, [r6]
	ldr r0, _0810F148 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r0, #0x1a
	ldr r4, _0810F12C @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r2, [r4]
	ldr r6, _0810F130 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x70]
	strb r1, [r6]
	ldr r2, _0810F14C @ =0x00000553
	adds r5, r7, r2
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r4, r7, r6
	str r3, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r1, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, [r1]
	str r2, [sp, #0x24]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x24]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sl
	str r0, [sp, #0x44]
	mov r6, sb
	str r6, [sp, #0x48]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0x40]
	str r5, [sp, #0x68]
	str r4, [sp, #0x6c]
	str r3, [sp, #0x30]
	ldr r3, [sp, #0x14]
	str r3, [sp, #0x34]
	ldr r4, [sp, #0x18]
	str r4, [sp, #0x38]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x3c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x50]
	mov r6, r8
	mov r8, r2
	mov r2, ip
	cmp r2, #0
	blt _0810F122
	cmp r1, #0
	blt _0810F122
	ldr r0, _0810F150 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0810F122
	ldr r0, _0810F154 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F158
_0810F122:
	movs r4, #0
	b _0810F168
	.align 2, 0
_0810F128: .4byte FUN_080f3cdc
_0810F12C: .4byte 0x0000046D
_0810F130: .4byte 0x0000046B
_0810F134: .4byte 0x000001DF
_0810F138: .4byte 0x00000222
_0810F13C: .4byte 0x0000024E
_0810F140: .4byte 0x00000469
_0810F144: .4byte 0x0000046A
_0810F148: .4byte 0x0000046C
_0810F14C: .4byte 0x00000553
_0810F150: .4byte 0x030046A8
_0810F154: .4byte 0x030046AC
_0810F158:
	ldr r0, _0810F178 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, ip
	adds r4, r0, r3
_0810F168:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810F17C
	adds r0, #4
	b _0810F188
	.align 2, 0
_0810F178: .4byte 0x030046A4
_0810F17C:
	ldr r0, _0810F19C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F188:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810F1A0
	cmp r2, #2
	beq _0810F1A6
	b _0810F1AC
	.align 2, 0
_0810F19C: .4byte 0x030046A4
_0810F1A0:
	ldr r4, [sp, #0x24]
	ldrb r0, [r4, #4]
	b _0810F1AA
_0810F1A6:
	ldr r2, [sp, #0x24]
	ldrb r0, [r2]
_0810F1AA:
	subs r1, r1, r0
_0810F1AC:
	ldr r3, [sp, #0x24]
	strh r1, [r3, #2]
	ldr r0, _0810F1C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810F1C8
	movs r0, #1
	b _0810F1CA
	.align 2, 0
_0810F1C4: .4byte 0x030047A4
_0810F1C8:
	movs r0, #0
_0810F1CA:
	cmp r0, #0
	beq _0810F208
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0810F1EA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810F1E6
	adds r2, r0, #0
_0810F1E6:
	cmp r2, #0
	bge _0810F1F4
_0810F1EA:
	ldr r6, _0810F1F0 @ =0x000005C4
	adds r0, r7, r6
	b _0810F64C
	.align 2, 0
_0810F1F0: .4byte 0x000005C4
_0810F1F4:
	ldr r1, _0810F204 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810F250
	.align 2, 0
_0810F204: .4byte 0x03002BE0
_0810F208:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810F234
	cmp r1, #0
	blt _0810F234
	ldr r0, _0810F238 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F234
	ldr r0, _0810F23C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F240
_0810F234:
	movs r5, #0
	b _0810F24E
	.align 2, 0
_0810F238: .4byte 0x030046A8
_0810F23C: .4byte 0x030046AC
_0810F240:
	ldr r0, _0810F2E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810F24E:
	movs r2, #0
_0810F250:
	ldr r3, _0810F2E8 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810F270
	ldr r1, _0810F2EC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810F270
	b _0810F58C
_0810F270:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	beq _0810F28A
	b _0810F66A
_0810F28A:
	ldr r0, _0810F2F0 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _0810F2F4
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x48]
	strb r2, [r3]
	ldr r6, [sp, #0x40]
	strb r5, [r6]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r6, [sp, #0x6c]
	str r1, [r6]
	ldr r0, [sp, #0x30]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x34]
	strb r5, [r1]
	ldr r3, [sp, #0x38]
	strb r5, [r3]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r0, [sp, #0x50]
	str r4, [r0]
	ldr r1, [sp, #0x44]
	strb r2, [r1]
	b _0810F442
	.align 2, 0
_0810F2E4: .4byte 0x030046A4
_0810F2E8: .4byte 0x00000256
_0810F2EC: .4byte 0x03002BE0
_0810F2F0: .4byte 0x00000222
_0810F2F4:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r2, [sp, #0x6c]
	str r1, [r2]
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x34]
	strb r5, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	ldr r4, [sp, #0x50]
	str r3, [r4]
	ldr r1, [sp, #0x44]
	strb r0, [r1]
	ldr r5, [r6]
	mov r2, r8
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810F358
	cmp r1, #0
	blt _0810F358
	ldr r0, _0810F35C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F358
	ldr r0, _0810F360 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F364
_0810F358:
	movs r4, #0
	b _0810F372
	.align 2, 0
_0810F35C: .4byte 0x030046A8
_0810F360: .4byte 0x030046AC
_0810F364:
	ldr r0, _0810F384 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810F372:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810F388
	adds r0, #4
	b _0810F394
	.align 2, 0
_0810F384: .4byte 0x030046A4
_0810F388:
	ldr r0, _0810F3A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F394:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810F3AC
	cmp r2, #2
	beq _0810F3B0
	b _0810F3B4
	.align 2, 0
_0810F3A8: .4byte 0x030046A4
_0810F3AC:
	ldrb r0, [r5, #4]
	b _0810F3B2
_0810F3B0:
	ldrb r0, [r5]
_0810F3B2:
	subs r1, r1, r0
_0810F3B4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810F3DC
	cmp r1, #0
	blt _0810F3DC
	ldr r0, _0810F3E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F3DC
	ldr r0, _0810F3E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F3E8
_0810F3DC:
	movs r4, #0
	b _0810F3F6
	.align 2, 0
_0810F3E0: .4byte 0x030046A8
_0810F3E4: .4byte 0x030046AC
_0810F3E8:
	ldr r0, _0810F408 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810F3F6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810F40C
	adds r0, #4
	b _0810F418
	.align 2, 0
_0810F408: .4byte 0x030046A4
_0810F40C:
	ldr r0, _0810F42C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F418:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810F430
	cmp r3, #2
	beq _0810F434
	b _0810F438
	.align 2, 0
_0810F42C: .4byte 0x030046A4
_0810F430:
	ldrb r0, [r5, #4]
	b _0810F436
_0810F434:
	ldrb r0, [r5]
_0810F436:
	subs r2, r2, r0
_0810F438:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0810F442:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x28]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _0810F46C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	cmp r0, #0
	bne _0810F550
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0810F470
	movs r0, #1
	b _0810F472
	.align 2, 0
_0810F46C: .4byte 0x00000482
_0810F470:
	movs r0, #0
_0810F472:
	ldr r3, _0810F560 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	cmp r0, #0
	bne _0810F550
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0810F564 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0810F568 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x5c]
	ldr r2, _0810F56C @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x60]
	ldr r4, _0810F570 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x64]
	ldr r6, _0810F574 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r0, _0810F578 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x2c]
	ldr r1, _0810F57C @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r6, _0810F580 @ =0x0203B400
	ldr r1, _0810F584 @ =0x030046B8
	ldr r5, _0810F588 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0810F4C2:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0810F4E0
	adds r3, #1
	cmp r3, #3
	ble _0810F4C2
	mov r0, r8
_0810F4E0:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x6c]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x68]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x60]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x64]
	strb r0, [r6]
	add r0, sp, #0x28
	ldrb r1, [r0]
	ldr r0, [sp, #0x54]
	strb r1, [r0]
	ldr r1, [sp, #0x2c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r6, [sp, #0x40]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r6, [sp, #0x6c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	ldr r6, [sp, #0x38]
	strb r1, [r6]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	ldr r2, [sp, #0x50]
	str r3, [r2]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x58]
	strb r0, [r4]
_0810F550:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x4c]
	strh r0, [r6]
	b _0810F66A
	.align 2, 0
_0810F560: .4byte 0x00000482
_0810F564: .4byte 0x0000054F
_0810F568: .4byte 0x0000054C
_0810F56C: .4byte 0x0000054D
_0810F570: .4byte 0x0000054E
_0810F574: .4byte 0x00000541
_0810F578: .4byte 0x000005BC
_0810F57C: .4byte 0x00000542
_0810F580: .4byte 0x0203B400
_0810F584: .4byte 0x030046B8
_0810F588: .4byte 0x000003FF
_0810F58C:
	add r6, sp, #0xc
	ldr r0, _0810F5CC @ =0x030046A4
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
	beq _0810F5D0
	adds r0, #4
	b _0810F5DC
	.align 2, 0
_0810F5CC: .4byte 0x030046A4
_0810F5D0:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810F5DC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r6, _0810F610 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810F614
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0810F63A
	.align 2, 0
_0810F610: .4byte 0x000004A4
_0810F614:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810F634
	cmp r0, #2
	beq _0810F630
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810F630:
	movs r0, #1
	b _0810F644
_0810F634:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0810F63A:
	ldr r1, _0810F658 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0810F644:
	cmp r0, #0
	bne _0810F66A
	ldr r3, _0810F65C @ =0x000005C4
	adds r0, r7, r3
_0810F64C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0810F66A
	.align 2, 0
_0810F658: .4byte 0xFFFFFDFF
_0810F65C: .4byte 0x000005C4
_0810F660:
	ldr r4, _0810F67C @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0810F66A:
	add sp, #0x74
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810F67C: .4byte 0x00000484
