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
	beq _08115894
	b _08115AEC
_08115894:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _08115960 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08115964 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _08115968 @ =Enemy_WaitPendingState
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0811596C @ =0x0000046B
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
	beq _08115988
	ldr r4, _08115970 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r0, #4
	ldr r1, _08115974 @ =0x00000222
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
	ldr r4, _08115978 @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0811597C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _08115980 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldrh r0, [r6]
	mov r6, ip
	ands r0, r6
	cmp r0, #0
	beq _081159CC
	ldr r7, _08115984 @ =0x0000024E
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
	bls _081159CC
	strh r1, [r2]
	b _081159CC
	.align 2, 0
_08115960: .4byte 0x00000469
_08115964: .4byte 0x0000046A
_08115968: .4byte Enemy_WaitPendingState
_0811596C: .4byte 0x0000046B
_08115970: .4byte 0x00000482
_08115974: .4byte 0x00000222
_08115978: .4byte 0x00000554
_0811597C: .4byte 0x00000551
_08115980: .4byte 0x00000552
_08115984: .4byte 0x0000024E
_08115988:
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08115A08 @ =0x00000482
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
	ldr r2, _08115A0C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _08115A10 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_081159CC:
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
	blt _08115A04
	cmp r1, #0
	blt _08115A04
	ldr r0, _08115A14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08115A04
	ldr r0, _08115A18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08115A1C
_08115A04:
	movs r4, #0
	b _08115A2A
	.align 2, 0
_08115A08: .4byte 0x00000482
_08115A0C: .4byte 0x00000551
_08115A10: .4byte 0x00000552
_08115A14: .4byte 0x030046A8
_08115A18: .4byte 0x030046AC
_08115A1C:
	ldr r0, _08115A3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08115A2A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08115A40
	adds r0, #4
	b _08115A4C
	.align 2, 0
_08115A3C: .4byte 0x030046A4
_08115A40:
	ldr r0, _08115A60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08115A4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08115A64
	cmp r3, #2
	beq _08115A68
	b _08115A6C
	.align 2, 0
_08115A60: .4byte 0x030046A4
_08115A64:
	ldrb r0, [r6, #4]
	b _08115A6A
_08115A68:
	ldrb r0, [r6]
_08115A6A:
	subs r2, r2, r0
_08115A6C:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _08115AA8 @ =0x000004A4
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
	bne _08115AAC
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08115AD2
	.align 2, 0
_08115AA8: .4byte 0x000004A4
_08115AAC:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08115ACC
	cmp r0, #2
	beq _08115AC8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08115AC8:
	movs r0, #1
	b _08115ADC
_08115ACC:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08115AD2:
	ldr r1, _08115AF8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08115ADC:
	cmp r0, #0
	bne _08115AEC
	ldr r4, _08115AFC @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08115AEC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08115AF8: .4byte 0xFFFFFDFF
_08115AFC: .4byte 0x000005C4
