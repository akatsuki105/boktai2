	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081587D0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081587A4
	movs r0, #0
	strb r0, [r1]
_081587A4:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r1, _081587D4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081587DC
	ldr r0, _081587D8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081587EC
	.align 2, 0
_081587D0: .4byte 0x0000046C
_081587D4: .4byte 0x0000A02F
_081587D8: .4byte 0x00000482
_081587DC:
	ldr r1, _08158810 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081587EC
	movs r0, #1
	strh r0, [r2]
_081587EC:
	ldr r1, _08158814 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08158818
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
	b _08158830
	.align 2, 0
_08158810: .4byte 0x00000482
_08158814: .4byte 0x0000025D
_08158818:
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
_08158830:
	movs r2, #2
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _08158846
	movs r0, #1
	b _08158848
_08158846:
	movs r0, #0
_08158848:
	adds r6, r0, #0
	cmp r6, #0
	bne _081588A0
	ldr r1, _08158898 @ =0x000004A4
	adds r4, r5, r1
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	cmp r0, #0
	beq _081588A0
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081588F8
	movs r1, #0x14
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0815889C @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081588F8
	.align 2, 0
_08158898: .4byte 0x000004A4
_0815889C: .4byte 0x00000484
_081588A0:
	ldr r1, _081588EC @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081588F8
	movs r2, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _081588F0 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r5, r2
	str r1, [r0]
	ldr r0, _081588F4 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	b _08158902
	.align 2, 0
_081588EC: .4byte 0x000004A4
_081588F0: .4byte 0x00000469
_081588F4: .4byte 0x0000046C
_081588F8:
	ldr r2, _08158910 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158902:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158910: .4byte 0x00000484
