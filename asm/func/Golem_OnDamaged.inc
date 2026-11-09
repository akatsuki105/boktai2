	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _0811AF10 @ =0x0000065C
	adds r1, r0, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	ldr r5, _0811AF14 @ =0xFEFFFFFF
	mov sl, r5
	ldr r0, [r4]
	ands r0, r5
	str r0, [r4]
	adds r0, r7, #0
	movs r1, #1
	bl PlayGolemSound
	movs r0, #0x80
	lsls r0, r0, #6
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r6, r7, r1
	ldrh r2, [r6]
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0811AE86
	b _0811B5F0
_0811AE86:
	ldr r2, _0811AF18 @ =0x000001DD
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, _0811AF1C @ =0xFFFFDFDF
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r3, _0811AF20 @ =0x00000544
	adds r1, r7, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0811AF24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r6
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
	str r3, [sp, #0x144]
	str r2, [sp, #0x110]
	cmp r5, #0
	blt _0811AF0A
	cmp r1, #0
	blt _0811AF0A
	ldr r0, _0811AF28 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811AF0A
	ldr r0, _0811AF2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811AF30
_0811AF0A:
	movs r4, #0
	b _0811AF3E
	.align 2, 0
_0811AF10: .4byte 0x0000065C
_0811AF14: .4byte 0xFEFFFFFF
_0811AF18: .4byte 0x000001DD
_0811AF1C: .4byte 0xFFFFDFDF
_0811AF20: .4byte 0x00000544
_0811AF24: .4byte 0x03002BE0
_0811AF28: .4byte 0x030046A8
_0811AF2C: .4byte 0x030046AC
_0811AF30:
	ldr r0, _0811AF50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811AF3E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811AF54
	adds r0, #4
	b _0811AF60
	.align 2, 0
_0811AF50: .4byte 0x030046A4
_0811AF54:
	ldr r0, _0811AF74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811AF60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811AF78
	cmp r2, #2
	beq _0811AF7C
	b _0811AF80
	.align 2, 0
_0811AF74: .4byte 0x030046A4
_0811AF78:
	ldrb r0, [r6, #4]
	b _0811AF7E
_0811AF7C:
	ldrb r0, [r6]
_0811AF7E:
	subs r1, r1, r0
_0811AF80:
	strh r1, [r6, #2]
	ldr r0, _0811AF94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811AF98
	movs r0, #1
	b _0811AF9A
	.align 2, 0
_0811AF94: .4byte 0x030047A4
_0811AF98:
	movs r0, #0
_0811AF9A:
	cmp r0, #0
	beq _0811AFD8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811AFBA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811AFB6
	adds r2, r0, #0
_0811AFB6:
	cmp r2, #0
	bge _0811AFC4
_0811AFBA:
	ldr r2, _0811AFC0 @ =0x000005C4
	adds r0, r7, r2
	b _0811B4F4
	.align 2, 0
_0811AFC0: .4byte 0x000005C4
_0811AFC4:
	ldr r1, _0811AFD4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811B020
	.align 2, 0
_0811AFD4: .4byte 0x03002BE0
_0811AFD8:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811B004
	cmp r1, #0
	blt _0811B004
	ldr r0, _0811B008 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811B004
	ldr r0, _0811B00C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B010
_0811B004:
	movs r5, #0
	b _0811B01E
	.align 2, 0
_0811B008: .4byte 0x030046A8
_0811B00C: .4byte 0x030046AC
_0811B010:
	ldr r0, _0811B060 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811B01E:
	movs r2, #0
_0811B020:
	ldr r4, _0811B064 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811B040
	ldr r1, _0811B068 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811B040
	b _0811B438
_0811B040:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x24]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811B06C
	movs r0, #0
	b _0811B50A
	.align 2, 0
_0811B060: .4byte 0x030046A4
_0811B064: .4byte 0x00000256
_0811B068: .4byte 0x03002BE0
_0811B06C:
	ldr r6, _0811B110 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x118]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x120]
	cmp r6, #0
	beq _0811B124
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0811B114 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x28]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0811B118 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x30]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x34]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x24]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0811B11C @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0811B120 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x24]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811B2F6
	.align 2, 0
_0811B110: .4byte 0x00000222
_0811B114: .4byte 0x0000046D
_0811B118: .4byte 0x0000046B
_0811B11C: .4byte 0x00000469
_0811B120: .4byte 0x00000484
_0811B124:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811B1E8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x38]
	strb r0, [r2]
	ldr r3, _0811B1EC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811B1F0 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x40]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x44]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x48]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0811B1F4 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0811B1F8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0811B1FC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0x50]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x50]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x50]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0x3c]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0x40]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	mov r0, sb
	cmp r0, #0
	blt _0811B1E2
	cmp r1, #0
	blt _0811B1E2
	ldr r0, _0811B200 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _0811B1E2
	ldr r0, _0811B204 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B208
_0811B1E2:
	movs r4, #0
	b _0811B218
	.align 2, 0
_0811B1E8: .4byte 0x0000046D
_0811B1EC: .4byte 0x0000046B
_0811B1F0: .4byte 0x00000553
_0811B1F4: .4byte 0x00000469
_0811B1F8: .4byte 0x00000484
_0811B1FC: .4byte 0x0000046C
_0811B200: .4byte 0x030046A8
_0811B204: .4byte 0x030046AC
_0811B208:
	ldr r0, _0811B228 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_0811B218:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811B22C
	adds r0, #4
	b _0811B238
	.align 2, 0
_0811B228: .4byte 0x030046A4
_0811B22C:
	ldr r0, _0811B24C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811B238:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811B250
	cmp r2, #2
	beq _0811B256
	b _0811B25C
	.align 2, 0
_0811B24C: .4byte 0x030046A4
_0811B250:
	ldr r2, [sp, #0x50]
	ldrb r0, [r2, #4]
	b _0811B25A
_0811B256:
	ldr r3, [sp, #0x50]
	ldrb r0, [r3]
_0811B25A:
	subs r1, r1, r0
_0811B25C:
	ldr r4, [sp, #0x50]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x144]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811B288
	cmp r1, #0
	blt _0811B288
	ldr r0, _0811B28C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811B288
	ldr r0, _0811B290 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B294
_0811B288:
	movs r4, #0
	b _0811B2A2
	.align 2, 0
_0811B28C: .4byte 0x030046A8
_0811B290: .4byte 0x030046AC
_0811B294:
	ldr r0, _0811B2B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811B2A2:
	ldr r6, [sp, #0x144]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811B2BC
	adds r0, #4
	b _0811B2C8
	.align 2, 0
_0811B2B8: .4byte 0x030046A4
_0811B2BC:
	ldr r0, _0811B2DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811B2C8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811B2E0
	cmp r3, #2
	beq _0811B2E4
	b _0811B2E8
	.align 2, 0
_0811B2DC: .4byte 0x030046A4
_0811B2E0:
	ldrb r0, [r5, #4]
	b _0811B2E6
_0811B2E4:
	ldrb r0, [r5]
_0811B2E6:
	subs r2, r2, r0
_0811B2E8:
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x144]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811B2F6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x118]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _0811B320 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811B3FE
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811B324
	movs r0, #1
	b _0811B326
	.align 2, 0
_0811B320: .4byte 0x00000482
_0811B324:
	movs r0, #0
_0811B326:
	ldr r3, _0811B410 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811B3FE
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811B414 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811B418 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811B41C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811B420 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811B424 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811B428 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811B42C @ =0x030046B8
	str r5, [sp, #0x148]
_0811B36C:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811B430 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811B434 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811B392
	adds r3, #1
	cmp r3, #3
	ble _0811B36C
	adds r0, r5, #0
_0811B392:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0x54
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811B3FE:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811B50A
	.align 2, 0
_0811B410: .4byte 0x00000482
_0811B414: .4byte 0x0000054F
_0811B418: .4byte 0x0000054C
_0811B41C: .4byte 0x0000054E
_0811B420: .4byte 0x00000541
_0811B424: .4byte 0x000005BC
_0811B428: .4byte 0x00000542
_0811B42C: .4byte 0x030046B8
_0811B430: .4byte 0x000003FF
_0811B434: .4byte 0x0203B400
_0811B438:
	mov sb, sp
	ldr r6, _0811B474 @ =0x030046A4
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
	beq _0811B478
	adds r0, #4
	b _0811B482
	.align 2, 0
_0811B474: .4byte 0x030046A4
_0811B478:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811B482:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0811B4B8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811B4BC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0811B4E2
	.align 2, 0
_0811B4B8: .4byte 0x000004A4
_0811B4BC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811B4DC
	cmp r0, #2
	beq _0811B4D8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811B4D8:
	movs r0, #1
	b _0811B4EC
_0811B4DC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0811B4E2:
	ldr r1, _0811B500 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811B4EC:
	cmp r0, #0
	bne _0811B508
	ldr r3, _0811B504 @ =0x000005C4
	adds r0, r7, r3
_0811B4F4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811B50A
	.align 2, 0
_0811B500: .4byte 0xFFFFFDFF
_0811B504: .4byte 0x000005C4
_0811B508:
	movs r0, #1
_0811B50A:
	cmp r0, #0
	bne _0811B584
	ldr r4, _0811B53C @ =0x000004A4
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
	bne _0811B540
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0811B566
	.align 2, 0
_0811B53C: .4byte 0x000004A4
_0811B540:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811B560
	cmp r0, #2
	beq _0811B55C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811B55C:
	movs r0, #1
	b _0811B570
_0811B560:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0811B566:
	ldr r1, _0811B57C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811B570:
	cmp r0, #0
	bne _0811B584
	ldr r4, _0811B580 @ =0x000005C4
	adds r0, r7, r4
	bl FUN_0811cf1c
	.align 2, 0
_0811B57C: .4byte 0xFFFFFDFF
_0811B580: .4byte 0x000005C4
_0811B584:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0811B5DC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0811B5E0 @ =0x0000046B
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
	ldr r6, _0811B5E4 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B5E8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0811B5EC @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	bl FUN_0811cf84
	.align 2, 0
_0811B5DC: .4byte 0x0000046D
_0811B5E0: .4byte 0x0000046B
_0811B5E4: .4byte 0x00000469
_0811B5E8: .4byte 0x0000046A
_0811B5EC: .4byte 0x00000484
_0811B5F0:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811B606
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	b _0811B848
_0811B606:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _0811B69C
	movs r0, #0x83
	lsls r0, r0, #2
	adds r3, r7, r0
	movs r1, #0x85
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r2, _0811B680 @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _0811B684 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _0811B688 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _0811B68C @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _0811B690 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0811B694 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _0811B698 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	bl _0811CF88
	.align 2, 0
_0811B680: .4byte 0x00000594
_0811B684: .4byte 0x0000046D
_0811B688: .4byte 0x0000046B
_0811B68C: .4byte 0x00000553
_0811B690: .4byte 0x0000046A
_0811B694: .4byte 0x00000484
_0811B698: .4byte 0x0000046C
_0811B69C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0811B6AC
	b _0811B854
_0811B6AC:
	movs r5, #0x93
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r5, [r0]
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	beq _0811B788
	ldr r6, [sp, #0x20]
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r2, #0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _0811B764 @ =0x000006E2
	adds r1, r6, r3
	movs r0, #0x14
	strh r0, [r1]
	movs r4, #0xc8
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrh r0, [r0]
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	ldr r6, _0811B768 @ =0x000005CC
	adds r0, r7, r6
	ldr r4, [r0]
	movs r1, #0x12
	ldr r3, _0811B76C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _0811B770 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x79
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	mov r5, sb
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B774 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r4, _0811B778 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _0811B77C @ =0x00000484
	adds r0, r7, r5
	mov r6, sb
	str r6, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	adds r4, #0x32
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [r2]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0811B780 @ =0xFEFFFFFC
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r1, _0811B784 @ =0x00000482
	adds r0, r7, r1
	strh r3, [r0]
	bl _0811CF88
	.align 2, 0
_0811B764: .4byte 0x000006E2
_0811B768: .4byte 0x000005CC
_0811B76C: .4byte 0x0000046D
_0811B770: .4byte 0x0000046B
_0811B774: .4byte 0x00000469
_0811B778: .4byte 0x0000046A
_0811B77C: .4byte 0x00000484
_0811B780: .4byte 0xFEFFFFFC
_0811B784: .4byte 0x00000482
_0811B788:
	ldr r2, _0811B804 @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0811B81C
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r2, #0
	strh r0, [r1]
	ldr r6, _0811B808 @ =0x000005CC
	adds r0, r7, r6
	ldr r3, [r0]
	movs r1, #0x12
	ldr r4, _0811B80C @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0811B810 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B814 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0811B818 @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	mov r3, sl
	ands r0, r3
	str r0, [r2]
	bl _0811CF88
	.align 2, 0
_0811B804: .4byte 0x0000049C
_0811B808: .4byte 0x000005CC
_0811B80C: .4byte 0x0000046D
_0811B810: .4byte 0x0000046B
_0811B814: .4byte 0x00000469
_0811B818: .4byte 0x0000046A
_0811B81C:
	adds r0, r7, #0
	movs r1, #1
	bl PlayGolemSound
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _0811B840
	adds r0, r7, #0
	bl Golem_TargetPlayerTile
	ldr r5, [sp, #0x20]
	ldr r0, _0811B850 @ =0x000006B4
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
_0811B840:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
_0811B848:
	strh r0, [r6]
_0811B84A:
	movs r0, #0
	bl FUN_0811cf8a
	.align 2, 0
_0811B850: .4byte 0x000006B4
_0811B854:
	ldr r1, _0811B8D0 @ =0x0000049C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0811B8E4
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r2, #0
	strh r0, [r1]
	ldr r4, _0811B8D4 @ =0x000005CC
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x12
	ldr r6, _0811B8D8 @ =0x0000046D
	adds r0, r7, r6
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B8DC @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0811B8E0 @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	mov r3, sl
	ands r0, r3
	str r0, [r2]
	bl _0811CF88
	.align 2, 0
_0811B8D0: .4byte 0x0000049C
_0811B8D4: .4byte 0x000005CC
_0811B8D8: .4byte 0x0000046D
_0811B8DC: .4byte 0x00000469
_0811B8E0: .4byte 0x0000046A
_0811B8E4:
	movs r3, #0x21
	rsbs r3, r3, #0
	ands r3, r2
	strh r3, [r6]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x114]
	cmp r0, #0
	bne _0811B84A
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	bne _0811B90A
	b _0811C07C
_0811B90A:
	ldr r5, _0811B9A4 @ =0x0000048D
	adds r2, r7, r5
	ldrb r0, [r2]
	cmp r0, #0
	bne _0811B936
	ldr r6, _0811B9A8 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0811B936
	ldr r1, _0811B9AC @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0811B936:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0
	bne _0811B944
	b _0811B84A
_0811B944:
	ldr r0, _0811B9B0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x80
	ldr r3, [sp, #0x114]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #4
	ldr r4, _0811B9B4 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r4, r7, r5
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
	str r4, [sp, #0x144]
	str r2, [sp, #0x110]
	str r3, [sp, #0x120]
	cmp r5, #0
	blt _0811B9A0
	cmp r1, #0
	blt _0811B9A0
	ldr r0, _0811B9B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811B9A0
	ldr r0, _0811B9BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B9C0
_0811B9A0:
	movs r4, #0
	b _0811B9CE
	.align 2, 0
_0811B9A4: .4byte 0x0000048D
_0811B9A8: .4byte 0x0000048C
_0811B9AC: .4byte 0x000004BE
_0811B9B0: .4byte 0x03002BE0
_0811B9B4: .4byte 0x00000222
_0811B9B8: .4byte 0x030046A8
_0811B9BC: .4byte 0x030046AC
_0811B9C0:
	ldr r0, _0811B9E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811B9CE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811B9E4
	adds r0, #4
	b _0811B9F0
	.align 2, 0
_0811B9E0: .4byte 0x030046A4
_0811B9E4:
	ldr r0, _0811BA04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811B9F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811BA08
	cmp r2, #2
	beq _0811BA0C
	b _0811BA10
	.align 2, 0
_0811BA04: .4byte 0x030046A4
_0811BA08:
	ldrb r0, [r6, #4]
	b _0811BA0E
_0811BA0C:
	ldrb r0, [r6]
_0811BA0E:
	subs r1, r1, r0
_0811BA10:
	strh r1, [r6, #2]
	ldr r0, _0811BA24 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811BA28
	movs r0, #1
	b _0811BA2A
	.align 2, 0
_0811BA24: .4byte 0x030047A4
_0811BA28:
	movs r0, #0
_0811BA2A:
	cmp r0, #0
	beq _0811BA68
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0811BA4A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811BA46
	adds r2, r0, #0
_0811BA46:
	cmp r2, #0
	bge _0811BA54
_0811BA4A:
	ldr r1, _0811BA50 @ =0x000005C4
	adds r0, r7, r1
	b _0811BF88
	.align 2, 0
_0811BA50: .4byte 0x000005C4
_0811BA54:
	ldr r1, _0811BA64 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811BAB0
	.align 2, 0
_0811BA64: .4byte 0x03002BE0
_0811BA68:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811BA94
	cmp r1, #0
	blt _0811BA94
	ldr r0, _0811BA98 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811BA94
	ldr r0, _0811BA9C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811BAA0
_0811BA94:
	movs r5, #0
	b _0811BAAE
	.align 2, 0
_0811BA98: .4byte 0x030046A8
_0811BA9C: .4byte 0x030046AC
_0811BAA0:
	ldr r0, _0811BAF0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811BAAE:
	movs r2, #0
_0811BAB0:
	ldr r3, _0811BAF4 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811BAD0
	ldr r1, _0811BAF8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811BAD0
	b _0811BEC8
_0811BAD0:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x58]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811BAFC
	movs r0, #0
	b _0811BF9E
	.align 2, 0
_0811BAF0: .4byte 0x030046A4
_0811BAF4: .4byte 0x00000256
_0811BAF8: .4byte 0x03002BE0
_0811BAFC:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x120]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0x118]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0811BBB8
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0811BB9C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0811BBA0 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x60]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0811BBA4 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x64]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x68]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x58
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0811BBA8 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0811BBAC @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0811BBB0 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x58]
	str r6, [r1]
	ldr r6, _0811BBB4 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811BD86
	.align 2, 0
_0811BB9C: .4byte 0x0000046D
_0811BBA0: .4byte 0x0000046B
_0811BBA4: .4byte 0x00000553
_0811BBA8: .4byte 0x00000469
_0811BBAC: .4byte 0x0000046A
_0811BBB0: .4byte 0x00000484
_0811BBB4: .4byte 0x0000046C
_0811BBB8:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0811BC78 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	strb r0, [r3]
	ldr r4, _0811BC7C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x70]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0811BC80 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x74]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x78]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x7c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0811BC84 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0811BC88 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0811BC8C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0x84]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x84]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x84]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0x70]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0x74]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0x7c]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0x80]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	mov r0, r8
	cmp r0, #0
	blt _0811BC74
	cmp r1, #0
	blt _0811BC74
	ldr r0, _0811BC90 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _0811BC74
	ldr r0, _0811BC94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811BC98
_0811BC74:
	movs r4, #0
	b _0811BCA8
	.align 2, 0
_0811BC78: .4byte 0x0000046D
_0811BC7C: .4byte 0x0000046B
_0811BC80: .4byte 0x00000553
_0811BC84: .4byte 0x00000469
_0811BC88: .4byte 0x0000046A
_0811BC8C: .4byte 0x00000484
_0811BC90: .4byte 0x030046A8
_0811BC94: .4byte 0x030046AC
_0811BC98:
	ldr r0, _0811BCB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_0811BCA8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811BCBC
	adds r0, #4
	b _0811BCC8
	.align 2, 0
_0811BCB8: .4byte 0x030046A4
_0811BCBC:
	ldr r0, _0811BCDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811BCC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811BCE0
	cmp r2, #2
	beq _0811BCE6
	b _0811BCEC
	.align 2, 0
_0811BCDC: .4byte 0x030046A4
_0811BCE0:
	ldr r2, [sp, #0x84]
	ldrb r0, [r2, #4]
	b _0811BCEA
_0811BCE6:
	ldr r3, [sp, #0x84]
	ldrb r0, [r3]
_0811BCEA:
	subs r1, r1, r0
_0811BCEC:
	ldr r4, [sp, #0x84]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x144]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811BD18
	cmp r1, #0
	blt _0811BD18
	ldr r0, _0811BD1C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811BD18
	ldr r0, _0811BD20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811BD24
_0811BD18:
	movs r4, #0
	b _0811BD32
	.align 2, 0
_0811BD1C: .4byte 0x030046A8
_0811BD20: .4byte 0x030046AC
_0811BD24:
	ldr r0, _0811BD48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811BD32:
	ldr r6, [sp, #0x144]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811BD4C
	adds r0, #4
	b _0811BD58
	.align 2, 0
_0811BD48: .4byte 0x030046A4
_0811BD4C:
	ldr r0, _0811BD6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811BD58:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811BD70
	cmp r3, #2
	beq _0811BD74
	b _0811BD78
	.align 2, 0
_0811BD6C: .4byte 0x030046A4
_0811BD70:
	ldrb r0, [r5, #4]
	b _0811BD76
_0811BD74:
	ldrb r0, [r5]
_0811BD76:
	subs r2, r2, r0
_0811BD78:
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x144]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811BD86:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x88]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x118]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _0811BDB0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811BE8E
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811BDB4
	movs r0, #1
	b _0811BDB6
	.align 2, 0
_0811BDB0: .4byte 0x00000482
_0811BDB4:
	movs r0, #0
_0811BDB6:
	ldr r3, _0811BEA0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811BE8E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811BEA4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811BEA8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811BEAC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811BEB0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811BEB4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811BEB8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811BEBC @ =0x030046B8
	str r5, [sp, #0x148]
_0811BDFC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811BEC0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811BEC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811BE22
	adds r3, #1
	cmp r3, #3
	ble _0811BDFC
	adds r0, r5, #0
_0811BE22:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0x88
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811BE8E:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811BF9E
	.align 2, 0
_0811BEA0: .4byte 0x00000482
_0811BEA4: .4byte 0x0000054F
_0811BEA8: .4byte 0x0000054C
_0811BEAC: .4byte 0x0000054E
_0811BEB0: .4byte 0x00000541
_0811BEB4: .4byte 0x000005BC
_0811BEB8: .4byte 0x00000542
_0811BEBC: .4byte 0x030046B8
_0811BEC0: .4byte 0x000003FF
_0811BEC4: .4byte 0x0203B400
_0811BEC8:
	add r6, sp, #8
	ldr r0, _0811BF08 @ =0x030046A4
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
	beq _0811BF0C
	adds r0, #4
	b _0811BF18
	.align 2, 0
_0811BF08: .4byte 0x030046A4
_0811BF0C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811BF18:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811BF4C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811BF50
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0811BF76
	.align 2, 0
_0811BF4C: .4byte 0x000004A4
_0811BF50:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811BF70
	cmp r0, #2
	beq _0811BF6C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811BF6C:
	movs r0, #1
	b _0811BF80
_0811BF70:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0811BF76:
	ldr r1, _0811BF94 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811BF80:
	cmp r0, #0
	bne _0811BF9C
	ldr r2, _0811BF98 @ =0x000005C4
	adds r0, r7, r2
_0811BF88:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811BF9E
	.align 2, 0
_0811BF94: .4byte 0xFFFFFDFF
_0811BF98: .4byte 0x000005C4
_0811BF9C:
	movs r0, #1
_0811BF9E:
	cmp r0, #0
	bne _0811C00C
	ldr r3, _0811BFD0 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811BFD4
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0811BFFA
	.align 2, 0
_0811BFD0: .4byte 0x000004A4
_0811BFD4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811BFF4
	cmp r0, #2
	beq _0811BFF0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811BFF0:
	movs r0, #1
	b _0811C004
_0811BFF4:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0811BFFA:
	ldr r1, _0811C064 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811C004:
	cmp r0, #0
	bne _0811C00C
	bl _0811CF18
_0811C00C:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r4, _0811C068 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0811C06C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0811C070 @ =0x00000553
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
	ldr r1, _0811C074 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0811C078 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _0811CF88
	.align 2, 0
_0811C064: .4byte 0xFFFFFDFF
_0811C068: .4byte 0x0000046D
_0811C06C: .4byte 0x0000046B
_0811C070: .4byte 0x00000553
_0811C074: .4byte 0x0000046A
_0811C078: .4byte 0x00000484
_0811C07C:
	ldr r6, [sp, #0x20]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811C08C
	b _0811C824
_0811C08C:
	ldr r3, _0811C124 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _0811C0B8
	ldr r4, _0811C128 @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0811C0B8
	ldr r5, _0811C12C @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0811C0B8:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _0811C0C8
	bl _0811B84A
_0811C0C8:
	ldr r0, _0811C130 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	adds r3, r7, r2
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
	str r3, [sp, #0x144]
	str r2, [sp, #0x110]
	cmp r5, #0
	blt _0811C11E
	cmp r1, #0
	blt _0811C11E
	ldr r0, _0811C134 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811C11E
	ldr r0, _0811C138 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C13C
_0811C11E:
	movs r4, #0
	b _0811C14A
	.align 2, 0
_0811C124: .4byte 0x0000048D
_0811C128: .4byte 0x0000048C
_0811C12C: .4byte 0x000004BE
_0811C130: .4byte 0x03002BE0
_0811C134: .4byte 0x030046A8
_0811C138: .4byte 0x030046AC
_0811C13C:
	ldr r0, _0811C15C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811C14A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811C160
	adds r0, #4
	b _0811C16C
	.align 2, 0
_0811C15C: .4byte 0x030046A4
_0811C160:
	ldr r0, _0811C180 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C16C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811C184
	cmp r2, #2
	beq _0811C188
	b _0811C18C
	.align 2, 0
_0811C180: .4byte 0x030046A4
_0811C184:
	ldrb r0, [r6, #4]
	b _0811C18A
_0811C188:
	ldrb r0, [r6]
_0811C18A:
	subs r1, r1, r0
_0811C18C:
	strh r1, [r6, #2]
	ldr r0, _0811C1A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811C1A4
	movs r0, #1
	b _0811C1A6
	.align 2, 0
_0811C1A0: .4byte 0x030047A4
_0811C1A4:
	movs r0, #0
_0811C1A6:
	cmp r0, #0
	beq _0811C1E4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _0811C1C6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811C1C2
	adds r2, r0, #0
_0811C1C2:
	cmp r2, #0
	bge _0811C1D0
_0811C1C6:
	ldr r4, _0811C1CC @ =0x000005C4
	adds r0, r7, r4
	b _0811C710
	.align 2, 0
_0811C1CC: .4byte 0x000005C4
_0811C1D0:
	ldr r1, _0811C1E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811C22C
	.align 2, 0
_0811C1E0: .4byte 0x03002BE0
_0811C1E4:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811C210
	cmp r1, #0
	blt _0811C210
	ldr r0, _0811C214 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811C210
	ldr r0, _0811C218 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C21C
_0811C210:
	movs r5, #0
	b _0811C22A
	.align 2, 0
_0811C214: .4byte 0x030046A8
_0811C218: .4byte 0x030046AC
_0811C21C:
	ldr r0, _0811C26C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811C22A:
	movs r2, #0
_0811C22C:
	ldr r6, _0811C270 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811C24C
	ldr r1, _0811C274 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811C24C
	b _0811C650
_0811C24C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x8c]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811C278
	movs r0, #0
	b _0811C726
	.align 2, 0
_0811C26C: .4byte 0x030046A4
_0811C270: .4byte 0x00000256
_0811C274: .4byte 0x03002BE0
_0811C278:
	ldr r3, _0811C320 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x118]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0x120]
	cmp r0, #0
	beq _0811C338
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0811C324 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x90]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0811C328 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x98]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x8c
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0811C32C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0811C330 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x8c]
	str r6, [r1]
	ldr r6, _0811C334 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0x94]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0x9c]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811C50C
	.align 2, 0
_0811C320: .4byte 0x00000222
_0811C324: .4byte 0x0000046D
_0811C328: .4byte 0x0000046B
_0811C32C: .4byte 0x00000469
_0811C330: .4byte 0x00000484
_0811C334: .4byte 0x0000046C
_0811C338:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811C400 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	strb r0, [r2]
	ldr r3, _0811C404 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0xa4]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811C408 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xac]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	strb r4, [r3]
	ldr r4, _0811C40C @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0811C410 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _0811C414 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xb8]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xb8]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xbc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0xa4]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0xa8]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0xac]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0xb0]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0xb4]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	ldr r0, [sp, #0xbc]
	cmp r0, #0
	blt _0811C3FA
	cmp r1, #0
	blt _0811C3FA
	ldr r0, _0811C418 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xbc]
	cmp r2, r0
	bhs _0811C3FA
	ldr r0, _0811C41C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C420
_0811C3FA:
	movs r4, #0
	b _0811C430
	.align 2, 0
_0811C400: .4byte 0x0000046D
_0811C404: .4byte 0x0000046B
_0811C408: .4byte 0x00000553
_0811C40C: .4byte 0x00000469
_0811C410: .4byte 0x0000046A
_0811C414: .4byte 0x00000484
_0811C418: .4byte 0x030046A8
_0811C41C: .4byte 0x030046AC
_0811C420:
	ldr r0, _0811C440 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xbc]
	adds r4, r0, r3
_0811C430:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811C444
	adds r0, #4
	b _0811C450
	.align 2, 0
_0811C440: .4byte 0x030046A4
_0811C444:
	ldr r0, _0811C464 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C450:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811C468
	cmp r2, #2
	beq _0811C46E
	b _0811C474
	.align 2, 0
_0811C464: .4byte 0x030046A4
_0811C468:
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4, #4]
	b _0811C472
_0811C46E:
	ldr r5, [sp, #0xb8]
	ldrb r0, [r5]
_0811C472:
	subs r1, r1, r0
_0811C474:
	ldr r6, [sp, #0xb8]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811C4A0
	cmp r1, #0
	blt _0811C4A0
	ldr r0, _0811C4A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811C4A0
	ldr r0, _0811C4A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C4AC
_0811C4A0:
	movs r4, #0
	b _0811C4BA
	.align 2, 0
_0811C4A4: .4byte 0x030046A8
_0811C4A8: .4byte 0x030046AC
_0811C4AC:
	ldr r0, _0811C4D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811C4BA:
	ldr r2, [sp, #0x144]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811C4D4
	adds r0, #4
	b _0811C4E0
	.align 2, 0
_0811C4D0: .4byte 0x030046A4
_0811C4D4:
	ldr r0, _0811C4F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C4E0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811C4F8
	cmp r3, #2
	beq _0811C4FC
	b _0811C500
	.align 2, 0
_0811C4F4: .4byte 0x030046A4
_0811C4F8:
	ldrb r0, [r5, #4]
	b _0811C4FE
_0811C4FC:
	ldrb r0, [r5]
_0811C4FE:
	subs r2, r2, r0
_0811C500:
	ldr r3, [sp, #0x144]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_0811C50C:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xc0]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x118]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _0811C538 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811C616
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811C53C
	movs r0, #1
	b _0811C53E
	.align 2, 0
_0811C538: .4byte 0x00000482
_0811C53C:
	movs r0, #0
_0811C53E:
	ldr r3, _0811C628 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811C616
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811C62C @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811C630 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811C634 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811C638 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811C63C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811C640 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811C644 @ =0x030046B8
	str r5, [sp, #0x148]
_0811C584:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811C648 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811C64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811C5AA
	adds r3, #1
	cmp r3, #3
	ble _0811C584
	adds r0, r5, #0
_0811C5AA:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0xc0
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811C616:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811C726
	.align 2, 0
_0811C628: .4byte 0x00000482
_0811C62C: .4byte 0x0000054F
_0811C630: .4byte 0x0000054C
_0811C634: .4byte 0x0000054E
_0811C638: .4byte 0x00000541
_0811C63C: .4byte 0x000005BC
_0811C640: .4byte 0x00000542
_0811C644: .4byte 0x030046B8
_0811C648: .4byte 0x000003FF
_0811C64C: .4byte 0x0203B400
_0811C650:
	add r6, sp, #0x10
	ldr r0, _0811C690 @ =0x030046A4
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
	beq _0811C694
	adds r0, #4
	b _0811C6A0
	.align 2, 0
_0811C690: .4byte 0x030046A4
_0811C694:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811C6A0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811C6D4 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811C6D8
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0811C6FE
	.align 2, 0
_0811C6D4: .4byte 0x000004A4
_0811C6D8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811C6F8
	cmp r0, #2
	beq _0811C6F4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811C6F4:
	movs r0, #1
	b _0811C708
_0811C6F8:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0811C6FE:
	ldr r1, _0811C71C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811C708:
	cmp r0, #0
	bne _0811C724
	ldr r2, _0811C720 @ =0x000005C4
	adds r0, r7, r2
_0811C710:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811C726
	.align 2, 0
_0811C71C: .4byte 0xFFFFFDFF
_0811C720: .4byte 0x000005C4
_0811C724:
	movs r0, #1
_0811C726:
	cmp r0, #0
	bne _0811C792
	ldr r3, _0811C758 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811C75C
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0811C782
	.align 2, 0
_0811C758: .4byte 0x000004A4
_0811C75C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811C77C
	cmp r0, #2
	beq _0811C778
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811C778:
	movs r0, #1
	b _0811C78C
_0811C77C:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0811C782:
	ldr r1, _0811C804 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811C78C:
	cmp r0, #0
	bne _0811C792
	b _0811CF18
_0811C792:
	ldr r2, _0811C808 @ =0x00000482
	adds r1, r7, r2
	movs r4, #0
	movs r5, #0
	movs r3, #1
	movs r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x20]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0811C7B2
	adds r0, #1
	strb r0, [r1]
_0811C7B2:
	ldr r2, _0811C80C @ =FUN_080f3cdc
	movs r1, #0xa
	ldr r6, _0811C810 @ =0x0000046D
	adds r0, r7, r6
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	subs r6, #0xeb
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0811C814 @ =0x00000469
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _0811C818 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _0811C81C @ =0x00000484
	adds r0, r7, r4
	str r5, [r0]
	ldr r5, _0811C820 @ =0x0000046C
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0x10
	ldr r6, [sp, #0x114]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	b _0811CF88
	.align 2, 0
_0811C804: .4byte 0xFFFFFDFF
_0811C808: .4byte 0x00000482
_0811C80C: .4byte FUN_080f3cdc
_0811C810: .4byte 0x0000046D
_0811C814: .4byte 0x00000469
_0811C818: .4byte 0x0000046A
_0811C81C: .4byte 0x00000484
_0811C820: .4byte 0x0000046C
_0811C824:
	ldr r0, _0811C8BC @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0811C850
	ldr r1, _0811C8C0 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0811C850
	ldr r3, _0811C8C4 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0811C850:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _0811C860
	bl _0811B84A
_0811C860:
	ldr r0, _0811C8C8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x90
	ldr r5, [sp, #0x114]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r6
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
	str r3, [sp, #0x144]
	str r2, [sp, #0x110]
	cmp r5, #0
	blt _0811C8B6
	cmp r1, #0
	blt _0811C8B6
	ldr r0, _0811C8CC @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811C8B6
	ldr r0, _0811C8D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C8D4
_0811C8B6:
	movs r4, #0
	b _0811C8E2
	.align 2, 0
_0811C8BC: .4byte 0x0000048D
_0811C8C0: .4byte 0x0000048C
_0811C8C4: .4byte 0x000004BE
_0811C8C8: .4byte 0x03002BE0
_0811C8CC: .4byte 0x030046A8
_0811C8D0: .4byte 0x030046AC
_0811C8D4:
	ldr r0, _0811C8F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811C8E2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811C8F8
	adds r0, #4
	b _0811C904
	.align 2, 0
_0811C8F4: .4byte 0x030046A4
_0811C8F8:
	ldr r0, _0811C918 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C904:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811C91C
	cmp r2, #2
	beq _0811C920
	b _0811C924
	.align 2, 0
_0811C918: .4byte 0x030046A4
_0811C91C:
	ldrb r0, [r6, #4]
	b _0811C922
_0811C920:
	ldrb r0, [r6]
_0811C922:
	subs r1, r1, r0
_0811C924:
	strh r1, [r6, #2]
	ldr r0, _0811C938 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811C93C
	movs r0, #1
	b _0811C93E
	.align 2, 0
_0811C938: .4byte 0x030047A4
_0811C93C:
	movs r0, #0
_0811C93E:
	cmp r0, #0
	beq _0811C974
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0811C950
	b _0811CE94
_0811C950:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811C95C
	adds r2, r0, #0
_0811C95C:
	cmp r2, #0
	bge _0811C962
	b _0811CE94
_0811C962:
	ldr r1, _0811C970 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811C9BC
	.align 2, 0
_0811C970: .4byte 0x03002BE0
_0811C974:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811C9A0
	cmp r1, #0
	blt _0811C9A0
	ldr r0, _0811C9A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811C9A0
	ldr r0, _0811C9A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C9AC
_0811C9A0:
	movs r5, #0
	b _0811C9BA
	.align 2, 0
_0811C9A4: .4byte 0x030046A8
_0811C9A8: .4byte 0x030046AC
_0811C9AC:
	ldr r0, _0811C9FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811C9BA:
	movs r2, #0
_0811C9BC:
	ldr r4, _0811CA00 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811C9DC
	ldr r1, _0811CA04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811C9DC
	b _0811CDD8
_0811C9DC:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0xc4]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811CA08
	movs r0, #0
	b _0811CEAE
	.align 2, 0
_0811C9FC: .4byte 0x030046A4
_0811CA00: .4byte 0x00000256
_0811CA04: .4byte 0x03002BE0
_0811CA08:
	ldr r6, _0811CAAC @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x118]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	str r2, [sp, #0x120]
	cmp r0, #0
	beq _0811CAC0
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0811CAB0 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0811CAB4 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd4]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	add r0, sp, #0xc4
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0811CAB8 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0811CABC @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0xc4]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0xc8]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0xcc]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0xd0]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0xd4]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811CC94
	.align 2, 0
_0811CAAC: .4byte 0x00000222
_0811CAB0: .4byte 0x0000046D
_0811CAB4: .4byte 0x0000046B
_0811CAB8: .4byte 0x00000469
_0811CABC: .4byte 0x00000484
_0811CAC0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811CB88 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	strb r0, [r2]
	ldr r3, _0811CB8C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0xdc]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811CB90 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xe4]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xe8]
	mov r2, sl
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xec]
	strb r4, [r3]
	ldr r4, _0811CB94 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0811CB98 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _0811CB9C @ =0x00000484
	adds r3, r7, r6
	mov r1, sl
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0xf0]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xf0]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xf0]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xf4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xd8]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0xdc]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0xe0]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0xe4]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0xe8]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0xec]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	ldr r0, [sp, #0xf4]
	cmp r0, #0
	blt _0811CB82
	cmp r1, #0
	blt _0811CB82
	ldr r0, _0811CBA0 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xf4]
	cmp r2, r0
	bhs _0811CB82
	ldr r0, _0811CBA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811CBA8
_0811CB82:
	movs r4, #0
	b _0811CBB8
	.align 2, 0
_0811CB88: .4byte 0x0000046D
_0811CB8C: .4byte 0x0000046B
_0811CB90: .4byte 0x00000553
_0811CB94: .4byte 0x00000469
_0811CB98: .4byte 0x0000046A
_0811CB9C: .4byte 0x00000484
_0811CBA0: .4byte 0x030046A8
_0811CBA4: .4byte 0x030046AC
_0811CBA8:
	ldr r0, _0811CBC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xf4]
	adds r4, r0, r3
_0811CBB8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811CBCC
	adds r0, #4
	b _0811CBD8
	.align 2, 0
_0811CBC8: .4byte 0x030046A4
_0811CBCC:
	ldr r0, _0811CBEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811CBD8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811CBF0
	cmp r2, #2
	beq _0811CBF6
	b _0811CBFC
	.align 2, 0
_0811CBEC: .4byte 0x030046A4
_0811CBF0:
	ldr r4, [sp, #0xf0]
	ldrb r0, [r4, #4]
	b _0811CBFA
_0811CBF6:
	ldr r5, [sp, #0xf0]
	ldrb r0, [r5]
_0811CBFA:
	subs r1, r1, r0
_0811CBFC:
	ldr r6, [sp, #0xf0]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811CC28
	cmp r1, #0
	blt _0811CC28
	ldr r0, _0811CC2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811CC28
	ldr r0, _0811CC30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811CC34
_0811CC28:
	movs r4, #0
	b _0811CC42
	.align 2, 0
_0811CC2C: .4byte 0x030046A8
_0811CC30: .4byte 0x030046AC
_0811CC34:
	ldr r0, _0811CC58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811CC42:
	ldr r2, [sp, #0x144]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811CC5C
	adds r0, #4
	b _0811CC68
	.align 2, 0
_0811CC58: .4byte 0x030046A4
_0811CC5C:
	ldr r0, _0811CC7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811CC68:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811CC80
	cmp r3, #2
	beq _0811CC84
	b _0811CC88
	.align 2, 0
_0811CC7C: .4byte 0x030046A4
_0811CC80:
	ldrb r0, [r5, #4]
	b _0811CC86
_0811CC84:
	ldrb r0, [r5]
_0811CC86:
	subs r2, r2, r0
_0811CC88:
	ldr r3, [sp, #0x144]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_0811CC94:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xf8]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x118]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _0811CCC0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811CD9E
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811CCC4
	movs r0, #1
	b _0811CCC6
	.align 2, 0
_0811CCC0: .4byte 0x00000482
_0811CCC4:
	movs r0, #0
_0811CCC6:
	ldr r3, _0811CDB0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811CD9E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811CDB4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811CDB8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811CDBC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811CDC0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811CDC4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811CDC8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811CDCC @ =0x030046B8
	str r5, [sp, #0x148]
_0811CD0C:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811CDD0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811CDD4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811CD32
	adds r3, #1
	cmp r3, #3
	ble _0811CD0C
	adds r0, r5, #0
_0811CD32:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0xf8
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811CD9E:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811CEAE
	.align 2, 0
_0811CDB0: .4byte 0x00000482
_0811CDB4: .4byte 0x0000054F
_0811CDB8: .4byte 0x0000054C
_0811CDBC: .4byte 0x0000054E
_0811CDC0: .4byte 0x00000541
_0811CDC4: .4byte 0x000005BC
_0811CDC8: .4byte 0x00000542
_0811CDCC: .4byte 0x030046B8
_0811CDD0: .4byte 0x000003FF
_0811CDD4: .4byte 0x0203B400
_0811CDD8:
	add r6, sp, #0x18
	ldr r0, _0811CE18 @ =0x030046A4
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
	beq _0811CE1C
	adds r0, #4
	b _0811CE28
	.align 2, 0
_0811CE18: .4byte 0x030046A4
_0811CE1C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811CE28:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811CE5C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811CE60
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0811CE86
	.align 2, 0
_0811CE5C: .4byte 0x000004A4
_0811CE60:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811CE80
	cmp r0, #2
	beq _0811CE7C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811CE7C:
	movs r0, #1
	b _0811CE90
_0811CE80:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0811CE86:
	ldr r1, _0811CEA4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811CE90:
	cmp r0, #0
	bne _0811CEAC
_0811CE94:
	ldr r2, _0811CEA8 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811CEAE
	.align 2, 0
_0811CEA4: .4byte 0xFFFFFDFF
_0811CEA8: .4byte 0x000005C4
_0811CEAC:
	movs r0, #1
_0811CEAE:
	cmp r0, #0
	bne _0811CF30
	ldr r3, _0811CEE0 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811CEE4
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0811CF0A
	.align 2, 0
_0811CEE0: .4byte 0x000004A4
_0811CEE4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811CF04
	cmp r0, #2
	beq _0811CF00
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811CF00:
	movs r0, #1
	b _0811CF14
_0811CF04:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0811CF0A:
	ldr r1, _0811CF28 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811CF14:
	cmp r0, #0
	bne _0811CF30
_0811CF18:
	ldr r1, _0811CF2C @ =0x000005C4
	adds r0, r7, r1
FUN_0811cf1c:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _0811B84A
	.align 2, 0
_0811CF28: .4byte 0xFFFFFDFF
_0811CF2C: .4byte 0x000005C4
_0811CF30:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0811CF9C @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _0811CFA0 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0811CFA4 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r5, _0811CFA8 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0811CFAC @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _0811CFB0 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0811CFB4 @ =0x00000482
	adds r1, r7, r3
FUN_0811cf84:
	movs r0, #2
	strh r0, [r1]
_0811CF88:
	movs r0, #1
FUN_0811cf8a:
	add sp, #0x14c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811CF9C: .4byte 0x0000046D
_0811CFA0: .4byte 0x0000046B
_0811CFA4: .4byte 0x00000553
_0811CFA8: .4byte 0x00000469
_0811CFAC: .4byte 0x00000484
_0811CFB0: .4byte 0x0000046C
_0811CFB4: .4byte 0x00000482
