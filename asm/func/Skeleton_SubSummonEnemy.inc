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
	ldr r2, _08111290 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08111294
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08111296
	.align 2, 0
_08111290: .4byte 0x0000046C
_08111294:
	movs r0, #0
_08111296:
	cmp r0, #0
	beq _081112E2
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
	ldr r4, _08111360 @ =Skeleton_StateSummonEnemyWindUp
	movs r2, #0x44
	ldr r0, _08111364 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08111368 @ =0x0000046B
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
	ldr r2, _0811136C @ =0x000006FC
	add r2, r8
	movs r0, #2
	ldrh r1, [r2, #0x26]
	orrs r0, r1
	strh r0, [r2, #0x26]
_081112E2:
	ldr r2, _08111368 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081112EE
	b _08111408
_081112EE:
	ldr r2, _0811136C @ =0x000006FC
	add r2, r8
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #3
	add r0, r8
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r0, _08111370 @ =0xFFFFFEFF
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
	ldr r1, _08111374 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _08111378
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08111378
	cmp r0, #2
	beq _0811135C
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811135C:
	movs r0, #1
	b _08111382
	.align 2, 0
_08111360: .4byte Skeleton_StateSummonEnemyWindUp
_08111364: .4byte 0x0000046D
_08111368: .4byte 0x0000046B
_0811136C: .4byte 0x000006FC
_08111370: .4byte 0xFFFFFEFF
_08111374: .4byte 0x000004A4
_08111378:
	ldr r0, _08111394 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_08111382:
	cmp r0, #0
	bne _0811139C
	ldr r2, _08111398 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _08111412
	.align 2, 0
_08111394: .4byte 0xFFFFFDFF
_08111398: .4byte 0x000005C4
_0811139C:
	ldr r3, _081113F8 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r5, _081113FC @ =0x0000046D
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
	ldr r1, _08111400 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r6, r5
	str r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r1, _08111404 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _08111412
	.align 2, 0
_081113F8: .4byte Enemy_ClearStateBegun
_081113FC: .4byte 0x0000046D
_08111400: .4byte 0x0000046A
_08111404: .4byte 0x00000714
_08111408:
	ldr r2, _08111420 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08111412:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08111420: .4byte 0x00000484
