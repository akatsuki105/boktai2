	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x78
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
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
	blt _0815B920
	cmp r1, #0
	blt _0815B920
	ldr r0, _0815B924 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B920
	ldr r0, _0815B928 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815B92C
_0815B920:
	movs r4, #0
	b _0815B93A
	.align 2, 0
_0815B924: .4byte 0x030046A8
_0815B928: .4byte 0x030046AC
_0815B92C:
	ldr r0, _0815B94C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815B93A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815B950
	adds r0, #4
	b _0815B95C
	.align 2, 0
_0815B94C: .4byte 0x030046A4
_0815B950:
	ldr r0, _0815B970 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815B95C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815B974
	cmp r2, #2
	beq _0815B978
	b _0815B97C
	.align 2, 0
_0815B970: .4byte 0x030046A4
_0815B974:
	ldrb r0, [r5, #4]
	b _0815B97A
_0815B978:
	ldrb r0, [r5]
_0815B97A:
	subs r1, r1, r0
_0815B97C:
	strh r1, [r5, #2]
	ldr r0, _0815B990 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815B994
	movs r0, #1
	b _0815B996
	.align 2, 0
_0815B990: .4byte 0x030047A4
_0815B994:
	movs r0, #0
_0815B996:
	cmp r0, #0
	beq _0815B9CC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	bne _0815B9A8
	b _0815BEE8
_0815B9A8:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815B9B4
	adds r2, r0, #0
_0815B9B4:
	cmp r2, #0
	bge _0815B9BA
	b _0815BEE8
_0815B9BA:
	ldr r1, _0815B9C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815BA14
	.align 2, 0
_0815B9C8: .4byte 0x03002BE0
_0815B9CC:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815B9F8
	cmp r1, #0
	blt _0815B9F8
	ldr r0, _0815B9FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B9F8
	ldr r0, _0815BA00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815BA04
_0815B9F8:
	movs r5, #0
	b _0815BA12
	.align 2, 0
_0815B9FC: .4byte 0x030046A8
_0815BA00: .4byte 0x030046AC
_0815BA04:
	ldr r0, _0815BA54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815BA12:
	movs r2, #0
_0815BA14:
	ldr r1, _0815BA58 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815BA34
	ldr r1, _0815BA5C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815BA34
	b _0815BE30
_0815BA34:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x44]
	cmp r1, #0
	beq _0815BA60
	movs r0, #0
	b _0815BF02
	.align 2, 0
_0815BA54: .4byte 0x030046A4
_0815BA58: .4byte 0x00000256
_0815BA5C: .4byte 0x03002BE0
_0815BA60:
	ldr r4, _0815BB00 @ =0x00000222
	adds r2, r7, r4
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x2c]
	cmp r3, #0
	beq _0815BB14
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0815BB04 @ =0x0000046D
	adds r2, r2, r7
	mov ip, r2
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0815BB08 @ =0x0000046B
	adds r4, r4, r7
	mov sl, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, _0815BB0C @ =0x00000553
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x74]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r5, r7, r4
	mov r6, sb
	strh r6, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, _0815BB10 @ =0x00000469
	adds r3, r7, r6
	strb r2, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	adds r6, #0x1b
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	mov r6, ip
	str r6, [sp, #0x68]
	mov r6, sl
	str r6, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x48]
	ldr r6, [sp, #0x74]
	str r6, [sp, #0x4c]
	str r5, [sp, #0x50]
	str r4, [sp, #0x54]
	str r3, [sp, #0x58]
	str r2, [sp, #0x5c]
	str r1, [sp, #0x24]
	str r0, [sp, #0x64]
	b _0815BCE8
	.align 2, 0
_0815BB00: .4byte 0x00000222
_0815BB04: .4byte 0x0000046D
_0815BB08: .4byte 0x0000046B
_0815BB0C: .4byte 0x00000553
_0815BB10: .4byte 0x00000469
_0815BB14:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0815BBD8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r0, [r2]
	ldr r4, _0815BBDC @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r6, #0
	strb r6, [r4]
	ldr r2, _0815BBE0 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x14]
	strb r0, [r2]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov ip, r4
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sl, r6
	strh r3, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x18]
	movs r4, #0
	strb r4, [r2]
	ldr r6, _0815BBE4 @ =0x00000469
	adds r6, r6, r7
	mov r8, r6
	strb r4, [r6]
	ldr r2, _0815BBE8 @ =0x0000046A
	adds r6, r7, r2
	strb r1, [r6]
	ldr r4, _0815BBEC @ =0x00000484
	adds r5, r7, r4
	str r3, [r5]
	ldr r1, _0815BBF0 @ =0x0000046C
	adds r4, r7, r1
	strb r0, [r4]
	adds r2, #0x3e
	adds r3, r7, r2
	ldr r0, [r3]
	str r0, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r0, [sp, #0x1c]
	strh r1, [r0]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	ldr r2, [sp, #0x1c]
	strh r0, [r2, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x28]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x68]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x60]
	ldr r3, [sp, #0x14]
	str r3, [sp, #0x48]
	mov r0, ip
	str r0, [sp, #0x4c]
	mov r3, sl
	str r3, [sp, #0x50]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x54]
	mov r3, r8
	str r3, [sp, #0x58]
	str r6, [sp, #0x5c]
	str r5, [sp, #0x24]
	str r4, [sp, #0x64]
	cmp r2, #0
	blt _0815BBD4
	cmp r1, #0
	blt _0815BBD4
	ldr r0, _0815BBF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815BBD4
	ldr r0, _0815BBF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815BBFC
_0815BBD4:
	movs r4, #0
	b _0815BC0A
	.align 2, 0
_0815BBD8: .4byte 0x0000046D
_0815BBDC: .4byte 0x0000046B
_0815BBE0: .4byte 0x00000553
_0815BBE4: .4byte 0x00000469
_0815BBE8: .4byte 0x0000046A
_0815BBEC: .4byte 0x00000484
_0815BBF0: .4byte 0x0000046C
_0815BBF4: .4byte 0x030046A8
_0815BBF8: .4byte 0x030046AC
_0815BBFC:
	ldr r0, _0815BC1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815BC0A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815BC20
	adds r0, #4
	b _0815BC2C
	.align 2, 0
_0815BC1C: .4byte 0x030046A4
_0815BC20:
	ldr r0, _0815BC40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815BC2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815BC44
	cmp r2, #2
	beq _0815BC4A
	b _0815BC50
	.align 2, 0
_0815BC40: .4byte 0x030046A4
_0815BC44:
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4, #4]
	b _0815BC4E
_0815BC4A:
	ldr r6, [sp, #0x1c]
	ldrb r0, [r6]
_0815BC4E:
	subs r1, r1, r0
_0815BC50:
	ldr r0, [sp, #0x1c]
	strh r1, [r0, #2]
	ldr r1, [sp, #0x28]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815BC7C
	cmp r1, #0
	blt _0815BC7C
	ldr r0, _0815BC80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815BC7C
	ldr r0, _0815BC84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815BC88
_0815BC7C:
	movs r4, #0
	b _0815BC96
	.align 2, 0
_0815BC80: .4byte 0x030046A8
_0815BC84: .4byte 0x030046AC
_0815BC88:
	ldr r0, _0815BCAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815BC96:
	ldr r2, [sp, #0x28]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815BCB0
	adds r0, #4
	b _0815BCBC
	.align 2, 0
_0815BCAC: .4byte 0x030046A4
_0815BCB0:
	ldr r0, _0815BCD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815BCBC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815BCD4
	cmp r3, #2
	beq _0815BCD8
	b _0815BCDC
	.align 2, 0
_0815BCD0: .4byte 0x030046A4
_0815BCD4:
	ldrb r0, [r5, #4]
	b _0815BCDA
_0815BCD8:
	ldrb r0, [r5]
_0815BCDA:
	subs r2, r2, r0
_0815BCDC:
	ldr r3, [sp, #0x28]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_0815BCE8:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x70]
	cmp r0, #0
	bne _0815BDF2
	movs r1, #4
	ldr r2, [sp, #0x2c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815BD12
	movs r0, #1
	b _0815BD14
_0815BD12:
	movs r0, #0
_0815BD14:
	ldr r3, _0815BE04 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x70]
	cmp r0, #0
	bne _0815BDF2
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0815BE08 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0815BE0C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x38]
	ldr r2, _0815BE10 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	ldr r4, _0815BE14 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x40]
	ldr r6, _0815BE18 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r0, _0815BE1C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _0815BE20 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r6, _0815BE24 @ =0x0203B400
	ldr r1, _0815BE28 @ =0x030046B8
	ldr r5, _0815BE2C @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0815BD64:
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
	bne _0815BD82
	adds r3, #1
	cmp r3, #3
	ble _0815BD64
	mov r0, sb
_0815BD82:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldrb r0, [r4]
	ldr r6, [sp, #0x38]
	strb r0, [r6]
	ldr r1, [sp, #0x58]
	ldrb r0, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [sp, #0x5c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x40]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x30]
	strb r1, [r0]
	ldr r1, [sp, #0x6c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x68]
	strb r1, [r4]
	ldr r6, [sp, #0x60]
	strb r3, [r6]
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r6, [sp, #0x4c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x50]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r6, [sp, #0x58]
	strb r1, [r6]
	ldr r0, [sp, #0x5c]
	strb r2, [r0]
	ldr r2, [sp, #0x24]
	str r3, [r2]
	ldr r3, [sp, #0x64]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x34]
	strb r0, [r4]
_0815BDF2:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r6, [sp, #0x70]
	strh r0, [r6]
	movs r0, #0
	b _0815BF02
	.align 2, 0
_0815BE04: .4byte 0x00000482
_0815BE08: .4byte 0x0000054F
_0815BE0C: .4byte 0x0000054C
_0815BE10: .4byte 0x0000054D
_0815BE14: .4byte 0x0000054E
_0815BE18: .4byte 0x00000541
_0815BE1C: .4byte 0x000005BC
_0815BE20: .4byte 0x00000542
_0815BE24: .4byte 0x0203B400
_0815BE28: .4byte 0x030046B8
_0815BE2C: .4byte 0x000003FF
_0815BE30:
	mov sb, sp
	ldr r6, _0815BE6C @ =0x030046A4
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
	beq _0815BE70
	adds r0, #4
	b _0815BE7A
	.align 2, 0
_0815BE6C: .4byte 0x030046A4
_0815BE70:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815BE7A:
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
	ldr r1, _0815BEB0 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815BEB4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0815BEDA
	.align 2, 0
_0815BEB0: .4byte 0x000004A4
_0815BEB4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815BED4
	cmp r0, #2
	beq _0815BED0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815BED0:
	movs r0, #1
	b _0815BEE4
_0815BED4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0815BEDA:
	ldr r1, _0815BEF8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815BEE4:
	cmp r0, #0
	bne _0815BF00
_0815BEE8:
	ldr r4, _0815BEFC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0815BF02
	.align 2, 0
_0815BEF8: .4byte 0xFFFFFDFF
_0815BEFC: .4byte 0x000005C4
_0815BF00:
	movs r0, #1
_0815BF02:
	cmp r0, #0
	beq _0815BF3E
	ldr r6, [sp, #8]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r6, r0
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0815BF50 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0815BF54 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r6, _0815BF58 @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r0, _0815BF5C @ =0x0000046C
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_0815BF3E:
	add sp, #0x78
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815BF50: .4byte 0x00000469
_0815BF54: .4byte 0x0000046A
_0815BF58: .4byte 0x00000484
_0815BF5C: .4byte 0x0000046C
