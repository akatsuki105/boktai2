	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08226550
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _0822654C @ =0x00000F14
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #1
	b _08226552
	.align 2, 0
_0822654C: .4byte 0x00000F14
_08226550:
	movs r0, #0
_08226552:
	cmp r0, #0
	beq _082265F4
	ldr r3, _0822665C @ =0x00000F58
	adds r1, r5, r3
	movs r0, #0
	str r0, [r1]
	ldr r4, _08226660 @ =0x00000DB8
	adds r2, r5, r4
	ldrh r1, [r2]
	ldr r6, _08226664 @ =0x00000E94
	adds r0, r5, r6
	movs r4, #0
	strh r1, [r0]
	ldr r0, _08226668 @ =0x00000DBA
	adds r3, r5, r0
	ldrh r1, [r3]
	adds r6, #2
	adds r0, r5, r6
	strh r1, [r0]
	ldr r1, _0822666C @ =0x00000DBC
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strh r1, [r0]
	ldr r1, _08226670 @ =0x00000E8C
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	ldr r2, _08226674 @ =0x00000E84
	adds r1, r5, r2
	strh r0, [r1]
	subs r6, #0xa
	adds r0, r5, r6
	ldrh r0, [r0]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _08226678 @ =0x00000F15
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _0822667C @ =0x00000F5C
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	cmp r0, #0
	beq _082265C0
	movs r1, #1
_082265C0:
	ldr r2, _08226680 @ =0x00000F25
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08226684 @ =0x00000DF4
	adds r0, r5, r3
	bl FUN_080136b4
	ldr r4, _08226688 @ =0x00000DA4
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x7f
	beq _082265F4
	ldr r6, _0822668C @ =0x00000D9C
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082265F4
	movs r0, #0xf5
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _08226690 @ =FUN_082239c0
	str r0, [r1]
_082265F4:
	ldr r1, _08226670 @ =0x00000E8C
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08226660 @ =0x00000DB8
	adds r1, r5, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	subs r0, r0, r1
	ldr r6, _08226694 @ =0x00000E8E
	adds r1, r5, r6
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r3, #2
	adds r2, r5, r3
	movs r4, #0
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, #0x8e
	adds r1, r5, r6
	strh r0, [r1]
	ldr r0, _0822668C @ =0x00000D9C
	adds r6, r5, r0
	ldr r1, _08226698 @ =0x00000DE4
	adds r4, r5, r1
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0822669C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _082266A4
	.align 2, 0
_0822665C: .4byte 0x00000F58
_08226660: .4byte 0x00000DB8
_08226664: .4byte 0x00000E94
_08226668: .4byte 0x00000DBA
_0822666C: .4byte 0x00000DBC
_08226670: .4byte 0x00000E8C
_08226674: .4byte 0x00000E84
_08226678: .4byte 0x00000F15
_0822667C: .4byte 0x00000F5C
_08226680: .4byte 0x00000F25
_08226684: .4byte 0x00000DF4
_08226688: .4byte 0x00000DA4
_0822668C: .4byte 0x00000D9C
_08226690: .4byte FUN_082239c0
_08226694: .4byte 0x00000E8E
_08226698: .4byte 0x00000DE4
_0822669C:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082266A4:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082266C8
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _082266D0
_082266C8:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082266D0:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08226708 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _0822674E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08226712
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0822670C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08226728
	.align 2, 0
_08226708: .4byte 0x0000FFFF
_0822670C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08226726
_08226712:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08226726
	strh r1, [r4, #8]
	movs r2, #1
	b _08226728
_08226726:
	movs r2, #0
_08226728:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08226750
	movs r0, #1
	strb r0, [r4, #7]
	b _08226750
_0822674E:
	movs r2, #0
_08226750:
	ldr r3, _082267FC @ =0x00000F14
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _08226800 @ =0x00000F58
	adds r1, r5, r4
	ldr r0, [r1]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r1]
	cmp r2, #0x1f
	ble _08226824
	ldr r6, _08226804 @ =0x00000E8C
	adds r0, r5, r6
	ldrh r1, [r0]
	ldr r2, _08226808 @ =0x00000DB8
	adds r0, r5, r2
	strh r1, [r0]
	subs r3, #0x86
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r4, _0822680C @ =0x00000DBA
	adds r0, r5, r4
	strh r1, [r0]
	adds r6, #0x8a
	adds r4, r5, r6
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08226810 @ =0x00000F18
	adds r3, r5, r1
	strh r0, [r3]
	movs r2, #3
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _082267D2
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _082267D2
	ldr r2, _08226814 @ =0x00000DEC
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08226818 @ =0x00000F42
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _0822681C @ =0x00000DF2
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r6, #0x2d
	adds r0, r5, r6
	strb r1, [r0]
_082267D2:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _08226820 @ =0x00000F0C
	adds r1, r5, r2
	ldr r2, [r1]
	cmp r2, #0
	bne _082267EC
	b _0822697E
_082267EC:
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
	b _0822697E
	.align 2, 0
_082267FC: .4byte 0x00000F14
_08226800: .4byte 0x00000F58
_08226804: .4byte 0x00000E8C
_08226808: .4byte 0x00000DB8
_0822680C: .4byte 0x00000DBA
_08226810: .4byte 0x00000F18
_08226814: .4byte 0x00000DEC
_08226818: .4byte 0x00000F42
_0822681C: .4byte 0x00000DF2
_08226820: .4byte 0x00000F0C
_08226824:
	ldr r3, _08226888 @ =0x00000F1C
	adds r0, r5, r3
	ldrh r0, [r0]
	subs r0, #0x10
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	ldr r4, _0822688C @ =0x00000F22
	adds r3, r5, r4
	ldr r0, _08226890 @ =0x00000F27
	adds r6, r5, r0
	lsls r0, r2, #0x10
	cmp r0, #0
	bge _08226852
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
_08226844:
	asrs r0, r0, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #0x10
	cmp r0, #0
	blt _08226844
_08226852:
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xff
	ble _0822686E
	ldr r0, _08226894 @ =0xFFFFFF00
	adds r4, r0, #0
_0822685E:
	asrs r0, r1, #0x10
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xff
	bgt _0822685E
_0822686E:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x10
	asrs r2, r0, #5
	movs r0, #7
	ands r2, r0
	adds r0, r2, #0
	cmp r0, #4
	bne _08226898
	movs r0, #0
	strb r0, [r3]
	b _082268B8
	.align 2, 0
_08226888: .4byte 0x00000F1C
_0822688C: .4byte 0x00000F22
_08226890: .4byte 0x00000F27
_08226894: .4byte 0xFFFFFF00
_08226898:
	cmp r0, #0
	bne _082268A2
	movs r0, #4
	strb r0, [r3]
	b _082268B8
_082268A2:
	cmp r0, #3
	bgt _082268B0
	movs r0, #4
	subs r0, r0, r2
	strb r0, [r3]
	movs r0, #1
	b _082268B6
_082268B0:
	subs r0, r2, #4
	strb r0, [r3]
	movs r0, #0
_082268B6:
	strb r0, [r6]
_082268B8:
	ldr r1, _0822693C @ =0x00000DE4
	adds r0, r5, r1
	ldr r2, _08226940 @ =0x00000E34
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, _08226944 @ =0x00000F15
	adds r2, r5, r3
	ldrb r2, [r2]
	ldr r4, _08226948 @ =0x00000F22
	adds r3, r5, r4
	ldrb r3, [r3]
	ldr r6, _0822694C @ =0x00000F27
	adds r4, r5, r6
	ldrb r4, [r4]
	str r4, [sp]
	bl FUN_08236fac
	ldr r1, _08226950 @ =0x00000E84
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08226954 @ =0x00000F58
	adds r4, r5, r3
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x20
	bl Div
	subs r6, #0x93
	adds r1, r5, r6
	ldrh r1, [r1]
	adds r1, r1, r0
	ldr r2, _08226958 @ =0x00000DB8
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _0822695C @ =0x00000E86
	adds r0, r5, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x20
	bl Div
	adds r3, r0, #0
	ldr r2, _08226960 @ =0x085B0A08
	ldr r0, [r4]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r4, _08226964 @ =0x00000F25
	adds r0, r5, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	muls r0, r2, r0
	cmp r0, #0
	blt _08226968
	asrs r2, r0, #0xc
	b _0822696E
	.align 2, 0
_0822693C: .4byte 0x00000DE4
_08226940: .4byte 0x00000E34
_08226944: .4byte 0x00000F15
_08226948: .4byte 0x00000F22
_0822694C: .4byte 0x00000F27
_08226950: .4byte 0x00000E84
_08226954: .4byte 0x00000F58
_08226958: .4byte 0x00000DB8
_0822695C: .4byte 0x00000E86
_08226960: .4byte 0x085B0A08
_08226964: .4byte 0x00000F25
_08226968:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0822696E:
	ldr r6, _08226988 @ =0x00000E96
	adds r0, r5, r6
	ldrh r0, [r0]
	adds r0, r0, r3
	adds r0, r0, r2
	ldr r2, _0822698C @ =0x00000DBA
	adds r1, r5, r2
	strh r0, [r1]
_0822697E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08226988: .4byte 0x00000E96
_0822698C: .4byte 0x00000DBA
