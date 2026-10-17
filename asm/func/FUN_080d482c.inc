	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D48B6
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl PlayerLink_SetAction
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4878
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _080D4870 @ =0x000002E6
	adds r1, r4, r6
	strb r0, [r1]
	ldr r0, _080D4874 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D4888
	.align 2, 0
_080D4870: .4byte 0x000002E6
_080D4874: .4byte 0x000002E7
_080D4878:
	lsrs r1, r1, #0x19
	ldr r2, _080D48F4 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080D48F8 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080D4888:
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r0, _080D48FC @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _080D48B6
	ldr r0, [r4, #0x18]
	ldrh r1, [r5]
	bl Sound_PlayForPlayer
	movs r0, #0
	strh r0, [r5]
_080D48B6:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #0
	bne _080D48C4
	b _080D49CA
_080D48C4:
	ldr r2, _080D4900 @ =0x00000395
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D4950
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r2, [r0]
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r3, #0x2c
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _080D4904
	asrs r0, r3, #3
	b _080D490A
	.align 2, 0
_080D48F4: .4byte 0x000002E6
_080D48F8: .4byte 0x000002E7
_080D48FC: .4byte 0x000003D6
_080D4900: .4byte 0x00000395
_080D4904:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D490A:
	strh r0, [r4, #0x34]
	cmp r1, #0
	blt _080D4914
	asrs r0, r1, #3
	b _080D491A
_080D4914:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D491A:
	strh r0, [r4, #0x38]
	ldr r3, _080D4948 @ =0x0000037E
	adds r5, r4, r3
	ldrh r1, [r5]
	cmp r1, #5
	bhi _080D49B2
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D493E
	ldr r0, [r4, #0x18]
	ldr r1, _080D494C @ =0x00000191
	bl Sound_PlayForPlayer
	adds r0, r4, #0
	adds r0, #0x2c
	bl Entity080acd4c_Spawn
_080D493E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b _080D49B2
	.align 2, 0
_080D4948: .4byte 0x0000037E
_080D494C: .4byte 0x00000191
_080D4950:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080D4980 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4984
	asrs r0, r0, #0xc
	b _080D498A
	.align 2, 0
_080D4980: .4byte gSineTable
_080D4984:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D498A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D49A8
	asrs r0, r0, #0xc
	b _080D49AE
_080D49A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D49AE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
_080D49B2:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r4, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _080D4A2C
_080D49CA:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _080D49F4 @ =0x00000395
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D49F8 @ =0x000004C5
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4A00
	ldr r6, _080D49FC @ =0x000004C7
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D4A00
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl PlayerLink_SetAction
	b _080D4A2C
	.align 2, 0
_080D49F4: .4byte 0x00000395
_080D49F8: .4byte 0x000004C5
_080D49FC: .4byte 0x000004C7
_080D4A00:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2a
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D4A2C
	adds r0, r4, #0
	bl PlayerLink_SetAnimFacing
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D4A2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
