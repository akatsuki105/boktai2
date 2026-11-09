	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815CD9E
	ldr r5, _0815CD84 @ =0x000001DF
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #2
	beq _0815CD44
	movs r0, #4
	ldr r7, _0815CD88 @ =0x00000222
	adds r2, r4, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0815CD44:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0x93
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r7, _0815CD8C @ =0x0000024E
	adds r0, r4, r7
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0815CE1C
	movs r2, #8
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0815CD90
	movs r0, #1
	b _0815CD92
	.align 2, 0
_0815CD84: .4byte 0x000001DF
_0815CD88: .4byte 0x00000222
_0815CD8C: .4byte 0x0000024E
_0815CD90:
	movs r0, #0
_0815CD92:
	cmp r0, #0
	bne _0815CE1C
	adds r0, r4, #0
	bl Cockatrice_ChooseAttack
	b _0815CE04
_0815CD9E:
	movs r2, #8
	movs r5, #0xe0
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0815CDB4
	movs r0, #1
	b _0815CDB6
_0815CDB4:
	movs r0, #0
_0815CDB6:
	adds r5, r0, #0
	cmp r5, #0
	bne _0815CE1C
	movs r1, #1
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	strb r5, [r0]
	ldr r2, _0815CE24 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r5, [r0]
	adds r2, #0x1b
	adds r0, r4, r2
	str r5, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r1, [r0]
	ldr r3, _0815CE28 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0815CE2C @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r7, #0xe6
	adds r0, r4, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_0815CE04:
	ldr r1, _0815CE30 @ =0xFFF7FFFF
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r4, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0815CE1C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815CE24: .4byte 0x00000469
_0815CE28: .4byte Enemy_ClearStateBegun
_0815CE2C: .4byte 0x0000046B
_0815CE30: .4byte 0xFFF7FFFF
