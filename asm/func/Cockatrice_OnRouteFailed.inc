	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815F500
	movs r0, #0xc0
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	bne _0815F504
_0815F500:
	movs r0, #0
	b _0815F712
_0815F504:
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r1, r0
	str r1, [r2]
	ldr r0, _0815F550 @ =0x00000482
	adds r1, r6, r0
	movs r3, #0
	movs r4, #0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	movs r1, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0815F554 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r4, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #2
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815F558
	movs r0, #1
	b _0815F55A
	.align 2, 0
_0815F550: .4byte 0x00000482
_0815F554: .4byte 0x00000469
_0815F558:
	movs r0, #0
_0815F55A:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815F5F4
	adds r0, r6, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	ldr r4, _0815F5D8 @ =FUN_080e6834
	movs r3, #0xe
	ldr r7, _0815F5DC @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815F5E0 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r5, #0
	strh r2, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl Cockatrice_SetHopVel
	ldr r3, _0815F5E4 @ =Cockatrice_StateDescendPuzzled
	movs r4, #3
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r7, _0815F5E8 @ =0x00000554
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815F5EC @ =0x00000551
	adds r0, r6, r2
	strb r5, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r2, _0815F5F0 @ =0xFFFFFEFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r2, r1, #0
	b _0815F658
	.align 2, 0
_0815F5D8: .4byte FUN_080e6834
_0815F5DC: .4byte 0x0000046D
_0815F5E0: .4byte 0x0000046B
_0815F5E4: .4byte Cockatrice_StateDescendPuzzled
_0815F5E8: .4byte 0x00000554
_0815F5EC: .4byte 0x00000551
_0815F5F0: .4byte 0xFFFFFEFF
_0815F5F4:
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, _0815F69C @ =Enemy_WaitPendingState
	movs r2, #0xe
	ldr r7, _0815F6A0 @ =0x0000046D
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815F6A4 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r7, #0xe6
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
	adds r7, #0x51
	adds r0, r6, r7
	ldr r3, [r0]
	movs r5, #9
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	subs r7, #0x50
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815F6A8 @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
_0815F658:
	movs r1, #0x10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r6, r1
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
	blt _0815F698
	cmp r1, #0
	blt _0815F698
	ldr r0, _0815F6AC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815F698
	ldr r0, _0815F6B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815F6B4
_0815F698:
	movs r4, #0
	b _0815F6C2
	.align 2, 0
_0815F69C: .4byte Enemy_WaitPendingState
_0815F6A0: .4byte 0x0000046D
_0815F6A4: .4byte 0x0000046B
_0815F6A8: .4byte 0x00000551
_0815F6AC: .4byte 0x030046A8
_0815F6B0: .4byte 0x030046AC
_0815F6B4:
	ldr r0, _0815F6D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815F6C2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815F6D8
	adds r0, #4
	b _0815F6E4
	.align 2, 0
_0815F6D4: .4byte 0x030046A4
_0815F6D8:
	ldr r0, _0815F6F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815F6E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815F6FC
	cmp r2, #2
	beq _0815F700
	b _0815F704
	.align 2, 0
_0815F6F8: .4byte 0x030046A4
_0815F6FC:
	ldrb r0, [r5, #4]
	b _0815F702
_0815F700:
	ldrb r0, [r5]
_0815F702:
	subs r1, r1, r0
_0815F704:
	strh r1, [r5, #2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_0815F712:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
