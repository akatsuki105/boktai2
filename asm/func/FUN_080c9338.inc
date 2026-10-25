	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C9394
	movs r4, #0
	strb r4, [r1]
	ldr r1, _080C94C8 @ =0x0000191E
	adds r0, r7, r1
	strh r4, [r0]
	movs r3, #0xc9
	lsls r3, r3, #5
	adds r2, r7, r3
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r7, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C9394:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080C93AA
	b _080C95B2
_080C93AA:
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _080C94CC @ =0x0000191C
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080C9402
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xa
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r2, _080C94D0 @ =0x000025E8
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _080C94C8 @ =0x0000191E
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #0xc9
	lsls r0, r0, #5
	adds r2, r7, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_080C9402:
	ldr r2, _080C94D0 @ =0x000025E8
	adds r4, r7, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080C9432
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C9432
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r7, r3
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	strh r5, [r4]
_080C9432:
	movs r0, #0xf
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C9488
	ldr r5, _080C94D4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	ldr r1, _080C94D8 @ =0x0000FFC0
	orrs r0, r1
	adds r1, #0x3f
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r6, _080C94DC @ =0x0203B400
	ldr r4, _080C94E0 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _080C94E4 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	adds r1, #0x80
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r3, [r2]
	movs r0, #0x1f
	ands r3, r0
	adds r3, #0x71
	adds r0, r7, #0
	add r2, sp, #0xc
	bl FUN_080c3db4
_080C9488:
	movs r0, #0x3f
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C949C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0xc
	bl FUN_080c4a40
_080C949C:
	ldr r3, _080C94C8 @ =0x0000191E
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _080C9584
	subs r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _080C94E8
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b _080C9584
	.align 2, 0
_080C94C8: .4byte 0x0000191E
_080C94CC: .4byte 0x0000191C
_080C94D0: .4byte 0x000025E8
_080C94D4: .4byte 0xFFFF0000
_080C94D8: .4byte 0x0000FFC0
_080C94DC: .4byte 0x0203B400
_080C94E0: .4byte 0x030046B8
_080C94E4: .4byte 0x000003FF
_080C94E8:
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _080C9584
	ldr r2, _080C953C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C9540 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080C9544 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r4, r0, #3
	movs r3, #0xff
	ands r4, r3
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C9548 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C954C
	asrs r3, r0, #0xc
	b _080C9552
	.align 2, 0
_080C953C: .4byte 0x030046B8
_080C9540: .4byte 0x000003FF
_080C9544: .4byte 0x0203B400
_080C9548: .4byte gSineTable
_080C954C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C9552:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C9572
	asrs r2, r0, #0xc
	b _080C9578
_080C9572:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C9578:
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080C9584:
	adds r0, r7, #0
	bl FUN_080c4990
	ldr r0, _080C95C0 @ =0x00000167
	cmp r8, r0
	ble _080C95B2
	ldr r1, _080C95C4 @ =0x0000191A
	adds r0, r7, r1
	movs r2, #0
	movs r3, #0
	strh r3, [r0]
	ldr r1, _080C95C8 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C95B2:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C95C0: .4byte 0x00000167
_080C95C4: .4byte 0x0000191A
_080C95C8: .4byte FUN_080c6c8c
