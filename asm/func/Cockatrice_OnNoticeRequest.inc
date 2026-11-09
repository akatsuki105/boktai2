	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r3, [r0]
	subs r1, #0xcc
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815CE58
	b _0815D1F8
_0815CE58:
	movs r2, #8
	movs r5, #0xe0
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0815CE6E
	movs r0, #1
	b _0815CE70
_0815CE6E:
	movs r0, #0
_0815CE70:
	adds r7, r0, #0
	cmp r7, #0
	beq _0815CE78
	b _0815D1F8
_0815CE78:
	movs r0, #0x80
	mov sb, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	mov r3, sb
	ands r0, r3
	mov r8, r1
	cmp r0, #0
	beq _0815CF78
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, _0815CF58 @ =0x00000482
	adds r1, r6, r5
	movs r4, #0
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r3, [r0]
	movs r2, #0xc
	mov ip, r2
	movs r1, #0x1a
	adds r5, #0xd6
	adds r2, r6, r5
	subs r5, #4
	adds r0, r6, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815CF5C @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _0815CF60 @ =0x00000552
	adds r0, r6, r3
	mov r5, ip
	strb r5, [r0]
	ldr r3, _0815CF64 @ =Enemy_WaitPendingState
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0815CF68 @ =0x0000046B
	adds r0, r6, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r7, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0815CF6C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _0815CF70 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	adds r5, #0x1c
	adds r0, r6, r5
	str r7, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	movs r0, #4
	ldr r3, _0815CF74 @ =0x00000222
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r5, r8
	ldrh r0, [r5]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne _0815CF32
	b _0815D0DA
_0815CF32:
	adds r3, #0x2c
	adds r2, r6, r3
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bhi _0815CF52
	b _0815D0DA
_0815CF52:
	strh r1, [r2]
	b _0815D0DA
	.align 2, 0
_0815CF58: .4byte 0x00000482
_0815CF5C: .4byte 0x00000551
_0815CF60: .4byte 0x00000552
_0815CF64: .4byte Enemy_WaitPendingState
_0815CF68: .4byte 0x0000046B
_0815CF6C: .4byte 0x00000469
_0815CF70: .4byte 0x0000046A
_0815CF74: .4byte 0x00000222
_0815CF78:
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0815CF86
	movs r0, #1
	b _0815CF88
_0815CF86:
	movs r0, #0
_0815CF88:
	cmp r0, #0
	bne _0815CF8E
	b _0815D0B4
_0815CF8E:
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
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
	blt _0815CFC6
	cmp r1, #0
	blt _0815CFC6
	ldr r0, _0815CFCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815CFC6
	ldr r0, _0815CFD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815CFD4
_0815CFC6:
	movs r4, #0
	b _0815CFE2
	.align 2, 0
_0815CFCC: .4byte 0x030046A8
_0815CFD0: .4byte 0x030046AC
_0815CFD4:
	ldr r0, _0815CFF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815CFE2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815CFF8
	adds r0, #4
	b _0815D004
	.align 2, 0
_0815CFF4: .4byte 0x030046A4
_0815CFF8:
	ldr r0, _0815D018 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D004:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815D01C
	cmp r3, #2
	beq _0815D020
	b _0815D024
	.align 2, 0
_0815D018: .4byte 0x030046A4
_0815D01C:
	ldrb r0, [r5, #4]
	b _0815D022
_0815D020:
	ldrb r0, [r5]
_0815D022:
	subs r2, r2, r0
_0815D024:
	movs r1, #0
	strh r2, [r5, #2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r3, _0815D064 @ =0x000004A4
	adds r0, r6, r3
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815D06C
	ldr r0, _0815D068 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0815D096
	.align 2, 0
_0815D064: .4byte 0x000004A4
_0815D068: .4byte 0xFFFFFDFF
_0815D06C:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815D08C
	cmp r0, #2
	beq _0815D088
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815D088:
	movs r0, #1
	b _0815D098
_0815D08C:
	ldr r0, _0815D0AC @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0815D096:
	movs r0, #0
_0815D098:
	cmp r0, #0
	beq _0815D09E
	b _0815D1F8
_0815D09E:
	ldr r5, _0815D0B0 @ =0x000005C4
	adds r0, r6, r5
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _0815D1F8
	.align 2, 0
_0815D0AC: .4byte 0xFFFFFDFF
_0815D0B0: .4byte 0x000005C4
_0815D0B4:
	adds r0, r6, #0
	bl Cockatrice_PauseBeforeMove
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r2, _0815D118 @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_0815D0DA:
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
	blt _0815D112
	cmp r1, #0
	blt _0815D112
	ldr r0, _0815D11C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815D112
	ldr r0, _0815D120 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815D124
_0815D112:
	movs r4, #0
	b _0815D132
	.align 2, 0
_0815D118: .4byte 0x00000482
_0815D11C: .4byte 0x030046A8
_0815D120: .4byte 0x030046AC
_0815D124:
	ldr r0, _0815D144 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815D132:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815D148
	adds r0, #4
	b _0815D154
	.align 2, 0
_0815D144: .4byte 0x030046A4
_0815D148:
	ldr r0, _0815D168 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D154:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815D16C
	cmp r3, #2
	beq _0815D170
	b _0815D174
	.align 2, 0
_0815D168: .4byte 0x030046A4
_0815D16C:
	ldrb r0, [r5, #4]
	b _0815D172
_0815D170:
	ldrb r0, [r5]
_0815D172:
	subs r2, r2, r0
_0815D174:
	movs r1, #0
	strh r2, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r1, _0815D1B4 @ =0x000004A4
	adds r0, r6, r1
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815D1BC
	ldr r0, _0815D1B8 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _0815D1E6
	.align 2, 0
_0815D1B4: .4byte 0x000004A4
_0815D1B8: .4byte 0xFFFFFDFF
_0815D1BC:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815D1DC
	cmp r0, #2
	beq _0815D1D8
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815D1D8:
	movs r0, #1
	b _0815D1E8
_0815D1DC:
	ldr r0, _0815D204 @ =0xFFFFFDFF
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_0815D1E6:
	movs r0, #0
_0815D1E8:
	cmp r0, #0
	bne _0815D1F8
	ldr r1, _0815D208 @ =0x000005C4
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0815D1F8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815D204: .4byte 0xFFFFFDFF
_0815D208: .4byte 0x000005C4
