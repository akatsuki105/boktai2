	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _081031B4 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08103220
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08103220
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r6, _081031B8 @ =0x000007A4
	adds r0, r0, r6
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r7, r5, r6
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	bne _08103220
	ldr r2, _081031BC @ =0xFFFF0000
	ldrh r1, [r4, #6]
	lsls r1, r1, #0x10
	ldrh r0, [r4, #4]
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, #8]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r1, _081031C0 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _081031C4
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081031C4
	cmp r0, #2
	beq _081031AE
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081031AE:
	movs r0, #1
	b _081031CE
	.align 2, 0
_081031B4: .4byte 0x000001DF
_081031B8: .4byte 0x000007A4
_081031BC: .4byte 0xFFFF0000
_081031C0: .4byte 0x000004A4
_081031C4:
	ldr r0, _08103228 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0
_081031CE:
	cmp r0, #0
	beq _08103220
	ldr r3, _0810322C @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r2, _08103230 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08103234 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #0x12
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08103238 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_08103220:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08103228: .4byte 0xFFFFFDFF
_0810322C: .4byte Enemy_ClearStateBegun
_08103230: .4byte 0x0000046D
_08103234: .4byte 0x0000046B
_08103238: .4byte 0x0000046A
