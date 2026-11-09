	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r1, #0
	adds r3, r2, #0
	adds r5, r4, #0
	adds r5, #8
	mov r1, sp
	adds r2, r5, #0
	bl Skeleton_PickFarPathNode
	ldr r1, _0810749C @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081074A0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	b _081074C6
	.align 2, 0
_0810749C: .4byte 0x000004A4
_081074A0:
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081074C0
	cmp r0, #2
	beq _081074BC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081074BC:
	movs r0, #1
	b _081074D0
_081074C0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_081074C6:
	ldr r1, _081074E4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081074D0:
	cmp r0, #0
	bne _081074EC
	ldr r1, _081074E8 @ =0x000005C4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _081075CA
	.align 2, 0
_081074E4: .4byte 0xFFFFFDFF
_081074E8: .4byte 0x000005C4
_081074EC:
	ldr r2, _08107558 @ =0x00000714
	adds r1, r7, r2
	movs r5, #0
	movs r7, #0
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _0810755C @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08107560 @ =0x0000046D
	adds r0, r4, r3
	movs r6, #1
	strb r6, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r7, [r0]
	subs r3, #0xaf
	adds r0, r4, r3
	ldr r2, [r0]
	movs r1, #0x1c
	ldrsh r0, [r2, r1]
	movs r3, #8
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r2, r3]
	movs r3, #0xc
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r0, #0
	ldrb r0, [r4, #5]
	subs r0, r1, r0
	cmp r0, #0
	bge _0810754C
	rsbs r0, r0, #0
_0810754C:
	cmp r0, #0x1f
	ble _081075A8
	cmp r1, #0
	blt _08107564
	asrs r0, r1, #5
	b _0810756A
	.align 2, 0
_08107558: .4byte 0x00000714
_0810755C: .4byte Enemy_ClearStateBegun
_08107560: .4byte 0x0000046D
_08107564:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0810756A:
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	movs r1, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081075A0 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _081075A4 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _081075CA
	.align 2, 0
_081075A0: .4byte 0x00000484
_081075A4: .4byte 0x0000046C
_081075A8:
	movs r1, #0x12
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	ldr r2, _081075D4 @ =0x00000469
	adds r0, r4, r2
	strb r5, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081075D8 @ =0x00000484
	adds r0, r4, r1
	str r7, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r6, [r0]
_081075CA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081075D4: .4byte 0x00000469
_081075D8: .4byte 0x00000484
