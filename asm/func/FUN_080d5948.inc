	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D596C
	ldr r2, _080D59EC @ =0x00000386
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl PlayerLink_SetAction
_080D596C:
	ldr r0, [r6, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x20]
	adds r0, r6, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080d5908
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_080cc268
	adds r0, r6, #0
	bl PlayerLink_SetAnimFacing
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D59F0 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
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
	beq _080D59F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D59FC
	.align 2, 0
_080D59EC: .4byte 0x00000386
_080D59F0: .4byte 0x000002E6
_080D59F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D59FC:
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
	beq _080D5A20
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5A28
_080D5A20:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5A28:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5A60 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5A98
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5A64
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5A58
	ldrb r0, [r4, #5]
_080D5A58:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5A74
	.align 2, 0
_080D5A60: .4byte 0x0000FFFF
_080D5A64:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5A74
	strh r1, [r4, #8]
_080D5A74:
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
	bne _080D5A98
	movs r0, #1
	strb r0, [r4, #7]
_080D5A98:
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080D5AD8
	ldr r2, _080D5AC4 @ =0x0000034A
	adds r0, r6, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D5AD8
	ldr r0, _080D5AC8 @ =0x00000386
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D5ACC
	strb r2, [r1]
	ldr r0, [r6, #0x18]
	movs r1, #0xc7
	bl Sound_PlayForPlayer
	b _080D5AD8
	.align 2, 0
_080D5AC4: .4byte 0x0000034A
_080D5AC8: .4byte 0x00000386
_080D5ACC:
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x18]
	movs r1, #0xc8
	bl Sound_PlayForPlayer
_080D5AD8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
