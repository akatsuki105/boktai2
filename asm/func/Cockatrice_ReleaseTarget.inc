	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x97
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	bl EnemyTargetManager_Release
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r6, r5
	ldr r1, _0815C6E0 @ =0xFFFFEFFF
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _0815C6FC
	movs r1, #2
	movs r7, #0xe0
	lsls r7, r7, #3
	adds r0, r4, r7
	ldr r0, [r0]
	ands r0, r1
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r2, _0815C6E4 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0815C6E8 @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	ldr r7, _0815C6EC @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r6, r5
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r5, _0815C6F0 @ =0x00000469
	adds r0, r6, r5
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r1, _0815C6F4 @ =0x00000484
	adds r0, r6, r1
	str r2, [r0]
	ldr r2, _0815C6F8 @ =0x0000046C
	adds r0, r6, r2
	strb r4, [r0]
	adds r5, #0x19
	adds r1, r6, r5
	movs r0, #2
	strh r0, [r1]
	b _0815C812
	.align 2, 0
_0815C6E0: .4byte 0xFFFFEFFF
_0815C6E4: .4byte 0x0000046D
_0815C6E8: .4byte 0x0000046B
_0815C6EC: .4byte 0x00000553
_0815C6F0: .4byte 0x00000469
_0815C6F4: .4byte 0x00000484
_0815C6F8: .4byte 0x0000046C
_0815C6FC:
	movs r1, #3
	movs r2, #1
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0815C738 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r5, _0815C73C @ =0x0000046A
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
	adds r7, #0x1c
	adds r0, r6, r7
	str r3, [r0]
	ldr r1, _0815C740 @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #2
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815C744
	movs r0, #1
	b _0815C746
	.align 2, 0
_0815C738: .4byte 0x00000469
_0815C73C: .4byte 0x0000046A
_0815C740: .4byte 0x0000046C
_0815C744:
	movs r0, #0
_0815C746:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815C7A8
	adds r0, r6, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	ldr r4, _0815C790 @ =FUN_080e6834
	movs r3, #0xe
	ldr r5, _0815C794 @ =0x0000046D
	adds r1, r6, r5
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r7, _0815C798 @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0815C79C @ =0x00000553
	adds r0, r6, r1
	strb r3, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r6, r5
	str r4, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r4, #0
	strh r2, [r0]
	ldr r3, _0815C7A0 @ =Cockatrice_StateFly
	movs r5, #0x11
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r7, _0815C7A4 @ =0x00000554
	b _0815C7EC
	.align 2, 0
_0815C790: .4byte FUN_080e6834
_0815C794: .4byte 0x0000046D
_0815C798: .4byte 0x0000046B
_0815C79C: .4byte 0x00000553
_0815C7A0: .4byte Cockatrice_StateFly
_0815C7A4: .4byte 0x00000554
_0815C7A8:
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, _0815C84C @ =Enemy_WaitPendingState
	movs r2, #0xe
	ldr r0, _0815C850 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815C854 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	ldr r7, _0815C858 @ =0x00000553
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r4, #0
	strh r5, [r0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	adds r7, #5
	adds r2, r6, r7
	subs r7, #4
_0815C7EC:
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815C85C @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_0815C812:
	mov r5, sp
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r5, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0815C846
	cmp r1, #0
	blt _0815C846
	ldr r0, _0815C860 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815C846
	ldr r0, _0815C864 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815C868
_0815C846:
	movs r4, #0
	b _0815C876
	.align 2, 0
_0815C84C: .4byte Enemy_WaitPendingState
_0815C850: .4byte 0x0000046D
_0815C854: .4byte 0x0000046B
_0815C858: .4byte 0x00000553
_0815C85C: .4byte 0x00000551
_0815C860: .4byte 0x030046A8
_0815C864: .4byte 0x030046AC
_0815C868:
	ldr r0, _0815C888 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815C876:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815C88C
	adds r0, #4
	b _0815C898
	.align 2, 0
_0815C888: .4byte 0x030046A4
_0815C88C:
	ldr r0, _0815C8AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815C898:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815C8B0
	cmp r2, #2
	beq _0815C8B4
	b _0815C8B8
	.align 2, 0
_0815C8AC: .4byte 0x030046A4
_0815C8B0:
	ldrb r0, [r5, #4]
	b _0815C8B6
_0815C8B4:
	ldrb r0, [r5]
_0815C8B6:
	subs r1, r1, r0
_0815C8B8:
	strh r1, [r5, #2]
	ldrh r1, [r6, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r2, _0815C8E0 @ =0x000004A4
	adds r0, r6, r2
	ldr r4, [r0]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815C8E4
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r6, r5
	b _0815C90A
	.align 2, 0
_0815C8E0: .4byte 0x000004A4
_0815C8E4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815C904
	cmp r0, #2
	beq _0815C900
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815C900:
	movs r0, #1
	b _0815C914
_0815C904:
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r6, r7
_0815C90A:
	ldr r1, _0815C92C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815C914:
	cmp r0, #0
	bne _0815C924
	ldr r1, _0815C930 @ =0x000005C4
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0815C924:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815C92C: .4byte 0xFFFFFDFF
_0815C930: .4byte 0x000005C4
