	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_080fa77c
	ldr r1, _081B3A44 @ =0x0000214A
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B3A18
	adds r0, r6, #0
	bl FUN_080f9f20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3A18
	b _081B3BC8
_081B3A18:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	mov sb, r0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3A30
	b _081B3BC8
_081B3A30:
	movs r2, #1
	ldr r1, _081B3A48 @ =0x0000065C
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081B3A4C
	movs r0, #1
	b _081B3A4E
	.align 2, 0
_081B3A44: .4byte 0x0000214A
_081B3A48: .4byte 0x0000065C
_081B3A4C:
	movs r0, #0
_081B3A4E:
	cmp r0, #0
	bne _081B3A54
	b _081B3BC8
_081B3A54:
	ldr r1, _081B3A7C @ =0x0000A107
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r4, r4, r6
	mov r8, r4
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B3A68
	b _081B3BC8
_081B3A68:
	ldr r1, _081B3A80 @ =0x0000067C
	add r1, sb
	ldrh r0, [r1]
	adds r7, r0, #0
	cmp r7, #0
	beq _081B3A84
	subs r0, #1
	strh r0, [r1]
	b _081B3BC8
	.align 2, 0
_081B3A7C: .4byte 0x0000A107
_081B3A80: .4byte 0x0000067C
_081B3A84:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081B3B70 @ =0x000004A4
	adds r5, r6, r1
	ldr r0, [r5]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r6, #0
	bl Enemy_SetAngleToward
	adds r0, r6, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r0, #0xc
	mov ip, r0
	movs r1, #0x1e
	subs r4, #0x60
	adds r2, r6, r4
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r7, [r0]
	ldr r2, _081B3B74 @ =0x00000551
	adds r0, r6, r2
	strb r7, [r0]
	ldr r3, _081B3B78 @ =0x00000552
	adds r0, r6, r3
	mov r4, ip
	strb r4, [r0]
	ldr r3, _081B3B7C @ =Enemy_WaitPendingState
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081B3B80 @ =0x0000046B
	adds r0, r6, r4
	strb r7, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	strh r7, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _081B3B84 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r7, [r0]
	ldr r3, _081B3B88 @ =0x0000046C
	adds r0, r6, r3
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x9c
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrb r2, [r0]
	ldr r3, _081B3B8C @ =0x00000251
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	bl Mover_SetPath
	ldr r5, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r7, #0xcc
	lsls r7, r7, #3
	add r7, sb
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B3B94
	ldr r0, _081B3B90 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B3BBC
	.align 2, 0
_081B3B70: .4byte 0x000004A4
_081B3B74: .4byte 0x00000551
_081B3B78: .4byte 0x00000552
_081B3B7C: .4byte Enemy_WaitPendingState
_081B3B80: .4byte 0x0000046B
_081B3B84: .4byte 0x00000469
_081B3B88: .4byte 0x0000046C
_081B3B8C: .4byte 0x00000251
_081B3B90: .4byte 0xFFFFFDFF
_081B3B94:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B3BB2
	cmp r0, #2
	beq _081B3BBC
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _081B3BBC
_081B3BB2:
	ldr r0, _081B3BDC @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B3BBC:
	movs r0, #2
	rsbs r0, r0, #0
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_081B3BC8:
	movs r0, #1
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B3BDC: .4byte 0xFFFFFDFF
