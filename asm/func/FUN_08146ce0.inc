	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08146D08 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146D0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146D0E
	.align 2, 0
_08146D08: .4byte 0x0000046C
_08146D0C:
	movs r0, #0
_08146D0E:
	cmp r0, #0
	beq _08146D92
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r4, #0
	str r4, [r0]
	ldr r5, _08146E50 @ =0x00000482
	adds r1, r7, r5
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08146E54 @ =0x00000222
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _08146E58 @ =0x0000024E
	adds r0, r7, r2
	strh r4, [r0]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r3, r7, r5
	ldr r0, _08146E5C @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _08146E60 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08146D82
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _08146E64 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08146E68 @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	adds r5, #0x9e
	adds r0, r7, r5
	strh r4, [r0]
	ldr r1, _08146E6C @ =0x00000202
	adds r0, r7, r1
	strh r4, [r0]
_08146D82:
	ldr r0, _08146E70 @ =0xFFFFFBFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r2, _08146E74 @ =0x00000542
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
_08146D92:
	ldr r3, _08146E78 @ =0x00000484
	adds r4, r7, r3
	ldr r0, [r4]
	cmp r0, #0x1e
	bgt _08146D9E
	b _08146F88
_08146D9E:
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r4, r4, r7
	mov sb, r4
	ldr r1, _08146E7C @ =0xFFFFFEFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r5, #0xe6
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	movs r4, #1
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r6, #0
	movs r3, #0
	mov r8, r3
	adds r0, r4, #0
	orrs r0, r2
	strh r0, [r1]
	adds r5, #0x13
	adds r0, r7, r5
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08146E80 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r5, _08146E84 @ =0x0000046A
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _08146E78 @ =0x00000484
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r2, _08146E88 @ =FUN_080e6794
	movs r1, #0xe
	adds r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	subs r3, #1
	adds r0, r7, r3
	strb r6, [r0]
	ldr r4, _08146E8C @ =0x00000553
	adds r0, r7, r4
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	adds r3, #0x39
	adds r0, r7, r3
	ldr r6, [r0]
	adds r5, r7, #0
	adds r5, #8
	ldr r4, _08146E90 @ =0x00000684
	add r4, sl
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	mov r8, sb
	cmp r0, #0
	bne _08146E94
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, r4
	b _08146EB8
	.align 2, 0
_08146E50: .4byte 0x00000482
_08146E54: .4byte 0x00000222
_08146E58: .4byte 0x0000024E
_08146E5C: .4byte 0xFFFFFC7F
_08146E60: .4byte 0xF3FFFFFF
_08146E64: .4byte 0xFEFFFFFF
_08146E68: .4byte 0xFFFFFDFF
_08146E6C: .4byte 0x00000202
_08146E70: .4byte 0xFFFFFBFF
_08146E74: .4byte 0x00000542
_08146E78: .4byte 0x00000484
_08146E7C: .4byte 0xFFFFFEFF
_08146E80: .4byte 0x00000469
_08146E84: .4byte 0x0000046A
_08146E88: .4byte FUN_080e6794
_08146E8C: .4byte 0x00000553
_08146E90: .4byte 0x00000684
_08146E94:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08146EB2
	cmp r0, #2
	beq _08146EC0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08146EC0
_08146EB2:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
_08146EB8:
	ldr r1, _08146F14 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08146EC0:
	ldr r1, _08146F18 @ =0x00000684
	add r1, sl
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_IsPosInRect
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08146F24
	movs r1, #0xc1
	rsbs r1, r1, #0
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _08146F1C @ =0x00000551
	adds r0, r7, r2
	strb r6, [r0]
	ldr r3, _08146F20 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	b _08146F6A
	.align 2, 0
_08146F14: .4byte 0xFFFFFDFF
_08146F18: .4byte 0x00000684
_08146F1C: .4byte 0x00000551
_08146F20: .4byte 0x00000552
_08146F24:
	movs r1, #0xc1
	rsbs r1, r1, #0
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r5, _08146F74 @ =0x000005A4
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r4, _08146F78 @ =0x00000554
	adds r0, r7, r4
	str r1, [r0]
	str r3, [r2]
	subs r5, #0x54
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08146F7C @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08146F80 @ =0x00000552
	adds r0, r7, r3
	strb r1, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	add r2, sl
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08146F6A:
	ldr r4, _08146F84 @ =0x00000482
	adds r1, r7, r4
	movs r0, #1
	strh r0, [r1]
	b _08146F9C
	.align 2, 0
_08146F74: .4byte 0x000005A4
_08146F78: .4byte 0x00000554
_08146F7C: .4byte 0x00000551
_08146F80: .4byte 0x00000552
_08146F84: .4byte 0x00000482
_08146F88:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
_08146F9C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
