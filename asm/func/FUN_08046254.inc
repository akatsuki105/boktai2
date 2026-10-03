	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r3, r0, #0
	adds r5, r1, #0
	ldrb r1, [r5, #5]
	cmp r1, #0
	beq _08046324
	movs r6, #0
	strb r6, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _080462B8 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r4, r5, #0
	adds r4, #0xa4
	lsls r0, r0, #5
	adds r7, r0, r3
	ldr r0, _080462BC @ =0x0000192C
	adds r7, r7, r0
	ldrh r3, [r1]
	movs r2, #1
	mov ip, r2
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r5, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080462C0
	movs r0, #8
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x2d
	mov r2, ip
	strb r2, [r0]
	b _080462CC
	.align 2, 0
_080462B8: .4byte 0x085AB404
_080462BC: .4byte 0x0000192C
_080462C0:
	adds r1, r5, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0x2d
	strb r6, [r0]
_080462CC:
	adds r6, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r0, [r6]
	cmp r0, #0
	beq _080462F2
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _080462FA
_080462F2:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080462FA:
	str r0, [r4, #8]
	movs r2, #0
	movs r0, #1
	strb r0, [r5, #8]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x60
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	adds r1, r0, #0
	str r1, [r4]
_08046324:
	ldr r1, [r5, #0x10]
	cmp r1, #7
	bls _08046336
	movs r1, #5
	movs r2, #0
	strb r1, [r5, #4]
	movs r1, #1
	strb r1, [r5, #5]
	str r2, [r5, #0x10]
_08046336:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
