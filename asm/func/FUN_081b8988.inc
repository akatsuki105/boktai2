	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B89A8
	b _081B8C00
_081B89A8:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _081B8A74 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081B8A78 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _081B8A7C @ =Enemy_WaitPendingState
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081B8A80 @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r7, #0
	strh r4, [r0]
	movs r3, #0x80
	mov ip, r3
	ldrh r0, [r6]
	ands r0, r3
	cmp r0, #0
	beq _081B8A9C
	ldr r4, _081B8A84 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r0, #4
	ldr r1, _081B8A88 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r4, #0xc
	mov r8, r4
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r4, _081B8A8C @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081B8A90 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B8A94 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldrh r0, [r6]
	mov r6, ip
	ands r0, r6
	cmp r0, #0
	beq _081B8AE0
	ldr r7, _081B8A98 @ =0x0000024E
	adds r2, r5, r7
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081B8AE0
	strh r1, [r2]
	b _081B8AE0
	.align 2, 0
_081B8A74: .4byte 0x00000469
_081B8A78: .4byte 0x0000046A
_081B8A7C: .4byte Enemy_WaitPendingState
_081B8A80: .4byte 0x0000046B
_081B8A84: .4byte 0x00000482
_081B8A88: .4byte 0x00000222
_081B8A8C: .4byte 0x00000554
_081B8A90: .4byte 0x00000551
_081B8A94: .4byte 0x00000552
_081B8A98: .4byte 0x0000024E
_081B8A9C:
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081B8B1C @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081B8B20 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B8B24 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_081B8AE0:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B8B18
	cmp r1, #0
	blt _081B8B18
	ldr r0, _081B8B28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B8B18
	ldr r0, _081B8B2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B8B30
_081B8B18:
	movs r4, #0
	b _081B8B3E
	.align 2, 0
_081B8B1C: .4byte 0x00000482
_081B8B20: .4byte 0x00000551
_081B8B24: .4byte 0x00000552
_081B8B28: .4byte 0x030046A8
_081B8B2C: .4byte 0x030046AC
_081B8B30:
	ldr r0, _081B8B50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B8B3E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B8B54
	adds r0, #4
	b _081B8B60
	.align 2, 0
_081B8B50: .4byte 0x030046A4
_081B8B54:
	ldr r0, _081B8B74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B8B60:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B8B78
	cmp r3, #2
	beq _081B8B7C
	b _081B8B80
	.align 2, 0
_081B8B74: .4byte 0x030046A4
_081B8B78:
	ldrb r0, [r6, #4]
	b _081B8B7E
_081B8B7C:
	ldrb r0, [r6]
_081B8B7E:
	subs r2, r2, r0
_081B8B80:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _081B8BBC @ =0x000004A4
	adds r0, r5, r7
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B8BC0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081B8BE6
	.align 2, 0
_081B8BBC: .4byte 0x000004A4
_081B8BC0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B8BE0
	cmp r0, #2
	beq _081B8BDC
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B8BDC:
	movs r0, #1
	b _081B8BF0
_081B8BE0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_081B8BE6:
	ldr r1, _081B8C0C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081B8BF0:
	cmp r0, #0
	bne _081B8C00
	ldr r4, _081B8C10 @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_081B8C00:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8C0C: .4byte 0xFFFFFDFF
_081B8C10: .4byte 0x000005C4
