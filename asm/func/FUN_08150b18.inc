	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08150B3C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150B40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08150B42
	.align 2, 0
_08150B3C: .4byte 0x0000046C
_08150B40:
	movs r0, #0
_08150B42:
	cmp r0, #0
	beq _08150B70
	ldr r4, _08150BC8 @ =FUN_0814caa0
	movs r3, #0xa
	ldr r6, _08150BCC @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r7, _08150BD0 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08150BD4 @ =0x00000553
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
_08150B70:
	movs r7, #0xc1
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08150B86
	b _08150DDA
_08150B86:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08150B94
	b _08150DDA
_08150B94:
	ldr r1, _08150BD0 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08150BA0
	b _08150DD0
_08150BA0:
	ldr r2, _08150BD8 @ =0x000004A4
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
	bne _08150BDC
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _08150C02
	.align 2, 0
_08150BC8: .4byte FUN_0814caa0
_08150BCC: .4byte 0x0000046D
_08150BD0: .4byte 0x0000046B
_08150BD4: .4byte 0x00000553
_08150BD8: .4byte 0x000004A4
_08150BDC:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08150BFC
	cmp r0, #2
	beq _08150BF8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08150BF8:
	movs r0, #1
	b _08150C0C
_08150BFC:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_08150C02:
	ldr r1, _08150C20 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08150C0C:
	cmp r0, #0
	bne _08150C28
	ldr r7, _08150C24 @ =0x000005C4
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _08150DDA
	.align 2, 0
_08150C20: .4byte 0xFFFFFDFF
_08150C24: .4byte 0x000005C4
_08150C28:
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
	beq _08150CB8
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _08150CA4 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _08150CA8 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08150CAC @ =0x00000484
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
	ldr r1, _08150CB0 @ =0x0000046B
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
	ldr r3, _08150CB4 @ =0x00000222
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08150DDA
	.align 2, 0
_08150CA4: .4byte 0x00000469
_08150CA8: .4byte 0x0000046A
_08150CAC: .4byte 0x00000484
_08150CB0: .4byte 0x0000046B
_08150CB4: .4byte 0x00000222
_08150CB8:
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
	blt _08150CF0
	cmp r1, #0
	blt _08150CF0
	ldr r0, _08150CF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08150CF0
	ldr r0, _08150CF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150CFC
_08150CF0:
	movs r4, #0
	b _08150D0A
	.align 2, 0
_08150CF4: .4byte 0x030046A8
_08150CF8: .4byte 0x030046AC
_08150CFC:
	ldr r0, _08150D1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08150D0A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08150D20
	adds r0, #4
	b _08150D2C
	.align 2, 0
_08150D1C: .4byte 0x030046A4
_08150D20:
	ldr r0, _08150D40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08150D2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08150D44
	cmp r2, #2
	beq _08150D48
	b _08150D4C
	.align 2, 0
_08150D40: .4byte 0x030046A4
_08150D44:
	ldrb r0, [r6, #4]
	b _08150D4A
_08150D48:
	ldrb r0, [r6]
_08150D4A:
	subs r1, r1, r0
_08150D4C:
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
	ldr r6, _08150DC0 @ =0x0000046D
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
	ldr r7, _08150DC4 @ =0x00000469
	adds r0, r5, r7
	strb r3, [r0]
	ldr r3, _08150DC8 @ =0x0000046A
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r0, _08150DCC @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _08150DDA
	.align 2, 0
_08150DC0: .4byte 0x0000046D
_08150DC4: .4byte 0x00000469
_08150DC8: .4byte 0x0000046A
_08150DCC: .4byte 0x00000482
_08150DD0:
	ldr r2, _08150DE4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08150DDA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08150DE4: .4byte 0x00000484
