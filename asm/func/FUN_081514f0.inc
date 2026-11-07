	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08151518 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0815151C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815151E
	.align 2, 0
_08151518: .4byte 0x0000046C
_0815151C:
	movs r0, #0
_0815151E:
	cmp r0, #0
	beq _0815155A
	ldr r4, _0815158C @ =FUN_0814e530
	movs r3, #0x29
	ldr r0, _08151590 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08151594 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #8
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0815155A:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r3, _08151598 @ =0x00000482
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r1, _0815159C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081515A0
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081515B0
	.align 2, 0
_0815158C: .4byte FUN_0814e530
_08151590: .4byte 0x0000046D
_08151594: .4byte 0x0000046B
_08151598: .4byte 0x00000482
_0815159C: .4byte 0x0000A02F
_081515A0:
	ldr r3, _081515D4 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081515B0
	movs r0, #1
	strh r0, [r2]
_081515B0:
	ldr r1, _081515D8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081515DC
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081515F4
	.align 2, 0
_081515D4: .4byte 0x00000482
_081515D8: .4byte 0x0000025D
_081515DC:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081515F4:
	ldr r2, _0815164C @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	adds r6, r0, #0
	cmp r6, #0
	bne _08151654
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815168E
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08151650 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r2, #4
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	b _081516C2
	.align 2, 0
_0815164C: .4byte 0x000004A4
_08151650: .4byte 0x00000469
_08151654:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815168E
	movs r2, #0x12
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081516D0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081516D4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_0815168E:
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081516BA
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081516C4
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081516C4
_081516BA:
	ldr r2, _081516D4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
_081516C2:
	str r0, [r1]
_081516C4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081516D0: .4byte 0x00000469
_081516D4: .4byte 0x00000484
