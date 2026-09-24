	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov ip, r6
	ldr r0, _081D7390 @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D736E
	b _081D76B0
_081D736E:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D7394
	movs r0, #1
	b _081D7396
	.align 2, 0
_081D7390: .4byte 0x0300019C
_081D7394:
	movs r0, #0
_081D7396:
	cmp r0, #0
	bne _081D739C
	b _081D74B8
_081D739C:
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D73D2
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D73DE
_081D73D2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D73DE:
	str r0, [r2]
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
	beq _081D7404
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D740E
_081D7404:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D740E:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7448 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D748E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7452
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D744C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7468
	.align 2, 0
_081D7448: .4byte 0x0000FFFF
_081D744C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7466
_081D7452:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7466
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7468
_081D7466:
	movs r2, #0
_081D7468:
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
	bne _081D7490
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7490
_081D748E:
	movs r2, #0
_081D7490:
	cmp r2, #0
	bne _081D7496
	b _081D76B0
_081D7496:
	ldr r1, [r7, #0x18]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #3
	strh r0, [r1]
	adds r0, #0xfd
	adds r1, r6, r0
	movs r0, #0x21
	str r0, [r1]
	b _081D76B0
_081D74B8:
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D74C6
	movs r0, #1
	b _081D74C8
_081D74C6:
	movs r0, #0
_081D74C8:
	cmp r0, #0
	beq _081D75C2
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7500
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D750C
_081D7500:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D750C:
	str r0, [r2]
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
	beq _081D7532
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D753C
_081D7532:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D753C:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7574 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D75AC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7578
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D756E
	ldrb r0, [r4, #5]
_081D756E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7588
	.align 2, 0
_081D7574: .4byte 0x0000FFFF
_081D7578:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7588
	strh r1, [r4, #8]
_081D7588:
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
	bne _081D75AC
	movs r0, #1
	strb r0, [r4, #7]
_081D75AC:
	adds r0, r6, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #3
	bne _081D76B0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x24
	str r0, [r1]
	b _081D76B0
_081D75C2:
	adds r0, r6, #0
	bl FUN_081d6fd4
	movs r1, #1
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D75D6
	movs r0, #1
	b _081D75D8
_081D75D6:
	movs r0, #0
_081D75D8:
	cmp r0, #0
	beq _081D76B0
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D760C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D7614
_081D760C:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7614:
	str r0, [r6]
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
	beq _081D7638
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D7640
_081D7638:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7640:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7678 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D76B0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D767C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7670
	ldrb r0, [r4, #5]
_081D7670:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D768C
	.align 2, 0
_081D7678: .4byte 0x0000FFFF
_081D767C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D768C
	strh r1, [r4, #8]
_081D768C:
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
	bne _081D76B0
	movs r0, #1
	strb r0, [r4, #7]
_081D76B0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
