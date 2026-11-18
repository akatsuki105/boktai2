	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	adds r7, r0, #0
	ldr r0, _081CBAC8 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CBACC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CBACE
	.align 2, 0
_081CBAC8: .4byte 0x0000046C
_081CBACC:
	movs r0, #0
_081CBACE:
	cmp r0, #0
	beq _081CBB1C
	ldr r1, _081CBC54 @ =0x000005A4
	adds r0, r7, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _081CBC58 @ =0x0000046D
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	ldr r5, _081CBC5C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081CBC60 @ =0x00000553
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _081CBC64 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081CBB1C:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _081CBB36
	b _081CC194
_081CBB36:
	ldr r0, _081CBC68 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0x14
	bgt _081CBB42
	b _081CC190
_081CBB42:
	ldr r1, _081CBC6C @ =0x00000222
	adds r1, r7, r1
	str r1, [sp, #8]
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r1]
	ands r0, r1
	movs r4, #0
	ldr r2, [sp, #8]
	strh r0, [r2]
	ldr r1, _081CBC70 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r3, _081CBC58 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	movs r5, #1
	strb r5, [r3]
	ldr r6, _081CBC5C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x10]
	strb r4, [r6]
	ldr r2, _081CBC60 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x14]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18]
	str r1, [r3]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x1c]
	mov r0, r8
	strh r0, [r6]
	ldr r1, _081CBC74 @ =0x00000543
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r6, #0xc
	mov sb, r6
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r6, _081CBC78 @ =0x00000554
	adds r0, r7, r6
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081CBC7C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081CBC80 @ =0x00000552
	adds r0, r7, r3
	mov r6, sb
	strb r6, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r1, r7
	mov ip, r1
	strb r0, [r1]
	subs r2, #0xe8
	adds r2, r2, r7
	mov sl, r2
	strb r5, [r2]
	subs r3, #0xe8
	adds r3, r3, r7
	mov sb, r3
	strb r4, [r3]
	ldr r4, _081CBC68 @ =0x00000484
	adds r6, r7, r4
	mov r0, r8
	str r0, [r6]
	ldr r1, _081CBC84 @ =0x0000046C
	adds r3, r7, r1
	strb r5, [r3]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r5, [r4]
	str r5, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x5c]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x60]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x58]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x18]
	str r3, [sp, #0x44]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x6c]
	ldr r3, [sp, #8]
	str r3, [sp, #0x28]
	mov r0, ip
	str r0, [sp, #0x4c]
	mov r3, sl
	str r3, [sp, #0x50]
	mov r0, sb
	str r0, [sp, #0x54]
	str r6, [sp, #0x68]
	adds r6, r4, #0
	mov r8, r2
	cmp r5, #0
	blt _081CBC4E
	cmp r1, #0
	blt _081CBC4E
	ldr r0, _081CBC88 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081CBC4E
	ldr r0, _081CBC8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBC90
_081CBC4E:
	movs r5, #0
	b _081CBC9E
	.align 2, 0
_081CBC54: .4byte 0x000005A4
_081CBC58: .4byte 0x0000046D
_081CBC5C: .4byte 0x0000046B
_081CBC60: .4byte 0x00000553
_081CBC64: .4byte 0xFFFFFDFF
_081CBC68: .4byte 0x00000484
_081CBC6C: .4byte 0x00000222
_081CBC70: .4byte Enemy_WaitPendingState
_081CBC74: .4byte 0x00000543
_081CBC78: .4byte 0x00000554
_081CBC7C: .4byte 0x00000551
_081CBC80: .4byte 0x00000552
_081CBC84: .4byte 0x0000046C
_081CBC88: .4byte 0x030046A8
_081CBC8C: .4byte 0x030046AC
_081CBC90:
	ldr r0, _081CBCB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_081CBC9E:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CBCB4
	adds r0, #4
	b _081CBCC0
	.align 2, 0
_081CBCB0: .4byte 0x030046A4
_081CBCB4:
	ldr r0, _081CBCD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CBCC0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CBCD8
	cmp r2, #2
	beq _081CBCDE
	b _081CBCE4
	.align 2, 0
_081CBCD4: .4byte 0x030046A4
_081CBCD8:
	ldr r2, [sp, #0x20]
	ldrb r0, [r2, #4]
	b _081CBCE2
_081CBCDE:
	ldr r3, [sp, #0x20]
	ldrb r0, [r3]
_081CBCE2:
	subs r1, r1, r0
_081CBCE4:
	ldr r4, [sp, #0x20]
	strh r1, [r4, #2]
	ldr r0, _081CBCFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CBD00
	movs r0, #1
	b _081CBD02
	.align 2, 0
_081CBCFC: .4byte 0x030047A4
_081CBD00:
	movs r0, #0
_081CBD02:
	cmp r0, #0
	beq _081CBD40
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081CBD22
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CBD1E
	adds r2, r0, #0
_081CBD1E:
	cmp r2, #0
	bge _081CBD2C
_081CBD22:
	ldr r6, _081CBD28 @ =0x000005C4
	adds r0, r7, r6
	b _081CC17C
	.align 2, 0
_081CBD28: .4byte 0x000005C4
_081CBD2C:
	ldr r1, _081CBD3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CBD88
	.align 2, 0
_081CBD3C: .4byte 0x03002BE0
_081CBD40:
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
	blt _081CBD6C
	cmp r1, #0
	blt _081CBD6C
	ldr r0, _081CBD70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CBD6C
	ldr r0, _081CBD74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBD78
_081CBD6C:
	movs r5, #0
	b _081CBD86
	.align 2, 0
_081CBD70: .4byte 0x030046A8
_081CBD74: .4byte 0x030046AC
_081CBD78:
	ldr r0, _081CBE1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CBD86:
	movs r2, #0
_081CBD88:
	ldr r3, _081CBE20 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CBDA8
	ldr r1, _081CBE24 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CBDA8
	b _081CC0C0
_081CBDA8:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081CBDC2
	b _081CC194
_081CBDC2:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x28]
	ldrh r1, [r5]
	ands r0, r1
	movs r5, #0
	ldr r1, [sp, #0x28]
	strh r0, [r1]
	movs r1, #0x80
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081CBE28
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r6, [sp, #0x60]
	strb r2, [r6]
	ldr r4, [sp, #0x58]
	strb r5, [r4]
	ldr r6, [sp, #0x40]
	strb r0, [r6]
	ldr r0, [sp, #0x44]
	str r1, [r0]
	ldr r1, [sp, #0x6c]
	strh r3, [r1]
	movs r0, #0xc
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r6, [sp, #0x50]
	strb r5, [r6]
	ldr r1, [sp, #0x54]
	strb r0, [r1]
	ldr r4, [sp, #0x68]
	str r3, [r4]
	ldr r5, [sp, #0x5c]
	strb r2, [r5]
	b _081CBF76
	.align 2, 0
_081CBE1C: .4byte 0x030046A4
_081CBE20: .4byte 0x00000256
_081CBE24: .4byte 0x03002BE0
_081CBE28:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r4, [sp, #0x58]
	strb r5, [r4]
	ldr r3, [sp, #0x40]
	strb r0, [r3]
	ldr r4, [sp, #0x44]
	str r1, [r4]
	ldr r1, [sp, #0x6c]
	strh r2, [r1]
	movs r1, #5
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r4, [sp, #0x50]
	strb r5, [r4]
	ldr r5, [sp, #0x54]
	strb r1, [r5]
	ldr r1, [sp, #0x68]
	str r2, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r4]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CBE8C
	cmp r1, #0
	blt _081CBE8C
	ldr r0, _081CBE90 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CBE8C
	ldr r0, _081CBE94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBE98
_081CBE8C:
	movs r5, #0
	b _081CBEA6
	.align 2, 0
_081CBE90: .4byte 0x030046A8
_081CBE94: .4byte 0x030046AC
_081CBE98:
	ldr r0, _081CBEB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CBEA6:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CBEBC
	adds r0, #4
	b _081CBEC8
	.align 2, 0
_081CBEB8: .4byte 0x030046A4
_081CBEBC:
	ldr r0, _081CBEDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CBEC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CBEE0
	cmp r2, #2
	beq _081CBEE4
	b _081CBEE8
	.align 2, 0
_081CBEDC: .4byte 0x030046A4
_081CBEE0:
	ldrb r0, [r4, #4]
	b _081CBEE6
_081CBEE4:
	ldrb r0, [r4]
_081CBEE6:
	subs r1, r1, r0
_081CBEE8:
	strh r1, [r4, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CBF10
	cmp r1, #0
	blt _081CBF10
	ldr r0, _081CBF14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CBF10
	ldr r0, _081CBF18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBF1C
_081CBF10:
	movs r5, #0
	b _081CBF2A
	.align 2, 0
_081CBF14: .4byte 0x030046A8
_081CBF18: .4byte 0x030046AC
_081CBF1C:
	ldr r0, _081CBF3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CBF2A:
	ldr r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CBF40
	adds r0, #4
	b _081CBF4C
	.align 2, 0
_081CBF3C: .4byte 0x030046A4
_081CBF40:
	ldr r0, _081CBF60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CBF4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CBF64
	cmp r3, #2
	beq _081CBF68
	b _081CBF6C
	.align 2, 0
_081CBF60: .4byte 0x030046A4
_081CBF64:
	ldrb r0, [r4, #4]
	b _081CBF6A
_081CBF68:
	ldrb r0, [r4]
_081CBF6A:
	subs r2, r2, r0
_081CBF6C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081CBF76:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sb
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081CBFA0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x64]
	cmp r0, #0
	bne _081CC084
	movs r1, #4
	ldr r2, [sp, #0x28]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CBFA4
	movs r0, #1
	b _081CBFA6
	.align 2, 0
_081CBFA0: .4byte 0x00000482
_081CBFA4:
	movs r0, #0
_081CBFA6:
	ldr r3, _081CC094 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x64]
	cmp r0, #0
	bne _081CC084
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081CC098 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081CC09C @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x34]
	ldr r1, _081CC0A0 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x38]
	ldr r2, _081CC0A4 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	ldr r4, _081CC0A8 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	ldr r5, _081CC0AC @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _081CC0B0 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r6, _081CC0B4 @ =0x0203B400
	ldr r1, _081CC0B8 @ =0x030046B8
	ldr r2, _081CC0BC @ =0x000003FF
	movs r5, #3
	mov r4, r8
_081CBFF6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _081CC014
	adds r3, #1
	cmp r3, #3
	ble _081CBFF6
	mov r0, r8
_081CC014:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x40]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x34]
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	ldr r5, [sp, #0x38]
	strb r0, [r5]
	ldr r6, [sp, #0x54]
	ldrb r0, [r6]
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x2c]
	strb r4, [r2]
	ldr r4, [sp, #0x48]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x60]
	strb r1, [r5]
	ldr r6, [sp, #0x58]
	strb r3, [r6]
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x6c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x4c]
	strb r0, [r4]
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r6, [sp, #0x54]
	strb r2, [r6]
	ldr r0, [sp, #0x68]
	str r3, [r0]
	ldr r2, [sp, #0x5c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x30]
	strb r0, [r3]
_081CC084:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x64]
	strh r0, [r4]
	b _081CC194
	.align 2, 0
_081CC094: .4byte 0x00000482
_081CC098: .4byte 0x0000054F
_081CC09C: .4byte 0x0000054C
_081CC0A0: .4byte 0x0000054D
_081CC0A4: .4byte 0x0000054E
_081CC0A8: .4byte 0x00000541
_081CC0AC: .4byte 0x000005BC
_081CC0B0: .4byte 0x00000542
_081CC0B4: .4byte 0x0203B400
_081CC0B8: .4byte 0x030046B8
_081CC0BC: .4byte 0x000003FF
_081CC0C0:
	mov sb, sp
	ldr r6, _081CC0FC @ =0x030046A4
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
	beq _081CC100
	adds r0, #4
	b _081CC10A
	.align 2, 0
_081CC0FC: .4byte 0x030046A4
_081CC100:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CC10A:
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
	ldr r6, _081CC140 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CC144
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081CC16A
	.align 2, 0
_081CC140: .4byte 0x000004A4
_081CC144:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CC164
	cmp r0, #2
	beq _081CC160
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CC160:
	movs r0, #1
	b _081CC174
_081CC164:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081CC16A:
	ldr r1, _081CC188 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CC174:
	cmp r0, #0
	bne _081CC194
	ldr r3, _081CC18C @ =0x000005C4
	adds r0, r7, r3
_081CC17C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081CC194
	.align 2, 0
_081CC188: .4byte 0xFFFFFDFF
_081CC18C: .4byte 0x000005C4
_081CC190:
	adds r0, #1
	str r0, [r1]
_081CC194:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
