	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldr r0, _081237B8 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08123708
	movs r0, #0
	strb r0, [r1]
_08123708:
	movs r0, #0x10
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r6, r1, #0
	cmp r4, #0x11
	bgt _08123736
	ldrh r4, [r3, #8]
	cmp r4, #0
	bne _08123736
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _08123736
	cmp r2, #1
	beq _08123736
	strh r4, [r3, #0xe]
_08123736:
	ldr r3, _081237BC @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08123742
	b _08123A78
_08123742:
	ldr r4, _081237C0 @ =0x0000046B
	adds r0, r7, r4
	movs r5, #0
	movs r3, #1
	strb r3, [r0]
	movs r0, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	str r1, [sp, #0x30]
	cmp r4, #0
	beq _081237D4
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _081237C4 @ =0x00000469
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081237C8 @ =0x0000046A
	adds r0, r7, r2
	strb r5, [r0]
	adds r4, #0x1c
	adds r0, r7, r4
	str r5, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _081237CC @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	subs r4, #0x17
	adds r0, r7, r4
	strb r3, [r0]
	ldr r3, _081237C0 @ =0x0000046B
	adds r0, r7, r3
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r0, _081237D0 @ =0xFFFFF67C
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08123A78
	.align 2, 0
_081237B8: .4byte 0x0000046D
_081237BC: .4byte 0x0000046E
_081237C0: .4byte 0x0000046B
_081237C4: .4byte 0x00000469
_081237C8: .4byte 0x0000046A
_081237CC: .4byte 0x00000594
_081237D0: .4byte 0xFFFFF67C
_081237D4:
	movs r0, #0x80
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0812384C
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x34]
	bl Enemy_PlayAnim
	movs r1, #0xe
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	ldr r2, _0812383C @ =0x00000469
	adds r0, r7, r2
	strb r4, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _08123840 @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r7, r2
	ldr r3, [sp, #0x34]
	strb r3, [r0]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r2, [r0]
	movs r1, #0x24
	ldr r5, _08123844 @ =0x0000046D
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _08123848 @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	b _08123A78
	.align 2, 0
_0812383C: .4byte 0x00000469
_08123840: .4byte 0x00000484
_08123844: .4byte 0x0000046D
_08123848: .4byte 0x0000046B
_0812384C:
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x34]
	bl Enemy_PlayAnim
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp]
	strb r0, [r4]
	ldr r0, _08123948 @ =0x00000469
	adds r0, r7, r0
	str r0, [sp, #4]
	ldr r3, [sp, #0x34]
	strb r3, [r0]
	ldr r1, _0812394C @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r5, [r1]
	ldr r2, _08123950 @ =0x00000484
	adds r2, r7, r2
	str r2, [sp, #0xc]
	str r5, [r2]
	ldr r4, _08123954 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x10]
	strb r3, [r4]
	ldr r1, _08123958 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r2, _0812395C @ =0x0000046D
	adds r6, r7, r2
	strb r3, [r6]
	ldr r3, _08123960 @ =0x0000046B
	adds r3, r3, r7
	mov ip, r3
	strb r5, [r3]
	ldr r4, _08123964 @ =0x00000553
	adds r4, r4, r7
	mov sl, r4
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x28
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08123968 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812396C @ =0x00000552
	adds r0, r7, r3
	movs r4, #7
	strb r4, [r0]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
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
	str r6, [sp, #0x28]
	ldr r3, [sp]
	str r3, [sp, #0x14]
	ldr r4, [sp, #4]
	str r4, [sp, #0x18]
	ldr r0, [sp, #8]
	str r0, [sp, #0x1c]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x24]
	mov r0, ip
	str r0, [sp, #0x20]
	cmp r2, #0
	blt _08123942
	cmp r1, #0
	blt _08123942
	ldr r0, _08123970 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08123942
	ldr r0, _08123974 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08123978
_08123942:
	movs r4, #0
	b _08123986
	.align 2, 0
_08123948: .4byte 0x00000469
_0812394C: .4byte 0x0000046A
_08123950: .4byte 0x00000484
_08123954: .4byte 0x0000046C
_08123958: .4byte Enemy_WaitPendingState
_0812395C: .4byte 0x0000046D
_08123960: .4byte 0x0000046B
_08123964: .4byte 0x00000553
_08123968: .4byte 0x00000551
_0812396C: .4byte 0x00000552
_08123970: .4byte 0x030046A8
_08123974: .4byte 0x030046AC
_08123978:
	ldr r0, _08123998 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08123986:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812399C
	adds r0, #4
	b _081239A8
	.align 2, 0
_08123998: .4byte 0x030046A4
_0812399C:
	ldr r0, _081239BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081239A8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081239C0
	cmp r2, #2
	beq _081239C4
	b _081239C8
	.align 2, 0
_081239BC: .4byte 0x030046A4
_081239C0:
	ldrb r0, [r5, #4]
	b _081239C6
_081239C4:
	ldrb r0, [r5]
_081239C6:
	subs r1, r1, r0
_081239C8:
	strh r1, [r5, #2]
	ldr r1, _081239F8 @ =0x000004A4
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
	bne _08123A00
	ldr r0, _081239FC @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _08123A2A
	.align 2, 0
_081239F8: .4byte 0x000004A4
_081239FC: .4byte 0xFFFFFDFF
_08123A00:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08123A20
	cmp r0, #2
	beq _08123A1C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08123A1C:
	movs r0, #1
	b _08123A2C
_08123A20:
	ldr r0, _08123A64 @ =0xFFFFFDFF
	ldr r4, [sp, #0x30]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08123A2A:
	movs r0, #0
_08123A2C:
	adds r3, r0, #0
	cmp r3, #0
	bne _08123A6C
	ldr r0, _08123A68 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r5, [sp, #0x28]
	strb r2, [r5]
	ldr r1, [sp, #0x20]
	strb r3, [r1]
	mov r4, sl
	strb r3, [r4]
	mov r5, sb
	str r0, [r5]
	movs r1, #0
	mov r0, r8
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x14]
	strb r0, [r4]
	ldr r5, [sp, #0x18]
	strb r1, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r1, [sp, #0x2c]
	str r3, [r1]
	ldr r3, [sp, #0x24]
	strb r2, [r3]
	b _08123A78
	.align 2, 0
_08123A64: .4byte 0xFFFFFDFF
_08123A68: .4byte Enemy_ClearStateBegun
_08123A6C:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_08123A78:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
