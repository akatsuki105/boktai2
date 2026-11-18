	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081CB80C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB810
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB812
	.align 2, 0
_081CB80C: .4byte 0x0000046C
_081CB810:
	movs r0, #0
_081CB812:
	cmp r0, #0
	beq _081CB840
	ldr r4, _081CB888 @ =FUN_081c87c8
	movs r3, #0xa
	ldr r6, _081CB88C @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r7, _081CB890 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081CB894 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081CB840:
	movs r7, #0xc1
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CB856
	b _081CBA9A
_081CB856:
	ldr r1, _081CB890 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CB862
	b _081CBA90
_081CB862:
	ldr r2, _081CB898 @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r4, #0xe1
	lsls r4, r4, #3
	add r4, r8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CB89C
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _081CB8C2
	.align 2, 0
_081CB888: .4byte FUN_081c87c8
_081CB88C: .4byte 0x0000046D
_081CB890: .4byte 0x0000046B
_081CB894: .4byte 0x00000553
_081CB898: .4byte 0x000004A4
_081CB89C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CB8BC
	cmp r0, #2
	beq _081CB8B8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CB8B8:
	movs r0, #1
	b _081CB8CC
_081CB8BC:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_081CB8C2:
	ldr r1, _081CB8E0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CB8CC:
	cmp r0, #0
	bne _081CB8E8
	ldr r7, _081CB8E4 @ =0x000005C4
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _081CBA9A
	.align 2, 0
_081CB8E0: .4byte 0xFFFFFDFF
_081CB8E4: .4byte 0x000005C4
_081CB8E8:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	movs r4, #0
	movs r6, #0
	orrs r1, r0
	strh r1, [r2]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _081CB978
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081CB964 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _081CB968 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081CB96C @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r2, #0x1a
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081CB970 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	movs r0, #4
	ldr r3, _081CB974 @ =0x00000222
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081CBA9A
	.align 2, 0
_081CB964: .4byte 0x00000469
_081CB968: .4byte 0x0000046A
_081CB96C: .4byte 0x00000484
_081CB970: .4byte 0x0000046B
_081CB974: .4byte 0x00000222
_081CB978:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
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
	blt _081CB9B0
	cmp r1, #0
	blt _081CB9B0
	ldr r0, _081CB9B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CB9B0
	ldr r0, _081CB9B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CB9BC
_081CB9B0:
	movs r4, #0
	b _081CB9CA
	.align 2, 0
_081CB9B4: .4byte 0x030046A8
_081CB9B8: .4byte 0x030046AC
_081CB9BC:
	ldr r0, _081CB9DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CB9CA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CB9E0
	adds r0, #4
	b _081CB9EC
	.align 2, 0
_081CB9DC: .4byte 0x030046A4
_081CB9E0:
	ldr r0, _081CBA00 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CB9EC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CBA04
	cmp r2, #2
	beq _081CBA08
	b _081CBA0C
	.align 2, 0
_081CBA00: .4byte 0x030046A4
_081CBA04:
	ldrb r0, [r6, #4]
	b _081CBA0A
_081CBA08:
	ldrb r0, [r6]
_081CBA0A:
	subs r1, r1, r0
_081CBA0C:
	movs r3, #0
	movs r4, #0
	strh r1, [r6, #2]
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #1
	ldr r6, _081CBA80 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0x3d
	adds r0, r5, r7
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r2, #7
	subs r6, #0xeb
	adds r0, r5, r6
	strb r3, [r0]
	ldr r7, _081CBA84 @ =0x00000469
	adds r0, r5, r7
	strb r3, [r0]
	ldr r3, _081CBA88 @ =0x0000046A
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r0, _081CBA8C @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _081CBA9A
	.align 2, 0
_081CBA80: .4byte 0x0000046D
_081CBA84: .4byte 0x00000469
_081CBA88: .4byte 0x0000046A
_081CBA8C: .4byte 0x00000482
_081CBA90:
	ldr r2, _081CBAA4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CBA9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CBAA4: .4byte 0x00000484
