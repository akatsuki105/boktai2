	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _0806E4D0
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
_0806E4D0:
	ldr r2, _0806E53C @ =0x0000037E
	adds r4, r7, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _0806E4E0
	ldr r0, _0806E540 @ =0x000001EB
	bl PlaySound_082406e0
_0806E4E0:
	ldrh r0, [r4]
	cmp r0, #9
	bls _0806E4E8
	b _0806E5EE
_0806E4E8:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _0806E544 @ =0x00000387
	adds r0, r7, r2
	ldrb r2, [r0]
	adds r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E548
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E550
	.align 2, 0
_0806E53C: .4byte 0x0000037E
_0806E540: .4byte 0x000001EB
_0806E544: .4byte 0x00000387
_0806E548:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E550:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E574
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E57C
_0806E574:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E57C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E5B4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806E61A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E5B8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E5AC
	ldrb r0, [r4, #5]
_0806E5AC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E5C8
	.align 2, 0
_0806E5B4: .4byte 0x0000FFFF
_0806E5B8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806E5C8
	strh r1, [r4, #8]
_0806E5C8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _0806E61A
	movs r0, #1
	strb r0, [r4, #7]
	b _0806E61A
_0806E5EE:
	cmp r0, #0x11
	bhi _0806E61A
	ldr r2, _0806E660 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0806E664 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806E668 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #7
	ldr r2, _0806E66C @ =0x000004BC
	adds r1, r7, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r7, r2
	strh r0, [r1]
_0806E61A:
	ldr r0, _0806E670 @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _0806E656
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	subs r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806E656:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E660: .4byte 0x030046B8
_0806E664: .4byte 0x000003FF
_0806E668: .4byte 0x0203B400
_0806E66C: .4byte 0x000004BC
_0806E670: .4byte 0x0000037E
