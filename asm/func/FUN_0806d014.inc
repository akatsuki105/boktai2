	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806D038
	ldr r2, _0806D0B8 @ =0x00000386
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08060b84
_0806D038:
	ldr r0, [r6, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x20]
	adds r0, r6, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_0806cfd4
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08060aa4
	adds r0, r6, #0
	bl FUN_080609dc
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0806D0BC @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
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
	beq _0806D0C0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D0C8
	.align 2, 0
_0806D0B8: .4byte 0x00000386
_0806D0BC: .4byte 0x000002E6
_0806D0C0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D0C8:
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
	beq _0806D0EC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D0F4
_0806D0EC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D0F4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D12C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D164
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D130
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D124
	ldrb r0, [r4, #5]
_0806D124:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D140
	.align 2, 0
_0806D12C: .4byte 0x0000FFFF
_0806D130:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D140
	strh r1, [r4, #8]
_0806D140:
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
	bne _0806D164
	movs r0, #1
	strb r0, [r4, #7]
_0806D164:
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _0806D222
	ldr r2, _0806D1A0 @ =0x0000034A
	adds r0, r6, r2
	ldrh r5, [r0]
	cmp r5, #0
	bne _0806D222
	adds r4, r6, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	adds r2, r0, #0
	cmp r2, #0
	beq _0806D1C8
	ldr r0, _0806D1A4 @ =0x00000386
	adds r1, r6, r0
	ldrb r2, [r1]
	cmp r2, #0
	beq _0806D1AC
	strb r5, [r1]
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0806D1A8 @ =0x00000163
	b _0806D1B8
	.align 2, 0
_0806D1A0: .4byte 0x0000034A
_0806D1A4: .4byte 0x00000386
_0806D1A8: .4byte 0x00000163
_0806D1AC:
	movs r0, #1
	strb r0, [r1]
	str r4, [sp]
	str r2, [sp, #4]
	movs r0, #0xb1
	lsls r0, r0, #1
_0806D1B8:
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _0806D222
_0806D1C8:
	ldr r0, _0806D1DC @ =0x00000386
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0806D1E0
	strb r2, [r1]
	movs r0, #0xc7
	bl PlaySound_082406e0
	b _0806D1EA
	.align 2, 0
_0806D1DC: .4byte 0x00000386
_0806D1E0:
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xc8
	bl PlaySound_082406e0
_0806D1EA:
	movs r1, #1
	ldr r0, _0806D200 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0806D204 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806D208
	movs r0, #1
	b _0806D20A
	.align 2, 0
_0806D200: .4byte 0x030046A0
_0806D204: .4byte 0x00000934
_0806D208:
	movs r0, #0
_0806D20A:
	cmp r0, #0
	beq _0806D222
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_0806D222:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
