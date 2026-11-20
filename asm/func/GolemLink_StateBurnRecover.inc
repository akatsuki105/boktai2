	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081C18C0 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C18C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C18C6
	.align 2, 0
_081C18C0: .4byte 0x0000046D
_081C18C4:
	movs r0, #0
_081C18C6:
	cmp r0, #0
	beq _081C18F6
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _081C196C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081C1970 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r5, _081C1974 @ =0x00000202
	adds r0, r6, r5
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #7
	bl Enemy_PlayAnim
_081C18F6:
	cmp r4, #0x3b
	bgt _081C1908
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #8]
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
_081C1908:
	ldr r7, _081C1978 @ =0x0000046E
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C1914
	b _081C1B40
_081C1914:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _081C197C @ =0x0000046B
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r5, [r0]
	adds r2, r6, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C1966
	cmp r1, #0
	blt _081C1966
	ldr r0, _081C1980 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C1966
	ldr r0, _081C1984 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C1988
_081C1966:
	movs r4, #0
	b _081C1996
	.align 2, 0
_081C196C: .4byte 0xFFFEBE3F
_081C1970: .4byte 0x0000021E
_081C1974: .4byte 0x00000202
_081C1978: .4byte 0x0000046E
_081C197C: .4byte 0x0000046B
_081C1980: .4byte 0x030046A8
_081C1984: .4byte 0x030046AC
_081C1988:
	ldr r0, _081C19A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C1996:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C19AC
	adds r0, #4
	b _081C19B8
	.align 2, 0
_081C19A8: .4byte 0x030046A4
_081C19AC:
	ldr r0, _081C19CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C19B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C19D0
	cmp r2, #2
	beq _081C19D4
	b _081C19D8
	.align 2, 0
_081C19CC: .4byte 0x030046A4
_081C19D0:
	ldrb r0, [r5, #4]
	b _081C19D6
_081C19D4:
	ldrb r0, [r5]
_081C19D6:
	subs r1, r1, r0
_081C19D8:
	strh r1, [r5, #2]
	ldr r5, _081C1A04 @ =0x000004A4
	adds r0, r6, r5
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C1A08
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	b _081C1A2E
	.align 2, 0
_081C1A04: .4byte 0x000004A4
_081C1A08:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C1A28
	cmp r0, #2
	beq _081C1A24
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C1A24:
	movs r0, #1
	b _081C1A38
_081C1A28:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
_081C1A2E:
	ldr r1, _081C1A8C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081C1A38:
	adds r4, r0, #0
	cmp r4, #0
	bne _081C1AAC
	ldr r1, _081C1A90 @ =Enemy_ClearStateBegun
	ldr r5, _081C1A94 @ =0x0000046D
	adds r0, r6, r5
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081C1A98 @ =0x0000046B
	adds r0, r6, r7
	strb r4, [r0]
	ldr r2, _081C1A9C @ =0x00000553
	adds r0, r6, r2
	strb r4, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r6, r5
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _081C1AA0 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081C1AA4 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C1AA8 @ =0x00000484
	adds r0, r6, r2
	str r4, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r3, [r0]
	b _081C1B40
	.align 2, 0
_081C1A8C: .4byte 0xFFFFFDFF
_081C1A90: .4byte Enemy_ClearStateBegun
_081C1A94: .4byte 0x0000046D
_081C1A98: .4byte 0x0000046B
_081C1A9C: .4byte 0x00000553
_081C1AA0: .4byte 0x00000469
_081C1AA4: .4byte 0x0000046A
_081C1AA8: .4byte 0x00000484
_081C1AAC:
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r1, [r0]
	movs r4, #0
	movs r5, #0
	movs r3, #1
	movs r0, #1
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r1, [r0]
	subs r7, #0x3f
	adds r0, r6, r7
	strb r3, [r0]
	ldr r1, _081C1B48 @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r6, r2
	str r5, [r0]
	adds r7, #3
	adds r0, r6, r7
	strb r3, [r0]
	ldr r2, _081C1B4C @ =Enemy_WaitPendingState
	movs r1, #0xe
	adds r7, #1
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _081C1B50 @ =0x0000046B
	adds r0, r6, r3
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	adds r7, #5
	adds r2, r6, r7
	subs r7, #4
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _081C1B54 @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _081C1B58 @ =0x00000552
	adds r0, r6, r3
	strb r5, [r0]
_081C1B40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1B48: .4byte 0x0000046A
_081C1B4C: .4byte Enemy_WaitPendingState
_081C1B50: .4byte 0x0000046B
_081C1B54: .4byte 0x00000551
_081C1B58: .4byte 0x00000552
