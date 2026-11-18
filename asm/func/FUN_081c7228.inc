	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _081C72DC @ =0x082522DC
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, #0
	bl Enemy_ClearPendingState
	ldr r2, _081C72E0 @ =0x000006D7
	adds r6, r4, r2
	ldrb r0, [r6]
	cmp r0, #3
	bls _081C724C
	b _081C7450
_081C724C:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _081C726C
	adds r0, r5, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C72F4
_081C726C:
	ldrb r0, [r6]
	cmp r0, #3
	bhi _081C72F4
	ldrb r1, [r5, #5]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl DogLink_PickWalkDest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C7290
	b _081C749C
_081C7290:
	ldr r2, _081C72E4 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r6, _081C72E8 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x11
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C72EC @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081C72F0 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _081C749C
	.align 2, 0
_081C72DC: .4byte 0x082522DC
_081C72E0: .4byte 0x000006D7
_081C72E4: .4byte Enemy_ClearStateBegun
_081C72E8: .4byte 0x0000046D
_081C72EC: .4byte 0x0000046A
_081C72F0: .4byte 0x00000484
_081C72F4:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _081C733C @ =0x000006BC
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _081C7308
	b _081C7450
_081C7308:
	ldr r3, _081C7340 @ =0x00000553
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _081C7314
	b _081C749C
_081C7314:
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	ldr r1, _081C7344 @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xc
	cmp r0, r1
	bne _081C732A
	b _081C749C
_081C732A:
	ldr r0, _081C7348 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C734C
	movs r0, #1
	b _081C734E
	.align 2, 0
_081C733C: .4byte 0x000006BC
_081C7340: .4byte 0x00000553
_081C7344: .4byte 0x00FFFFFF
_081C7348: .4byte 0x030047A4
_081C734C:
	movs r0, #0
_081C734E:
	cmp r0, #0
	beq _081C7362
	adds r0, r5, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C7360
	b _081C749C
_081C7360:
	b _081C7370
_081C7362:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _081C739C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_081C7370:
	ldr r1, _081C73A0 @ =0x000004A4
	adds r0, r5, r1
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C73A4
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _081C73CA
	.align 2, 0
_081C739C: .4byte 0x03002BE0
_081C73A0: .4byte 0x000004A4
_081C73A4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C73C4
	cmp r0, #2
	beq _081C73C0
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C73C0:
	movs r0, #1
	b _081C73D4
_081C73C4:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_081C73CA:
	ldr r1, _081C73E8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081C73D4:
	cmp r0, #0
	bne _081C73F0
	ldr r1, _081C73EC @ =0x000005C4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _081C749C
	.align 2, 0
_081C73E8: .4byte 0xFFFFFDFF
_081C73EC: .4byte 0x000005C4
_081C73F0:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081C7444 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C7448 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081C744C @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _081C749C
	.align 2, 0
_081C7444: .4byte 0x0000046D
_081C7448: .4byte 0x0000046A
_081C744C: .4byte 0x00000484
_081C7450:
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _081C74A4 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081C74A8 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _081C74AC @ =FUN_081ca14c
	movs r2, #0x2a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C74B0 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
_081C749C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C74A4: .4byte 0x00000469
_081C74A8: .4byte 0x0000046A
_081C74AC: .4byte FUN_081ca14c
_081C74B0: .4byte 0x0000046B
