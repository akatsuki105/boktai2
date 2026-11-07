	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _0814B5B4 @ =0x082520E4
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, #0
	bl Enemy_ClearPendingState
	ldr r2, _0814B5B8 @ =0x000006D7
	adds r6, r4, r2
	ldrb r0, [r6]
	cmp r0, #3
	bls _0814B524
	b _0814B728
_0814B524:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0814B544
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B5CC
_0814B544:
	ldrb r0, [r6]
	cmp r0, #3
	bhi _0814B5CC
	ldrb r1, [r5, #5]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl FUN_0814b090
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B568
	b _0814B774
_0814B568:
	ldr r2, _0814B5BC @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r6, _0814B5C0 @ =0x0000046D
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
	ldr r1, _0814B5C4 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0814B5C8 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _0814B774
	.align 2, 0
_0814B5B4: .4byte 0x082520E4
_0814B5B8: .4byte 0x000006D7
_0814B5BC: .4byte Enemy_ClearStateBegun
_0814B5C0: .4byte 0x0000046D
_0814B5C4: .4byte 0x0000046A
_0814B5C8: .4byte 0x00000484
_0814B5CC:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _0814B614 @ =0x000006BC
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0814B5E0
	b _0814B728
_0814B5E0:
	ldr r3, _0814B618 @ =0x00000553
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _0814B5EC
	b _0814B774
_0814B5EC:
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	ldr r1, _0814B61C @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xc
	cmp r0, r1
	bne _0814B602
	b _0814B774
_0814B602:
	ldr r0, _0814B620 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814B624
	movs r0, #1
	b _0814B626
	.align 2, 0
_0814B614: .4byte 0x000006BC
_0814B618: .4byte 0x00000553
_0814B61C: .4byte 0x00FFFFFF
_0814B620: .4byte 0x030047A4
_0814B624:
	movs r0, #0
_0814B626:
	cmp r0, #0
	beq _0814B63A
	adds r0, r5, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B638
	b _0814B774
_0814B638:
	b _0814B648
_0814B63A:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0814B674 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_0814B648:
	ldr r1, _0814B678 @ =0x000004A4
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
	bne _0814B67C
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _0814B6A2
	.align 2, 0
_0814B674: .4byte 0x03002BE0
_0814B678: .4byte 0x000004A4
_0814B67C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814B69C
	cmp r0, #2
	beq _0814B698
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814B698:
	movs r0, #1
	b _0814B6AC
_0814B69C:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_0814B6A2:
	ldr r1, _0814B6C0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814B6AC:
	cmp r0, #0
	bne _0814B6C8
	ldr r1, _0814B6C4 @ =0x000005C4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _0814B774
	.align 2, 0
_0814B6C0: .4byte 0xFFFFFDFF
_0814B6C4: .4byte 0x000005C4
_0814B6C8:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0814B71C @ =0x0000046D
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
	ldr r1, _0814B720 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0814B724 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _0814B774
	.align 2, 0
_0814B71C: .4byte 0x0000046D
_0814B720: .4byte 0x0000046A
_0814B724: .4byte 0x00000484
_0814B728:
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _0814B77C @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _0814B780 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _0814B784 @ =FUN_0814e424
	movs r2, #0x2a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814B788 @ =0x0000046B
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
_0814B774:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814B77C: .4byte 0x00000469
_0814B780: .4byte 0x0000046A
_0814B784: .4byte FUN_0814e424
_0814B788: .4byte 0x0000046B
