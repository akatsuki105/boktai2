	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081736D0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081736D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081736D6
	.align 2, 0
_081736D0: .4byte 0x0000046C
_081736D4:
	movs r0, #0
_081736D6:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r4, r5, r3
	cmp r0, #0
	beq _081737AC
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r7, _08173738 @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0817373C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldr r4, _08173740 @ =0x000001DD
	adds r0, r5, r4
	movs r7, #0xe0
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrb r4, [r0]
	ldr r2, _08173744 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08173748
	asrs r1, r0, #0xc
	b _0817374E
	.align 2, 0
_08173738: .4byte 0x0000046D
_0817373C: .4byte 0x0000046B
_08173740: .4byte 0x000001DD
_08173744: .4byte gSineTable
_08173748:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817374E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08173768
	asrs r0, r0, #0xc
	b _0817376E
_08173768:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817376E:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x20
	strh r0, [r2]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
	movs r7, #0xde
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	movs r0, #0x80
	ldr r1, _081737DC @ =0x00001008
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r4, r3, #0
_081737AC:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _081737C6
	b _081738CC
_081737C6:
	movs r2, #0x20
	ldr r3, _081737DC @ =0x00001008
	adds r1, r6, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081737E0
	movs r0, #1
	b _081737E2
	.align 2, 0
_081737DC: .4byte 0x00001008
_081737E0:
	movs r0, #0
_081737E2:
	adds r4, r0, #0
	cmp r4, #0
	beq _0817384C
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r7, _0817383C @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08173840 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	strh r2, [r0]
	movs r4, #0xd
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08173844 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08173848 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r3, [r0]
	b _081738A8
	.align 2, 0
_0817383C: .4byte 0x0000046D
_08173840: .4byte 0x0000046B
_08173844: .4byte 0x0000046A
_08173848: .4byte 0x00000484
_0817384C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _081738B4 @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r7, _081738B8 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #0x14
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081738BC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081738C0 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	ldr r4, _081738C4 @ =0x0000046C
	adds r0, r5, r4
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_08175898
	ldr r0, _081738C8 @ =0x000003D9
	bl PlaySound_082406e0
_081738A8:
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081738D6
	.align 2, 0
_081738B4: .4byte 0x0000046D
_081738B8: .4byte 0x0000046B
_081738BC: .4byte 0x0000046A
_081738C0: .4byte 0x00000484
_081738C4: .4byte 0x0000046C
_081738C8: .4byte 0x000003D9
_081738CC:
	ldr r7, _081738DC @ =0x00000484
	adds r1, r5, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081738D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081738DC: .4byte 0x00000484
