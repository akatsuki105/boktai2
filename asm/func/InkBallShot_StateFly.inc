	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0xfe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0820312E
	adds r4, r7, #0
	adds r4, #0xdc
	adds r5, r7, #0
	adds r5, #0xe4
	movs r1, #0x1c
	adds r1, r1, r7
	mov sb, r1
	ldrh r0, [r5]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0xfc
	adds r3, r3, r7
	mov r8, r3
	ldrh r0, [r3]
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp, #4]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r5, [sp, #8]
	mov r5, r8
	cmp r6, #0
	bne _082030BC
	movs r1, #1
	rsbs r1, r1, #0
	b _082030F4
_082030BC:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #4]
	ldr r1, [sp, #4]
_082030F4:
	ldrh r0, [r5]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r1, r0
	bgt _08203110
	ldr r3, [sp, #8]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #1
	str r0, [sp]
	b _08203150
_08203110:
	ldrh r0, [r4]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r4, #2]
	mov r2, sb
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	mov r3, sb
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	b _08203150
_0820312E:
	adds r2, r7, #0
	adds r2, #0x1c
	adds r1, r7, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov sb, r2
_08203150:
	adds r4, r7, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08203180
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08203188
_08203180:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08203188:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082031AC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _082031B4
_082031AC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082031B4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _082031EC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08203224
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082031F0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082031E4
	ldrb r0, [r4, #5]
_082031E4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08203200
	.align 2, 0
_082031EC: .4byte 0x0000FFFF
_082031F0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08203200
	strh r1, [r4, #8]
_08203200:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _08203224
	movs r0, #1
	strb r0, [r4, #7]
_08203224:
	adds r4, r7, #0
	adds r4, #0x8c
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	subs r4, #0x50
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r1, r7, #0
	adds r1, #0xee
	ldrh r0, [r1]
	cmp r0, #0
	beq _0820325A
	subs r0, #1
	strh r0, [r1]
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _08203262
_0820325A:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
_08203262:
	strh r0, [r4, #6]
	adds r1, r7, #0
	adds r1, #0xfb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	subs r1, #0xf
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08203282
	movs r3, #1
	str r3, [sp]
_08203282:
	ldr r0, [sp]
	cmp r0, #0
	beq _08203290
	adds r0, r7, #0
	movs r1, #1
	bl InkBallShot_SetState
_08203290:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
