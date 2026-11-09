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
	ldr r2, _08183014 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08183018
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818301A
	.align 2, 0
_08183014: .4byte 0x0000046C
_08183018:
	movs r0, #0
_0818301A:
	cmp r0, #0
	beq _08183054
	ldr r4, _081830A0 @ =FUN_081807dc
	movs r3, #0x26
	ldr r0, _081830A4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081830A8 @ =0x0000046B
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
	movs r2, #0x20
	ldr r1, _081830AC @ =0x00000898
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08183054:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818306A
	b _081831B0
_0818306A:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r0, _081830B0 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081830B4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081830B8
	ldr r3, _081830B0 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081830C8
	.align 2, 0
_081830A0: .4byte FUN_081807dc
_081830A4: .4byte 0x0000046D
_081830A8: .4byte 0x0000046B
_081830AC: .4byte 0x00000898
_081830B0: .4byte 0x00000482
_081830B4: .4byte 0x0000A02F
_081830B8:
	ldr r1, _081830EC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081830C8
	movs r0, #1
	strh r0, [r2]
_081830C8:
	ldr r3, _081830F0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081830F4
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
	b _0818310C
	.align 2, 0
_081830EC: .4byte 0x00000482
_081830F0: .4byte 0x0000025D
_081830F4:
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
_0818310C:
	ldr r0, _08183160 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	adds r6, r0, #0
	cmp r6, #0
	bne _0818316C
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081831A6
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08183164 @ =0x00000469
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
	movs r2, #0x10
	ldr r1, _08183168 @ =0x00000898
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	b _081831AE
	.align 2, 0
_08183160: .4byte 0x000004A4
_08183164: .4byte 0x00000469
_08183168: .4byte 0x00000898
_0818316C:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081831A6
	movs r2, #0x10
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081831BC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081831C0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081831A6:
	ldr r0, _081831C0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
_081831AE:
	str r0, [r1]
_081831B0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081831BC: .4byte 0x00000469
_081831C0: .4byte 0x00000484
