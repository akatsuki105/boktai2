	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A0A54 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0A58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A0A5A
	.align 2, 0
_081A0A54: .4byte 0x0000046C
_081A0A58:
	movs r0, #0
_081A0A5A:
	cmp r0, #0
	beq _081A0ACC
	ldr r3, _081A0B28 @ =FUN_0819bfa8
	movs r2, #0x26
	ldr r4, _081A0B2C @ =0x0000046D
	adds r0, r6, r4
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081A0B30 @ =0x0000046B
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r0, _081A0B34 @ =0x00000E48
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0B38 @ =0x00000EB8
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _081A0B3C @ =0x000008DC
	adds r1, r5, r3
	adds r0, r6, #0
	movs r2, #0xf8
	bl FUN_0819ee40
	ldr r7, _081A0B40 @ =0x00000ECC
	adds r0, r5, r7
	strb r4, [r0]
	ldr r0, _081A0B44 @ =0x0000016F
	bl PlaySound_082406e0
_081A0ACC:
	ldr r1, _081A0B30 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0B5C
	ldr r2, _081A0B48 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r3, _081A0B2C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081A0B30 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081A0B4C @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #7
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A0B50 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081A0B54 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081A0B58 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081A0B66
	.align 2, 0
_081A0B28: .4byte FUN_0819bfa8
_081A0B2C: .4byte 0x0000046D
_081A0B30: .4byte 0x0000046B
_081A0B34: .4byte 0x00000E48
_081A0B38: .4byte 0x00000EB8
_081A0B3C: .4byte 0x000008DC
_081A0B40: .4byte 0x00000ECC
_081A0B44: .4byte 0x0000016F
_081A0B48: .4byte FUN_0819bd2c
_081A0B4C: .4byte 0x00000553
_081A0B50: .4byte 0x00000469
_081A0B54: .4byte 0x0000046A
_081A0B58: .4byte 0x00000484
_081A0B5C:
	ldr r0, _081A0B6C @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0B66:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0B6C: .4byte 0x00000484
