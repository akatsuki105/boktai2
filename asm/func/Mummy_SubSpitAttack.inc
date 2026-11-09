	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0812C7EC @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812C7F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812C7F2
	.align 2, 0
_0812C7EC: .4byte 0x0000046C
_0812C7F0:
	movs r0, #0
_0812C7F2:
	cmp r0, #0
	beq _0812C828
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r4, _0812C924 @ =Mummy_StateSpit
	movs r3, #0x25
	ldr r0, _0812C928 @ =0x0000046D
	adds r1, r7, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812C92C @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r2, [r0]
_0812C828:
	ldr r1, _0812C92C @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812C834
	b _0812C99A
_0812C834:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r1, _0812C930 @ =0xFFFFFEFF
	ldrh r0, [r5]
	ands r1, r0
	movs r6, #0
	strh r1, [r5]
	ldr r4, _0812C934 @ =0x0000071E
	add r4, r8
	ldr r0, _0812C938 @ =0xFFFFF7FF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, _0812C93C @ =0x00000222
	adds r2, r7, r3
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _0812C940 @ =Mummy_StateWaitBombs
	movs r0, #0x26
	ldr r4, _0812C928 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp]
	movs r2, #1
	strb r2, [r4]
	ldr r3, _0812C92C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #4]
	strb r6, [r3]
	ldr r4, _0812C944 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xc]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x10]
	movs r3, #0
	strh r3, [r1]
	movs r0, #0x10
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14]
	strb r6, [r4]
	ldr r1, _0812C948 @ =0x00000469
	adds r1, r1, r7
	mov r8, r1
	strb r6, [r1]
	ldr r3, _0812C94C @ =0x0000046A
	adds r3, r3, r7
	mov sb, r3
	strb r0, [r3]
	ldr r4, _0812C950 @ =0x00000484
	adds r4, r4, r7
	mov sl, r4
	movs r0, #0
	str r0, [r4]
	ldr r1, _0812C954 @ =0x0000046C
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _0812C958 @ =0x000004A4
	adds r0, r7, r2
	ldr r6, [r0]
	adds r3, r7, #0
	adds r3, #8
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	str r3, [sp, #0x30]
	bl Map_IsPosInAgentIsland
	str r4, [sp, #0x20]
	ldr r4, [sp]
	str r4, [sp, #0x24]
	ldr r1, [sp, #4]
	str r1, [sp, #0x1c]
	ldr r4, [sp, #8]
	ldr r2, [sp, #0xc]
	str r2, [sp, #0x28]
	ldr r1, [sp, #0x10]
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r3, [sp, #0x30]
	cmp r0, #0
	beq _0812C95C
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812C95C
	cmp r0, #2
	beq _0812C920
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812C920:
	movs r0, #1
	b _0812C966
	.align 2, 0
_0812C924: .4byte Mummy_StateSpit
_0812C928: .4byte 0x0000046D
_0812C92C: .4byte 0x0000046B
_0812C930: .4byte 0xFFFFFEFF
_0812C934: .4byte 0x0000071E
_0812C938: .4byte 0xFFFFF7FF
_0812C93C: .4byte 0x00000222
_0812C940: .4byte Mummy_StateWaitBombs
_0812C944: .4byte 0x00000553
_0812C948: .4byte 0x00000469
_0812C94C: .4byte 0x0000046A
_0812C950: .4byte 0x00000484
_0812C954: .4byte 0x0000046C
_0812C958: .4byte 0x000004A4
_0812C95C:
	ldr r0, _0812C9AC @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_0812C966:
	adds r3, r0, #0
	cmp r3, #0
	bne _0812C99A
	ldr r0, _0812C9B0 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r1, [sp, #0x24]
	strb r2, [r1]
	ldr r1, [sp, #0x1c]
	strb r3, [r1]
	strb r3, [r4]
	ldr r4, [sp, #0x28]
	str r0, [r4]
	movs r1, #0
	ldr r0, [sp, #0x2c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x18]
	strb r0, [r4]
	mov r0, r8
	strb r1, [r0]
	mov r4, sb
	strb r1, [r4]
	mov r0, sl
	str r3, [r0]
	ldr r1, [sp, #0x20]
	strb r2, [r1]
_0812C99A:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812C9AC: .4byte 0xFFFFFDFF
_0812C9B0: .4byte Enemy_ClearStateBegun
