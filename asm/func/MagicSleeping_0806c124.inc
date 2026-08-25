	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _0806C156
	bl GetPlayerCoffinID
	ldr r2, _0806C1D8 @ =0x00000387
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_08063220
	adds r0, r6, #0
	bl FUN_08066e84
	adds r0, r6, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
_0806C156:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_08060c40
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	adds r2, #0x33
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, #0x18
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
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
	beq _0806C1DC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806C1E4
	.align 2, 0
_0806C1D8: .4byte 0x00000387
_0806C1DC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806C1E4:
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
	beq _0806C208
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806C210
_0806C208:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806C210:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806C248 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806C280
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806C24C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806C240
	ldrb r0, [r4, #5]
_0806C240:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806C25C
	.align 2, 0
_0806C248: .4byte 0x0000FFFF
_0806C24C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806C25C
	strh r1, [r4, #8]
_0806C25C:
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
	bne _0806C280
	movs r0, #1
	strb r0, [r4, #7]
_0806C280:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _0806C2CC @ =0x00000387
	adds r1, r6, r2
	ldrb r1, [r1]
	ldr r2, _0806C2D0 @ =0x00000207
	adds r1, r1, r2
	bl FUN_0822b20c
	ldr r0, _0806C2D4 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0806C2C4
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0806C2D8 @ =0x00000381
	adds r1, r6, r0
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
_0806C2C4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C2CC: .4byte 0x00000387
_0806C2D0: .4byte 0x00000207
_0806C2D4: .4byte 0x0000037E
_0806C2D8: .4byte 0x00000381
