	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0817458C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08174590
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08174592
	.align 2, 0
_0817458C: .4byte 0x0000046C
_08174590:
	movs r0, #0
_08174592:
	cmp r0, #0
	beq _08174658
	movs r2, #0x10
	ldr r3, _081745AC @ =0x00001008
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081745B0
	movs r0, #1
	b _081745B2
	.align 2, 0
_081745AC: .4byte 0x00001008
_081745B0:
	movs r0, #0
_081745B2:
	adds r2, r0, #0
	cmp r2, #0
	bne _08174658
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r4, #1
	ldr r3, _0817468C @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_081776ac
	adds r0, r7, #0
	bl FUN_08176e14
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r2, _08174690 @ =0x00000472
	adds r1, r5, r2
	ldr r3, _08174694 @ =0xFFFFFF00
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #8
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08177f7c
	ldr r0, _08174698 @ =0x00000474
	adds r2, r5, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08176530
	ldr r1, _0817469C @ =0x00000F8C
	adds r2, r7, r1
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _081746A0 @ =0x00000FA4
	adds r0, r7, r2
	ldrh r1, [r0]
	ldr r3, _081746A4 @ =0x00000F94
	adds r0, r7, r3
	strh r1, [r0]
	movs r0, #0x10
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r0, #0xf9
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08174658:
	adds r0, r5, #0
	bl FUN_081765f8
	movs r6, #0xb1
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _081746A8 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081746B0
	ldr r3, _081746AC @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081746C0
	.align 2, 0
_0817468C: .4byte 0x0000046D
_08174690: .4byte 0x00000472
_08174694: .4byte 0xFFFFFF00
_08174698: .4byte 0x00000474
_0817469C: .4byte 0x00000F8C
_081746A0: .4byte 0x00000FA4
_081746A4: .4byte 0x00000F94
_081746A8: .4byte 0x0000A02F
_081746AC: .4byte 0x00000482
_081746B0:
	ldr r1, _081746E4 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081746C0
	movs r0, #1
	strh r0, [r2]
_081746C0:
	ldr r3, _081746E8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081746EC
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _08174704
	.align 2, 0
_081746E4: .4byte 0x00000482
_081746E8: .4byte 0x0000025D
_081746EC:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_08174704:
	ldr r0, _0817474C @ =0x00000472
	adds r1, r5, r0
	ldr r2, _08174750 @ =0xFFFFFC00
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	ldr r3, _08174754 @ =0x000004A4
	adds r0, r5, r3
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _08174734
	rsbs r2, r2, #0
_08174734:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08174758
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08174742
	rsbs r2, r2, #0
_08174742:
	cmp r2, #0x20
	bgt _08174758
	movs r0, #1
	b _081747C2
	.align 2, 0
_0817474C: .4byte 0x00000472
_08174750: .4byte 0xFFFFFC00
_08174754: .4byte 0x000004A4
_08174758:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08174764
	cmp r1, #0
	beq _081747C0
_08174764:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _08174788 @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0817478C
	asrs r1, r0, #0xc
	b _08174792
	.align 2, 0
_08174788: .4byte gSineTable
_0817478C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08174792:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _081747B0 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081747B4
	asrs r1, r0, #0xc
	b _081747BA
	.align 2, 0
_081747B0: .4byte gSineTable
_081747B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081747BA:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_081747C0:
	movs r0, #0
_081747C2:
	cmp r0, #0
	beq _081748B8
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r3, _08174834 @ =0x000004A4
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r1, #0xee
	lsls r1, r1, #1
	adds r3, r5, r1
	strb r0, [r3]
	ldr r2, _08174838 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817483C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08174840 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _081748B8
	ldrb r1, [r3]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08174848
	ldr r3, _08174844 @ =0xFFFFFF00
	adds r1, r1, r3
	b _08174856
	.align 2, 0
_08174834: .4byte 0x000004A4
_08174838: .4byte 0x030046B8
_0817483C: .4byte 0x000003FF
_08174840: .4byte 0x0203B400
_08174844: .4byte 0xFFFFFF00
_08174848:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08174856
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08174856:
	cmp r1, #0
	bge _0817485C
	rsbs r1, r1, #0
_0817485C:
	cmp r1, #0x20
	ble _081748B8
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r1, _081748A8 @ =0x00000472
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldr r2, _081748AC @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	adds r0, r5, #0
	bl FUN_0817697c
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _081748B0 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r1, _081748B4 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0817496E
	.align 2, 0
_081748A8: .4byte 0x00000472
_081748AC: .4byte 0x0000FFFF
_081748B0: .4byte 0x00000469
_081748B4: .4byte 0x0000046C
_081748B8:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08178640
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08177890
	ldr r2, _08174948 @ =0x00000F94
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	bne _08174960
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _0817494C @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _08174950 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08174954 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08174958 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _0817495C @ =0x00001008
	adds r2, r7, r3
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xf9
	lsls r0, r0, #2
	bl sound_08240740
	b _0817496E
	.align 2, 0
_08174948: .4byte 0x00000F94
_0817494C: .4byte 0x00000469
_08174950: .4byte 0x0000046A
_08174954: .4byte Enemy_ClearStateBegun
_08174958: .4byte 0x0000046B
_0817495C: .4byte 0x00001008
_08174960:
	subs r0, #1
	strh r0, [r1]
	ldr r6, _08174978 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0817496E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08174978: .4byte 0x00000484
