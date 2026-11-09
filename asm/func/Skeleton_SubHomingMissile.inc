	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08110F14 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08110F18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08110F1A
	.align 2, 0
_08110F14: .4byte 0x0000046C
_08110F18:
	movs r0, #0
_08110F1A:
	cmp r0, #0
	beq _08110F5A
	movs r0, #0x80
	lsls r0, r0, #1
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r6, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08110FC8 @ =Skeleton_StateHomingMissileWindUp
	movs r2, #0x3e
	ldr r0, _08110FCC @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110FD0 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
_08110F5A:
	ldr r2, _08110FD0 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08110F66
	b _08111074
_08110F66:
	ldr r0, _08110FD4 @ =0x0000074C
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _08110FD8 @ =0x00000744
	add r0, r8
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r0, _08110FDC @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	bl Skeleton_PickFarPathNode
	ldr r1, _08110FE0 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _08110FE4
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08110FE4
	cmp r0, #2
	beq _08110FC2
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08110FC2:
	movs r0, #1
	b _08110FEE
	.align 2, 0
_08110FC8: .4byte Skeleton_StateHomingMissileWindUp
_08110FCC: .4byte 0x0000046D
_08110FD0: .4byte 0x0000046B
_08110FD4: .4byte 0x0000074C
_08110FD8: .4byte 0x00000744
_08110FDC: .4byte 0xFFFFFEFF
_08110FE0: .4byte 0x000004A4
_08110FE4:
	ldr r0, _08111000 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_08110FEE:
	cmp r0, #0
	bne _08111008
	ldr r2, _08111004 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _0811107E
	.align 2, 0
_08111000: .4byte 0xFFFFFDFF
_08111004: .4byte 0x000005C4
_08111008:
	ldr r3, _08111064 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r5, _08111068 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r6, r5
	movs r1, #0
	strh r2, [r0]
	movs r3, #0x12
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0811106C @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r6, r5
	str r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r1, _08111070 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _0811107E
	.align 2, 0
_08111064: .4byte Enemy_ClearStateBegun
_08111068: .4byte 0x0000046D
_0811106C: .4byte 0x0000046A
_08111070: .4byte 0x00000714
_08111074:
	ldr r2, _0811108C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811107E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811108C: .4byte 0x00000484
