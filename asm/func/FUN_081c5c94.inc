	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _081C5D20 @ =0x000006C2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r7, #0
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	beq _081C5D42
	ldr r3, _081C5D24 @ =0x000001DF
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081C5CD8
	movs r0, #4
	ldr r1, _081C5D28 @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081C5CD8:
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #0xce
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081C5D0C
	adds r0, r4, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C5D3A
_081C5D0C:
	movs r1, #8
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C5D2C
	movs r0, #1
	b _081C5D2E
	.align 2, 0
_081C5D20: .4byte 0x000006C2
_081C5D24: .4byte 0x000001DF
_081C5D28: .4byte 0x00000222
_081C5D2C:
	movs r0, #0
_081C5D2E:
	cmp r0, #0
	bne _081C5DAA
	adds r0, r4, #0
	bl FUN_081c7228
	b _081C5DAA
_081C5D3A:
	adds r0, r4, #0
	bl FUN_081c6048
	b _081C5D9A
_081C5D42:
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r6, r3
	movs r1, #0xd
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	ldr r2, _081C5DB0 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _081C5DB4 @ =0x0000046A
	adds r0, r4, r3
	strb r7, [r0]
	adds r6, #0x1c
	adds r0, r4, r6
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _081C5DB8 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081C5DBC @ =0x0000046B
	adds r0, r4, r1
	strb r7, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_081C5D9A:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C5DAA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C5DB0: .4byte 0x00000469
_081C5DB4: .4byte 0x0000046A
_081C5DB8: .4byte Enemy_ClearStateBegun
_081C5DBC: .4byte 0x0000046B
