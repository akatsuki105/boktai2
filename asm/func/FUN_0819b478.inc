	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r2, _0819B4A4 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819B4A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819B4AA
	.align 2, 0
_0819B4A4: .4byte 0x0000046D
_0819B4A8:
	movs r0, #0
_0819B4AA:
	cmp r0, #0
	beq _0819B56E
	ldr r3, _0819B51C @ =0x00000CBB
	adds r2, r6, r3
	ldrb r1, [r2]
	movs r0, #2
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r4, _0819B520 @ =0x00000CB9
	adds r0, r6, r4
	strb r3, [r0]
	movs r5, #0xcb
	lsls r5, r5, #4
	adds r1, r6, r5
	movs r0, #0x80
	strh r0, [r1]
	ldr r0, _0819B524 @ =0x00000CB4
	adds r1, r6, r0
	movs r0, #4
	strb r0, [r1]
	ldr r2, _0819B528 @ =0x00000CB5
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0819B52C @ =0x00000CA8
	adds r2, r6, r3
	subs r4, #0x21
	adds r0, r6, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r4, sp
	adds r3, r7, #0
	adds r3, #8
	ldrh r0, [r7, #8]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _0819B530
	asrs r1, r0, #1
	b _0819B536
	.align 2, 0
_0819B51C: .4byte 0x00000CBB
_0819B520: .4byte 0x00000CB9
_0819B524: .4byte 0x00000CB4
_0819B528: .4byte 0x00000CB5
_0819B52C: .4byte 0x00000CA8
_0819B530:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0819B536:
	mov r0, sp
	strh r1, [r0]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0819B546
	asrs r0, r0, #1
	b _0819B54C
_0819B546:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0819B54C:
	mov r3, sp
	strh r0, [r3, #4]
	ldr r4, _0819B598 @ =0x00000CA8
	adds r2, r6, r4
	mov r1, sp
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
_0819B56E:
	ldr r2, _0819B59C @ =gSineTable
	ldr r5, _0819B5A0 @ =0x00000CB9
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r0, r6, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B5A4
	asrs r1, r0, #0xc
	b _0819B5AA
	.align 2, 0
_0819B598: .4byte 0x00000CA8
_0819B59C: .4byte gSineTable
_0819B5A0: .4byte 0x00000CB9
_0819B5A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B5AA:
	ldr r3, _0819B5D4 @ =0x00000CA8
	adds r0, r6, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r7, #8]
	ldr r4, _0819B5D8 @ =0x00000CB9
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	adds r3, #8
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B5DC
	asrs r1, r0, #0xc
	b _0819B5E2
	.align 2, 0
_0819B5D4: .4byte 0x00000CA8
_0819B5D8: .4byte 0x00000CB9
_0819B5DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B5E2:
	ldr r5, _0819B618 @ =0x00000CAC
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
	ldr r1, _0819B61C @ =0x00000CB9
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r0, r6, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B620
	asrs r1, r0, #0xc
	b _0819B626
	.align 2, 0
_0819B618: .4byte 0x00000CAC
_0819B61C: .4byte 0x00000CB9
_0819B620:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B626:
	ldr r3, _0819B65C @ =0x00000CA8
	adds r0, r6, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	ldr r4, _0819B660 @ =0x00000A7C
	adds r1, r6, r4
	strh r0, [r1]
	ldr r5, _0819B664 @ =0x00000CB9
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #8
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B668
	asrs r1, r0, #0xc
	b _0819B66E
	.align 2, 0
_0819B65C: .4byte 0x00000CA8
_0819B660: .4byte 0x00000A7C
_0819B664: .4byte 0x00000CB9
_0819B668:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B66E:
	ldr r5, _0819B698 @ =0x00000CAC
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r1, r6, r2
	strh r0, [r1]
	mov r3, r8
	cmp r3, #0x3b
	bgt _0819B6A4
	ldr r4, _0819B69C @ =0x00000CB4
	adds r1, r6, r4
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ldr r5, _0819B6A0 @ =0x00000EAC
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
	b _0819B976
	.align 2, 0
_0819B698: .4byte 0x00000CAC
_0819B69C: .4byte 0x00000CB4
_0819B6A0: .4byte 0x00000EAC
_0819B6A4:
	mov r0, r8
	cmp r0, #0xb3
	bgt _0819B748
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0819B6DE
	ldr r2, _0819B724 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819B728 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0819B72C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	bgt _0819B6DE
	ldr r2, _0819B730 @ =0x00000CB5
	adds r0, r6, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	strb r1, [r0]
	ldr r0, _0819B734 @ =0x00000169
	bl PlaySound_082406e0
_0819B6DE:
	ldr r0, _0819B738 @ =0x03002BE0
	mov r3, sp
	ldr r4, _0819B73C @ =0x00000CA8
	adds r2, r6, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r1, [r0, #0x2c]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r5, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	ldr r3, _0819B740 @ =0x00000CB6
	adds r1, r6, r3
	strb r0, [r1]
	ldr r4, _0819B744 @ =0x00000EAC
	adds r0, r6, r4
	strb r5, [r0]
	b _0819B976
	.align 2, 0
_0819B724: .4byte 0x030046B8
_0819B728: .4byte 0x000003FF
_0819B72C: .4byte 0x0203B400
_0819B730: .4byte 0x00000CB5
_0819B734: .4byte 0x00000169
_0819B738: .4byte 0x03002BE0
_0819B73C: .4byte 0x00000CA8
_0819B740: .4byte 0x00000CB6
_0819B744: .4byte 0x00000EAC
_0819B748:
	ldr r5, _0819B788 @ =0x00000CBB
	adds r3, r6, r5
	ldrb r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0819B7AA
	movs r0, #0xcb
	lsls r0, r0, #4
	adds r2, r6, r0
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	ldr r0, _0819B78C @ =0x000001FF
	cmp r1, r0
	bgt _0819B794
	adds r0, r4, #0
	adds r0, #8
	strh r0, [r2]
	ldr r0, _0819B790 @ =0x00000CB4
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bhi _0819B7AA
	movs r0, #0x10
	strb r0, [r1]
	b _0819B7AA
	.align 2, 0
_0819B788: .4byte 0x00000CBB
_0819B78C: .4byte 0x000001FF
_0819B790: .4byte 0x00000CB4
_0819B794:
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2]
	ldr r2, _0819B7F4 @ =0x00000CB4
	adds r1, r6, r2
	movs r0, #0x10
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
_0819B7AA:
	ldr r0, _0819B7F8 @ =0x03002BE0
	mov r3, sp
	ldr r4, _0819B7FC @ =0x00000CA8
	adds r2, r6, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	ldr r3, _0819B800 @ =0x00000CB6
	adds r1, r6, r3
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819B808
	ldr r4, _0819B804 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0819B816
	.align 2, 0
_0819B7F4: .4byte 0x00000CB4
_0819B7F8: .4byte 0x03002BE0
_0819B7FC: .4byte 0x00000CA8
_0819B800: .4byte 0x00000CB6
_0819B804: .4byte 0xFFFFFF00
_0819B808:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819B816
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0819B816:
	adds r0, r1, #0
	cmp r1, #0
	bge _0819B81E
	rsbs r0, r1, #0
_0819B81E:
	cmp r0, #0x14
	ble _0819B83E
	cmp r1, #0
	ble _0819B834
	ldr r0, _0819B830 @ =0x00000CB6
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #4
	b _0819B83C
	.align 2, 0
_0819B830: .4byte 0x00000CB6
_0819B834:
	ldr r2, _0819B860 @ =0x00000CB6
	adds r1, r6, r2
	ldrb r0, [r1]
	subs r0, #4
_0819B83C:
	strb r0, [r1]
_0819B83E:
	ldr r2, _0819B864 @ =gSineTable
	ldr r3, _0819B860 @ =0x00000CB6
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	cmp r0, #0
	blt _0819B868
	asrs r3, r0, #0xc
	b _0819B86E
	.align 2, 0
_0819B860: .4byte 0x00000CB6
_0819B864: .4byte gSineTable
_0819B868:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0819B86E:
	ldr r5, _0819B890 @ =0x00000CA8
	adds r1, r6, r5
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _0819B894 @ =0x00000CB6
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	cmp r0, #0
	blt _0819B898
	asrs r2, r0, #0xc
	b _0819B89E
	.align 2, 0
_0819B890: .4byte 0x00000CA8
_0819B894: .4byte 0x00000CB6
_0819B898:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0819B89E:
	ldr r3, _0819B908 @ =0x00000CAC
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r5, _0819B90C @ =0x00000CBB
	adds r4, r6, r5
	ldrb r1, [r4]
	movs r5, #4
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0819B976
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r3, #2
	orrs r0, r3
	str r0, [r2]
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldrb r3, [r2, #6]
	subs r0, r3, #6
	strb r0, [r2, #6]
	ldr r2, _0819B910 @ =0x00000A66
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	ldr r0, [r7, #0x44]
	ldrb r0, [r0, #6]
	cmp r3, r0
	bge _0819B8EC
	ldr r0, _0819B914 @ =0x00000169
	bl PlaySound_082406e0
_0819B8EC:
	ldrb r1, [r4]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0819B976
	ldr r0, _0819B918 @ =0x000001DF
	cmp r8, r0
	bgt _0819B91C
	movs r3, #0xcb
	lsls r3, r3, #4
	adds r1, r6, r3
	ldrh r0, [r1]
	subs r0, #1
	b _0819B974
	.align 2, 0
_0819B908: .4byte 0x00000CAC
_0819B90C: .4byte 0x00000CBB
_0819B910: .4byte 0x00000A66
_0819B914: .4byte 0x00000169
_0819B918: .4byte 0x000001DF
_0819B91C:
	ldr r0, _0819B930 @ =0x00000243
	cmp r8, r0
	bgt _0819B934
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r1, r6, r4
	ldrh r0, [r1]
	adds r0, #6
	b _0819B974
	.align 2, 0
_0819B930: .4byte 0x00000243
_0819B934:
	ldr r0, _0819B948 @ =0x00000293
	cmp r8, r0
	bgt _0819B94C
	movs r5, #0xcb
	lsls r5, r5, #4
	adds r1, r6, r5
	ldrh r0, [r1]
	subs r0, #4
	b _0819B974
	.align 2, 0
_0819B948: .4byte 0x00000293
_0819B94C:
	ldr r0, _0819B960 @ =0x000002E3
	cmp r8, r0
	bgt _0819B964
	movs r0, #0xcb
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #4
	b _0819B974
	.align 2, 0
_0819B960: .4byte 0x000002E3
_0819B964:
	ldr r0, _0819B990 @ =0x00000333
	cmp r8, r0
	ble _0819B976
	movs r2, #0xcb
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #6
_0819B974:
	strh r0, [r1]
_0819B976:
	ldr r3, _0819B994 @ =0x00000CB4
	adds r0, r6, r3
	ldrb r1, [r0]
	ldr r4, _0819B998 @ =0x00000CB5
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B99C
	asrs r2, r0, #4
	b _0819B9A2
	.align 2, 0
_0819B990: .4byte 0x00000333
_0819B994: .4byte 0x00000CB4
_0819B998: .4byte 0x00000CB5
_0819B99C:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r2, r0, #0
_0819B9A2:
	ldr r5, _0819B9EC @ =0x00000CB9
	adds r1, r6, r5
	ldrb r0, [r1]
	adds r0, r0, r2
	movs r4, #0
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0819fc5c
	ldr r1, _0819B9F0 @ =0x00000CBB
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0819BA00
	ldr r2, _0819B9F4 @ =FUN_0819baa0
	movs r1, #0x2d
	ldr r5, _0819B9F8 @ =0x0000046D
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _0819B9FC @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	b _0819BA7C
	.align 2, 0
_0819B9EC: .4byte 0x00000CB9
_0819B9F0: .4byte 0x00000CBB
_0819B9F4: .4byte FUN_0819baa0
_0819B9F8: .4byte 0x0000046D
_0819B9FC: .4byte 0x0000046B
_0819BA00:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r8, r0
	ble _0819BA7C
	movs r3, #0x94
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	ldr r4, _0819BA8C @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	ldr r5, _0819BA90 @ =0x0000046B
	adds r5, r5, r7
	mov r8, r5
	ldr r0, _0819BA94 @ =0x00000553
	adds r3, r7, r0
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r1, r7
	mov ip, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r7, r7, r2
	ldr r4, _0819BA98 @ =FUN_0819bbd8
	mov sl, r4
	movs r5, #4
	ldr r0, _0819BA9C @ =0x00000ABE
	adds r2, r6, r0
	movs r4, #2
	adds r0, #0xf0
	adds r1, r6, r0
_0819BA4E:
	ldrh r0, [r2]
	orrs r0, r5
	strh r0, [r2]
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r2, #0x50
	adds r1, #0x50
	subs r4, #1
	cmp r4, #0
	bge _0819BA4E
	movs r2, #0
	movs r1, #0x2e
	movs r0, #1
	mov r4, sb
	strb r0, [r4]
	mov r5, r8
	strb r2, [r5]
	strb r1, [r3]
	mov r0, sl
	mov r1, ip
	str r0, [r1]
	strh r2, [r7]
_0819BA7C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819BA8C: .4byte 0x0000046D
_0819BA90: .4byte 0x0000046B
_0819BA94: .4byte 0x00000553
_0819BA98: .4byte FUN_0819bbd8
_0819BA9C: .4byte 0x00000ABE
