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
	ldr r4, _081CC58C @ =0x00008002
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r7, r2
	ldrh r2, [r3]
	ands r4, r2
	cmp r4, #0
	beq _081CC590
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r3]
_081CC586:
	movs r0, #0
	bl _081CD5F6
	.align 2, 0
_081CC58C: .4byte 0x00008002
_081CC590:
	ldr r5, _081CC610 @ =0x0000049C
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081CC628
	ldr r1, _081CC614 @ =0x000005CC
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _081CC618 @ =0x0000046D
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
	ldr r1, _081CC61C @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _081CC620 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _081CC624 @ =0xFEFFFFFF
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
	bl _081CD5F4
	.align 2, 0
_081CC610: .4byte 0x0000049C
_081CC614: .4byte 0x000005CC
_081CC618: .4byte 0x0000046D
_081CC61C: .4byte 0x00000469
_081CC620: .4byte 0x0000046C
_081CC624: .4byte 0xFEFFFFFF
_081CC628:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	strh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081CC586
	ldr r5, _081CC6F8 @ =0x000004BE
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _081CC586
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081CC650
	bl _081CCE88
_081CC650:
	ldr r0, _081CC6FC @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _081CC67C
	ldr r1, _081CC700 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081CC67C
	ldr r3, _081CC6F8 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081CC67C:
	movs r2, #0x80
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r5, _081CC704 @ =0x00000222
	adds r4, r7, r5
	ldrh r1, [r4]
	movs r5, #0
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	str r4, [sp, #0xb0]
	cmp r0, #0
	bne _081CC6A8
	b _081CC586
_081CC6A8:
	adds r0, r7, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CC6B6
	b _081CCDBC
_081CC6B6:
	movs r6, #0x95
	lsls r6, r6, #3
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
	blt _081CC6F2
	cmp r1, #0
	blt _081CC6F2
	ldr r0, _081CC708 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CC6F2
	ldr r0, _081CC70C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CC710
_081CC6F2:
	movs r4, #0
	b _081CC71E
	.align 2, 0
_081CC6F8: .4byte 0x000004BE
_081CC6FC: .4byte 0x0000048D
_081CC700: .4byte 0x0000048C
_081CC704: .4byte 0x00000222
_081CC708: .4byte 0x030046A8
_081CC70C: .4byte 0x030046AC
_081CC710:
	ldr r0, _081CC730 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CC71E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CC734
	adds r0, #4
	b _081CC740
	.align 2, 0
_081CC730: .4byte 0x030046A4
_081CC734:
	ldr r0, _081CC754 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CC740:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CC758
	cmp r2, #2
	beq _081CC75C
	b _081CC760
	.align 2, 0
_081CC754: .4byte 0x030046A4
_081CC758:
	ldrb r0, [r5, #4]
	b _081CC75E
_081CC75C:
	ldrb r0, [r5]
_081CC75E:
	subs r1, r1, r0
_081CC760:
	strh r1, [r5, #2]
	ldr r0, _081CC774 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CC778
	movs r0, #1
	b _081CC77A
	.align 2, 0
_081CC774: .4byte 0x030047A4
_081CC778:
	movs r0, #0
_081CC77A:
	cmp r0, #0
	beq _081CC7B8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081CC79A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CC796
	adds r2, r0, #0
_081CC796:
	cmp r2, #0
	bge _081CC7A4
_081CC79A:
	ldr r2, _081CC7A0 @ =0x000005C4
	adds r0, r7, r2
	b _081CCCC4
	.align 2, 0
_081CC7A0: .4byte 0x000005C4
_081CC7A4:
	ldr r1, _081CC7B4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CC800
	.align 2, 0
_081CC7B4: .4byte 0x03002BE0
_081CC7B8:
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
	blt _081CC7E4
	cmp r1, #0
	blt _081CC7E4
	ldr r0, _081CC7E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CC7E4
	ldr r0, _081CC7EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CC7F0
_081CC7E4:
	movs r5, #0
	b _081CC7FE
	.align 2, 0
_081CC7E8: .4byte 0x030046A8
_081CC7EC: .4byte 0x030046AC
_081CC7F0:
	ldr r0, _081CC840 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CC7FE:
	movs r2, #0
_081CC800:
	ldr r4, _081CC844 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CC820
	ldr r1, _081CC848 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CC820
	b _081CCC08
_081CC820:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _081CC84C
	movs r0, #0
	b _081CCCDA
	.align 2, 0
_081CC840: .4byte 0x030046A4
_081CC844: .4byte 0x00000256
_081CC848: .4byte 0x03002BE0
_081CC84C:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0xb0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081CC8F8
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _081CC8E8 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _081CC8EC @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x14]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _081CC8F0 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081CC8F4 @ =0x00000484
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
	b _081CCAC6
	.align 2, 0
_081CC8E8: .4byte 0x0000046D
_081CC8EC: .4byte 0x0000046B
_081CC8F0: .4byte 0x00000469
_081CC8F4: .4byte 0x00000484
_081CC8F8:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _081CC9B8 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _081CC9BC @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081CC9C0 @ =0x00000553
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
	ldr r3, _081CC9C4 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _081CC9C8 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081CC9CC @ =0x00000484
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
	blt _081CC9B4
	cmp r1, #0
	blt _081CC9B4
	ldr r0, _081CC9D0 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081CC9B4
	ldr r0, _081CC9D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CC9D8
_081CC9B4:
	movs r4, #0
	b _081CC9E8
	.align 2, 0
_081CC9B8: .4byte 0x0000046D
_081CC9BC: .4byte 0x0000046B
_081CC9C0: .4byte 0x00000553
_081CC9C4: .4byte 0x00000469
_081CC9C8: .4byte 0x0000046A
_081CC9CC: .4byte 0x00000484
_081CC9D0: .4byte 0x030046A8
_081CC9D4: .4byte 0x030046AC
_081CC9D8:
	ldr r0, _081CC9F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081CC9E8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CC9FC
	adds r0, #4
	b _081CCA08
	.align 2, 0
_081CC9F8: .4byte 0x030046A4
_081CC9FC:
	ldr r0, _081CCA1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CCA08:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CCA20
	cmp r2, #2
	beq _081CCA26
	b _081CCA2C
	.align 2, 0
_081CCA1C: .4byte 0x030046A4
_081CCA20:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _081CCA2A
_081CCA26:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_081CCA2A:
	subs r1, r1, r0
_081CCA2C:
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
	blt _081CCA58
	cmp r1, #0
	blt _081CCA58
	ldr r0, _081CCA5C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CCA58
	ldr r0, _081CCA60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CCA64
_081CCA58:
	movs r4, #0
	b _081CCA72
	.align 2, 0
_081CCA5C: .4byte 0x030046A8
_081CCA60: .4byte 0x030046AC
_081CCA64:
	ldr r0, _081CCA88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CCA72:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CCA8C
	adds r0, #4
	b _081CCA98
	.align 2, 0
_081CCA88: .4byte 0x030046A4
_081CCA8C:
	ldr r0, _081CCAAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CCA98:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CCAB0
	cmp r3, #2
	beq _081CCAB4
	b _081CCAB8
	.align 2, 0
_081CCAAC: .4byte 0x030046A4
_081CCAB0:
	ldrb r0, [r5, #4]
	b _081CCAB6
_081CCAB4:
	ldrb r0, [r5]
_081CCAB6:
	subs r2, r2, r0
_081CCAB8:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CCAC6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CCAF0 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081CCBD0
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CCAF4
	movs r0, #1
	b _081CCAF6
	.align 2, 0
_081CCAF0: .4byte 0x00000482
_081CCAF4:
	movs r0, #0
_081CCAF6:
	ldr r1, _081CCBE0 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081CCBD0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081CCBE4 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CCBE8 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CCBEC @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CCBF0 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _081CCBF4 @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081CCBF8 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CCBFC @ =0x030046B8
	adds r2, r4, #0
_081CCB3E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CCC00 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CCC04 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CCB62
	adds r3, #1
	cmp r3, #3
	ble _081CCB3E
	adds r0, r4, #0
_081CCB62:
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
_081CCBD0:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081CCCDA
	.align 2, 0
_081CCBE0: .4byte 0x00000482
_081CCBE4: .4byte 0x0000054F
_081CCBE8: .4byte 0x0000054C
_081CCBEC: .4byte 0x0000054E
_081CCBF0: .4byte 0x00000541
_081CCBF4: .4byte 0x000005BC
_081CCBF8: .4byte 0x00000542
_081CCBFC: .4byte 0x030046B8
_081CCC00: .4byte 0x000003FF
_081CCC04: .4byte 0x0203B400
_081CCC08:
	mov sb, sp
	ldr r6, _081CCC44 @ =0x030046A4
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
	beq _081CCC48
	adds r0, #4
	b _081CCC52
	.align 2, 0
_081CCC44: .4byte 0x030046A4
_081CCC48:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CCC52:
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
	ldr r6, _081CCC88 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CCC8C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081CCCB2
	.align 2, 0
_081CCC88: .4byte 0x000004A4
_081CCC8C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CCCAC
	cmp r0, #2
	beq _081CCCA8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CCCA8:
	movs r0, #1
	b _081CCCBC
_081CCCAC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081CCCB2:
	ldr r1, _081CCCD0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CCCBC:
	cmp r0, #0
	bne _081CCCD8
	ldr r3, _081CCCD4 @ =0x000005C4
	adds r0, r7, r3
_081CCCC4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CCCDA
	.align 2, 0
_081CCCD0: .4byte 0xFFFFFDFF
_081CCCD4: .4byte 0x000005C4
_081CCCD8:
	movs r0, #1
_081CCCDA:
	cmp r0, #0
	bne _081CCD54
	ldr r4, _081CCD0C @ =0x000004A4
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
	bne _081CCD10
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _081CCD36
	.align 2, 0
_081CCD0C: .4byte 0x000004A4
_081CCD10:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CCD30
	cmp r0, #2
	beq _081CCD2C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CCD2C:
	movs r0, #1
	b _081CCD40
_081CCD30:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_081CCD36:
	ldr r1, _081CCD4C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CCD40:
	cmp r0, #0
	bne _081CCD54
	ldr r4, _081CCD50 @ =0x000005C4
	adds r0, r7, r4
	bl _081CD588
	.align 2, 0
_081CCD4C: .4byte 0xFFFFFDFF
_081CCD50: .4byte 0x000005C4
_081CCD54:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081CCDAC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081CCDB0 @ =0x0000046B
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
	ldr r1, _081CCDB4 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081CCDB8 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _081CD5F4
	.align 2, 0
_081CCDAC: .4byte 0x0000046D
_081CCDB0: .4byte 0x0000046B
_081CCDB4: .4byte 0x0000046A
_081CCDB8: .4byte 0x00000484
_081CCDBC:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _081CCDCC
	bl _081CD5F4
_081CCDCC:
	ldr r2, _081CCE34 @ =Enemy_ClearStateBegun
	mov r8, r2
	movs r1, #0x10
	ldr r3, _081CCE38 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r2, _081CCE3C @ =0x0000046B
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
	ldr r5, _081CCE40 @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081CCE44 @ =0x00000484
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
	blt _081CCE48
	asrs r0, r1, #5
	b _081CCE4E
	.align 2, 0
_081CCE34: .4byte Enemy_ClearStateBegun
_081CCE38: .4byte 0x0000046D
_081CCE3C: .4byte 0x0000046B
_081CCE40: .4byte 0x0000046A
_081CCE44: .4byte 0x00000484
_081CCE48:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081CCE4E:
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
	bl DogLink_PickWalkDest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CCE84
	b _081CD5F4
_081CCE84:
	bl _081CC586

_081CCE88:
	ldr r6, _081CCF1C @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _081CCEB4
	ldr r1, _081CCF20 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081CCEB4
	ldr r3, _081CCF24 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081CCEB4:
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CCEC4
	bl _081CC586
_081CCEC4:
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r5
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
	blt _081CCF16
	cmp r1, #0
	blt _081CCF16
	ldr r0, _081CCF28 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CCF16
	ldr r0, _081CCF2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CCF30
_081CCF16:
	movs r4, #0
	b _081CCF3E
	.align 2, 0
_081CCF1C: .4byte 0x0000048D
_081CCF20: .4byte 0x0000048C
_081CCF24: .4byte 0x000004BE
_081CCF28: .4byte 0x030046A8
_081CCF2C: .4byte 0x030046AC
_081CCF30:
	ldr r0, _081CCF50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CCF3E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CCF54
	adds r0, #4
	b _081CCF60
	.align 2, 0
_081CCF50: .4byte 0x030046A4
_081CCF54:
	ldr r0, _081CCF74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CCF60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CCF78
	cmp r2, #2
	beq _081CCF7C
	b _081CCF80
	.align 2, 0
_081CCF74: .4byte 0x030046A4
_081CCF78:
	ldrb r0, [r5, #4]
	b _081CCF7E
_081CCF7C:
	ldrb r0, [r5]
_081CCF7E:
	subs r1, r1, r0
_081CCF80:
	strh r1, [r5, #2]
	ldr r0, _081CCF94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CCF98
	movs r0, #1
	b _081CCF9A
	.align 2, 0
_081CCF94: .4byte 0x030047A4
_081CCF98:
	movs r0, #0
_081CCF9A:
	cmp r0, #0
	beq _081CCFD8
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081CCFBA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CCFB6
	adds r2, r0, #0
_081CCFB6:
	cmp r2, #0
	bge _081CCFC4
_081CCFBA:
	ldr r1, _081CCFC0 @ =0x000005C4
	adds r0, r7, r1
	b _081CD504
	.align 2, 0
_081CCFC0: .4byte 0x000005C4
_081CCFC4:
	ldr r1, _081CCFD4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CD020
	.align 2, 0
_081CCFD4: .4byte 0x03002BE0
_081CCFD8:
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
	blt _081CD004
	cmp r1, #0
	blt _081CD004
	ldr r0, _081CD008 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CD004
	ldr r0, _081CD00C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD010
_081CD004:
	movs r5, #0
	b _081CD01E
	.align 2, 0
_081CD008: .4byte 0x030046A8
_081CD00C: .4byte 0x030046AC
_081CD010:
	ldr r0, _081CD060 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CD01E:
	movs r2, #0
_081CD020:
	ldr r3, _081CD064 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CD040
	ldr r1, _081CD068 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CD040
	b _081CD444
_081CD040:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x3c]
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _081CD06C
	movs r0, #0
	b _081CD51A
	.align 2, 0
_081CD060: .4byte 0x030046A4
_081CD064: .4byte 0x00000256
_081CD068: .4byte 0x03002BE0
_081CD06C:
	ldr r5, _081CD110 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x98]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb0]
	cmp r6, #0
	beq _081CD130
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081CD114 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x40]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081CD118 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x44]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081CD11C @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x48]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x4c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sp
	ldrh r2, [r2, #0x3c]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081CD120 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081CD124 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081CD128 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x3c]
	str r6, [r1]
	ldr r6, _081CD12C @ =0x0000046C
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
	b _081CD302
	.align 2, 0
_081CD110: .4byte 0x00000222
_081CD114: .4byte 0x0000046D
_081CD118: .4byte 0x0000046B
_081CD11C: .4byte 0x00000553
_081CD120: .4byte 0x00000469
_081CD124: .4byte 0x0000046A
_081CD128: .4byte 0x00000484
_081CD12C: .4byte 0x0000046C
_081CD130:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081CD1F4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _081CD1F8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081CD1FC @ =0x00000553
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
	ldr r2, _081CD200 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081CD204 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081CD208 @ =0x0000046C
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
	blt _081CD1EE
	cmp r1, #0
	blt _081CD1EE
	ldr r0, _081CD20C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081CD1EE
	ldr r0, _081CD210 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD214
_081CD1EE:
	movs r4, #0
	b _081CD224
	.align 2, 0
_081CD1F4: .4byte 0x0000046D
_081CD1F8: .4byte 0x0000046B
_081CD1FC: .4byte 0x00000553
_081CD200: .4byte 0x00000469
_081CD204: .4byte 0x00000484
_081CD208: .4byte 0x0000046C
_081CD20C: .4byte 0x030046A8
_081CD210: .4byte 0x030046AC
_081CD214:
	ldr r0, _081CD234 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081CD224:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CD238
	adds r0, #4
	b _081CD244
	.align 2, 0
_081CD234: .4byte 0x030046A4
_081CD238:
	ldr r0, _081CD258 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CD244:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CD25C
	cmp r2, #2
	beq _081CD262
	b _081CD268
	.align 2, 0
_081CD258: .4byte 0x030046A4
_081CD25C:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _081CD266
_081CD262:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_081CD266:
	subs r1, r1, r0
_081CD268:
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
	blt _081CD294
	cmp r1, #0
	blt _081CD294
	ldr r0, _081CD298 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CD294
	ldr r0, _081CD29C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD2A0
_081CD294:
	movs r4, #0
	b _081CD2AE
	.align 2, 0
_081CD298: .4byte 0x030046A8
_081CD29C: .4byte 0x030046AC
_081CD2A0:
	ldr r0, _081CD2C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CD2AE:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CD2C8
	adds r0, #4
	b _081CD2D4
	.align 2, 0
_081CD2C4: .4byte 0x030046A4
_081CD2C8:
	ldr r0, _081CD2E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CD2D4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CD2EC
	cmp r3, #2
	beq _081CD2F0
	b _081CD2F4
	.align 2, 0
_081CD2E8: .4byte 0x030046A4
_081CD2EC:
	ldrb r0, [r5, #4]
	b _081CD2F2
_081CD2F0:
	ldrb r0, [r5]
_081CD2F2:
	subs r2, r2, r0
_081CD2F4:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CD302:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CD32C @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081CD40C
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CD330
	movs r0, #1
	b _081CD332
	.align 2, 0
_081CD32C: .4byte 0x00000482
_081CD330:
	movs r0, #0
_081CD332:
	ldr r1, _081CD41C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081CD40C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081CD420 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CD424 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CD428 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CD42C @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _081CD430 @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081CD434 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CD438 @ =0x030046B8
	adds r2, r4, #0
_081CD37A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CD43C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CD440 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CD39E
	adds r3, #1
	cmp r3, #3
	ble _081CD37A
	adds r0, r4, #0
_081CD39E:
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
_081CD40C:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081CD51A
	.align 2, 0
_081CD41C: .4byte 0x00000482
_081CD420: .4byte 0x0000054F
_081CD424: .4byte 0x0000054C
_081CD428: .4byte 0x0000054E
_081CD42C: .4byte 0x00000541
_081CD430: .4byte 0x000005BC
_081CD434: .4byte 0x00000542
_081CD438: .4byte 0x030046B8
_081CD43C: .4byte 0x000003FF
_081CD440: .4byte 0x0203B400
_081CD444:
	add r6, sp, #8
	ldr r0, _081CD484 @ =0x030046A4
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
	beq _081CD488
	adds r0, #4
	b _081CD494
	.align 2, 0
_081CD484: .4byte 0x030046A4
_081CD488:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CD494:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081CD4C8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CD4CC
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _081CD4F2
	.align 2, 0
_081CD4C8: .4byte 0x000004A4
_081CD4CC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CD4EC
	cmp r0, #2
	beq _081CD4E8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CD4E8:
	movs r0, #1
	b _081CD4FC
_081CD4EC:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_081CD4F2:
	ldr r1, _081CD510 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CD4FC:
	cmp r0, #0
	bne _081CD518
	ldr r2, _081CD514 @ =0x000005C4
	adds r0, r7, r2
_081CD504:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CD51A
	.align 2, 0
_081CD510: .4byte 0xFFFFFDFF
_081CD514: .4byte 0x000005C4
_081CD518:
	movs r0, #1
_081CD51A:
	cmp r0, #0
	bne _081CD59C
	ldr r3, _081CD54C @ =0x000004A4
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
	bne _081CD550
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _081CD576
	.align 2, 0
_081CD54C: .4byte 0x000004A4
_081CD550:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CD570
	cmp r0, #2
	beq _081CD56C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CD56C:
	movs r0, #1
	b _081CD580
_081CD570:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_081CD576:
	ldr r1, _081CD594 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CD580:
	cmp r0, #0
	bne _081CD59C
	ldr r1, _081CD598 @ =0x000005C4
	adds r0, r7, r1
_081CD588:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _081CC586
	.align 2, 0
_081CD594: .4byte 0xFFFFFDFF
_081CD598: .4byte 0x000005C4
_081CD59C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _081CD608 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _081CD60C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081CD610 @ =0x00000553
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
	ldr r5, _081CD614 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _081CD618 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _081CD61C @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081CD620 @ =0x00000482
	adds r1, r7, r3
	movs r0, #4
	strh r0, [r1]
_081CD5F4:
	movs r0, #1
_081CD5F6:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081CD608: .4byte 0x0000046D
_081CD60C: .4byte 0x0000046B
_081CD610: .4byte 0x00000553
_081CD614: .4byte 0x00000469
_081CD618: .4byte 0x00000484
_081CD61C: .4byte 0x0000046C
_081CD620: .4byte 0x00000482
