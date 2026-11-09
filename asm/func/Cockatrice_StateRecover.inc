	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, _08153B0C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153B10
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08153B12
	.align 2, 0
_08153B0C: .4byte 0x0000046D
_08153B10:
	movs r0, #0
_08153B12:
	cmp r0, #0
	beq _08153B30
	ldr r1, _08153B98 @ =0x000001DD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #3
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	subs r0, #0x40
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
_08153B30:
	cmp r4, #0x3c
	bgt _08153B36
	b _08153D7A
_08153B36:
	ldr r2, _08153B9C @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153B42
	b _08153D7A
_08153B42:
	ldr r3, _08153BA0 @ =0x0000046B
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	ldr r5, _08153BA4 @ =0x000001DF
	adds r0, r7, r5
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r5, [r0]
	adds r2, r7, #0
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
	blt _08153B92
	cmp r1, #0
	blt _08153B92
	ldr r0, _08153BA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08153B92
	ldr r0, _08153BAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08153BB0
_08153B92:
	movs r4, #0
	b _08153BBE
	.align 2, 0
_08153B98: .4byte 0x000001DD
_08153B9C: .4byte 0x0000046E
_08153BA0: .4byte 0x0000046B
_08153BA4: .4byte 0x000001DF
_08153BA8: .4byte 0x030046A8
_08153BAC: .4byte 0x030046AC
_08153BB0:
	ldr r0, _08153BD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08153BBE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08153BD4
	adds r0, #4
	b _08153BE0
	.align 2, 0
_08153BD0: .4byte 0x030046A4
_08153BD4:
	ldr r0, _08153BF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08153BE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08153BF8
	cmp r2, #2
	beq _08153BFC
	b _08153C00
	.align 2, 0
_08153BF4: .4byte 0x030046A4
_08153BF8:
	ldrb r0, [r5, #4]
	b _08153BFE
_08153BFC:
	ldrb r0, [r5]
_08153BFE:
	subs r1, r1, r0
_08153C00:
	strh r1, [r5, #2]
	ldr r1, _08153C2C @ =0x000004A4
	adds r0, r7, r1
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08153C30
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	b _08153C56
	.align 2, 0
_08153C2C: .4byte 0x000004A4
_08153C30:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08153C50
	cmp r0, #2
	beq _08153C4C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08153C4C:
	movs r0, #1
	b _08153C60
_08153C50:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
_08153C56:
	ldr r1, _08153CB0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08153C60:
	adds r4, r0, #0
	cmp r4, #0
	bne _08153CD0
	ldr r1, _08153CB4 @ =Enemy_ClearStateBegun
	ldr r6, _08153CB8 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	strb r3, [r0]
	ldr r2, _08153CBC @ =0x0000046B
	adds r0, r7, r2
	strb r4, [r0]
	ldr r5, _08153CC0 @ =0x00000553
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08153CC4 @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08153CC8 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08153CCC @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	b _08153D7A
	.align 2, 0
_08153CB0: .4byte 0xFFFFFDFF
_08153CB4: .4byte Enemy_ClearStateBegun
_08153CB8: .4byte 0x0000046D
_08153CBC: .4byte 0x0000046B
_08153CC0: .4byte 0x00000553
_08153CC4: .4byte 0x00000469
_08153CC8: .4byte 0x0000046A
_08153CCC: .4byte 0x00000484
_08153CD0:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	movs r4, #0
	movs r5, #0
	movs r2, #1
	movs r6, #1
	strh r6, [r0, #6]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _08153D80 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _08153D84 @ =Enemy_WaitPendingState
	mov ip, r0
	movs r1, #0xe
	adds r3, #1
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _08153D88 @ =0x0000046B
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, ip
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r2, #0x81
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r2, _08153D8C @ =0x00000482
	adds r0, r7, r2
	strh r6, [r0]
	movs r2, #0x10
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08153D90 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08153D94 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
_08153D7A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08153D80: .4byte 0x00000469
_08153D84: .4byte Enemy_WaitPendingState
_08153D88: .4byte 0x0000046B
_08153D8C: .4byte 0x00000482
_08153D90: .4byte 0x00000551
_08153D94: .4byte 0x00000552
