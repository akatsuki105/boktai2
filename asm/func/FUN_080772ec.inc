	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _08077340 @ =0x00000387
	adds r0, r4, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08236fac
	adds r4, #0xe8
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077344
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _0807734C
	.align 2, 0
_08077340: .4byte 0x00000387
_08077344:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807734C:
	str r0, [r4]
	ldrb r0, [r5, #4]
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
	beq _08077370
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _08077378
_08077370:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08077378:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080773B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _080773E8
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080773B4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080773A8
	ldrb r0, [r5, #5]
_080773A8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080773C4
	.align 2, 0
_080773B0: .4byte 0x0000FFFF
_080773B4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080773C4
	strh r1, [r5, #8]
_080773C4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _080773E8
	movs r0, #1
	strb r0, [r5, #7]
_080773E8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
