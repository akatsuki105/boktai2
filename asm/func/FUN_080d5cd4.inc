	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080D5CF0
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0
	bl PlayerLink_SetAction
_080D5CF0:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080D5D44
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xfe
	ands r0, r1
	adds r0, #1
	strb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D5D34
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D5D2C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _080D5D30 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _080D5D42
	.align 2, 0
_080D5D2C: .4byte 0x000002E6
_080D5D30: .4byte 0x000002E7
_080D5D34:
	lsrs r1, r1, #0x19
	ldr r2, _080D5D98 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _080D5D9C @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_080D5D42:
	strb r0, [r1]
_080D5D44:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
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
	beq _080D5DA0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5DA8
	.align 2, 0
_080D5D98: .4byte 0x000002E6
_080D5D9C: .4byte 0x000002E7
_080D5DA0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5DA8:
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
	beq _080D5DCC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5DD4
_080D5DCC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5DD4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5E0C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5E44
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5E10
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5E04
	ldrb r0, [r4, #5]
_080D5E04:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5E20
	.align 2, 0
_080D5E0C: .4byte 0x0000FFFF
_080D5E10:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5E20
	strh r1, [r4, #8]
_080D5E20:
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
	bne _080D5E44
	movs r0, #1
	strb r0, [r4, #7]
_080D5E44:
	ldr r1, _080D5E6C @ =0x000003FF
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _080D5E62
	adds r0, r6, #0
	bl PlayerLink_SetAnimFacing
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D5E62:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5E6C: .4byte 0x000003FF
