	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _081BC2F4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BC2F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BC2FA
	.align 2, 0
_081BC2F4: .4byte 0x0000046D
_081BC2F8:
	movs r0, #0
_081BC2FA:
	cmp r0, #0
	beq _081BC306
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081BC306:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r5, #0x13
	bgt _081BC332
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _081BC332
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081BC332
	cmp r2, #1
	beq _081BC332
	strh r3, [r4, #0xe]
_081BC332:
	ldr r2, _081BC424 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BC340
	bl _081BCB20
_081BC340:
	ldr r3, _081BC428 @ =0x0000046B
	adds r0, r7, r3
	movs r4, #0
	movs r5, #1
	strb r5, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r0, [r1]
	ldr r2, _081BC42C @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r5, [r2]
	ldr r3, _081BC430 @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r4, [r3]
	ldr r5, _081BC434 @ =0x00000484
	adds r5, r5, r7
	mov ip, r5
	str r4, [r5]
	ldr r0, _081BC438 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r1, #1
	strb r1, [r0]
	ldr r1, _081BC43C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r2, _081BC440 @ =0x0000046D
	adds r3, r7, r2
	movs r5, #1
	strb r5, [r3]
	subs r2, #2
	adds r2, r2, r7
	mov sb, r2
	strb r4, [r2]
	ldr r5, _081BC444 @ =0x00000553
	adds r5, r5, r7
	mov r8, r5
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r6, r7, r0
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	strh r4, [r5]
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	str r3, [sp, #0x2c]
	ldr r0, [sp, #8]
	str r0, [sp, #0x18]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x1c]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x20]
	mov r0, ip
	str r0, [sp, #0x34]
	mov r3, sl
	str r3, [sp, #0x28]
	mov r4, sb
	str r4, [sp, #0x24]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r6, [sp, #0x54]
	str r5, [sp, #0x50]
	mov sl, r2
	cmp r1, #0
	bne _081BC3E2
	b _081BC990
_081BC3E2:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
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
	blt _081BC41E
	cmp r1, #0
	blt _081BC41E
	ldr r0, _081BC448 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081BC41E
	ldr r0, _081BC44C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC450
_081BC41E:
	movs r4, #0
	b _081BC45E
	.align 2, 0
_081BC424: .4byte 0x0000046E
_081BC428: .4byte 0x0000046B
_081BC42C: .4byte 0x00000469
_081BC430: .4byte 0x0000046A
_081BC434: .4byte 0x00000484
_081BC438: .4byte 0x0000046C
_081BC43C: .4byte Enemy_WaitPendingState
_081BC440: .4byte 0x0000046D
_081BC444: .4byte 0x00000553
_081BC448: .4byte 0x030046A8
_081BC44C: .4byte 0x030046AC
_081BC450:
	ldr r0, _081BC470 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081BC45E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BC474
	adds r0, #4
	b _081BC480
	.align 2, 0
_081BC470: .4byte 0x030046A4
_081BC474:
	ldr r0, _081BC494 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BC480:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BC498
	cmp r2, #2
	beq _081BC49C
	b _081BC4A0
	.align 2, 0
_081BC494: .4byte 0x030046A4
_081BC498:
	ldrb r0, [r5, #4]
	b _081BC49E
_081BC49C:
	ldrb r0, [r5]
_081BC49E:
	subs r1, r1, r0
_081BC4A0:
	strh r1, [r5, #2]
	ldr r0, _081BC4B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BC4B8
	movs r0, #1
	b _081BC4BA
	.align 2, 0
_081BC4B4: .4byte 0x030047A4
_081BC4B8:
	movs r0, #0
_081BC4BA:
	cmp r0, #0
	beq _081BC4F8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081BC4DA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BC4D6
	adds r2, r0, #0
_081BC4D6:
	cmp r2, #0
	bge _081BC4E4
_081BC4DA:
	ldr r3, _081BC4E0 @ =0x000005C4
	adds r0, r7, r3
	b _081BC938
	.align 2, 0
_081BC4E0: .4byte 0x000005C4
_081BC4E4:
	ldr r1, _081BC4F4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BC540
	.align 2, 0
_081BC4F4: .4byte 0x03002BE0
_081BC4F8:
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
	blt _081BC524
	cmp r1, #0
	blt _081BC524
	ldr r0, _081BC528 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BC524
	ldr r0, _081BC52C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC530
_081BC524:
	movs r5, #0
	b _081BC53E
	.align 2, 0
_081BC528: .4byte 0x030046A8
_081BC52C: .4byte 0x030046AC
_081BC530:
	ldr r0, _081BC578 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BC53E:
	movs r2, #0
_081BC540:
	ldr r1, _081BC57C @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BC560
	ldr r1, _081BC580 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BC560
	b _081BC878
_081BC560:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081BC584
	movs r0, #0
	b _081BC94E
	.align 2, 0
_081BC578: .4byte 0x030046A4
_081BC57C: .4byte 0x00000256
_081BC580: .4byte 0x03002BE0
_081BC584:
	ldr r3, _081BC5E0 @ =0x00000222
	adds r2, r7, r3
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
	mov sb, r2
	cmp r3, #0
	beq _081BC5E4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x2c]
	strb r2, [r3]
	ldr r3, [sp, #0x24]
	strb r5, [r3]
	ldr r3, [sp, #0x4c]
	strb r0, [r3]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	ldr r1, [sp, #0x50]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x18]
	strb r5, [r3]
	ldr r1, [sp, #0x1c]
	strb r5, [r1]
	ldr r3, [sp, #0x20]
	strb r0, [r3]
	ldr r5, [sp, #0x34]
	str r4, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _081BC732
	.align 2, 0
_081BC5E0: .4byte 0x00000222
_081BC5E4:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	strb r5, [r4]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	str r1, [r4]
	ldr r1, [sp, #0x50]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x18]
	strb r5, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r5, [sp, #0x20]
	strb r1, [r5]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r2, [sp, #0x28]
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
	blt _081BC648
	cmp r1, #0
	blt _081BC648
	ldr r0, _081BC64C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BC648
	ldr r0, _081BC650 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC654
_081BC648:
	movs r4, #0
	b _081BC662
	.align 2, 0
_081BC64C: .4byte 0x030046A8
_081BC650: .4byte 0x030046AC
_081BC654:
	ldr r0, _081BC674 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BC662:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BC678
	adds r0, #4
	b _081BC684
	.align 2, 0
_081BC674: .4byte 0x030046A4
_081BC678:
	ldr r0, _081BC698 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BC684:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BC69C
	cmp r2, #2
	beq _081BC6A0
	b _081BC6A4
	.align 2, 0
_081BC698: .4byte 0x030046A4
_081BC69C:
	ldrb r0, [r5, #4]
	b _081BC6A2
_081BC6A0:
	ldrb r0, [r5]
_081BC6A2:
	subs r1, r1, r0
_081BC6A4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BC6CC
	cmp r1, #0
	blt _081BC6CC
	ldr r0, _081BC6D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BC6CC
	ldr r0, _081BC6D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC6D8
_081BC6CC:
	movs r4, #0
	b _081BC6E6
	.align 2, 0
_081BC6D0: .4byte 0x030046A8
_081BC6D4: .4byte 0x030046AC
_081BC6D8:
	ldr r0, _081BC6F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BC6E6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BC6FC
	adds r0, #4
	b _081BC708
	.align 2, 0
_081BC6F8: .4byte 0x030046A4
_081BC6FC:
	ldr r0, _081BC71C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BC708:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BC720
	cmp r3, #2
	beq _081BC724
	b _081BC728
	.align 2, 0
_081BC71C: .4byte 0x030046A4
_081BC720:
	ldrb r0, [r5, #4]
	b _081BC726
_081BC724:
	ldrb r0, [r5]
_081BC726:
	subs r2, r2, r0
_081BC728:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081BC732:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _081BC83C
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BC75C
	movs r0, #1
	b _081BC75E
_081BC75C:
	movs r0, #0
_081BC75E:
	ldr r3, _081BC84C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _081BC83C
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081BC850 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BC854 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _081BC858 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _081BC85C @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x48]
	ldr r5, _081BC860 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _081BC864 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _081BC868 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _081BC86C @ =0x0203B400
	ldr r1, _081BC870 @ =0x030046B8
	ldr r5, _081BC874 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081BC7AE:
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
	bne _081BC7CC
	adds r3, #1
	cmp r3, #3
	ble _081BC7AE
	mov r0, r8
_081BC7CC:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x58]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r0, [sp, #0x54]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x50]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r2, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
_081BC83C:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	movs r0, #0
	b _081BC94E
	.align 2, 0
_081BC84C: .4byte 0x00000482
_081BC850: .4byte 0x0000054F
_081BC854: .4byte 0x0000054C
_081BC858: .4byte 0x0000054D
_081BC85C: .4byte 0x0000054E
_081BC860: .4byte 0x00000541
_081BC864: .4byte 0x000005BC
_081BC868: .4byte 0x00000542
_081BC86C: .4byte 0x0203B400
_081BC870: .4byte 0x030046B8
_081BC874: .4byte 0x000003FF
_081BC878:
	mov sb, sp
	ldr r6, _081BC8B4 @ =0x030046A4
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
	beq _081BC8B8
	adds r0, #4
	b _081BC8C2
	.align 2, 0
_081BC8B4: .4byte 0x030046A4
_081BC8B8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BC8C2:
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
	ldr r5, _081BC8FC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081BC904
	ldr r0, _081BC900 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BC92E
	.align 2, 0
_081BC8FC: .4byte 0x000004A4
_081BC900: .4byte 0xFFFFFDFF
_081BC904:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BC924
	cmp r0, #2
	beq _081BC920
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BC920:
	movs r0, #1
	b _081BC930
_081BC924:
	ldr r0, _081BC944 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BC92E:
	movs r0, #0
_081BC930:
	cmp r0, #0
	bne _081BC94C
	ldr r4, _081BC948 @ =0x000005C4
	adds r0, r7, r4
_081BC938:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081BC94E
	.align 2, 0
_081BC944: .4byte 0xFFFFFDFF
_081BC948: .4byte 0x000005C4
_081BC94C:
	movs r0, #1
_081BC94E:
	cmp r0, #0
	bne _081BC954
	b _081BCB20
_081BC954:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r5, #0x64
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081BC988 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081BC98C @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	b _081BCB20
	.align 2, 0
_081BC988: .4byte 0x00000551
_081BC98C: .4byte 0x00000552
_081BC990:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x28
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
	ldr r3, _081BCA10 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081BCA14 @ =0x00000482
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	subs r3, #0xa9
	adds r0, r7, r3
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
	blt _081BCA0C
	cmp r1, #0
	blt _081BCA0C
	ldr r0, _081BCA18 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BCA0C
	ldr r0, _081BCA1C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BCA20
_081BCA0C:
	movs r4, #0
	b _081BCA2E
	.align 2, 0
_081BCA10: .4byte 0x00000551
_081BCA14: .4byte 0x00000482
_081BCA18: .4byte 0x030046A8
_081BCA1C: .4byte 0x030046AC
_081BCA20:
	ldr r0, _081BCA40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BCA2E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BCA44
	adds r0, #4
	b _081BCA50
	.align 2, 0
_081BCA40: .4byte 0x030046A4
_081BCA44:
	ldr r0, _081BCA64 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BCA50:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BCA68
	cmp r2, #2
	beq _081BCA6C
	b _081BCA70
	.align 2, 0
_081BCA64: .4byte 0x030046A4
_081BCA68:
	ldrb r0, [r5, #4]
	b _081BCA6E
_081BCA6C:
	ldrb r0, [r5]
_081BCA6E:
	subs r1, r1, r0
_081BCA70:
	strh r1, [r5, #2]
	ldr r4, _081BCAA0 @ =0x000004A4
	adds r0, r7, r4
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
	bne _081BCAA8
	ldr r0, _081BCAA4 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BCAD2
	.align 2, 0
_081BCAA0: .4byte 0x000004A4
_081BCAA4: .4byte 0xFFFFFDFF
_081BCAA8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BCAC8
	cmp r0, #2
	beq _081BCAC4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BCAC4:
	movs r0, #1
	b _081BCAD4
_081BCAC8:
	ldr r0, _081BCB0C @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BCAD2:
	movs r0, #0
_081BCAD4:
	adds r3, r0, #0
	cmp r3, #0
	bne _081BCB14
	ldr r0, _081BCB10 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r4, [sp, #0x2c]
	strb r2, [r4]
	ldr r5, [sp, #0x24]
	strb r3, [r5]
	ldr r1, [sp, #0x4c]
	strb r3, [r1]
	ldr r4, [sp, #0x54]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x50]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x18]
	strb r0, [r4]
	ldr r5, [sp, #0x1c]
	strb r1, [r5]
	ldr r0, [sp, #0x20]
	strb r1, [r0]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r3, [sp, #0x28]
	strb r2, [r3]
	b _081BCB20
	.align 2, 0
_081BCB0C: .4byte 0xFFFFFDFF
_081BCB10: .4byte Enemy_ClearStateBegun
_081BCB14:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081BCB20:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
