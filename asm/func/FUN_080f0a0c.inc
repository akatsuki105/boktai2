	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080F0A84 @ =0x00001010
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F0A7E
	movs r0, #0x80
	lsls r0, r0, #0x11
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r2, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _080F0A7E
	movs r0, #0x80
	lsls r0, r0, #0xd
	ands r0, r2
	cmp r0, #0
	beq _080F0A7E
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	bne _080F0A7E
	movs r4, #0x97
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _080F0A64
	ldrb r1, [r0, #5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080F0A7E
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080F0A7E
_080F0A64:
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080F0A7E
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080f9a38
	adds r3, r0, #0
	cmp r3, #0
	bne _080F0A88
_080F0A7E:
	movs r0, #0
	b _080F0B1A
	.align 2, 0
_080F0A84: .4byte 0x00001010
_080F0A88:
	ldr r1, _080F0B20 @ =0xFFFEBE3F
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	ldr r2, _080F0B24 @ =0x0000021E
	adds r0, r6, r2
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	movs r4, #0x88
	lsls r4, r4, #2
	adds r0, r6, r4
	strh r2, [r0]
	ldr r1, _080F0B28 @ =0x00000202
	adds r0, r6, r1
	strh r2, [r0]
	movs r4, #0x97
	lsls r4, r4, #3
	adds r0, r6, r4
	str r3, [r0]
	ldr r0, _080F0B2C @ =FUN_080e48d0
	mov ip, r0
	movs r1, #0x10
	ldr r3, _080F0B30 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	subs r4, #0x4d
	adds r0, r6, r4
	strb r5, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r4, ip
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _080F0B34 @ =0x00000469
	adds r0, r6, r1
	strb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r5, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r2, [r0]
	ldr r2, _080F0B38 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #0x80
	lsls r0, r0, #4
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
_080F0B1A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080F0B20: .4byte 0xFFFEBE3F
_080F0B24: .4byte 0x0000021E
_080F0B28: .4byte 0x00000202
_080F0B2C: .4byte FUN_080e48d0
_080F0B30: .4byte 0x0000046D
_080F0B34: .4byte 0x00000469
_080F0B38: .4byte 0x0000046C
