	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D61B0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D6180
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _080D6178 @ =0x000002E6
	adds r1, r5, r6
	strb r0, [r1]
	ldr r0, _080D617C @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _080D6190
	.align 2, 0
_080D6178: .4byte 0x000002E6
_080D617C: .4byte 0x000002E7
_080D6180:
	lsrs r1, r1, #0x19
	ldr r2, _080D6204 @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080D6208 @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
_080D6190:
	ldr r6, _080D620C @ =0x000003D6
	adds r4, r5, r6
	ldrh r0, [r4]
	cmp r0, #0
	beq _080D61A6
	ldr r0, [r5, #0x18]
	ldrh r1, [r4]
	bl Sound_PlayForPlayer
	movs r0, #0
	strh r0, [r4]
_080D61A6:
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0
	bl PlayerLink_SetAction
_080D61B0:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _080D6204 @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	ldr r6, _080D6208 @ =0x000002E7
	adds r0, r5, r6
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl AuxAnim_SetAnim
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _080D6210
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D6218
	.align 2, 0
_080D6204: .4byte 0x000002E6
_080D6208: .4byte 0x000002E7
_080D620C: .4byte 0x000003D6
_080D6210:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D6218:
	str r0, [r6]
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
	beq _080D623C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080D6244
_080D623C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D6244:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D627C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080D62B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D6280
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D6274
	ldrb r0, [r4, #5]
_080D6274:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D6290
	.align 2, 0
_080D627C: .4byte 0x0000FFFF
_080D6280:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _080D6290
	strh r1, [r4, #8]
_080D6290:
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
	bne _080D62B4
	movs r0, #1
	strb r0, [r4, #7]
_080D62B4:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _080D62C2
	b _080D63BA
_080D62C2:
	ldr r1, _080D62F0 @ =0x00000395
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6340
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _080D62F4
	asrs r0, r3, #3
	b _080D62FA
	.align 2, 0
_080D62F0: .4byte 0x00000395
_080D62F4:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D62FA:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _080D6304
	asrs r0, r1, #3
	b _080D630A
_080D6304:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D630A:
	strh r0, [r5, #0x38]
	ldr r3, _080D6338 @ =0x0000037E
	adds r4, r5, r3
	ldrh r1, [r4]
	cmp r1, #5
	bhi _080D63A2
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D632E
	ldr r0, [r5, #0x18]
	ldr r1, _080D633C @ =0x00000191
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	adds r0, #0x2c
	bl Entity080acd4c_Spawn
_080D632E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _080D63A2
	.align 2, 0
_080D6338: .4byte 0x0000037E
_080D633C: .4byte 0x00000191
_080D6340:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _080D6370 @ =gSineTable
	adds r0, r4, #0
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
	blt _080D6374
	asrs r0, r0, #0xc
	b _080D637A
	.align 2, 0
_080D6370: .4byte gSineTable
_080D6374:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D637A:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6398
	asrs r0, r0, #0xc
	b _080D639E
_080D6398:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D639E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
_080D63A2:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r0, [r4]
	bl Camera_Shake
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _080D6400
_080D63BA:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _080D63E4 @ =0x00000395
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _080D63E8 @ =0x000004C5
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D63F0
	ldr r6, _080D63EC @ =0x000004C7
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D63F0
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl PlayerLink_SetAction
	b _080D6400
	.align 2, 0
_080D63E4: .4byte 0x00000395
_080D63E8: .4byte 0x000004C5
_080D63EC: .4byte 0x000004C7
_080D63F0:
	adds r0, r5, #0
	bl PlayerLink_SetAnimFacing
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D6400:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
