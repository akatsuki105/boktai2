	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08225688
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08225684 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _0822568A
	.align 2, 0
_08225684: .4byte 0x00000F14
_08225688:
	movs r0, #0
_0822568A:
	cmp r0, #0
	beq _08225724
	ldr r3, _08225758 @ =0x00000E8C
	adds r1, r6, r3
	movs r4, #0
	movs r2, #0
	movs r0, #0x19
	strh r0, [r1]
	ldr r0, _0822575C @ =0x00000E8E
	adds r1, r6, r0
	movs r0, #0x66
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #4
	adds r0, r6, r1
	strh r2, [r0]
	ldr r2, _08225760 @ =0x00000F15
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	subs r3, #0xa8
	adds r0, r6, r3
	subs r2, #0xe1
	adds r1, r6, r2
	ldr r1, [r1]
	ldr r3, _08225764 @ =0x00000F29
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _08225768 @ =0x00000F33
	adds r0, r6, r1
	strb r4, [r0]
	ldr r3, _0822576C @ =0x00000D9C
	adds r2, r6, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08225770 @ =0x00000DA5
	adds r0, r6, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r2, _08225774 @ =0x00000DA4
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_08223374
	ldr r3, _08225778 @ =0x00000DBA
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #8
	strh r0, [r1]
	ldr r2, _0822577C @ =0x00000E9E
	adds r1, r6, r2
	strh r0, [r1]
	adds r3, #0x3a
	adds r0, r6, r3
	bl FUN_080136b4
	movs r0, #0x8f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_08223984
	ldr r1, _08225780 @ =0x00000DC8
	adds r0, r6, r1
	ldr r1, _08225784 @ =0x00000117
	bl FUN_0822b20c
_08225724:
	ldr r2, _0822576C @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _08225788 @ =0x00000DE4
	adds r4, r6, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _0822578C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08225794
	.align 2, 0
_08225758: .4byte 0x00000E8C
_0822575C: .4byte 0x00000E8E
_08225760: .4byte 0x00000F15
_08225764: .4byte 0x00000F29
_08225768: .4byte 0x00000F33
_0822576C: .4byte 0x00000D9C
_08225770: .4byte 0x00000DA5
_08225774: .4byte 0x00000DA4
_08225778: .4byte 0x00000DBA
_0822577C: .4byte 0x00000E9E
_08225780: .4byte 0x00000DC8
_08225784: .4byte 0x00000117
_08225788: .4byte 0x00000DE4
_0822578C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08225794:
	str r0, [r5]
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
	beq _082257B8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082257C0
_082257B8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082257C0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082257F8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0822583E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08225802
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082257FC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08225818
	.align 2, 0
_082257F8: .4byte 0x0000FFFF
_082257FC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08225816
_08225802:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08225816
	strh r1, [r4, #8]
	movs r2, #1
	b _08225818
_08225816:
	movs r2, #0
_08225818:
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
	bne _08225840
	movs r0, #1
	strb r0, [r4, #7]
	b _08225840
_0822583E:
	movs r2, #0
_08225840:
	ldr r3, _082258A0 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	cmp r2, #0
	beq _08225896
	ldr r0, _082258A4 @ =0x00000F16
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _082258A8 @ =0x00000F18
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _08225888
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08225888
	ldr r2, _082258AC @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _082258B0 @ =0x00000F42
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _082258B4 @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _082258B8 @ =0x00000F43
	adds r0, r6, r2
	strb r1, [r0]
_08225888:
	movs r0, #1
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08225896:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082258A0: .4byte 0x00000F14
_082258A4: .4byte 0x00000F16
_082258A8: .4byte 0x00000F18
_082258AC: .4byte 0x00000DEC
_082258B0: .4byte 0x00000F42
_082258B4: .4byte 0x00000DF2
_082258B8: .4byte 0x00000F43
