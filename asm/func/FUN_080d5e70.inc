	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #8
	bl FUN_080cc3c4
	ldr r1, _080D5E94 @ =0x0000037D
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _080D5E98
	cmp r0, #1
	bne _080D5E92
	b _080D600E
_080D5E92:
	b _080D6130
	.align 2, 0
_080D5E94: .4byte 0x0000037D
_080D5E98:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D5ED0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D5EC8 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _080D5ECC @ =0x000002E7
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _080D5EE0
	.align 2, 0
_080D5EC8: .4byte 0x000002E6
_080D5ECC: .4byte 0x000002E7
_080D5ED0:
	lsrs r0, r1, #0x19
	ldr r2, _080D5F34 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _080D5F38 @ =0x000002E7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
_080D5EE0:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _080D5F34 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl AuxAnim_SetAnim
	adds r5, r7, #0
	adds r5, #0xe8
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
	beq _080D5F3C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5F44
	.align 2, 0
_080D5F34: .4byte 0x000002E6
_080D5F38: .4byte 0x000002E7
_080D5F3C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5F44:
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
	beq _080D5F68
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5F70
_080D5F68:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5F70:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5FA8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5FE0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5FAC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5FA0
	ldrb r0, [r4, #5]
_080D5FA0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5FBC
	.align 2, 0
_080D5FA8: .4byte 0x0000FFFF
_080D5FAC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5FBC
	strh r1, [r4, #8]
_080D5FBC:
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
	bne _080D5FE0
	movs r0, #1
	strb r0, [r4, #7]
_080D5FE0:
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bhi _080D6008
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r7, #0x18]
	movs r1, #0xd8
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
	ldr r2, _080D6004 @ =0x0000037D
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	b _080D6130
	.align 2, 0
_080D6004: .4byte 0x0000037D
_080D6008:
	subs r0, #0x1e
	strh r0, [r1]
	b _080D6130
_080D600E:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _080D6064 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl AuxAnim_SetAnim
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _080D6068
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D6070
	.align 2, 0
_080D6064: .4byte 0x000002E6
_080D6068:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D6070:
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
	beq _080D6094
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D609C
_080D6094:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D609C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D60D4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D611A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D60DE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D60D8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080D60F4
	.align 2, 0
_080D60D4: .4byte 0x0000FFFF
_080D60D8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D60F2
_080D60DE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D60F2
	strh r1, [r4, #8]
	movs r2, #1
	b _080D60F4
_080D60F2:
	movs r2, #0
_080D60F4:
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
	bne _080D611C
	movs r0, #1
	strb r0, [r4, #7]
	b _080D611C
_080D611A:
	movs r2, #0
_080D611C:
	cmp r2, #0
	beq _080D6130
	adds r0, r7, #0
	bl PlayerLink_SetAnimFacing
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D6130:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
