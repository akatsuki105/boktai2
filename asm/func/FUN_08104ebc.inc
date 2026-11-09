	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r7, r6, r3
	ldrh r1, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08104EDC
	b _08105160
_08104EDC:
	ldr r4, _08104F80 @ =0x00000724
	adds r0, r2, r4
	ldrb r5, [r0]
	cmp r5, #0
	beq _08104EE8
	b _08105160
_08104EE8:
	movs r0, #0x80
	mov ip, r0
	ands r1, r0
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08104F9C
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08104F84 @ =0x00000469
	adds r0, r6, r3
	strb r5, [r0]
	ldr r4, _08104F88 @ =0x0000046A
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08104F8C @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #4
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r2, #0x1a
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08104F90 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldrh r0, [r7]
	mov r3, ip
	ands r0, r3
	cmp r0, #0
	beq _08104F72
	ldr r4, _08104F94 @ =0x0000024E
	adds r2, r6, r4
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r7, [r2]
	adds r0, r0, r7
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08104F72
	strh r1, [r2]
_08104F72:
	movs r0, #4
	ldr r4, _08104F98 @ =0x00000222
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0810502A
	.align 2, 0
_08104F80: .4byte 0x00000724
_08104F84: .4byte 0x00000469
_08104F88: .4byte 0x0000046A
_08104F8C: .4byte 0x00000484
_08104F90: .4byte 0x0000046B
_08104F94: .4byte 0x0000024E
_08104F98: .4byte 0x00000222
_08104F9C:
	movs r1, #3
	movs r2, #1
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _08105068 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0810506C @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r3, _08105070 @ =0x00000484
	adds r0, r6, r3
	str r4, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r2, [r0]
	ldr r3, _08105074 @ =Enemy_WaitPendingState
	movs r1, #0xe
	adds r7, #4
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08105078 @ =0x0000046B
	adds r0, r6, r2
	strb r4, [r0]
	adds r5, #0xe7
	adds r0, r6, r5
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	strh r4, [r0]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r4, _0810507C @ =0x00000482
	adds r1, r6, r4
	movs r0, #2
	strh r0, [r1]
	adds r7, #0x28
	adds r0, r6, r7
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	subs r7, #0x4c
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _08105080 @ =0x00000551
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08105084 @ =0x00000552
	adds r0, r6, r3
	strb r4, [r0]
_0810502A:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r6, r4
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
	blt _08105062
	cmp r1, #0
	blt _08105062
	ldr r0, _08105088 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08105062
	ldr r0, _0810508C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08105090
_08105062:
	movs r4, #0
	b _0810509E
	.align 2, 0
_08105068: .4byte 0x00000469
_0810506C: .4byte 0x0000046A
_08105070: .4byte 0x00000484
_08105074: .4byte Enemy_WaitPendingState
_08105078: .4byte 0x0000046B
_0810507C: .4byte 0x00000482
_08105080: .4byte 0x00000551
_08105084: .4byte 0x00000552
_08105088: .4byte 0x030046A8
_0810508C: .4byte 0x030046AC
_08105090:
	ldr r0, _081050B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810509E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081050B4
	adds r0, #4
	b _081050C0
	.align 2, 0
_081050B0: .4byte 0x030046A4
_081050B4:
	ldr r0, _081050D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081050C0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081050D8
	cmp r3, #2
	beq _081050DC
	b _081050E0
	.align 2, 0
_081050D4: .4byte 0x030046A4
_081050D8:
	ldrb r0, [r5, #4]
	b _081050DE
_081050DC:
	ldrb r0, [r5]
_081050DE:
	subs r2, r2, r0
_081050E0:
	movs r1, #0
	strh r2, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r0, [r0]
	strh r1, [r0, #6]
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r1, [r0]
	ldr r2, _0810511C @ =0x000004A4
	adds r0, r6, r2
	ldr r4, [r0]
	adds r5, r6, #0
	adds r5, #8
	adds r7, r1, #0
	adds r7, #8
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08105120
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
	b _08105146
	.align 2, 0
_0810511C: .4byte 0x000004A4
_08105120:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08105140
	cmp r0, #2
	beq _0810513C
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810513C:
	movs r0, #1
	b _08105150
_08105140:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r6, r4
_08105146:
	ldr r1, _08105168 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08105150:
	cmp r0, #0
	bne _08105160
	ldr r5, _0810516C @ =0x000005C4
	adds r0, r6, r5
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_08105160:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08105168: .4byte 0xFFFFFDFF
_0810516C: .4byte 0x000005C4
