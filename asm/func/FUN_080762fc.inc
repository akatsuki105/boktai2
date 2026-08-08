	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r1, _08076318 @ =0x0000037D
	adds r0, r6, r1
	ldrb r4, [r0]
	cmp r4, #1
	bne _0807630E
	b _08076504
_0807630E:
	cmp r4, #1
	bgt _0807631C
	cmp r4, #0
	beq _0807632A
	b _08076598
	.align 2, 0
_08076318: .4byte 0x0000037D
_0807631C:
	cmp r4, #2
	bne _08076322
	b _08076548
_08076322:
	cmp r4, #3
	bne _08076328
	b _08076590
_08076328:
	b _08076598
_0807632A:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _0807637C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0807639C
	cmp r0, #0
	beq _08076384
	movs r0, #4
	str r0, [sp]
	ldr r0, _08076380 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _0807639C
	.align 2, 0
_0807637C: .4byte 0x0000FFFF
_08076380: .4byte 0x00001FFF
_08076384:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080763C4 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_0807639C:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080763D0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080763C8 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _080763CC @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b _080763E0
	.align 2, 0
_080763C4: .4byte 0x00001FFF
_080763C8: .4byte 0x000002E6
_080763CC: .4byte 0x000002E7
_080763D0:
	lsrs r1, r1, #0x19
	ldr r2, _08076434 @ =0x000002E6
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _08076438 @ =0x000002E7
	adds r0, r6, r1
	strb r2, [r0]
_080763E0:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
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
	beq _0807643C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08076444
	.align 2, 0
_08076434: .4byte 0x000002E6
_08076438: .4byte 0x000002E7
_0807643C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076444:
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
	beq _08076468
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076470
_08076468:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076470:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080764A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080764E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080764AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080764A0
	ldrb r0, [r4, #5]
_080764A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080764BC
	.align 2, 0
_080764A8: .4byte 0x0000FFFF
_080764AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080764BC
	strh r1, [r4, #8]
_080764BC:
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
	bne _080764E0
	movs r0, #1
	strb r0, [r4, #7]
_080764E0:
	ldr r0, _080764FC @ =0x000001AD
	bl PlaySound_082406e0
	adds r0, r6, #0
	movs r1, #0x16
	movs r2, #1
	bl FUN_08060b84
	ldr r0, _08076500 @ =0x000003F6
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	b _08076598
	.align 2, 0
_080764FC: .4byte 0x000001AD
_08076500: .4byte 0x000003F6
_08076504:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r2, _08076540 @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08076598
	ldr r1, _08076544 @ =0x000003F6
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xef
	strb r4, [r0]
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r6, #0
	movs r1, #0x16
	movs r2, #2
	bl FUN_08060b84
	b _08076598
	.align 2, 0
_08076540: .4byte 0x0000037E
_08076544: .4byte 0x000003F6
_08076548:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r2, _08076588 @ =0x000003F6
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #0x3c
	strh r0, [r1]
	ldr r0, _0807658C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08076598
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_08060b84
	adds r0, r6, #0
	bl FUN_080726b4
	b _08076598
	.align 2, 0
_08076588: .4byte 0x000003F6
_0807658C: .4byte 0x0000037E
_08076590:
	adds r0, r6, #0
	movs r1, #5
	bl FUN_08060c40
_08076598:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
