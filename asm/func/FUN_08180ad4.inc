	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	ldr r0, _08180AF4 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180AF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180AFA
	.align 2, 0
_08180AF4: .4byte 0x0000046C
_08180AF8:
	movs r0, #0
_08180AFA:
	adds r6, r0, #0
	cmp r6, #0
	beq _08180B98
	ldr r4, _08180B7C @ =FUN_081804fc
	movs r3, #0xa
	ldr r2, _08180B80 @ =0x0000046D
	adds r1, r7, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08180B84 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08180B88 @ =0x00000553
	adds r0, r7, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r2, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	strb r0, [r7, #5]
	ldr r1, _08180B8C @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	bl Enemy_RunScript
	ldr r2, _08180B8C @ =0x000001DF
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _08180B5E
	movs r0, #4
	ldr r3, _08180B90 @ =0x00000222
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08180B5E:
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r2, _08180B94 @ =0x0000024E
	adds r0, r7, r2
	strh r1, [r0]
	b _0818119A
	.align 2, 0
_08180B7C: .4byte FUN_081804fc
_08180B80: .4byte 0x0000046D
_08180B84: .4byte 0x0000046B
_08180B88: .4byte 0x00000553
_08180B8C: .4byte 0x000001DF
_08180B90: .4byte 0x00000222
_08180B94: .4byte 0x0000024E
_08180B98:
	ldr r3, _08180C6C @ =0x0000046B
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08180BA4
	b _08181190
_08180BA4:
	movs r0, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r6, [r4]
	ldr r1, _08180C70 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0xc]
	strb r6, [r1]
	ldr r2, _08180C74 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	adds r3, #0x19
	adds r3, r7, r3
	str r3, [sp, #0x14]
	str r6, [r3]
	ldr r4, _08180C78 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x18]
	movs r1, #1
	strb r1, [r4]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _08180C7C @ =0x0000046D
	adds r3, r3, r7
	mov sb, r3
	strb r1, [r3]
	ldr r4, _08180C6C @ =0x0000046B
	adds r4, r4, r7
	mov sl, r4
	strb r6, [r4]
	ldr r1, _08180C80 @ =0x00000553
	adds r5, r7, r1
	strb r0, [r5]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r4, r7, r3
	str r2, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r6, [r3]
	subs r1, #0xab
	adds r1, r1, r7
	mov r8, r1
	ldr r2, [r1]
	str r2, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x3c]
	mov r6, sb
	str r6, [sp, #0x40]
	mov r0, sl
	str r0, [sp, #0x38]
	str r5, [sp, #0x64]
	str r4, [sp, #0x24]
	str r3, [sp, #0x4c]
	ldr r3, [sp, #8]
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0xc]
	str r4, [sp, #0x30]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x34]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x48]
	mov r6, r8
	mov r8, r2
	mov r2, ip
	cmp r2, #0
	blt _08180C68
	cmp r1, #0
	blt _08180C68
	ldr r0, _08180C84 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08180C68
	ldr r0, _08180C88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180C8C
_08180C68:
	movs r4, #0
	b _08180C9C
	.align 2, 0
_08180C6C: .4byte 0x0000046B
_08180C70: .4byte 0x00000469
_08180C74: .4byte 0x0000046A
_08180C78: .4byte 0x0000046C
_08180C7C: .4byte 0x0000046D
_08180C80: .4byte 0x00000553
_08180C84: .4byte 0x030046A8
_08180C88: .4byte 0x030046AC
_08180C8C:
	ldr r0, _08180CAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, ip
	adds r4, r0, r3
_08180C9C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08180CB0
	adds r0, #4
	b _08180CBC
	.align 2, 0
_08180CAC: .4byte 0x030046A4
_08180CB0:
	ldr r0, _08180CD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08180CBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08180CD4
	cmp r2, #2
	beq _08180CDA
	b _08180CE0
	.align 2, 0
_08180CD0: .4byte 0x030046A4
_08180CD4:
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4, #4]
	b _08180CDE
_08180CDA:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2]
_08180CDE:
	subs r1, r1, r0
_08180CE0:
	ldr r3, [sp, #0x1c]
	strh r1, [r3, #2]
	ldr r0, _08180CF8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08180CFC
	movs r0, #1
	b _08180CFE
	.align 2, 0
_08180CF8: .4byte 0x030047A4
_08180CFC:
	movs r0, #0
_08180CFE:
	cmp r0, #0
	beq _08180D3C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08180D1E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08180D1A
	adds r2, r0, #0
_08180D1A:
	cmp r2, #0
	bge _08180D28
_08180D1E:
	ldr r6, _08180D24 @ =0x000005C4
	adds r0, r7, r6
	b _0818117C
	.align 2, 0
_08180D24: .4byte 0x000005C4
_08180D28:
	ldr r1, _08180D38 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08180D84
	.align 2, 0
_08180D38: .4byte 0x03002BE0
_08180D3C:
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
	blt _08180D68
	cmp r1, #0
	blt _08180D68
	ldr r0, _08180D6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180D68
	ldr r0, _08180D70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180D74
_08180D68:
	movs r5, #0
	b _08180D82
	.align 2, 0
_08180D6C: .4byte 0x030046A8
_08180D70: .4byte 0x030046AC
_08180D74:
	ldr r0, _08180E18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08180D82:
	movs r2, #0
_08180D84:
	ldr r3, _08180E1C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08180DA4
	ldr r1, _08180E20 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08180DA4
	b _081810C0
_08180DA4:
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
	beq _08180DBE
	b _0818119A
_08180DBE:
	ldr r0, _08180E24 @ =0x00000222
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
	beq _08180E28
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x40]
	strb r2, [r3]
	ldr r6, [sp, #0x38]
	strb r5, [r6]
	ldr r3, [sp, #0x64]
	strb r0, [r3]
	ldr r6, [sp, #0x24]
	str r1, [r6]
	ldr r0, [sp, #0x4c]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x2c]
	strb r5, [r1]
	ldr r3, [sp, #0x30]
	strb r5, [r3]
	ldr r6, [sp, #0x34]
	strb r0, [r6]
	ldr r0, [sp, #0x48]
	str r4, [r0]
	ldr r1, [sp, #0x3c]
	strb r2, [r1]
	b _08180F76
	.align 2, 0
_08180E18: .4byte 0x030046A4
_08180E1C: .4byte 0x00000256
_08180E20: .4byte 0x03002BE0
_08180E24: .4byte 0x00000222
_08180E28:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r2, [sp, #0x38]
	strb r5, [r2]
	ldr r4, [sp, #0x64]
	strb r0, [r4]
	ldr r2, [sp, #0x24]
	str r1, [r2]
	ldr r4, [sp, #0x4c]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x2c]
	strb r5, [r2]
	ldr r4, [sp, #0x30]
	strb r5, [r4]
	ldr r2, [sp, #0x34]
	strb r1, [r2]
	ldr r4, [sp, #0x48]
	str r3, [r4]
	ldr r1, [sp, #0x3c]
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
	blt _08180E8C
	cmp r1, #0
	blt _08180E8C
	ldr r0, _08180E90 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180E8C
	ldr r0, _08180E94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180E98
_08180E8C:
	movs r4, #0
	b _08180EA6
	.align 2, 0
_08180E90: .4byte 0x030046A8
_08180E94: .4byte 0x030046AC
_08180E98:
	ldr r0, _08180EB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08180EA6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08180EBC
	adds r0, #4
	b _08180EC8
	.align 2, 0
_08180EB8: .4byte 0x030046A4
_08180EBC:
	ldr r0, _08180EDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08180EC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08180EE0
	cmp r2, #2
	beq _08180EE4
	b _08180EE8
	.align 2, 0
_08180EDC: .4byte 0x030046A4
_08180EE0:
	ldrb r0, [r5, #4]
	b _08180EE6
_08180EE4:
	ldrb r0, [r5]
_08180EE6:
	subs r1, r1, r0
_08180EE8:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08180F10
	cmp r1, #0
	blt _08180F10
	ldr r0, _08180F14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08180F10
	ldr r0, _08180F18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08180F1C
_08180F10:
	movs r4, #0
	b _08180F2A
	.align 2, 0
_08180F14: .4byte 0x030046A8
_08180F18: .4byte 0x030046AC
_08180F1C:
	ldr r0, _08180F3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08180F2A:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08180F40
	adds r0, #4
	b _08180F4C
	.align 2, 0
_08180F3C: .4byte 0x030046A4
_08180F40:
	ldr r0, _08180F60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08180F4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08180F64
	cmp r3, #2
	beq _08180F68
	b _08180F6C
	.align 2, 0
_08180F60: .4byte 0x030046A4
_08180F64:
	ldrb r0, [r5, #4]
	b _08180F6A
_08180F68:
	ldrb r0, [r5]
_08180F6A:
	subs r2, r2, r0
_08180F6C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08180F76:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _08180FA0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _08181084
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08180FA4
	movs r0, #1
	b _08180FA6
	.align 2, 0
_08180FA0: .4byte 0x00000482
_08180FA4:
	movs r0, #0
_08180FA6:
	ldr r3, _08181094 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _08181084
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08181098 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0818109C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081810A0 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r4, _081810A4 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r6, _081810A8 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r0, _081810AC @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _081810B0 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x54]
	ldr r6, _081810B4 @ =0x0203B400
	ldr r1, _081810B8 @ =0x030046B8
	ldr r5, _081810BC @ =0x000003FF
	movs r4, #3
	mov r2, r8
_08180FF6:
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
	bne _08181014
	adds r3, #1
	cmp r3, #3
	ble _08180FF6
	mov r0, r8
_08181014:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x58]
	strb r0, [r6]
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r6, [sp, #0x60]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x50]
	strb r1, [r0]
	ldr r1, [sp, #0x28]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r6, [sp, #0x38]
	strb r3, [r6]
	ldr r4, [sp, #0x64]
	strb r0, [r4]
	ldr r6, [sp, #0x24]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x4c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r6, [sp, #0x30]
	strb r1, [r6]
	ldr r0, [sp, #0x34]
	strb r2, [r0]
	ldr r2, [sp, #0x48]
	str r3, [r2]
	ldr r3, [sp, #0x3c]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x54]
	strb r0, [r4]
_08181084:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r6, [sp, #0x44]
	strh r0, [r6]
	b _0818119A
	.align 2, 0
_08181094: .4byte 0x00000482
_08181098: .4byte 0x0000054F
_0818109C: .4byte 0x0000054C
_081810A0: .4byte 0x0000054D
_081810A4: .4byte 0x0000054E
_081810A8: .4byte 0x00000541
_081810AC: .4byte 0x000005BC
_081810B0: .4byte 0x00000542
_081810B4: .4byte 0x0203B400
_081810B8: .4byte 0x030046B8
_081810BC: .4byte 0x000003FF
_081810C0:
	mov sb, sp
	ldr r6, _081810FC @ =0x030046A4
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
	beq _08181100
	adds r0, #4
	b _0818110A
	.align 2, 0
_081810FC: .4byte 0x030046A4
_08181100:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818110A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _08181140 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08181144
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0818116A
	.align 2, 0
_08181140: .4byte 0x000004A4
_08181144:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08181164
	cmp r0, #2
	beq _08181160
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08181160:
	movs r0, #1
	b _08181174
_08181164:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0818116A:
	ldr r1, _08181188 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08181174:
	cmp r0, #0
	bne _0818119A
	ldr r4, _0818118C @ =0x000005C4
	adds r0, r7, r4
_0818117C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0818119A
	.align 2, 0
_08181188: .4byte 0xFFFFFDFF
_0818118C: .4byte 0x000005C4
_08181190:
	ldr r6, _081811AC @ =0x00000484
	adds r1, r7, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818119A:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081811AC: .4byte 0x00000484
