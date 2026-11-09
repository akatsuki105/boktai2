	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x104
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08111484
	ldr r3, _08111474 @ =0x0000048A
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811147C
	ldr r0, _08111478 @ =0x00000211
	bl PlaySound_082406e0
	b _08111484
	.align 2, 0
_08111474: .4byte 0x0000048A
_08111478: .4byte 0x00000211
_0811147C:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08111484:
	adds r0, r7, #0
	bl Skeleton_CountHitForScript
	movs r0, #0x80
	lsls r0, r0, #6
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r3, [r1]
	adds r2, r3, #0
	ands r0, r2
	str r1, [sp, #0xf4]
	cmp r0, #0
	bne _081114A2
	b _08111C10
_081114A2:
	ldr r5, _0811152C @ =0x000001DD
	adds r0, r7, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, _08111530 @ =0xFFFFDFDF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _08111534 @ =0x00000544
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08111538 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r5
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
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe8]
	cmp r5, #0
	blt _08111528
	cmp r1, #0
	blt _08111528
	ldr r0, _0811153C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08111528
	ldr r0, _08111540 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111544
_08111528:
	movs r4, #0
	b _08111552
	.align 2, 0
_0811152C: .4byte 0x000001DD
_08111530: .4byte 0xFFFFDFDF
_08111534: .4byte 0x00000544
_08111538: .4byte 0x03002BE0
_0811153C: .4byte 0x030046A8
_08111540: .4byte 0x030046AC
_08111544:
	ldr r0, _08111564 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08111552:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08111568
	adds r0, #4
	b _08111574
	.align 2, 0
_08111564: .4byte 0x030046A4
_08111568:
	ldr r0, _08111588 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08111574:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811158C
	cmp r2, #2
	beq _08111590
	b _08111594
	.align 2, 0
_08111588: .4byte 0x030046A4
_0811158C:
	ldrb r0, [r6, #4]
	b _08111592
_08111590:
	ldrb r0, [r6]
_08111592:
	subs r1, r1, r0
_08111594:
	strh r1, [r6, #2]
	ldr r0, _081115A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081115AC
	movs r0, #1
	b _081115AE
	.align 2, 0
_081115A8: .4byte 0x030047A4
_081115AC:
	movs r0, #0
_081115AE:
	cmp r0, #0
	beq _081115EC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081115CE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081115CA
	adds r2, r0, #0
_081115CA:
	cmp r2, #0
	bge _081115D8
_081115CE:
	ldr r2, _081115D4 @ =0x000005C4
	adds r0, r7, r2
	b _08111B04
	.align 2, 0
_081115D4: .4byte 0x000005C4
_081115D8:
	ldr r1, _081115E8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08111634
	.align 2, 0
_081115E8: .4byte 0x03002BE0
_081115EC:
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
	blt _08111618
	cmp r1, #0
	blt _08111618
	ldr r0, _0811161C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08111618
	ldr r0, _08111620 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111624
_08111618:
	movs r5, #0
	b _08111632
	.align 2, 0
_0811161C: .4byte 0x030046A8
_08111620: .4byte 0x030046AC
_08111624:
	ldr r0, _0811166C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08111632:
	movs r2, #0
_08111634:
	ldr r4, _08111670 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08111654
	ldr r1, _08111674 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08111654
	b _08111A44
_08111654:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf4]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x1c]
	cmp r0, #0
	beq _08111678
	movs r0, #0
	b _08111B1A
	.align 2, 0
_0811166C: .4byte 0x030046A4
_08111670: .4byte 0x00000256
_08111674: .4byte 0x03002BE0
_08111678:
	ldr r6, _0811171C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf4]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xfc]
	cmp r6, #0
	beq _08111730
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08111720 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x20]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08111724 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x24]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x28]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x2c]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x1c]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _08111728 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0811172C @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x1c]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _08111902
	.align 2, 0
_0811171C: .4byte 0x00000222
_08111720: .4byte 0x0000046D
_08111724: .4byte 0x0000046B
_08111728: .4byte 0x00000469
_0811172C: .4byte 0x00000484
_08111730:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081117F4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x30]
	strb r0, [r2]
	ldr r3, _081117F8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x34]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081117FC @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x38]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x40]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x44]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _08111800 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08111804 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08111808 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x48]
	ldr r1, [sp, #0xe8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x48]
	strh r1, [r6]
	ldr r6, [sp, #0xe8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x48]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x3c]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x40]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, sl
	cmp r0, #0
	blt _081117EE
	cmp r1, #0
	blt _081117EE
	ldr r0, _0811180C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081117EE
	ldr r0, _08111810 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111814
_081117EE:
	movs r4, #0
	b _08111824
	.align 2, 0
_081117F4: .4byte 0x0000046D
_081117F8: .4byte 0x0000046B
_081117FC: .4byte 0x00000553
_08111800: .4byte 0x00000469
_08111804: .4byte 0x00000484
_08111808: .4byte 0x0000046C
_0811180C: .4byte 0x030046A8
_08111810: .4byte 0x030046AC
_08111814:
	ldr r0, _08111834 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_08111824:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08111838
	adds r0, #4
	b _08111844
	.align 2, 0
_08111834: .4byte 0x030046A4
_08111838:
	ldr r0, _08111858 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08111844:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811185C
	cmp r2, #2
	beq _08111862
	b _08111868
	.align 2, 0
_08111858: .4byte 0x030046A4
_0811185C:
	ldr r2, [sp, #0x48]
	ldrb r0, [r2, #4]
	b _08111866
_08111862:
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
_08111866:
	subs r1, r1, r0
_08111868:
	ldr r4, [sp, #0x48]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08111894
	cmp r1, #0
	blt _08111894
	ldr r0, _08111898 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08111894
	ldr r0, _0811189C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081118A0
_08111894:
	movs r4, #0
	b _081118AE
	.align 2, 0
_08111898: .4byte 0x030046A8
_0811189C: .4byte 0x030046AC
_081118A0:
	ldr r0, _081118C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081118AE:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081118C8
	adds r0, #4
	b _081118D4
	.align 2, 0
_081118C4: .4byte 0x030046A4
_081118C8:
	ldr r0, _081118E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081118D4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081118EC
	cmp r3, #2
	beq _081118F0
	b _081118F4
	.align 2, 0
_081118E8: .4byte 0x030046A4
_081118EC:
	ldrb r0, [r5, #4]
	b _081118F2
_081118F0:
	ldrb r0, [r5]
_081118F2:
	subs r2, r2, r0
_081118F4:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08111902:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x4c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0811192C @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _08111A0C
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08111930
	movs r0, #1
	b _08111932
	.align 2, 0
_0811192C: .4byte 0x00000482
_08111930:
	movs r0, #0
_08111932:
	ldr r3, _08111A1C @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _08111A0C
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08111A20 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08111A24 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08111A28 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _08111A2C @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _08111A30 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _08111A34 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _08111A38 @ =0x030046B8
	str r4, [sp, #0x100]
_08111978:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08111A3C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08111A40 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _0811199E
	adds r3, #1
	cmp r3, #3
	ble _08111978
	adds r0, r4, #0
_0811199E:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x4c
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_08111A0C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _08111B1A
	.align 2, 0
_08111A1C: .4byte 0x00000482
_08111A20: .4byte 0x0000054F
_08111A24: .4byte 0x0000054D
_08111A28: .4byte 0x0000054E
_08111A2C: .4byte 0x00000541
_08111A30: .4byte 0x000005BC
_08111A34: .4byte 0x00000542
_08111A38: .4byte 0x030046B8
_08111A3C: .4byte 0x000003FF
_08111A40: .4byte 0x0203B400
_08111A44:
	mov sb, sp
	ldr r6, _08111A80 @ =0x030046A4
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
	beq _08111A84
	adds r0, #4
	b _08111A8E
	.align 2, 0
_08111A80: .4byte 0x030046A4
_08111A84:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08111A8E:
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
	ldr r6, _08111AC8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08111AD0
	ldr r0, _08111ACC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08111AFA
	.align 2, 0
_08111AC8: .4byte 0x000004A4
_08111ACC: .4byte 0xFFFFFDFF
_08111AD0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08111AF0
	cmp r0, #2
	beq _08111AEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08111AEC:
	movs r0, #1
	b _08111AFC
_08111AF0:
	ldr r0, _08111B10 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08111AFA:
	movs r0, #0
_08111AFC:
	cmp r0, #0
	bne _08111B18
	ldr r4, _08111B14 @ =0x000005C4
	adds r0, r7, r4
_08111B04:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08111B1A
	.align 2, 0
_08111B10: .4byte 0xFFFFFDFF
_08111B14: .4byte 0x000005C4
_08111B18:
	movs r0, #1
_08111B1A:
	cmp r0, #0
	bne _08111BA0
	ldr r5, _08111B50 @ =0x000004A4
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
	bne _08111B58
	ldr r0, _08111B54 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08111B82
	.align 2, 0
_08111B50: .4byte 0x000004A4
_08111B54: .4byte 0xFFFFFDFF
_08111B58:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08111B78
	cmp r0, #2
	beq _08111B74
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08111B74:
	movs r0, #1
	b _08111B84
_08111B78:
	ldr r0, _08111B98 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08111B82:
	movs r0, #0
_08111B84:
	cmp r0, #0
	bne _08111BA0
	ldr r4, _08111B9C @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _08112C40
	.align 2, 0
_08111B98: .4byte 0xFFFFFDFF
_08111B9C: .4byte 0x000005C4
_08111BA0:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08111BFC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08111C00 @ =0x0000046B
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
	ldr r6, _08111C04 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08111C08 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08111C0C @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #3
	bl FUN_08112498
	.align 2, 0
_08111BFC: .4byte 0x0000046D
_08111C00: .4byte 0x0000046B
_08111C04: .4byte 0x00000469
_08111C08: .4byte 0x0000046A
_08111C0C: .4byte 0x00000484
_08111C10:
	ldr r4, _08111C24 @ =0x00008002
	ands r4, r2
	cmp r4, #0
	beq _08111C28
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	ldr r1, [sp, #0xf4]
	bl FUN_08112c3e
	.align 2, 0
_08111C24: .4byte 0x00008002
_08111C28:
	ldr r2, _08111C9C @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _08111CC0
	ldr r3, _08111CA0 @ =0x000005CC
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r5, _08111CA4 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _08111CA8 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08111CAC @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08111CB0 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08111CB4 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _08111CB8 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08111CBC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	bl _08112C42
	.align 2, 0
_08111C9C: .4byte 0x0000049C
_08111CA0: .4byte 0x000005CC
_08111CA4: .4byte 0x0000046D
_08111CA8: .4byte 0x0000046B
_08111CAC: .4byte 0x00000469
_08111CB0: .4byte 0x0000046A
_08111CB4: .4byte 0x00000484
_08111CB8: .4byte 0x0000046C
_08111CBC: .4byte 0xFEFFFFFF
_08111CC0:
	movs r4, #0x21
	rsbs r4, r4, #0
	ands r4, r3
	ldr r6, [sp, #0xf4]
	strh r4, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _08111CD8
	bl _08112C40
_08111CD8:
	ldr r1, _08111D38 @ =0x000004BE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08111CE6
	bl _08112C40
_08111CE6:
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _08111CFE
	bl _08112C40
_08111CFE:
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	bne _08111D08
	b _081124B0
_08111D08:
	ldr r4, _08111D3C @ =0x0000048D
	adds r2, r7, r4
	ldrb r0, [r2]
	cmp r0, #0
	bne _08111D44
	ldr r6, _08111D40 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08111D44
	ldr r1, _08111D38 @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r0, #1
	b _08111D46
	.align 2, 0
_08111D38: .4byte 0x000004BE
_08111D3C: .4byte 0x0000048D
_08111D40: .4byte 0x0000048C
_08111D44:
	movs r0, #0
_08111D46:
	cmp r0, #0
	beq _08111D50
	ldr r0, _08111DC0 @ =0x000003A7
	bl PlaySound_082406e0
_08111D50:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, [r2]
	cmp r0, #0
	bne _08111D60
	bl _08112C40
_08111D60:
	movs r1, #0x80
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #4
	ldr r4, _08111DC4 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _08111DC8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r2]
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
	str r4, [sp, #0xd4]
	str r2, [sp, #0xe8]
	str r3, [sp, #0xfc]
	cmp r5, #0
	blt _08111DBA
	cmp r1, #0
	blt _08111DBA
	ldr r0, _08111DCC @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08111DBA
	ldr r0, _08111DD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111DD4
_08111DBA:
	movs r4, #0
	b _08111DE2
	.align 2, 0
_08111DC0: .4byte 0x000003A7
_08111DC4: .4byte 0x00000222
_08111DC8: .4byte 0x03002BE0
_08111DCC: .4byte 0x030046A8
_08111DD0: .4byte 0x030046AC
_08111DD4:
	ldr r0, _08111DF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08111DE2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08111DF8
	adds r0, #4
	b _08111E04
	.align 2, 0
_08111DF4: .4byte 0x030046A4
_08111DF8:
	ldr r0, _08111E18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08111E04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08111E1C
	cmp r2, #2
	beq _08111E20
	b _08111E24
	.align 2, 0
_08111E18: .4byte 0x030046A4
_08111E1C:
	ldrb r0, [r6, #4]
	b _08111E22
_08111E20:
	ldrb r0, [r6]
_08111E22:
	subs r1, r1, r0
_08111E24:
	strh r1, [r6, #2]
	ldr r0, _08111E38 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08111E3C
	movs r0, #1
	b _08111E3E
	.align 2, 0
_08111E38: .4byte 0x030047A4
_08111E3C:
	movs r0, #0
_08111E3E:
	cmp r0, #0
	beq _08111E7C
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _08111E5E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08111E5A
	adds r2, r0, #0
_08111E5A:
	cmp r2, #0
	bge _08111E68
_08111E5E:
	ldr r1, _08111E64 @ =0x000005C4
	adds r0, r7, r1
	b _08112398
	.align 2, 0
_08111E64: .4byte 0x000005C4
_08111E68:
	ldr r1, _08111E78 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08111EC4
	.align 2, 0
_08111E78: .4byte 0x03002BE0
_08111E7C:
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
	blt _08111EA8
	cmp r1, #0
	blt _08111EA8
	ldr r0, _08111EAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08111EA8
	ldr r0, _08111EB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111EB4
_08111EA8:
	movs r5, #0
	b _08111EC2
	.align 2, 0
_08111EAC: .4byte 0x030046A8
_08111EB0: .4byte 0x030046AC
_08111EB4:
	ldr r0, _08111EFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08111EC2:
	movs r2, #0
_08111EC4:
	ldr r3, _08111F00 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08111EE4
	ldr r1, _08111F04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08111EE4
	b _081122D4
_08111EE4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x50]
	cmp r0, #0
	beq _08111F08
	movs r0, #0
	b _081123AE
	.align 2, 0
_08111EFC: .4byte 0x030046A4
_08111F00: .4byte 0x00000256
_08111F04: .4byte 0x03002BE0
_08111F08:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0xfc]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0xf4]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08111FC4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08111FA8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08111FAC @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08111FB0 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x60]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x50
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08111FB4 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08111FB8 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08111FBC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x50]
	str r6, [r1]
	ldr r6, _08111FC0 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _08112192
	.align 2, 0
_08111FA8: .4byte 0x0000046D
_08111FAC: .4byte 0x0000046B
_08111FB0: .4byte 0x00000553
_08111FB4: .4byte 0x00000469
_08111FB8: .4byte 0x0000046A
_08111FBC: .4byte 0x00000484
_08111FC0: .4byte 0x0000046C
_08111FC4:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _08112084 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x64]
	strb r0, [r3]
	ldr r4, _08112088 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x68]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0811208C @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x70]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x74]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x78]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08112090 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _08112094 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08112098 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0xe8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x7c]
	strh r1, [r6]
	ldr r6, [sp, #0xe8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x7c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x70]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x74]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, sb
	cmp r0, #0
	blt _08112080
	cmp r1, #0
	blt _08112080
	ldr r0, _0811209C @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _08112080
	ldr r0, _081120A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081120A4
_08112080:
	movs r4, #0
	b _081120B4
	.align 2, 0
_08112084: .4byte 0x0000046D
_08112088: .4byte 0x0000046B
_0811208C: .4byte 0x00000553
_08112090: .4byte 0x00000469
_08112094: .4byte 0x0000046A
_08112098: .4byte 0x00000484
_0811209C: .4byte 0x030046A8
_081120A0: .4byte 0x030046AC
_081120A4:
	ldr r0, _081120C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081120B4:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081120C8
	adds r0, #4
	b _081120D4
	.align 2, 0
_081120C4: .4byte 0x030046A4
_081120C8:
	ldr r0, _081120E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081120D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081120EC
	cmp r2, #2
	beq _081120F2
	b _081120F8
	.align 2, 0
_081120E8: .4byte 0x030046A4
_081120EC:
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2, #4]
	b _081120F6
_081120F2:
	ldr r3, [sp, #0x7c]
	ldrb r0, [r3]
_081120F6:
	subs r1, r1, r0
_081120F8:
	ldr r4, [sp, #0x7c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08112124
	cmp r1, #0
	blt _08112124
	ldr r0, _08112128 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08112124
	ldr r0, _0811212C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08112130
_08112124:
	movs r4, #0
	b _0811213E
	.align 2, 0
_08112128: .4byte 0x030046A8
_0811212C: .4byte 0x030046AC
_08112130:
	ldr r0, _08112154 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811213E:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08112158
	adds r0, #4
	b _08112164
	.align 2, 0
_08112154: .4byte 0x030046A4
_08112158:
	ldr r0, _08112178 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08112164:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811217C
	cmp r3, #2
	beq _08112180
	b _08112184
	.align 2, 0
_08112178: .4byte 0x030046A4
_0811217C:
	ldrb r0, [r5, #4]
	b _08112182
_08112180:
	ldrb r0, [r5]
_08112182:
	subs r2, r2, r0
_08112184:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08112192:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x80]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081121BC @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0811229C
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081121C0
	movs r0, #1
	b _081121C2
	.align 2, 0
_081121BC: .4byte 0x00000482
_081121C0:
	movs r0, #0
_081121C2:
	ldr r3, _081122AC @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0811229C
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081122B0 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081122B4 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081122B8 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _081122BC @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081122C0 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081122C4 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081122C8 @ =0x030046B8
	str r4, [sp, #0x100]
_08112208:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081122CC @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081122D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _0811222E
	adds r3, #1
	cmp r3, #3
	ble _08112208
	adds r0, r4, #0
_0811222E:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x80
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_0811229C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081123AE
	.align 2, 0
_081122AC: .4byte 0x00000482
_081122B0: .4byte 0x0000054F
_081122B4: .4byte 0x0000054D
_081122B8: .4byte 0x0000054E
_081122BC: .4byte 0x00000541
_081122C0: .4byte 0x000005BC
_081122C4: .4byte 0x00000542
_081122C8: .4byte 0x030046B8
_081122CC: .4byte 0x000003FF
_081122D0: .4byte 0x0203B400
_081122D4:
	add r6, sp, #8
	ldr r0, _08112314 @ =0x030046A4
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
	beq _08112318
	adds r0, #4
	b _08112324
	.align 2, 0
_08112314: .4byte 0x030046A4
_08112318:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08112324:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811235C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08112364
	ldr r0, _08112360 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0811238E
	.align 2, 0
_0811235C: .4byte 0x000004A4
_08112360: .4byte 0xFFFFFDFF
_08112364:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08112384
	cmp r0, #2
	beq _08112380
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112380:
	movs r0, #1
	b _08112390
_08112384:
	ldr r0, _081123A4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0811238E:
	movs r0, #0
_08112390:
	cmp r0, #0
	bne _081123AC
	ldr r3, _081123A8 @ =0x000005C4
	adds r0, r7, r3
_08112398:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081123AE
	.align 2, 0
_081123A4: .4byte 0xFFFFFDFF
_081123A8: .4byte 0x000005C4
_081123AC:
	movs r0, #1
_081123AE:
	adds r1, r0, #0
	cmp r1, #0
	bne _08112440
	ldr r4, [sp, #0x18]
	ldr r5, _081123EC @ =0x00000744
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _081123F0 @ =0x000004A4
	adds r0, r7, r6
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
	bne _081123F8
	ldr r0, _081123F4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08112422
	.align 2, 0
_081123EC: .4byte 0x00000744
_081123F0: .4byte 0x000004A4
_081123F4: .4byte 0xFFFFFDFF
_081123F8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08112418
	cmp r0, #2
	beq _08112414
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112414:
	movs r0, #1
	b _08112424
_08112418:
	ldr r0, _08112438 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08112422:
	movs r0, #0
_08112424:
	cmp r0, #0
	bne _08112440
	ldr r4, _0811243C @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _08112C40
	.align 2, 0
_08112438: .4byte 0xFFFFFDFF
_0811243C: .4byte 0x000005C4
_08112440:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081124A0 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081124A4 @ =0x0000046B
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
	ldr r1, _081124A8 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081124AC @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
FUN_08112498:
	strh r0, [r1]
	movs r0, #1
	b _08112C42
	.align 2, 0
_081124A0: .4byte 0x0000046D
_081124A4: .4byte 0x0000046B
_081124A8: .4byte 0x0000046A
_081124AC: .4byte 0x00000484
_081124B0:
	ldr r0, _081124E0 @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _081124EC
	ldr r1, _081124E4 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081124EC
	ldr r3, _081124E8 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r0, #1
	b _081124EE
	.align 2, 0
_081124E0: .4byte 0x0000048D
_081124E4: .4byte 0x0000048C
_081124E8: .4byte 0x000004BE
_081124EC:
	movs r0, #0
_081124EE:
	cmp r0, #0
	beq _081124F8
	ldr r0, _08112560 @ =0x000003A7
	bl PlaySound_082406e0
_081124F8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _08112506
	b _08112C40
_08112506:
	ldr r0, _08112564 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x10
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r5
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
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe8]
	cmp r5, #0
	blt _0811255A
	cmp r1, #0
	blt _0811255A
	ldr r0, _08112568 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811255A
	ldr r0, _0811256C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08112570
_0811255A:
	movs r4, #0
	b _0811257E
	.align 2, 0
_08112560: .4byte 0x000003A7
_08112564: .4byte 0x03002BE0
_08112568: .4byte 0x030046A8
_0811256C: .4byte 0x030046AC
_08112570:
	ldr r0, _08112590 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811257E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08112594
	adds r0, #4
	b _081125A0
	.align 2, 0
_08112590: .4byte 0x030046A4
_08112594:
	ldr r0, _081125B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081125A0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081125B8
	cmp r2, #2
	beq _081125BC
	b _081125C0
	.align 2, 0
_081125B4: .4byte 0x030046A4
_081125B8:
	ldrb r0, [r6, #4]
	b _081125BE
_081125BC:
	ldrb r0, [r6]
_081125BE:
	subs r1, r1, r0
_081125C0:
	strh r1, [r6, #2]
	ldr r0, _081125D4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081125D8
	movs r0, #1
	b _081125DA
	.align 2, 0
_081125D4: .4byte 0x030047A4
_081125D8:
	movs r0, #0
_081125DA:
	cmp r0, #0
	beq _08112618
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081125FA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081125F6
	adds r2, r0, #0
_081125F6:
	cmp r2, #0
	bge _08112604
_081125FA:
	ldr r1, _08112600 @ =0x000005C4
	adds r0, r7, r1
	b _08112B40
	.align 2, 0
_08112600: .4byte 0x000005C4
_08112604:
	ldr r1, _08112614 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08112660
	.align 2, 0
_08112614: .4byte 0x03002BE0
_08112618:
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
	blt _08112644
	cmp r1, #0
	blt _08112644
	ldr r0, _08112648 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08112644
	ldr r0, _0811264C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08112650
_08112644:
	movs r5, #0
	b _0811265E
	.align 2, 0
_08112648: .4byte 0x030046A8
_0811264C: .4byte 0x030046AC
_08112650:
	ldr r0, _08112698 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811265E:
	movs r2, #0
_08112660:
	ldr r3, _0811269C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08112680
	ldr r1, _081126A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08112680
	b _08112A7C
_08112680:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x84]
	cmp r0, #0
	beq _081126A4
	movs r0, #0
	b _08112B56
	.align 2, 0
_08112698: .4byte 0x030046A4
_0811269C: .4byte 0x00000256
_081126A0: .4byte 0x03002BE0
_081126A4:
	ldr r5, _08112748 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0xf4]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xfc]
	cmp r0, #0
	beq _08112768
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0811274C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x88]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08112750 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x8c]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08112754 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x90]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x94]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x84
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08112758 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0811275C @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08112760 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x84]
	str r6, [r1]
	ldr r6, _08112764 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x8c]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x94]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _0811293A
	.align 2, 0
_08112748: .4byte 0x00000222
_0811274C: .4byte 0x0000046D
_08112750: .4byte 0x0000046B
_08112754: .4byte 0x00000553
_08112758: .4byte 0x00000469
_0811275C: .4byte 0x0000046A
_08112760: .4byte 0x00000484
_08112764: .4byte 0x0000046C
_08112768:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811282C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x98]
	strb r0, [r2]
	ldr r3, _08112830 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _08112834 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xac]
	strb r4, [r3]
	ldr r4, _08112838 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0811283C @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _08112840 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0xb0]
	ldr r1, [sp, #0xe8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xb0]
	strh r1, [r6]
	ldr r6, [sp, #0xe8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xb0]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x98]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x9c]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0xa4]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0xa8]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0xac]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, r8
	cmp r0, #0
	blt _08112828
	cmp r1, #0
	blt _08112828
	ldr r0, _08112844 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _08112828
	ldr r0, _08112848 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811284C
_08112828:
	movs r4, #0
	b _0811285C
	.align 2, 0
_0811282C: .4byte 0x0000046D
_08112830: .4byte 0x0000046B
_08112834: .4byte 0x00000553
_08112838: .4byte 0x00000469
_0811283C: .4byte 0x0000046A
_08112840: .4byte 0x00000484
_08112844: .4byte 0x030046A8
_08112848: .4byte 0x030046AC
_0811284C:
	ldr r0, _0811286C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_0811285C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08112870
	adds r0, #4
	b _0811287C
	.align 2, 0
_0811286C: .4byte 0x030046A4
_08112870:
	ldr r0, _08112890 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811287C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08112894
	cmp r2, #2
	beq _0811289A
	b _081128A0
	.align 2, 0
_08112890: .4byte 0x030046A4
_08112894:
	ldr r2, [sp, #0xb0]
	ldrb r0, [r2, #4]
	b _0811289E
_0811289A:
	ldr r3, [sp, #0xb0]
	ldrb r0, [r3]
_0811289E:
	subs r1, r1, r0
_081128A0:
	ldr r4, [sp, #0xb0]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081128CC
	cmp r1, #0
	blt _081128CC
	ldr r0, _081128D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081128CC
	ldr r0, _081128D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081128D8
_081128CC:
	movs r4, #0
	b _081128E6
	.align 2, 0
_081128D0: .4byte 0x030046A8
_081128D4: .4byte 0x030046AC
_081128D8:
	ldr r0, _081128FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081128E6:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08112900
	adds r0, #4
	b _0811290C
	.align 2, 0
_081128FC: .4byte 0x030046A4
_08112900:
	ldr r0, _08112920 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811290C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08112924
	cmp r3, #2
	beq _08112928
	b _0811292C
	.align 2, 0
_08112920: .4byte 0x030046A4
_08112924:
	ldrb r0, [r5, #4]
	b _0811292A
_08112928:
	ldrb r0, [r5]
_0811292A:
	subs r2, r2, r0
_0811292C:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811293A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xb4]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _08112964 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _08112A44
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08112968
	movs r0, #1
	b _0811296A
	.align 2, 0
_08112964: .4byte 0x00000482
_08112968:
	movs r0, #0
_0811296A:
	ldr r3, _08112A54 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _08112A44
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08112A58 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08112A5C @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08112A60 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _08112A64 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _08112A68 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _08112A6C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _08112A70 @ =0x030046B8
	str r4, [sp, #0x100]
_081129B0:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08112A74 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08112A78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081129D6
	adds r3, #1
	cmp r3, #3
	ble _081129B0
	adds r0, r4, #0
_081129D6:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0xb4
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_08112A44:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _08112B56
	.align 2, 0
_08112A54: .4byte 0x00000482
_08112A58: .4byte 0x0000054F
_08112A5C: .4byte 0x0000054D
_08112A60: .4byte 0x0000054E
_08112A64: .4byte 0x00000541
_08112A68: .4byte 0x000005BC
_08112A6C: .4byte 0x00000542
_08112A70: .4byte 0x030046B8
_08112A74: .4byte 0x000003FF
_08112A78: .4byte 0x0203B400
_08112A7C:
	add r6, sp, #0x10
	ldr r0, _08112ABC @ =0x030046A4
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
	beq _08112AC0
	adds r0, #4
	b _08112ACC
	.align 2, 0
_08112ABC: .4byte 0x030046A4
_08112AC0:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08112ACC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08112B04 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08112B0C
	ldr r0, _08112B08 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08112B36
	.align 2, 0
_08112B04: .4byte 0x000004A4
_08112B08: .4byte 0xFFFFFDFF
_08112B0C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08112B2C
	cmp r0, #2
	beq _08112B28
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112B28:
	movs r0, #1
	b _08112B38
_08112B2C:
	ldr r0, _08112B4C @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08112B36:
	movs r0, #0
_08112B38:
	cmp r0, #0
	bne _08112B54
	ldr r3, _08112B50 @ =0x000005C4
	adds r0, r7, r3
_08112B40:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08112B56
	.align 2, 0
_08112B4C: .4byte 0xFFFFFDFF
_08112B50: .4byte 0x000005C4
_08112B54:
	movs r0, #1
_08112B56:
	adds r1, r0, #0
	cmp r1, #0
	bne _08112BE8
	ldr r4, [sp, #0x18]
	ldr r5, _08112B94 @ =0x00000744
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _08112B98 @ =0x000004A4
	adds r0, r7, r6
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
	bne _08112BA0
	ldr r0, _08112B9C @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08112BCA
	.align 2, 0
_08112B94: .4byte 0x00000744
_08112B98: .4byte 0x000004A4
_08112B9C: .4byte 0xFFFFFDFF
_08112BA0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08112BC0
	cmp r0, #2
	beq _08112BBC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112BBC:
	movs r0, #1
	b _08112BCC
_08112BC0:
	ldr r0, _08112BE0 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08112BCA:
	movs r0, #0
_08112BCC:
	cmp r0, #0
	bne _08112BE8
	ldr r4, _08112BE4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08112C40
	.align 2, 0
_08112BE0: .4byte 0xFFFFFDFF
_08112BE4: .4byte 0x000005C4
_08112BE8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08112C54 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08112C58 @ =0x0000046B
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
	ldr r6, _08112C5C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08112C60 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08112C64 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
FUN_08112c3e:
	strh r0, [r1]
_08112C40:
	movs r0, #0
_08112C42:
	add sp, #0x104
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08112C54: .4byte 0x0000046D
_08112C58: .4byte 0x0000046B
_08112C5C: .4byte 0x00000469
_08112C60: .4byte 0x0000046A
_08112C64: .4byte 0x00000484
