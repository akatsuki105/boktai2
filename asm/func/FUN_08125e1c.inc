	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r7, r0, #0
	ldr r0, _08125F48 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08125E38
	movs r0, #0
	strb r0, [r1]
_08125E38:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08125E52
	bl _081266D2
_08125E52:
	ldr r2, _08125F4C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08125E60
	bl _081266CE
_08125E60:
	ldr r3, _08125F50 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r0, #3
	movs r1, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _08125F54 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r0, _08125F58 @ =0x0000046A
	adds r0, r0, r7
	mov sl, r0
	strb r6, [r0]
	ldr r2, _08125F4C @ =0x00000484
	adds r2, r2, r7
	mov sb, r2
	str r6, [r2]
	ldr r3, _08125F48 @ =0x0000046C
	adds r5, r7, r3
	strb r1, [r5]
	ldr r2, _08125F5C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _08125F60 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r1, [r4]
	ldr r1, _08125F64 @ =0x0000046B
	adds r1, r1, r7
	mov ip, r1
	strb r6, [r1]
	adds r3, #0xe7
	adds r4, r7, r3
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r3, r7, r0
	str r2, [r3]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r2, r7, r1
	strh r6, [r2]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r7, r6
	ldrh r0, [r1]
	movs r6, #0x80
	ands r0, r6
	str r5, [sp, #0x50]
	ldr r5, [sp, #8]
	str r5, [sp, #0x40]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x44]
	mov r5, sl
	str r5, [sp, #0x48]
	mov r6, sb
	str r6, [sp, #0x5c]
	mov r5, r8
	str r5, [sp, #0x54]
	mov r6, ip
	str r6, [sp, #0x4c]
	str r4, [sp, #0x2c]
	str r3, [sp, #0x30]
	str r2, [sp, #0x34]
	mov r8, r1
	cmp r0, #0
	bne _08125EFA
	b _08126544
_08125EFA:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #0x80
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r7, r4
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov sb, r2
	cmp r4, #0
	blt _08125F44
	cmp r1, #0
	blt _08125F44
	ldr r0, _08125F68 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08125F44
	ldr r0, _08125F6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125F70
_08125F44:
	movs r4, #0
	b _08125F7E
	.align 2, 0
_08125F48: .4byte 0x0000046C
_08125F4C: .4byte 0x00000484
_08125F50: .4byte 0x000001DF
_08125F54: .4byte 0x00000469
_08125F58: .4byte 0x0000046A
_08125F5C: .4byte Enemy_WaitPendingState
_08125F60: .4byte 0x0000046D
_08125F64: .4byte 0x0000046B
_08125F68: .4byte 0x030046A8
_08125F6C: .4byte 0x030046AC
_08125F70:
	ldr r0, _08125F90 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08125F7E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08125F94
	adds r0, #4
	b _08125FA0
	.align 2, 0
_08125F90: .4byte 0x030046A4
_08125F94:
	ldr r0, _08125FB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08125FA0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08125FB8
	cmp r2, #2
	beq _08125FBC
	b _08125FC0
	.align 2, 0
_08125FB4: .4byte 0x030046A4
_08125FB8:
	ldrb r0, [r5, #4]
	b _08125FBE
_08125FBC:
	ldrb r0, [r5]
_08125FBE:
	subs r1, r1, r0
_08125FC0:
	strh r1, [r5, #2]
	ldr r0, _08125FD4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08125FD8
	movs r0, #1
	b _08125FDA
	.align 2, 0
_08125FD4: .4byte 0x030047A4
_08125FD8:
	movs r0, #0
_08125FDA:
	cmp r0, #0
	beq _08126018
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08125FFA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08125FF6
	adds r2, r0, #0
_08125FF6:
	cmp r2, #0
	bge _08126004
_08125FFA:
	ldr r6, _08126000 @ =0x000005C4
	adds r0, r7, r6
	b _0812645C
	.align 2, 0
_08126000: .4byte 0x000005C4
_08126004:
	ldr r1, _08126014 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08126060
	.align 2, 0
_08126014: .4byte 0x03002BE0
_08126018:
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
	blt _08126044
	cmp r1, #0
	blt _08126044
	ldr r0, _08126048 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126044
	ldr r0, _0812604C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126050
_08126044:
	movs r5, #0
	b _0812605E
	.align 2, 0
_08126048: .4byte 0x030046A8
_0812604C: .4byte 0x030046AC
_08126050:
	ldr r0, _08126098 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812605E:
	movs r2, #0
_08126060:
	ldr r3, _0812609C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08126080
	ldr r1, _081260A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08126080
	b _0812639C
_08126080:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, r8
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081260A4
	movs r0, #0
	b _08126472
	.align 2, 0
_08126098: .4byte 0x030046A4
_0812609C: .4byte 0x00000256
_081260A0: .4byte 0x03002BE0
_081260A4:
	ldr r5, _08126100 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x3c]
	cmp r3, #0
	beq _08126104
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r6, [sp, #0x4c]
	strb r5, [r6]
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	ldr r6, [sp, #0x30]
	str r1, [r6]
	ldr r0, [sp, #0x34]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x40]
	strb r5, [r1]
	ldr r3, [sp, #0x44]
	strb r5, [r3]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	ldr r6, [sp, #0x5c]
	str r4, [r6]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _08126252
	.align 2, 0
_08126100: .4byte 0x00000222
_08126104:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x30]
	str r1, [r4]
	ldr r1, [sp, #0x34]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, sb
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08126168
	cmp r1, #0
	blt _08126168
	ldr r0, _0812616C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126168
	ldr r0, _08126170 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126174
_08126168:
	movs r4, #0
	b _08126182
	.align 2, 0
_0812616C: .4byte 0x030046A8
_08126170: .4byte 0x030046AC
_08126174:
	ldr r0, _08126194 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08126182:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08126198
	adds r0, #4
	b _081261A4
	.align 2, 0
_08126194: .4byte 0x030046A4
_08126198:
	ldr r0, _081261B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081261A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081261BC
	cmp r2, #2
	beq _081261C0
	b _081261C4
	.align 2, 0
_081261B8: .4byte 0x030046A4
_081261BC:
	ldrb r0, [r5, #4]
	b _081261C2
_081261C0:
	ldrb r0, [r5]
_081261C2:
	subs r1, r1, r0
_081261C4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081261EC
	cmp r1, #0
	blt _081261EC
	ldr r0, _081261F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081261EC
	ldr r0, _081261F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081261F8
_081261EC:
	movs r4, #0
	b _08126206
	.align 2, 0
_081261F0: .4byte 0x030046A8
_081261F4: .4byte 0x030046AC
_081261F8:
	ldr r0, _08126218 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08126206:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812621C
	adds r0, #4
	b _08126228
	.align 2, 0
_08126218: .4byte 0x030046A4
_0812621C:
	ldr r0, _0812623C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08126228:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08126240
	cmp r3, #2
	beq _08126244
	b _08126248
	.align 2, 0
_0812623C: .4byte 0x030046A4
_08126240:
	ldrb r0, [r5, #4]
	b _08126246
_08126244:
	ldrb r0, [r5]
_08126246:
	subs r2, r2, r0
_08126248:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08126252:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x10]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, r8
	ldrh r0, [r5]
	ands r0, r1
	mov sl, r4
	ldr r6, _0812627C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x58]
	cmp r0, #0
	bne _08126360
	movs r1, #4
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08126280
	movs r0, #1
	b _08126282
	.align 2, 0
_0812627C: .4byte 0x00000482
_08126280:
	movs r0, #0
_08126282:
	ldr r3, _08126370 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _08126360
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _08126374 @ =0x0000054F
	adds r6, r7, r6
	str r6, [sp, #0x28]
	ldr r0, _08126378 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x1c]
	ldr r1, _0812637C @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _08126380 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x24]
	ldr r4, _08126384 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x14]
	ldr r5, _08126388 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r6, _0812638C @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x18]
	ldr r6, _08126390 @ =0x0203B400
	ldr r1, _08126394 @ =0x030046B8
	ldr r5, _08126398 @ =0x000003FF
	movs r2, #3
	mov r4, sl
_081262D2:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081262F0
	adds r3, #1
	cmp r3, #3
	ble _081262D2
	mov r0, sl
_081262F0:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x30]
	ldr r0, [r2]
	mov r4, ip
	str r0, [r4]
	ldr r5, [sp, #0x2c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x28]
	strb r0, [r6]
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r4, [sp, #0x44]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	ldrb r0, [r6]
	ldr r1, [sp, #0x24]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #0x10]
	ldr r2, [sp, #0x14]
	strb r4, [r2]
	ldr r5, [sp, #0x38]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x54]
	strb r1, [r6]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r6, [sp, #0x30]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x34]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r6, [sp, #0x48]
	strb r2, [r6]
	ldr r0, [sp, #0x5c]
	str r3, [r0]
	ldr r2, [sp, #0x50]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x18]
	strb r0, [r3]
_08126360:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x58]
	strh r0, [r4]
	movs r0, #0
	b _08126472
	.align 2, 0
_08126370: .4byte 0x00000482
_08126374: .4byte 0x0000054F
_08126378: .4byte 0x0000054C
_0812637C: .4byte 0x0000054D
_08126380: .4byte 0x0000054E
_08126384: .4byte 0x00000541
_08126388: .4byte 0x000005BC
_0812638C: .4byte 0x00000542
_08126390: .4byte 0x0203B400
_08126394: .4byte 0x030046B8
_08126398: .4byte 0x000003FF
_0812639C:
	mov sl, sp
	ldr r6, _081263D8 @ =0x030046A4
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
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081263DC
	adds r0, #4
	b _081263E6
	.align 2, 0
_081263D8: .4byte 0x030046A4
_081263DC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081263E6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sl
	strh r0, [r4, #2]
	mov r5, sb
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _08126420 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08126428
	ldr r0, _08126424 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08126452
	.align 2, 0
_08126420: .4byte 0x000004A4
_08126424: .4byte 0xFFFFFDFF
_08126428:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08126448
	cmp r0, #2
	beq _08126444
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08126444:
	movs r0, #1
	b _08126454
_08126448:
	ldr r0, _08126468 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08126452:
	movs r0, #0
_08126454:
	cmp r0, #0
	bne _08126470
	ldr r4, _0812646C @ =0x000005C4
	adds r0, r7, r4
_0812645C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08126472
	.align 2, 0
_08126468: .4byte 0xFFFFFDFF
_0812646C: .4byte 0x000005C4
_08126470:
	movs r0, #1
_08126472:
	cmp r0, #0
	bne _081264F8
	ldr r5, _081264A8 @ =0x000004A4
	adds r0, r7, r5
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
	bne _081264B0
	ldr r0, _081264AC @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081264DA
	.align 2, 0
_081264A8: .4byte 0x000004A4
_081264AC: .4byte 0xFFFFFDFF
_081264B0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081264D0
	cmp r0, #2
	beq _081264CC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081264CC:
	movs r0, #1
	b _081264DC
_081264D0:
	ldr r0, _081264F0 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081264DA:
	movs r0, #0
_081264DC:
	cmp r0, #0
	bne _081264F8
	ldr r4, _081264F4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081266D2
	.align 2, 0
_081264F0: .4byte 0xFFFFFDFF
_081264F4: .4byte 0x000005C4
_081264F8:
	movs r0, #4
	ldr r5, _08126538 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r5, #0xc
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r6, #0x64
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0812653C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08126540 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
	b _081266D2
	.align 2, 0
_08126538: .4byte 0x00000222
_0812653C: .4byte 0x00000551
_08126540: .4byte 0x00000552
_08126544:
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r5, #0x4c
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	subs r6, #8
	adds r0, r7, r6
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081265BC @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081265C0 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
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
	blt _081265B8
	cmp r1, #0
	blt _081265B8
	ldr r0, _081265C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081265B8
	ldr r0, _081265C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081265CC
_081265B8:
	movs r4, #0
	b _081265DA
	.align 2, 0
_081265BC: .4byte 0x00000551
_081265C0: .4byte 0x00000552
_081265C4: .4byte 0x030046A8
_081265C8: .4byte 0x030046AC
_081265CC:
	ldr r0, _081265EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081265DA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081265F0
	adds r0, #4
	b _081265FC
	.align 2, 0
_081265EC: .4byte 0x030046A4
_081265F0:
	ldr r0, _08126610 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081265FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08126614
	cmp r2, #2
	beq _08126618
	b _0812661C
	.align 2, 0
_08126610: .4byte 0x030046A4
_08126614:
	ldrb r0, [r5, #4]
	b _0812661A
_08126618:
	ldrb r0, [r5]
_0812661A:
	subs r1, r1, r0
_0812661C:
	strh r1, [r5, #2]
	ldr r5, _0812664C @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08126654
	ldr r0, _08126650 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0812667E
	.align 2, 0
_0812664C: .4byte 0x000004A4
_08126650: .4byte 0xFFFFFDFF
_08126654:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08126674
	cmp r0, #2
	beq _08126670
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08126670:
	movs r0, #1
	b _08126680
_08126674:
	ldr r0, _081266B8 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0812667E:
	movs r0, #0
_08126680:
	adds r3, r0, #0
	cmp r3, #0
	bne _081266C0
	ldr r0, _081266BC @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r6, [sp, #0x2c]
	strb r3, [r6]
	ldr r1, [sp, #0x30]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x34]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r3, [sp, #0x50]
	strb r2, [r3]
	b _081266D2
	.align 2, 0
_081266B8: .4byte 0xFFFFFDFF
_081266BC: .4byte Enemy_ClearStateBegun
_081266C0:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081266D2

_081266CE:
	adds r0, #1
	str r0, [r1]
_081266D2:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
