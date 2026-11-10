	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xbc
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r4, _0814EB08 @ =0x00008002
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r7, r2
	ldrh r2, [r3]
	ands r4, r2
	cmp r4, #0
	beq _0814EB0C
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r3]
_0814EB02:
	movs r0, #0
	bl FUN_0814fb76
	.align 2, 0
_0814EB08: .4byte 0x00008002
_0814EB0C:
	ldr r5, _0814EB8C @ =0x0000049C
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0814EBA4
	ldr r1, _0814EB90 @ =0x000005CC
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _0814EB94 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	subs r5, #0x31
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
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
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0814EB98 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _0814EB9C @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _0814EBA0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r4, #0xd5
	lsls r4, r4, #3
	adds r2, r6, r4
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl _0814FB74
	.align 2, 0
_0814EB8C: .4byte 0x0000049C
_0814EB90: .4byte 0x000005CC
_0814EB94: .4byte 0x0000046D
_0814EB98: .4byte 0x00000469
_0814EB9C: .4byte 0x0000046C
_0814EBA0: .4byte 0xFEFFFFFF
_0814EBA4:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	strh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0814EB02
	ldr r5, _0814EC7C @ =0x000004BE
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0814EB02
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0814EBCC
	bl _0814F410
_0814EBCC:
	ldr r0, _0814EC80 @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0814EBF8
	ldr r1, _0814EC84 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0814EBF8
	ldr r3, _0814EC7C @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0814EBF8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r3, r7, r4
	ldr r0, [r3]
	cmp r0, #0
	bne _0814EC06
	b _0814EB02
_0814EC06:
	movs r2, #0x80
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r1, _0814EC88 @ =0x00000222
	adds r4, r7, r1
	ldrh r1, [r4]
	movs r5, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _0814EC8C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r3]
	adds r0, r7, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	str r4, [sp, #0xb0]
	cmp r0, #0
	bne _0814EC3A
	b _0814F344
_0814EC3A:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
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
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r4, #0
	blt _0814EC76
	cmp r1, #0
	blt _0814EC76
	ldr r0, _0814EC90 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814EC76
	ldr r0, _0814EC94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814EC98
_0814EC76:
	movs r4, #0
	b _0814ECA6
	.align 2, 0
_0814EC7C: .4byte 0x000004BE
_0814EC80: .4byte 0x0000048D
_0814EC84: .4byte 0x0000048C
_0814EC88: .4byte 0x00000222
_0814EC8C: .4byte 0x03002BE0
_0814EC90: .4byte 0x030046A8
_0814EC94: .4byte 0x030046AC
_0814EC98:
	ldr r0, _0814ECB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814ECA6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814ECBC
	adds r0, #4
	b _0814ECC8
	.align 2, 0
_0814ECB8: .4byte 0x030046A4
_0814ECBC:
	ldr r0, _0814ECDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814ECC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814ECE0
	cmp r2, #2
	beq _0814ECE4
	b _0814ECE8
	.align 2, 0
_0814ECDC: .4byte 0x030046A4
_0814ECE0:
	ldrb r0, [r5, #4]
	b _0814ECE6
_0814ECE4:
	ldrb r0, [r5]
_0814ECE6:
	subs r1, r1, r0
_0814ECE8:
	strh r1, [r5, #2]
	ldr r0, _0814ECFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814ED00
	movs r0, #1
	b _0814ED02
	.align 2, 0
_0814ECFC: .4byte 0x030047A4
_0814ED00:
	movs r0, #0
_0814ED02:
	cmp r0, #0
	beq _0814ED40
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _0814ED22
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814ED1E
	adds r2, r0, #0
_0814ED1E:
	cmp r2, #0
	bge _0814ED2C
_0814ED22:
	ldr r4, _0814ED28 @ =0x000005C4
	adds r0, r7, r4
	b _0814F24C
	.align 2, 0
_0814ED28: .4byte 0x000005C4
_0814ED2C:
	ldr r1, _0814ED3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814ED88
	.align 2, 0
_0814ED3C: .4byte 0x03002BE0
_0814ED40:
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
	blt _0814ED6C
	cmp r1, #0
	blt _0814ED6C
	ldr r0, _0814ED70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814ED6C
	ldr r0, _0814ED74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814ED78
_0814ED6C:
	movs r5, #0
	b _0814ED86
	.align 2, 0
_0814ED70: .4byte 0x030046A8
_0814ED74: .4byte 0x030046AC
_0814ED78:
	ldr r0, _0814EDC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814ED86:
	movs r2, #0
_0814ED88:
	ldr r6, _0814EDCC @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814EDA8
	ldr r1, _0814EDD0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814EDA8
	b _0814F190
_0814EDA8:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _0814EDD4
	movs r0, #0
	b _0814F262
	.align 2, 0
_0814EDC8: .4byte 0x030046A4
_0814EDCC: .4byte 0x00000256
_0814EDD0: .4byte 0x03002BE0
_0814EDD4:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r2, [sp, #0xb0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0814EE80
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0814EE70 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x10]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0814EE74 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x14]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov r8, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0814EE78 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0814EE7C @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0xac]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0814F04E
	.align 2, 0
_0814EE70: .4byte 0x0000046D
_0814EE74: .4byte 0x0000046B
_0814EE78: .4byte 0x00000469
_0814EE7C: .4byte 0x00000484
_0814EE80:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0814EF40 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _0814EF44 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0814EF48 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x28]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x30]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0814EF4C @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0814EF50 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0814EF54 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x34]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x34]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, ip
	cmp r0, #0
	blt _0814EF3C
	cmp r1, #0
	blt _0814EF3C
	ldr r0, _0814EF58 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0814EF3C
	ldr r0, _0814EF5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814EF60
_0814EF3C:
	movs r4, #0
	b _0814EF70
	.align 2, 0
_0814EF40: .4byte 0x0000046D
_0814EF44: .4byte 0x0000046B
_0814EF48: .4byte 0x00000553
_0814EF4C: .4byte 0x00000469
_0814EF50: .4byte 0x0000046A
_0814EF54: .4byte 0x00000484
_0814EF58: .4byte 0x030046A8
_0814EF5C: .4byte 0x030046AC
_0814EF60:
	ldr r0, _0814EF80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0814EF70:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814EF84
	adds r0, #4
	b _0814EF90
	.align 2, 0
_0814EF80: .4byte 0x030046A4
_0814EF84:
	ldr r0, _0814EFA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814EF90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814EFA8
	cmp r2, #2
	beq _0814EFAE
	b _0814EFB4
	.align 2, 0
_0814EFA4: .4byte 0x030046A4
_0814EFA8:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _0814EFB2
_0814EFAE:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_0814EFB2:
	subs r1, r1, r0
_0814EFB4:
	ldr r4, [sp, #0x34]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814EFE0
	cmp r1, #0
	blt _0814EFE0
	ldr r0, _0814EFE4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814EFE0
	ldr r0, _0814EFE8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814EFEC
_0814EFE0:
	movs r4, #0
	b _0814EFFA
	.align 2, 0
_0814EFE4: .4byte 0x030046A8
_0814EFE8: .4byte 0x030046AC
_0814EFEC:
	ldr r0, _0814F010 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814EFFA:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814F014
	adds r0, #4
	b _0814F020
	.align 2, 0
_0814F010: .4byte 0x030046A4
_0814F014:
	ldr r0, _0814F034 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F020:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814F038
	cmp r3, #2
	beq _0814F03C
	b _0814F040
	.align 2, 0
_0814F034: .4byte 0x030046A4
_0814F038:
	ldrb r0, [r5, #4]
	b _0814F03E
_0814F03C:
	ldrb r0, [r5]
_0814F03E:
	subs r2, r2, r0
_0814F040:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814F04E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814F078 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0814F158
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814F07C
	movs r0, #1
	b _0814F07E
	.align 2, 0
_0814F078: .4byte 0x00000482
_0814F07C:
	movs r0, #0
_0814F07E:
	ldr r1, _0814F168 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0814F158
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0814F16C @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814F170 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814F174 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814F178 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _0814F17C @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0814F180 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814F184 @ =0x030046B8
	adds r2, r4, #0
_0814F0C6:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814F188 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814F18C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814F0EA
	adds r3, #1
	cmp r3, #3
	ble _0814F0C6
	adds r0, r4, #0
_0814F0EA:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x38
	ldrb r1, [r0]
	ldr r0, [sp, #0xa0]
	strb r1, [r0]
	mov r1, ip
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814F158:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0814F262
	.align 2, 0
_0814F168: .4byte 0x00000482
_0814F16C: .4byte 0x0000054F
_0814F170: .4byte 0x0000054C
_0814F174: .4byte 0x0000054E
_0814F178: .4byte 0x00000541
_0814F17C: .4byte 0x000005BC
_0814F180: .4byte 0x00000542
_0814F184: .4byte 0x030046B8
_0814F188: .4byte 0x000003FF
_0814F18C: .4byte 0x0203B400
_0814F190:
	mov sb, sp
	ldr r6, _0814F1CC @ =0x030046A4
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
	beq _0814F1D0
	adds r0, #4
	b _0814F1DA
	.align 2, 0
_0814F1CC: .4byte 0x030046A4
_0814F1D0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814F1DA:
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
	ldr r6, _0814F210 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0814F214
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0814F23A
	.align 2, 0
_0814F210: .4byte 0x000004A4
_0814F214:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814F234
	cmp r0, #2
	beq _0814F230
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814F230:
	movs r0, #1
	b _0814F244
_0814F234:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0814F23A:
	ldr r1, _0814F258 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814F244:
	cmp r0, #0
	bne _0814F260
	ldr r3, _0814F25C @ =0x000005C4
	adds r0, r7, r3
_0814F24C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814F262
	.align 2, 0
_0814F258: .4byte 0xFFFFFDFF
_0814F25C: .4byte 0x000005C4
_0814F260:
	movs r0, #1
_0814F262:
	cmp r0, #0
	bne _0814F2DC
	ldr r4, _0814F294 @ =0x000004A4
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
	bne _0814F298
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0814F2BE
	.align 2, 0
_0814F294: .4byte 0x000004A4
_0814F298:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814F2B8
	cmp r0, #2
	beq _0814F2B4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814F2B4:
	movs r0, #1
	b _0814F2C8
_0814F2B8:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0814F2BE:
	ldr r1, _0814F2D4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814F2C8:
	cmp r0, #0
	bne _0814F2DC
	ldr r4, _0814F2D8 @ =0x000005C4
	adds r0, r7, r4
	bl FUN_0814fb08
	.align 2, 0
_0814F2D4: .4byte 0xFFFFFDFF
_0814F2D8: .4byte 0x000005C4
_0814F2DC:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0814F334 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0814F338 @ =0x0000046B
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
	ldr r1, _0814F33C @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0814F340 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _0814FB74
	.align 2, 0
_0814F334: .4byte 0x0000046D
_0814F338: .4byte 0x0000046B
_0814F33C: .4byte 0x0000046A
_0814F340: .4byte 0x00000484
_0814F344:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _0814F354
	bl _0814FB74
_0814F354:
	ldr r2, _0814F3BC @ =Enemy_ClearStateBegun
	mov r8, r2
	movs r1, #0x10
	ldr r3, _0814F3C0 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r2, _0814F3C4 @ =0x0000046B
	adds r0, r7, r2
	strb r5, [r0]
	adds r2, #0xe8
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r7, r2
	strb r5, [r0]
	ldr r5, _0814F3C8 @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0814F3CC @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xa0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0814F3D0
	asrs r0, r1, #5
	b _0814F3D6
	.align 2, 0
_0814F3BC: .4byte Enemy_ClearStateBegun
_0814F3C0: .4byte 0x0000046D
_0814F3C4: .4byte 0x0000046B
_0814F3C8: .4byte 0x0000046A
_0814F3CC: .4byte 0x00000484
_0814F3D0:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0814F3D6:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	ldrb r1, [r7, #5]
	adds r0, r1, #0
	adds r0, #0xa0
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7, #5]
	movs r5, #0xdb
	lsls r5, r5, #3
	adds r2, r6, r5
	movs r0, #0x5a
	strb r0, [r2]
	adds r0, r7, #0
	bl Dog_PickWalkDest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814F40C
	b _0814FB74
_0814F40C:
	bl _0814EB02

_0814F410:
	ldr r6, _0814F4AC @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _0814F43C
	ldr r1, _0814F4B0 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0814F43C
	ldr r3, _0814F4B4 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0814F43C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _0814F44C
	bl _0814EB02
_0814F44C:
	ldr r0, _0814F4B8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
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
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r6
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
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r4, #0
	blt _0814F4A6
	cmp r1, #0
	blt _0814F4A6
	ldr r0, _0814F4BC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814F4A6
	ldr r0, _0814F4C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F4C4
_0814F4A6:
	movs r4, #0
	b _0814F4D2
	.align 2, 0
_0814F4AC: .4byte 0x0000048D
_0814F4B0: .4byte 0x0000048C
_0814F4B4: .4byte 0x000004BE
_0814F4B8: .4byte 0x03002BE0
_0814F4BC: .4byte 0x030046A8
_0814F4C0: .4byte 0x030046AC
_0814F4C4:
	ldr r0, _0814F4E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814F4D2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814F4E8
	adds r0, #4
	b _0814F4F4
	.align 2, 0
_0814F4E4: .4byte 0x030046A4
_0814F4E8:
	ldr r0, _0814F508 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F4F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814F50C
	cmp r2, #2
	beq _0814F510
	b _0814F514
	.align 2, 0
_0814F508: .4byte 0x030046A4
_0814F50C:
	ldrb r0, [r5, #4]
	b _0814F512
_0814F510:
	ldrb r0, [r5]
_0814F512:
	subs r1, r1, r0
_0814F514:
	strh r1, [r5, #2]
	ldr r0, _0814F528 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814F52C
	movs r0, #1
	b _0814F52E
	.align 2, 0
_0814F528: .4byte 0x030047A4
_0814F52C:
	movs r0, #0
_0814F52E:
	cmp r0, #0
	beq _0814F564
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0814F540
	b _0814FA80
_0814F540:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814F54C
	adds r2, r0, #0
_0814F54C:
	cmp r2, #0
	bge _0814F552
	b _0814FA80
_0814F552:
	ldr r1, _0814F560 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814F5AC
	.align 2, 0
_0814F560: .4byte 0x03002BE0
_0814F564:
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
	blt _0814F590
	cmp r1, #0
	blt _0814F590
	ldr r0, _0814F594 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814F590
	ldr r0, _0814F598 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F59C
_0814F590:
	movs r5, #0
	b _0814F5AA
	.align 2, 0
_0814F594: .4byte 0x030046A8
_0814F598: .4byte 0x030046AC
_0814F59C:
	ldr r0, _0814F5EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814F5AA:
	movs r2, #0
_0814F5AC:
	ldr r4, _0814F5F0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814F5CC
	ldr r1, _0814F5F4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814F5CC
	b _0814F9C4
_0814F5CC:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x3c]
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _0814F5F8
	movs r0, #0
	b _0814FA9A
	.align 2, 0
_0814F5EC: .4byte 0x030046A4
_0814F5F0: .4byte 0x00000256
_0814F5F4: .4byte 0x03002BE0
_0814F5F8:
	ldr r6, _0814F69C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb0]
	cmp r6, #0
	beq _0814F6B0
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0814F6A0 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x40]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0814F6A4 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x48]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x3c]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0814F6A8 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0814F6AC @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x3c]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0xac]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb4]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0814F882
	.align 2, 0
_0814F69C: .4byte 0x00000222
_0814F6A0: .4byte 0x0000046D
_0814F6A4: .4byte 0x0000046B
_0814F6A8: .4byte 0x00000469
_0814F6AC: .4byte 0x00000484
_0814F6B0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0814F774 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _0814F778 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0814F77C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0814F780 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0814F784 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0814F788 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x68]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x68]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x68]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, sl
	cmp r0, #0
	blt _0814F76E
	cmp r1, #0
	blt _0814F76E
	ldr r0, _0814F78C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0814F76E
	ldr r0, _0814F790 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F794
_0814F76E:
	movs r4, #0
	b _0814F7A4
	.align 2, 0
_0814F774: .4byte 0x0000046D
_0814F778: .4byte 0x0000046B
_0814F77C: .4byte 0x00000553
_0814F780: .4byte 0x00000469
_0814F784: .4byte 0x00000484
_0814F788: .4byte 0x0000046C
_0814F78C: .4byte 0x030046A8
_0814F790: .4byte 0x030046AC
_0814F794:
	ldr r0, _0814F7B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0814F7A4:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814F7B8
	adds r0, #4
	b _0814F7C4
	.align 2, 0
_0814F7B4: .4byte 0x030046A4
_0814F7B8:
	ldr r0, _0814F7D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F7C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814F7DC
	cmp r2, #2
	beq _0814F7E2
	b _0814F7E8
	.align 2, 0
_0814F7D8: .4byte 0x030046A4
_0814F7DC:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _0814F7E6
_0814F7E2:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_0814F7E6:
	subs r1, r1, r0
_0814F7E8:
	ldr r4, [sp, #0x68]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814F814
	cmp r1, #0
	blt _0814F814
	ldr r0, _0814F818 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814F814
	ldr r0, _0814F81C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F820
_0814F814:
	movs r4, #0
	b _0814F82E
	.align 2, 0
_0814F818: .4byte 0x030046A8
_0814F81C: .4byte 0x030046AC
_0814F820:
	ldr r0, _0814F844 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814F82E:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814F848
	adds r0, #4
	b _0814F854
	.align 2, 0
_0814F844: .4byte 0x030046A4
_0814F848:
	ldr r0, _0814F868 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F854:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814F86C
	cmp r3, #2
	beq _0814F870
	b _0814F874
	.align 2, 0
_0814F868: .4byte 0x030046A4
_0814F86C:
	ldrb r0, [r5, #4]
	b _0814F872
_0814F870:
	ldrb r0, [r5]
_0814F872:
	subs r2, r2, r0
_0814F874:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814F882:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814F8AC @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0814F98C
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814F8B0
	movs r0, #1
	b _0814F8B2
	.align 2, 0
_0814F8AC: .4byte 0x00000482
_0814F8B0:
	movs r0, #0
_0814F8B2:
	ldr r1, _0814F99C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0814F98C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0814F9A0 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814F9A4 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814F9A8 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814F9AC @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _0814F9B0 @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0814F9B4 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814F9B8 @ =0x030046B8
	adds r2, r4, #0
_0814F8FA:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814F9BC @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814F9C0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814F91E
	adds r3, #1
	cmp r3, #3
	ble _0814F8FA
	adds r0, r4, #0
_0814F91E:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x6c
	ldrb r1, [r0]
	ldr r0, [sp, #0xa0]
	strb r1, [r0]
	mov r1, ip
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814F98C:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0814FA9A
	.align 2, 0
_0814F99C: .4byte 0x00000482
_0814F9A0: .4byte 0x0000054F
_0814F9A4: .4byte 0x0000054C
_0814F9A8: .4byte 0x0000054E
_0814F9AC: .4byte 0x00000541
_0814F9B0: .4byte 0x000005BC
_0814F9B4: .4byte 0x00000542
_0814F9B8: .4byte 0x030046B8
_0814F9BC: .4byte 0x000003FF
_0814F9C0: .4byte 0x0203B400
_0814F9C4:
	add r6, sp, #8
	ldr r0, _0814FA04 @ =0x030046A4
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
	beq _0814FA08
	adds r0, #4
	b _0814FA14
	.align 2, 0
_0814FA04: .4byte 0x030046A4
_0814FA08:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814FA14:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0814FA48 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0814FA4C
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0814FA72
	.align 2, 0
_0814FA48: .4byte 0x000004A4
_0814FA4C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814FA6C
	cmp r0, #2
	beq _0814FA68
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814FA68:
	movs r0, #1
	b _0814FA7C
_0814FA6C:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0814FA72:
	ldr r1, _0814FA90 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814FA7C:
	cmp r0, #0
	bne _0814FA98
_0814FA80:
	ldr r2, _0814FA94 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814FA9A
	.align 2, 0
_0814FA90: .4byte 0xFFFFFDFF
_0814FA94: .4byte 0x000005C4
_0814FA98:
	movs r0, #1
_0814FA9A:
	cmp r0, #0
	bne _0814FB1C
	ldr r3, _0814FACC @ =0x000004A4
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
	bne _0814FAD0
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0814FAF6
	.align 2, 0
_0814FACC: .4byte 0x000004A4
_0814FAD0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814FAF0
	cmp r0, #2
	beq _0814FAEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814FAEC:
	movs r0, #1
	b _0814FB00
_0814FAF0:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0814FAF6:
	ldr r1, _0814FB14 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814FB00:
	cmp r0, #0
	bne _0814FB1C
	ldr r1, _0814FB18 @ =0x000005C4
	adds r0, r7, r1
FUN_0814fb08:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _0814EB02
	.align 2, 0
_0814FB14: .4byte 0xFFFFFDFF
_0814FB18: .4byte 0x000005C4
_0814FB1C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0814FB88 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _0814FB8C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0814FB90 @ =0x00000553
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
	ldr r5, _0814FB94 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0814FB98 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _0814FB9C @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0814FBA0 @ =0x00000482
	adds r1, r7, r3
	movs r0, #4
	strh r0, [r1]
_0814FB74:
	movs r0, #1
FUN_0814fb76:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814FB88: .4byte 0x0000046D
_0814FB8C: .4byte 0x0000046B
_0814FB90: .4byte 0x00000553
_0814FB94: .4byte 0x00000469
_0814FB98: .4byte 0x00000484
_0814FB9C: .4byte 0x0000046C
_0814FBA0: .4byte 0x00000482
