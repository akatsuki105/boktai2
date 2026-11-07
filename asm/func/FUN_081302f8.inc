	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08130310
	b _08130442
_08130310:
	ldr r0, _081303CC @ =0x03002BE0
	mov sb, r0
	ldr r2, [r0]
	cmp r2, #0
	bne _0813031C
	b _08130442
_0813031C:
	ldr r1, _081303D0 @ =0x000004A4
	adds r1, r1, r5
	mov r8, r1
	ldr r0, [r1]
	adds r7, r5, #0
	adds r7, #8
	adds r2, #0x2c
	adds r1, r7, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08130336
	b _08130442
_08130336:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r5, r2
	ldr r2, [r3]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r3]
	movs r2, #0
	strh r6, [r0, #6]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r4, r5, r3
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x24
	str r0, [r4]
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081303D4 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	mov sb, r0
	ldr r3, _081303D8 @ =0x0000046D
	adds r0, r5, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081303DC @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	mov r1, sb
	str r1, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	mov r3, r8
	ldr r6, [r3]
	ldr r0, [r4]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081303E0
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	b _08130404
	.align 2, 0
_081303CC: .4byte 0x03002BE0
_081303D0: .4byte 0x000004A4
_081303D4: .4byte 0x00000484
_081303D8: .4byte 0x0000046D
_081303DC: .4byte 0x00000553
_081303E0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081303FE
	cmp r0, #2
	beq _0813040C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0813040C
_081303FE:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
_08130404:
	ldr r1, _08130450 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0813040C:
	ldr r2, _08130454 @ =0x00004010
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08130458 @ =0x00000482
	adds r1, r5, r0
	movs r4, #0
	movs r0, #3
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r3, r5, r1
	ldr r1, [r3]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r0, #2
	orrs r0, r2
	strh r0, [r1]
	ldr r0, [r3]
	ldr r3, _0813045C @ =0x0000065C
	adds r0, r0, r3
	strh r4, [r0]
_08130442:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08130450: .4byte 0xFFFFFDFF
_08130454: .4byte 0x00004010
_08130458: .4byte 0x00000482
_0813045C: .4byte 0x0000065C
