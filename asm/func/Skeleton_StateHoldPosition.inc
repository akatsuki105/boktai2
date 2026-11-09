	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0810DA88 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810DA8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810DA8E
	.align 2, 0
_0810DA88: .4byte 0x0000046D
_0810DA8C:
	movs r0, #0
_0810DA8E:
	cmp r0, #0
	beq _0810DA9C
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _0810DB9E
_0810DA9C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0xec
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0810DABA
	ldr r0, _0810DAD0 @ =0x0000075C
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810DAD8
_0810DABA:
	movs r0, #0xe6
	lsls r0, r0, #3
	add r0, r8
	ldr r1, _0810DAD4 @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl Skeleton_RetreatOrChase
	b _0810DB9E
	.align 2, 0
_0810DAD0: .4byte 0x0000075C
_0810DAD4: .4byte 0xFFFFFEFF
_0810DAD8:
	adds r0, r5, #0
	bl Skeleton_CanAttack
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0810DB9E
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r2, _0810DB18 @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810DB1C
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0810DB42
	.align 2, 0
_0810DB18: .4byte 0x000004A4
_0810DB1C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810DB3C
	cmp r0, #2
	beq _0810DB38
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810DB38:
	movs r0, #1
	b _0810DB4C
_0810DB3C:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_0810DB42:
	ldr r1, _0810DB60 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0810DB4C:
	cmp r0, #0
	bne _0810DB68
	ldr r2, _0810DB64 @ =0x000005C4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _0810DB9E
	.align 2, 0
_0810DB60: .4byte 0xFFFFFDFF
_0810DB64: .4byte 0x000005C4
_0810DB68:
	movs r2, #0xe6
	lsls r2, r2, #3
	add r2, r8
	ldr r1, _0810DBA8 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0810DBAC @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0810DB9E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810DBA8: .4byte 0xFFFFFEFF
_0810DBAC: .4byte 0x00000484
