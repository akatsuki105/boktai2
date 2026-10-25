	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803547E
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x20
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r1, [r3]
	movs r2, #0xff
	movs r1, #2
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035410
	ldr r2, _0803540C @ =0x00000824
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x16
	cmp r0, #0
	bne _08035420
	movs r3, #0x12
	b _08035420
	.align 2, 0
_0803540C: .4byte 0x00000824
_08035410:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #0x12
	cmp r0, #0
	beq _08035420
	movs r3, #0x16
_08035420:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	adds r0, r6, #0
	bl Boss_PlayAnim
	movs r2, #0xc6
	ldr r3, _0803545C @ =0x0000087C
	adds r1, r5, r3
	movs r3, #0
	strb r4, [r1]
	ldr r4, _08035460 @ =0x0000087A
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08035468
	ldr r0, _08035464 @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _0803547E
	.align 2, 0
_0803545C: .4byte 0x0000087C
_08035460: .4byte 0x0000087A
_08035464: .4byte 0x00000878
_08035468:
	cmp r0, #0
	bne _08035478
	ldr r1, _08035474 @ =0x00000878
	adds r0, r5, r1
	b _0803547C
	.align 2, 0
_08035474: .4byte 0x00000878
_08035478:
	ldr r2, _080354EC @ =0x00000878
	adds r0, r5, r2
_0803547C:
	strh r3, [r0]
_0803547E:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0xb3
	lsls r4, r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, _080354F0 @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035580
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _080354CC
	adds r0, r2, #2
	strh r0, [r3]
_080354CC:
	ldr r2, _080354F4 @ =gSineTable
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080354F8
	asrs r1, r0, #0xc
	b _080354FE
	.align 2, 0
_080354EC: .4byte 0x00000878
_080354F0: .4byte 0x00000167
_080354F4: .4byte gSineTable
_080354F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080354FE:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08035514
	movs r0, #0
	strh r0, [r1]
_08035514:
	cmp r7, #0x3f
	bgt _08035522
	movs r0, #4
	movs r4, #0xc5
	lsls r4, r4, #1
	adds r1, r5, r4
	b _0803552E
_08035522:
	cmp r7, #0x7f
	bgt _08035530
	movs r0, #2
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
_0803552E:
	strb r0, [r1]
_08035530:
	cmp r7, #0xa4
	bne _08035580
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	ldr r3, _08035560 @ =0x00000824
	adds r1, r5, r3
	movs r0, #2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08035564
	movs r4, #0xcf
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _08035572
	.align 2, 0
_08035560: .4byte 0x00000824
_08035564:
	ldr r0, _08035588 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_08035572:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	ldr r0, [r0]
	str r0, [r1]
_08035580:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035588: .4byte 0x03003584
