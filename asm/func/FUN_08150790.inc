	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081507B4 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081507B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081507BA
	.align 2, 0
_081507B4: .4byte 0x0000046C
_081507B8:
	movs r0, #0
_081507BA:
	cmp r0, #0
	beq _081507E8
	ldr r4, _081508F4 @ =FUN_0814e1fc
	movs r3, #0x27
	ldr r0, _081508F8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081508FC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_081507E8:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081507FE
	b _08150B06
_081507FE:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815080C
	b _08150B06
_0815080C:
	ldr r0, _08150900 @ =0x03002BE0
	mov r2, sp
	adds r3, r5, #0
	adds r3, #8
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r2, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r2, r1, r0
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r1, [r0, #8]
	mov r8, r3
	cmp r1, #6
	beq _08150862
	cmp r1, #0xc
	beq _08150862
	cmp r1, #0x13
	beq _08150862
	cmp r1, #0x19
	bne _0815091C
_08150862:
	ldrh r1, [r0, #0xe]
	ldrb r0, [r0, #7]
	subs r0, #1
	cmp r1, r0
	bne _0815091C
	ldr r3, _08150904 @ =0x000006B4
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815091C
	ldr r4, _08150908 @ =0x000001DF
	adds r0, r5, r4
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl Enemy_SetEmote
	movs r2, #0x10
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0815090C @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08150910 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08150914 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #0xe1
	lsls r4, r4, #3
	adds r2, r6, r4
	ldr r0, _08150900 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081508D0
	b _08150B06
_081508D0:
	ldr r0, _08150918 @ =0x0000024E
	adds r4, r5, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bhi _081508F0
	b _08150B06
_081508F0:
	strh r1, [r4]
	b _08150B06
	.align 2, 0
_081508F4: .4byte FUN_0814e1fc
_081508F8: .4byte 0x0000046D
_081508FC: .4byte 0x0000046B
_08150900: .4byte 0x03002BE0
_08150904: .4byte 0x000006B4
_08150908: .4byte 0x000001DF
_0815090C: .4byte 0x00000469
_08150910: .4byte 0x0000046A
_08150914: .4byte 0x00000484
_08150918: .4byte 0x0000024E
_0815091C:
	ldr r4, _0815099C @ =0x0000046B
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08150928
	b _08150AFC
_08150928:
	movs r2, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r5, r6
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081509B0
	movs r2, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081509A0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _081509A4 @ =0x00000484
	adds r0, r5, r6
	str r1, [r0]
	ldr r2, _081509A8 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0815099C @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #4
	ldr r4, _081509AC @ =0x00000222
	adds r2, r5, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08150B06
	.align 2, 0
_0815099C: .4byte 0x0000046B
_081509A0: .4byte 0x00000469
_081509A4: .4byte 0x00000484
_081509A8: .4byte 0x0000046C
_081509AC: .4byte 0x00000222
_081509B0:
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081509E4
	cmp r1, #0
	blt _081509E4
	ldr r0, _081509E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081509E4
	ldr r0, _081509EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081509F0
_081509E4:
	movs r4, #0
	b _081509FE
	.align 2, 0
_081509E8: .4byte 0x030046A8
_081509EC: .4byte 0x030046AC
_081509F0:
	ldr r0, _08150A10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081509FE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08150A14
	adds r0, #4
	b _08150A20
	.align 2, 0
_08150A10: .4byte 0x030046A4
_08150A14:
	ldr r0, _08150A34 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08150A20:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08150A38
	cmp r3, #2
	beq _08150A3C
	b _08150A40
	.align 2, 0
_08150A34: .4byte 0x030046A4
_08150A38:
	ldrb r0, [r6, #4]
	b _08150A3E
_08150A3C:
	ldrb r0, [r6]
_08150A3E:
	subs r2, r2, r0
_08150A40:
	movs r1, #0
	movs r4, #0
	strh r2, [r6, #2]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r3, [r0]
	movs r2, #1
	ldr r6, _08150AC8 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0x25
	adds r0, r5, r6
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08150ACC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08150AD0 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	ldr r4, _08150AD4 @ =0x0000046C
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0x3b
	adds r0, r5, r6
	ldr r4, [r0]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _08150AD8
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08150AD8
	cmp r0, #2
	beq _08150AC2
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08150AC2:
	movs r0, #1
	b _08150AE2
	.align 2, 0
_08150AC8: .4byte 0x0000046D
_08150ACC: .4byte 0x0000046A
_08150AD0: .4byte 0x00000484
_08150AD4: .4byte 0x0000046C
_08150AD8:
	ldr r0, _08150AF4 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0
_08150AE2:
	cmp r0, #0
	bne _08150B06
	ldr r1, _08150AF8 @ =0x000005C4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _08150B06
	.align 2, 0
_08150AF4: .4byte 0xFFFFFDFF
_08150AF8: .4byte 0x000005C4
_08150AFC:
	ldr r2, _08150B14 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08150B06:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08150B14: .4byte 0x00000484
