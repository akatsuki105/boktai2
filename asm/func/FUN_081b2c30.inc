	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081B2C58 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B2C5C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B2C5E
	.align 2, 0
_081B2C58: .4byte 0x0000046C
_081B2C5C:
	movs r0, #0
_081B2C5E:
	cmp r0, #0
	beq _081B2CAC
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _081B2D8C @ =FUN_081aec90
	movs r2, #0x22
	ldr r0, _081B2D90 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B2D94 @ =0x0000046B
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081B2D98 @ =0x00000553
	adds r0, r7, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r0, _081B2D9C @ =0x00000672
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, sb
	strh r1, [r0]
_081B2CAC:
	ldr r3, _081B2D94 @ =0x0000046B
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B2CB8
	b _081B2E0C
_081B2CB8:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	ldr r1, _081B2DA0 @ =0xFFFFFEFF
	ldrh r0, [r5]
	ands r1, r0
	movs r4, #0
	movs r6, #0
	strh r1, [r5]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, _081B2DA4 @ =0x0000067E
	add r0, sb
	ldrh r3, [r0]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r5, #0xc
	mov ip, r5
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r5, _081B2DA8 @ =0x00000554
	adds r0, r7, r5
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B2DAC @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B2DB0 @ =0x00000552
	adds r0, r7, r3
	mov r5, ip
	strb r5, [r0]
	ldr r2, _081B2DB4 @ =Enemy_WaitPendingState
	movs r1, #0xe
	subs r3, #0xe5
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081B2D94 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081B2DB8 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B2DBC @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r6, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	adds r2, #0x3a
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xcc
	lsls r4, r4, #3
	add r4, sb
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B2DC4
	ldr r0, _081B2DC0 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _081B2DEE
	.align 2, 0
_081B2D8C: .4byte FUN_081aec90
_081B2D90: .4byte 0x0000046D
_081B2D94: .4byte 0x0000046B
_081B2D98: .4byte 0x00000553
_081B2D9C: .4byte 0x00000672
_081B2DA0: .4byte 0xFFFFFEFF
_081B2DA4: .4byte 0x0000067E
_081B2DA8: .4byte 0x00000554
_081B2DAC: .4byte 0x00000551
_081B2DB0: .4byte 0x00000552
_081B2DB4: .4byte Enemy_WaitPendingState
_081B2DB8: .4byte 0x00000469
_081B2DBC: .4byte 0x0000046A
_081B2DC0: .4byte 0xFFFFFDFF
_081B2DC4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B2DE4
	cmp r0, #2
	beq _081B2DE0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B2DE0:
	movs r0, #1
	b _081B2DF0
_081B2DE4:
	ldr r0, _081B2E04 @ =0xFFFFFDFF
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081B2DEE:
	movs r0, #0
_081B2DF0:
	cmp r0, #0
	bne _081B2E16
	ldr r1, _081B2E08 @ =0x000005C4
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B2E16
	.align 2, 0
_081B2E04: .4byte 0xFFFFFDFF
_081B2E08: .4byte 0x000005C4
_081B2E0C:
	ldr r2, _081B2E24 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B2E16:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B2E24: .4byte 0x00000484
