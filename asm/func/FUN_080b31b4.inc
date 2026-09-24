	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
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
	beq _080B3204
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B320C
_080B3204:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B320C:
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
	beq _080B3230
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B3238
_080B3230:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B3238:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3270 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B32A8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3274
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3268
	ldrb r0, [r4, #5]
_080B3268:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3284
	.align 2, 0
_080B3270: .4byte 0x0000FFFF
_080B3274:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3284
	strh r1, [r4, #8]
_080B3284:
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
	bne _080B32A8
	movs r0, #1
	strb r0, [r4, #7]
_080B32A8:
	adds r1, r5, #0
	adds r1, #0xde
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080B32D0
	adds r1, #0xf
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x64]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	adds r0, r5, #0
	movs r1, #2
	bl Generator_SetState
	b _080B32D6
_080B32D0:
	adds r0, r5, #0
	bl FUN_080b2888
_080B32D6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
