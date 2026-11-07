	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08130604
	bl Coffin_GetPos
	adds r4, r0, #0
	cmp r4, #0
	beq _08130604
	ldr r2, _08130550 @ =0x000004A4
	adds r0, r6, r2
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08130554
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
	b _0813057A
	.align 2, 0
_08130550: .4byte 0x000004A4
_08130554:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08130574
	cmp r0, #2
	beq _08130570
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08130570:
	movs r0, #1
	b _08130584
_08130574:
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r6, r7
_0813057A:
	ldr r1, _081305F4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08130584:
	cmp r0, #0
	beq _08130604
	movs r5, #4
	movs r1, #0xcc
	lsls r1, r1, #3
	add r1, r8
	ldrh r2, [r1]
	movs r0, #4
	movs r3, #0
	movs r4, #0
	orrs r0, r2
	strh r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r2, [r0]
	movs r1, #1
	ldr r7, _081305F8 @ =0x0000046D
	adds r0, r6, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0x25
	adds r0, r6, r7
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r2, #7
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _081305FC @ =0x0000046A
	adds r0, r6, r3
	strb r2, [r0]
	adds r7, #0x1b
	adds r0, r6, r7
	str r4, [r0]
	ldr r2, _08130600 @ =0x0000046C
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, #0x18
	adds r0, r6, r3
	strh r5, [r0]
	movs r0, #1
	b _08130606
	.align 2, 0
_081305F4: .4byte 0xFFFFFDFF
_081305F8: .4byte 0x0000046D
_081305FC: .4byte 0x0000046A
_08130600: .4byte 0x0000046C
_08130604:
	movs r0, #0
_08130606:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
