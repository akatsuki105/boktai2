	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _080D561C
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
	ldr r1, _080D56E4 @ =0x0000039A
	bl Sound_PlayForPlayer
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl TransEffect_Create
_080D561C:
	ldr r0, _080D56E8 @ =0x0000037E
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _080D562E
	ldr r0, [r6, #0x18]
	ldr r1, _080D56EC @ =0x000003A1
	bl Sound_PlayForPlayer
_080D562E:
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _080D5654
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_080cc3c4
	movs r1, #0x82
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_080D5654:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r0, _080D56F0 @ =0x0000095E
	adds r1, r6, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080D568E
	movs r0, #0x20
	strh r0, [r1]
_080D568E:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D56F4 @ =0x000002E6
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
	beq _080D56F8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5700
	.align 2, 0
_080D56E4: .4byte 0x0000039A
_080D56E8: .4byte 0x0000037E
_080D56EC: .4byte 0x000003A1
_080D56F0: .4byte 0x0000095E
_080D56F4: .4byte 0x000002E6
_080D56F8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5700:
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
	beq _080D5724
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D572C
_080D5724:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D572C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5764 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D579C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5768
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D575C
	ldrb r0, [r4, #5]
_080D575C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5778
	.align 2, 0
_080D5764: .4byte 0x0000FFFF
_080D5768:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5778
	strh r1, [r4, #8]
_080D5778:
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
	bne _080D579C
	movs r0, #1
	strb r0, [r4, #7]
_080D579C:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r1, #0xe
	bl Video_SetAuxSpritePltt
	ldr r2, _080D57E0 @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080D57D8
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D57D8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D57E0: .4byte 0x0000037E
