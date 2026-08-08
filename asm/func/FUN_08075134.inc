	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _08075154 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08075148
	bl _08075970
_08075148:
	lsls r0, r0, #2
	ldr r1, _08075158 @ =_0807515C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08075154: .4byte 0x0000037D
_08075158: .4byte _0807515C
_0807515C: @ jump table
	.4byte _08075174 @ case 0
	.4byte _08075290 @ case 1
	.4byte _080753FC @ case 2
	.4byte _08075550 @ case 3
	.4byte _080756AC @ case 4
	.4byte _08075840 @ case 5
_08075174:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
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
	beq _080751C8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080751D0
_080751C8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080751D0:
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
	beq _080751F4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080751FC
_080751F4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080751FC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08075234 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0807526C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075238
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0807522C
	ldrb r0, [r4, #5]
_0807522C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075248
	.align 2, 0
_08075234: .4byte 0x0000FFFF
_08075238:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075248
	strh r1, [r4, #8]
_08075248:
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
	bne _0807526C
	movs r0, #1
	strb r0, [r4, #7]
_0807526C:
	ldr r3, _0807528C @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _08075280
	b _08075970
_08075280:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_0807528C: .4byte 0x0000037E
_08075290:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080752E8 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	movs r3, #0xe8
	adds r3, r3, r6
	mov ip, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r7, ip
	cmp r1, r0
	beq _080752EC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080752F4
	.align 2, 0
_080752E8: .4byte 0x000002E6
_080752EC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080752F4:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807531E
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _0807532A
_0807531E:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_0807532A:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08075360 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08075398
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075364
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075358
	ldrb r0, [r4, #5]
_08075358:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075374
	.align 2, 0
_08075360: .4byte 0x0000FFFF
_08075364:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075374
	strh r1, [r4, #8]
_08075374:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _08075398
	movs r0, #1
	strb r0, [r4, #7]
_08075398:
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r3, _080753F4 @ =0x0000037E
	adds r4, r6, r3
	ldrb r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xf0
	strb r1, [r0]
	ldrh r0, [r4]
	cmp r0, #8
	bls _080753D8
	lsls r0, r0, #3
	adds r1, r6, #0
	adds r1, #0xf1
	strb r0, [r1]
	ldrh r0, [r4]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080753F8 @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_080753D8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080753E8
	b _08075970
_080753E8:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_080753F4: .4byte 0x0000037E
_080753F8: .4byte 0x000003F6
_080753FC:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08075458 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
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
	beq _0807545C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08075464
	.align 2, 0
_08075458: .4byte 0x000002E6
_0807545C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075464:
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
	beq _08075488
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08075490
_08075488:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08075490:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080754C8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08075500
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080754CC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080754C0
	ldrb r0, [r4, #5]
_080754C0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080754DC
	.align 2, 0
_080754C8: .4byte 0x0000FFFF
_080754CC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080754DC
	strh r1, [r4, #8]
_080754DC:
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
	bne _08075500
	movs r0, #1
	strb r0, [r4, #7]
_08075500:
	ldr r3, _08075548 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08075522
	b _08075970
_08075522:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _0807554C @ =FUN_080726e0
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08075970
	.align 2, 0
_08075548: .4byte 0x0000037E
_0807554C: .4byte FUN_080726e0
_08075550:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _080755A8 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	movs r3, #0xe8
	adds r3, r3, r6
	mov ip, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r7, ip
	cmp r1, r0
	beq _080755AC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080755B4
	.align 2, 0
_080755A8: .4byte 0x000002E6
_080755AC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080755B4:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080755DE
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080755EA
_080755DE:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080755EA:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08075620 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08075658
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075624
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075618
	ldrb r0, [r4, #5]
_08075618:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075634
	.align 2, 0
_08075620: .4byte 0x0000FFFF
_08075624:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075634
	strh r1, [r4, #8]
_08075634:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _08075658
	movs r0, #1
	strb r0, [r4, #7]
_08075658:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	adds r1, r6, #0
	adds r1, #0xf0
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r3, _080756A8 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0807569C
	b _08075970
_0807569C:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_080756A8: .4byte 0x0000037E
_080756AC:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08075704 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	movs r3, #0xe8
	adds r3, r3, r6
	mov ip, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r7, ip
	cmp r1, r0
	beq _08075708
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08075710
	.align 2, 0
_08075704: .4byte 0x000002E6
_08075708:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08075710:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0807573A
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _08075746
_0807573A:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08075746:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0807577C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080757B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075780
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08075774
	ldrb r0, [r4, #5]
_08075774:
	subs r0, #1
	strh r0, [r4, #8]
	b _08075790
	.align 2, 0
_0807577C: .4byte 0x0000FFFF
_08075780:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08075790
	strh r1, [r4, #8]
_08075790:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _080757B4
	movs r0, #1
	strb r0, [r4, #7]
_080757B4:
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r0, _080757F8 @ =0x0000037E
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0xf0
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _08075800
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r6, #0
	adds r2, #0xf1
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _080757FC @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	b _08075818
	.align 2, 0
_080757F8: .4byte 0x0000037E
_080757FC: .4byte 0x000003F6
_08075800:
	adds r1, r6, #0
	adds r1, #0xf1
	movs r0, #0x40
	strb r0, [r1]
	ldr r3, _08075838 @ =0x000003F6
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_08075818:
	ldr r0, _0807583C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0807582C
	b _08075970
_0807582C:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08075970
	.align 2, 0
_08075838: .4byte 0x000003F6
_0807583C: .4byte 0x0000037E
_08075840:
	adds r4, r6, #0
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r5, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _080758A0 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080758A4
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _080758AC
	.align 2, 0
_080758A0: .4byte 0x000002E6
_080758A4:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080758AC:
	str r0, [r4]
	ldrb r0, [r5, #4]
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
	beq _080758D0
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _080758D8
_080758D0:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080758D8:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r3, _08075910 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _08075948
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08075914
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08075908
	ldrb r0, [r5, #5]
_08075908:
	subs r0, #1
	strh r0, [r5, #8]
	b _08075924
	.align 2, 0
_08075910: .4byte 0x0000FFFF
_08075914:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _08075924
	strh r1, [r5, #8]
_08075924:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075948
	movs r0, #1
	strb r0, [r5, #7]
_08075948:
	ldr r3, _08075978 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08075970
	adds r0, r6, #0
	bl FUN_08072620
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _0807597C @ =FUN_08074d90
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
_08075970:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075978: .4byte 0x0000037E
_0807597C: .4byte FUN_08074d90
