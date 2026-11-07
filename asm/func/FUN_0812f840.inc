	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0812F880 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F854
	movs r0, #0
	strb r0, [r1]
_0812F854:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _0812F884 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812F88C
	ldr r3, _0812F888 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0812F89C
	.align 2, 0
_0812F880: .4byte 0x0000046C
_0812F884: .4byte 0x0000A02F
_0812F888: .4byte 0x00000482
_0812F88C:
	ldr r4, _0812F8C0 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0812F89C
	movs r0, #1
	strh r0, [r2]
_0812F89C:
	ldr r1, _0812F8C4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812F8C8
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
	b _0812F8E0
	.align 2, 0
_0812F8C0: .4byte 0x00000482
_0812F8C4: .4byte 0x0000025D
_0812F8C8:
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
_0812F8E0:
	ldr r2, _0812F92C @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	cmp r0, #0
	beq _0812F938
	ldr r1, [r4]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812F938
	movs r2, #0xd
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0812F930 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _0812F934 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0812F9DE
	.align 2, 0
_0812F92C: .4byte 0x000004A4
_0812F930: .4byte 0x00000469
_0812F934: .4byte 0x0000046C
_0812F938:
	ldr r1, _0812F9B0 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812F9C4
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0812F9B4 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _0812F9B8 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0812F9BC @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	ldr r4, _0812F9C0 @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl Enemy_StepTowardPathNode
	b _0812F9DE
	.align 2, 0
_0812F9B0: .4byte 0x000004A4
_0812F9B4: .4byte 0x00000469
_0812F9B8: .4byte 0x0000046A
_0812F9BC: .4byte 0x00000484
_0812F9C0: .4byte 0x0000046D
_0812F9C4:
	ldr r4, _0812F9E8 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0812F9DE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812F9E8: .4byte 0x00000484
