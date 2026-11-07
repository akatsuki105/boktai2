	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0812FA54 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FA10
	movs r0, #0
	strb r0, [r1]
_0812FA10:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FA26
	b _0812FBD2
_0812FA26:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r1, _0812FA58 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812FA60
	ldr r3, _0812FA5C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0812FA70
	.align 2, 0
_0812FA54: .4byte 0x0000046C
_0812FA58: .4byte 0x0000A02F
_0812FA5C: .4byte 0x00000482
_0812FA60:
	ldr r1, _0812FA94 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0812FA70
	movs r0, #1
	strh r0, [r2]
_0812FA70:
	ldr r3, _0812FA98 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812FA9C
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
	b _0812FAB4
	.align 2, 0
_0812FA94: .4byte 0x00000482
_0812FA98: .4byte 0x0000025D
_0812FA9C:
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
_0812FAB4:
	movs r2, #0x80
	lsls r2, r2, #7
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	bne _0812FAF0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812FAE4
	movs r0, #1
	b _0812FAE6
_0812FAE4:
	movs r0, #0
_0812FAE6:
	cmp r0, #0
	bne _0812FAF0
	adds r0, r5, #0
	bl FUN_081307b0
_0812FAF0:
	ldr r3, _0812FB5C @ =0x000004A4
	adds r4, r5, r3
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	adds r6, r0, #0
	cmp r6, #0
	bne _0812FB6C
	ldr r1, [r4]
	mov r0, r8
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FBA8
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _0812FB60 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r6, [r0]
	ldr r0, _0812FB64 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812FB68 @ =0xFFFFBFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	b _0812FBD2
	.align 2, 0
_0812FB5C: .4byte 0x000004A4
_0812FB60: .4byte 0x00000469
_0812FB64: .4byte 0x0000046C
_0812FB68: .4byte 0xFFFFBFFF
_0812FB6C:
	ldr r1, [r4]
	mov r3, r8
	str r3, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FBA8
	movs r2, #6
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0812FBE0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _0812FBE4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_0812FBA8:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7]
	ands r0, r1
	cmp r0, #0
	bne _0812FBC8
	ldr r0, _0812FBE8 @ =0x0000065C
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0812FBC8
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	str r1, [r7]
_0812FBC8:
	ldr r3, _0812FBE4 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812FBD2:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812FBE0: .4byte 0x00000469
_0812FBE4: .4byte 0x00000484
_0812FBE8: .4byte 0x0000065C
