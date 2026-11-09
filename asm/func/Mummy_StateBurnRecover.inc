	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r7, r0, #0
	adds r6, r1, #0
	str r7, [sp, #4]
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _08122D14 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08122D18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08122D1A
	.align 2, 0
_08122D14: .4byte 0x0000046D
_08122D18:
	movs r0, #0
_08122D1A:
	cmp r0, #0
	beq _08122D50
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _08122E4C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08122E50 @ =0x0000021E
	adds r0, r7, r2
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	subs r2, #0x1e
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #7
	bl Enemy_PlayAnim
	ldr r1, _08122E54 @ =0x0000046E
	adds r0, r7, r1
	strb r4, [r0]
_08122D50:
	cmp r6, #0x3b
	bgt _08122D5A
	movs r0, #0
	strh r0, [r5, #8]
	strh r0, [r5, #0xe]
_08122D5A:
	ldr r2, _08122E54 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122D66
	b _08122FBC
_08122D66:
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r6, #0
	movs r5, #0
	strh r5, [r0]
	ldr r1, _08122E58 @ =0x0000046B
	adds r0, r7, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r1, _08122E5C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r2, _08122E60 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #8]
	strb r4, [r2]
	ldr r2, _08122E58 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r6, [r2]
	ldr r2, _08122E64 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x14]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x18]
	strh r5, [r1]
	movs r0, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sl, r2
	strb r0, [r2]
	ldr r0, _08122E68 @ =0x00000469
	adds r0, r0, r7
	mov sb, r0
	strb r4, [r0]
	ldr r1, _08122E6C @ =0x0000046A
	adds r1, r1, r7
	mov r8, r1
	strb r6, [r1]
	ldr r2, _08122E70 @ =0x00000484
	adds r6, r7, r2
	str r5, [r6]
	ldr r0, _08122E74 @ =0x0000046C
	adds r5, r7, r0
	strb r4, [r5]
	adds r4, r7, #0
	adds r4, #0x9c
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r1, r4, #0
	bl Mover_SetPath
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	strh r1, [r3]
	ldr r0, [r4, #8]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r4, [sp, #8]
	str r4, [sp, #0x28]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x20]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x34]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x1c]
	ldr r4, [sp, #0x18]
	str r4, [sp, #0x30]
	str r6, [sp, #0x2c]
	str r5, [sp, #0x24]
	cmp r2, #0
	blt _08122E48
	cmp r1, #0
	blt _08122E48
	ldr r0, _08122E78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08122E48
	ldr r0, _08122E7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08122E80
_08122E48:
	movs r4, #0
	b _08122E8E
	.align 2, 0
_08122E4C: .4byte 0xFFFEBE3F
_08122E50: .4byte 0x0000021E
_08122E54: .4byte 0x0000046E
_08122E58: .4byte 0x0000046B
_08122E5C: .4byte Enemy_WaitPendingState
_08122E60: .4byte 0x0000046D
_08122E64: .4byte 0x00000553
_08122E68: .4byte 0x00000469
_08122E6C: .4byte 0x0000046A
_08122E70: .4byte 0x00000484
_08122E74: .4byte 0x0000046C
_08122E78: .4byte 0x030046A8
_08122E7C: .4byte 0x030046AC
_08122E80:
	ldr r0, _08122EA4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08122E8E:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x38]
	bl Map_FindTileOverride
	ldr r3, [sp, #0x38]
	cmp r0, #0
	beq _08122EA8
	adds r0, #4
	b _08122EB4
	.align 2, 0
_08122EA4: .4byte 0x030046A4
_08122EA8:
	ldr r0, _08122EC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08122EB4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08122ECC
	cmp r2, #2
	beq _08122ED0
	b _08122ED4
	.align 2, 0
_08122EC8: .4byte 0x030046A4
_08122ECC:
	ldrb r0, [r3, #4]
	b _08122ED2
_08122ED0:
	ldrb r0, [r3]
_08122ED2:
	subs r1, r1, r0
_08122ED4:
	strh r1, [r3, #2]
	ldr r6, _08122F00 @ =0x000004A4
	adds r0, r7, r6
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08122F04
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _08122F2A
	.align 2, 0
_08122F00: .4byte 0x000004A4
_08122F04:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08122F24
	cmp r0, #2
	beq _08122F20
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08122F20:
	movs r0, #1
	b _08122F34
_08122F24:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, r4
_08122F2A:
	ldr r1, _08122F6C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08122F34:
	adds r3, r0, #0
	cmp r3, #0
	bne _08122F74
	ldr r0, _08122F70 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r6, [sp, #0x28]
	strb r2, [r6]
	ldr r1, [sp, #0x20]
	strb r3, [r1]
	ldr r4, [sp, #0x34]
	strb r3, [r4]
	ldr r6, [sp, #0x1c]
	str r0, [r6]
	movs r1, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	mov r4, sl
	strb r0, [r4]
	mov r6, sb
	strb r1, [r6]
	mov r0, r8
	strb r1, [r0]
	ldr r1, [sp, #0x2c]
	str r3, [r1]
	ldr r4, [sp, #0x24]
	strb r2, [r4]
	b _08122FBC
	.align 2, 0
_08122F6C: .4byte 0xFFFFFDFF
_08122F70: .4byte Enemy_ClearStateBegun
_08122F74:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r5, #0
	movs r0, #1
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	adds r6, #0xb0
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08122FCC @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r4, [r0]
_08122FBC:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08122FCC: .4byte 0x00000551
