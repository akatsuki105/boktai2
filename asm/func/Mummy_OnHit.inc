	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	adds r5, r4, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08121B0A
	b _08121C26
_08121B0A:
	ldrh r0, [r6, #0xa]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08121BF8
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _08121B2C @ =0x0000071E
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08121B30
	movs r0, #1
	b _08121B32
	.align 2, 0
_08121B2C: .4byte 0x0000071E
_08121B30:
	movs r0, #0
_08121B32:
	cmp r0, #0
	bne _08121B42
	ldr r0, [r6, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08121C26
_08121B42:
	ldr r0, _08121BEC @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08121B78
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08121B78
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08121BF0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08121B78:
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	bl EnemyTargetManager_FindOwnerByID
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r5, r3
	str r0, [r1]
	adds r2, r6, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r3, [r4]
	cmp r3, #0
	bne _08121C26
	ldr r0, [r6, #0x4c]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08121C26
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #1
	str r1, [r0]
	ldr r2, _08121BF4 @ =0x0000049C
	adds r0, r5, r2
	movs r2, #4
	str r2, [r0]
	movs r6, #0x93
	lsls r6, r6, #3
	adds r0, r5, r6
	str r3, [r0]
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	subs r6, #0xe
	adds r0, r5, r6
	strh r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #0x1e
	strh r0, [r4]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	b _08121C26
	.align 2, 0
_08121BEC: .4byte 0xFFFFF7FF
_08121BF0: .4byte 0xFEFFFFFF
_08121BF4: .4byte 0x0000049C
_08121BF8:
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08121C26
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08121C26
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08121C2C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08121C26:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08121C2C: .4byte 0xFEFFFFFF
