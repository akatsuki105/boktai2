	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bne _0806DD98
	ldr r2, _0806DE6C @ =0x0000037E
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806DDCE
_0806DD98:
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08063220
	adds r0, r6, #0
	bl FUN_08066e84
	ldr r0, _0806DE70 @ =0x0000039A
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0806DDCE:
	ldr r1, _0806DE6C @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _0806DDF6
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_08060c40
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_0806DDF6:
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r6, #0
	adds r0, #0xc2
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd0
	ldr r0, _0806DE74 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r3, #0xd4
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
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
	beq _0806DE78
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806DE80
	.align 2, 0
_0806DE6C: .4byte 0x0000037E
_0806DE70: .4byte 0x0000039A
_0806DE74: .4byte 0x03003584
_0806DE78:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806DE80:
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
	beq _0806DEA4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806DEAC
_0806DEA4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806DEAC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0806DEE4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806DF1C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806DEE8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806DEDC
	ldrb r0, [r4, #5]
_0806DEDC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806DEF8
	.align 2, 0
_0806DEE4: .4byte 0x0000FFFF
_0806DEE8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806DEF8
	strh r1, [r4, #8]
_0806DEF8:
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
	bne _0806DF1C
	movs r0, #1
	strb r0, [r4, #7]
_0806DF1C:
	ldr r3, _0806DF74 @ =0x0000095E
	adds r1, r6, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _0806DF78 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806DF42
	movs r0, #0x20
	strh r0, [r1]
_0806DF42:
	ldr r0, _0806DF7C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _0806DF6C
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0806DF80 @ =0x00000381
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DF6C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806DF74: .4byte 0x0000095E
_0806DF78: .4byte 0x0000FFFF
_0806DF7C: .4byte 0x0000037E
_0806DF80: .4byte 0x00000381
