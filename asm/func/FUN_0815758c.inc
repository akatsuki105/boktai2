	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r7, r0, #0
	ldr r0, _081576F0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081575A8
	movs r0, #0
	strb r0, [r1]
_081575A8:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081575C0
	bl _08157DE4
_081575C0:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081575D2
	bl _08157DE4
_081575D2:
	ldr r2, _081576F4 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081575E0
	bl _08157DE0
_081575E0:
	ldr r3, _081576F8 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081576FC @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _08157700 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _081576F4 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081576F0 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _08157704 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _08157708 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _0815770C @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _08157710 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x50]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x5c]
	mov r0, sb
	str r0, [sp, #0x54]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r5, [sp, #0x2c]
	str r4, [sp, #0x34]
	str r3, [sp, #0x30]
	mov sl, r2
	cmp r1, #0
	bne _0815767E
	b _08157C18
_0815767E:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08157714 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
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
	mov r8, r2
	cmp r4, #0
	blt _081576EA
	cmp r1, #0
	blt _081576EA
	ldr r0, _08157718 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081576EA
	ldr r0, _0815771C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157720
_081576EA:
	movs r4, #0
	b _0815772E
	.align 2, 0
_081576F0: .4byte 0x0000046C
_081576F4: .4byte 0x00000484
_081576F8: .4byte 0x000001DF
_081576FC: .4byte 0x00000469
_08157700: .4byte 0x0000046A
_08157704: .4byte Enemy_WaitPendingState
_08157708: .4byte 0x0000046D
_0815770C: .4byte 0x0000046B
_08157710: .4byte 0x00000553
_08157714: .4byte 0x00000551
_08157718: .4byte 0x030046A8
_0815771C: .4byte 0x030046AC
_08157720:
	ldr r0, _08157740 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815772E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08157744
	adds r0, #4
	b _08157750
	.align 2, 0
_08157740: .4byte 0x030046A4
_08157744:
	ldr r0, _08157764 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157750:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157768
	cmp r2, #2
	beq _0815776C
	b _08157770
	.align 2, 0
_08157764: .4byte 0x030046A4
_08157768:
	ldrb r0, [r5, #4]
	b _0815776E
_0815776C:
	ldrb r0, [r5]
_0815776E:
	subs r1, r1, r0
_08157770:
	strh r1, [r5, #2]
	ldr r0, _08157784 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08157788
	movs r0, #1
	b _0815778A
	.align 2, 0
_08157784: .4byte 0x030047A4
_08157788:
	movs r0, #0
_0815778A:
	cmp r0, #0
	beq _081577C8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081577AA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081577A6
	adds r2, r0, #0
_081577A6:
	cmp r2, #0
	bge _081577B4
_081577AA:
	ldr r2, _081577B0 @ =0x000005C4
	adds r0, r7, r2
	b _08157C06
	.align 2, 0
_081577B0: .4byte 0x000005C4
_081577B4:
	ldr r1, _081577C4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08157810
	.align 2, 0
_081577C4: .4byte 0x03002BE0
_081577C8:
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
	blt _081577F4
	cmp r1, #0
	blt _081577F4
	ldr r0, _081577F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081577F4
	ldr r0, _081577FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157800
_081577F4:
	movs r5, #0
	b _0815780E
	.align 2, 0
_081577F8: .4byte 0x030046A8
_081577FC: .4byte 0x030046AC
_08157800:
	ldr r0, _081578A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815780E:
	movs r2, #0
_08157810:
	ldr r4, _081578A4 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08157830
	ldr r1, _081578A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08157830
	b _08157B44
_08157830:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08157844
	b _08157DE4
_08157844:
	ldr r0, _081578AC @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x38]
	cmp r3, #0
	beq _081578B0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	ldr r0, [sp, #0x34]
	str r1, [r0]
	ldr r1, [sp, #0x30]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081579FE
	.align 2, 0
_081578A0: .4byte 0x030046A4
_081578A4: .4byte 0x00000256
_081578A8: .4byte 0x03002BE0
_081578AC: .4byte 0x00000222
_081578B0:
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
	ldr r4, [sp, #0x34]
	str r1, [r4]
	ldr r1, [sp, #0x30]
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
	mov r3, r8
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
	blt _08157914
	cmp r1, #0
	blt _08157914
	ldr r0, _08157918 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157914
	ldr r0, _0815791C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157920
_08157914:
	movs r4, #0
	b _0815792E
	.align 2, 0
_08157918: .4byte 0x030046A8
_0815791C: .4byte 0x030046AC
_08157920:
	ldr r0, _08157940 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815792E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08157944
	adds r0, #4
	b _08157950
	.align 2, 0
_08157940: .4byte 0x030046A4
_08157944:
	ldr r0, _08157964 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157950:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157968
	cmp r2, #2
	beq _0815796C
	b _08157970
	.align 2, 0
_08157964: .4byte 0x030046A4
_08157968:
	ldrb r0, [r5, #4]
	b _0815796E
_0815796C:
	ldrb r0, [r5]
_0815796E:
	subs r1, r1, r0
_08157970:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08157998
	cmp r1, #0
	blt _08157998
	ldr r0, _0815799C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157998
	ldr r0, _081579A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081579A4
_08157998:
	movs r4, #0
	b _081579B2
	.align 2, 0
_0815799C: .4byte 0x030046A8
_081579A0: .4byte 0x030046AC
_081579A4:
	ldr r0, _081579C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081579B2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081579C8
	adds r0, #4
	b _081579D4
	.align 2, 0
_081579C4: .4byte 0x030046A4
_081579C8:
	ldr r0, _081579E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081579D4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081579EC
	cmp r3, #2
	beq _081579F0
	b _081579F4
	.align 2, 0
_081579E8: .4byte 0x030046A4
_081579EC:
	ldrb r0, [r5, #4]
	b _081579F2
_081579F0:
	ldrb r0, [r5]
_081579F2:
	subs r2, r2, r0
_081579F4:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081579FE:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _08157B08
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08157A28
	movs r0, #1
	b _08157A2A
_08157A28:
	movs r0, #0
_08157A2A:
	ldr r3, _08157B18 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _08157B08
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _08157B1C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08157B20 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _08157B24 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x24]
	ldr r4, _08157B28 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _08157B2C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x18]
	ldr r0, _08157B30 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _08157B34 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x1c]
	ldr r6, _08157B38 @ =0x0203B400
	ldr r1, _08157B3C @ =0x030046B8
	ldr r5, _08157B40 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_08157A7A:
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
	bne _08157A98
	adds r3, #1
	cmp r3, #3
	ble _08157A7A
	mov r0, sb
_08157A98:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x28]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x18]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x54]
	strb r1, [r5]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r0, [sp, #0x34]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r2, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
_08157B08:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x58]
	strh r0, [r2]
	b _08157DE4
	.align 2, 0
_08157B18: .4byte 0x00000482
_08157B1C: .4byte 0x0000054F
_08157B20: .4byte 0x0000054C
_08157B24: .4byte 0x0000054D
_08157B28: .4byte 0x0000054E
_08157B2C: .4byte 0x00000541
_08157B30: .4byte 0x000005BC
_08157B34: .4byte 0x00000542
_08157B38: .4byte 0x0203B400
_08157B3C: .4byte 0x030046B8
_08157B40: .4byte 0x000003FF
_08157B44:
	mov sb, sp
	ldr r6, _08157B80 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _08157B84
	adds r0, #4
	b _08157B8E
	.align 2, 0
_08157B80: .4byte 0x030046A4
_08157B84:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08157B8E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _08157BC8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08157BD0
	ldr r0, _08157BCC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08157BFA
	.align 2, 0
_08157BC8: .4byte 0x000004A4
_08157BCC: .4byte 0xFFFFFDFF
_08157BD0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08157BF0
	cmp r0, #2
	beq _08157BEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08157BEC:
	movs r0, #1
	b _08157BFC
_08157BF0:
	ldr r0, _08157C10 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08157BFA:
	movs r0, #0
_08157BFC:
	cmp r0, #0
	beq _08157C02
	b _08157DE4
_08157C02:
	ldr r4, _08157C14 @ =0x000005C4
	adds r0, r7, r4
_08157C06:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08157DE4
	.align 2, 0
_08157C10: .4byte 0xFFFFFDFF
_08157C14: .4byte 0x000005C4
_08157C18:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08157C2A
	b _08157DA2
_08157C2A:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08157C94 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
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
	blt _08157C90
	cmp r1, #0
	blt _08157C90
	ldr r0, _08157C98 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157C90
	ldr r0, _08157C9C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157CA0
_08157C90:
	movs r4, #0
	b _08157CAE
	.align 2, 0
_08157C94: .4byte 0x00000551
_08157C98: .4byte 0x030046A8
_08157C9C: .4byte 0x030046AC
_08157CA0:
	ldr r0, _08157CC0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08157CAE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08157CC4
	adds r0, #4
	b _08157CD0
	.align 2, 0
_08157CC0: .4byte 0x030046A4
_08157CC4:
	ldr r0, _08157CE4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157CD0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157CE8
	cmp r2, #2
	beq _08157CEC
	b _08157CF0
	.align 2, 0
_08157CE4: .4byte 0x030046A4
_08157CE8:
	ldrb r0, [r5, #4]
	b _08157CEE
_08157CEC:
	ldrb r0, [r5]
_08157CEE:
	subs r1, r1, r0
_08157CF0:
	strh r1, [r5, #2]
	ldr r2, _08157D20 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08157D28
	ldr r0, _08157D24 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _08157D52
	.align 2, 0
_08157D20: .4byte 0x000004A4
_08157D24: .4byte 0xFFFFFDFF
_08157D28:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08157D48
	cmp r0, #2
	beq _08157D44
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08157D44:
	movs r0, #1
	b _08157D54
_08157D48:
	ldr r0, _08157D8C @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_08157D52:
	movs r0, #0
_08157D54:
	adds r3, r0, #0
	cmp r3, #0
	bne _08157D94
	ldr r0, _08157D90 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r1, [sp, #0x54]
	strb r2, [r1]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r3, [r5]
	ldr r1, [sp, #0x34]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _08157DE4
	.align 2, 0
_08157D8C: .4byte 0xFFFFFDFF
_08157D90: .4byte Enemy_ClearStateBegun
_08157D94:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _08157DE4
_08157DA2:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08157DDC @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _08157DE4
	.align 2, 0
_08157DDC: .4byte 0x00000551

_08157DE0:
	adds r0, #1
	str r0, [r1]
_08157DE4:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
