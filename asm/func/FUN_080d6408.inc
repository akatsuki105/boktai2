	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _080D644C
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl PlayerLink_SetAction
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080cdda8
	ldr r0, [r6, #0x18]
	ldr r1, _080D64E4 @ =0x0000039A
	bl Sound_PlayForPlayer
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl TransEffect_Create
_080D644C:
	ldr r3, _080D64E8 @ =0x0000037E
	adds r0, r6, r3
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _080D6474
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_080cc3c4
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_080D6474:
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	adds r1, r6, #0
	adds r1, #0xd0
	ldr r0, _080D64EC @ =0x03003584
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D64F0 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl AuxAnim_SetAnim
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
	beq _080D64F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D64FC
	.align 2, 0
_080D64E4: .4byte 0x0000039A
_080D64E8: .4byte 0x0000037E
_080D64EC: .4byte 0x03003584
_080D64F0: .4byte 0x000002E6
_080D64F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D64FC:
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
	beq _080D6520
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D6528
_080D6520:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D6528:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080D6560 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D6598
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D6564
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D6558
	ldrb r0, [r4, #5]
_080D6558:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D6574
	.align 2, 0
_080D6560: .4byte 0x0000FFFF
_080D6564:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D6574
	strh r1, [r4, #8]
_080D6574:
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
	bne _080D6598
	movs r0, #1
	strb r0, [r4, #7]
_080D6598:
	ldr r3, _080D65F0 @ =0x0000095E
	adds r1, r6, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _080D65F4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080D65BE
	movs r0, #0x20
	strh r0, [r1]
_080D65BE:
	ldr r0, _080D65F8 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _080D65E8
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _080D65FC @ =0x00000381
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D65E8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D65F0: .4byte 0x0000095E
_080D65F4: .4byte 0x0000FFFF
_080D65F8: .4byte 0x0000037E
_080D65FC: .4byte 0x00000381
