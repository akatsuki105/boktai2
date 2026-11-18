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
	beq _081B2FA0
	b _081B31F0
_081B2FA0:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _081B3068 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081B306C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _081B3070 @ =Enemy_WaitPendingState
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081B3074 @ =0x0000046B
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
	beq _081B308C
	ldr r4, _081B3078 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0xc
	mov r8, r2
	movs r1, #0x1e
	adds r4, #0xd6
	adds r2, r5, r4
	subs r4, #4
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081B307C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B3080 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	movs r0, #4
	ldr r7, _081B3084 @ =0x00000222
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r6]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _081B30D0
	ldr r3, _081B3088 @ =0x0000024E
	adds r2, r5, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	adds r7, #0x2a
	adds r1, r5, r7
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081B30D0
	strh r1, [r2]
	b _081B30D0
	.align 2, 0
_081B3068: .4byte 0x00000469
_081B306C: .4byte 0x0000046A
_081B3070: .4byte Enemy_WaitPendingState
_081B3074: .4byte 0x0000046B
_081B3078: .4byte 0x00000482
_081B307C: .4byte 0x00000551
_081B3080: .4byte 0x00000552
_081B3084: .4byte 0x00000222
_081B3088: .4byte 0x0000024E
_081B308C:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081B310C @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
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
	ldr r2, _081B3110 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B3114 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_081B30D0:
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
	blt _081B3108
	cmp r1, #0
	blt _081B3108
	ldr r0, _081B3118 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B3108
	ldr r0, _081B311C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B3120
_081B3108:
	movs r4, #0
	b _081B312E
	.align 2, 0
_081B310C: .4byte 0x00000482
_081B3110: .4byte 0x00000551
_081B3114: .4byte 0x00000552
_081B3118: .4byte 0x030046A8
_081B311C: .4byte 0x030046AC
_081B3120:
	ldr r0, _081B3140 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B312E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B3144
	adds r0, #4
	b _081B3150
	.align 2, 0
_081B3140: .4byte 0x030046A4
_081B3144:
	ldr r0, _081B3164 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B3150:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B3168
	cmp r3, #2
	beq _081B316C
	b _081B3170
	.align 2, 0
_081B3164: .4byte 0x030046A4
_081B3168:
	ldrb r0, [r6, #4]
	b _081B316E
_081B316C:
	ldrb r0, [r6]
_081B316E:
	subs r2, r2, r0
_081B3170:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _081B31AC @ =0x000004A4
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
	bne _081B31B0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081B31D6
	.align 2, 0
_081B31AC: .4byte 0x000004A4
_081B31B0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B31D0
	cmp r0, #2
	beq _081B31CC
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B31CC:
	movs r0, #1
	b _081B31E0
_081B31D0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_081B31D6:
	ldr r1, _081B31FC @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081B31E0:
	cmp r0, #0
	bne _081B31F0
	ldr r4, _081B3200 @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_081B31F0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B31FC: .4byte 0xFFFFFDFF
_081B3200: .4byte 0x000005C4
