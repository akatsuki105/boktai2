	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B2A2E
	subs r0, #1
	strh r0, [r1]
	b _080B2B60
_080B2A2E:
	ldr r0, [r5, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x18]
	adds r2, r5, #0
	adds r2, #0x6e
	ldrh r1, [r2]
	ldr r0, _080B2A94 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r0, #2
	strb r0, [r5, #0x1f]
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B2A98
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2AA0
	.align 2, 0
_080B2A94: .4byte 0x0000FFFB
_080B2A98:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2AA0:
	str r0, [r5, #0x18]
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
	beq _080B2AC4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2ACC
_080B2AC4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2ACC:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2B04 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2B4A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2B0E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2B08
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B2B24
	.align 2, 0
_080B2B04: .4byte 0x0000FFFF
_080B2B08:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2B22
_080B2B0E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2B22
	strh r1, [r4, #8]
	movs r2, #1
	b _080B2B24
_080B2B22:
	movs r2, #0
_080B2B24:
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
	bne _080B2B4C
	movs r0, #1
	strb r0, [r4, #7]
	b _080B2B4C
_080B2B4A:
	movs r2, #0
_080B2B4C:
	cmp r2, #0
	beq _080B2B60
	adds r0, r5, #0
	adds r0, #0x68
	bl Hitbox_Register
	adds r0, r5, #0
	movs r1, #2
	bl Generator_SetState
_080B2B60:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
