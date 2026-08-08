	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	ldr r2, _080DF5BC @ =0x000001A3
	adds r1, r7, r2
	ldrb r1, [r1]
	bl Mod
	adds r2, r0, #0
	cmp r2, #0
	beq _080DF560
	b _080DF6CC
_080DF560:
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r5, r7, r3
	ldrb r0, [r5]
	movs r4, #0x5c
	muls r0, r4, r0
	adds r0, r0, r7
	adds r0, #0x84
	adds r3, #2
	adds r1, r7, r3
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrb r0, [r5]
	adds r5, r0, #0
	muls r5, r4, r5
	adds r5, r5, r7
	adds r5, #0x3c
	muls r4, r0, r4
	adds r4, r4, r7
	adds r4, #0x84
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
	beq _080DF5C0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080DF5C8
	.align 2, 0
_080DF5BC: .4byte 0x000001A3
_080DF5C0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DF5C8:
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
	beq _080DF5EC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080DF5F4
_080DF5EC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DF5F4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DF62C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DF664
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DF630
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DF624
	ldrb r0, [r4, #5]
_080DF624:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DF640
	.align 2, 0
_080DF62C: .4byte 0x0000FFFF
_080DF630:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DF640
	strh r1, [r4, #8]
_080DF640:
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
	bne _080DF664
	movs r0, #1
	strb r0, [r4, #7]
_080DF664:
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r5, r7, r3
	ldrb r0, [r5]
	movs r4, #0x5c
	muls r0, r4, r0
	adds r2, r7, #0
	adds r2, #0x58
	adds r2, r2, r0
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r0, [r5]
	adds r2, r0, #0
	muls r2, r4, r2
	adds r3, r7, #0
	adds r3, #0x3c
	adds r2, r3, r2
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r3, r3, r0
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r7, r0
	ldrb r1, [r7, #6]
	adds r0, #0x42
	strb r1, [r0]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r7, r0
	adds r0, #0x94
	movs r1, #4
	strh r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080DF6CC
	movs r0, #0
	strb r0, [r5]
_080DF6CC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
