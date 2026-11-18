	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081B3C10 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B3C14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B3C16
	.align 2, 0
_081B3C10: .4byte 0x0000046C
_081B3C14:
	movs r0, #0
_081B3C16:
	cmp r0, #0
	beq _081B3C44
	ldr r4, _081B3C74 @ =FUN_081b197c
	movs r3, #0x23
	ldr r0, _081B3C78 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B3C7C @ =0x0000046B
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
_081B3C44:
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B3C84
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3C84
	ldr r1, _081B3C80 @ =0x0000065C
	adds r0, r7, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	b _081B3DC2
	.align 2, 0
_081B3C74: .4byte FUN_081b197c
_081B3C78: .4byte 0x0000046D
_081B3C7C: .4byte 0x0000046B
_081B3C80: .4byte 0x0000065C
_081B3C84:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r3, _081B3CB8 @ =0x00000482
	adds r1, r5, r3
	movs r0, #6
	strh r0, [r1]
	ldr r1, _081B3CBC @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B3CC0
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081B3CD0
	.align 2, 0
_081B3CB8: .4byte 0x00000482
_081B3CBC: .4byte 0x0000A02F
_081B3CC0:
	ldr r3, _081B3CF4 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081B3CD0
	movs r0, #1
	strh r0, [r2]
_081B3CD0:
	ldr r1, _081B3CF8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B3CFC
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
	b _081B3D14
	.align 2, 0
_081B3CF4: .4byte 0x00000482
_081B3CF8: .4byte 0x0000025D
_081B3CFC:
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
_081B3D14:
	ldr r2, _081B3D6C @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	adds r6, r0, #0
	cmp r6, #0
	bne _081B3D7C
	ldr r1, [r4]
	mov r3, r8
	str r3, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3DB8
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081B3D70 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r1, _081B3D74 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	ldr r1, _081B3D78 @ =0x0000065C
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081B3DC2
	.align 2, 0
_081B3D6C: .4byte 0x000004A4
_081B3D70: .4byte 0x00000469
_081B3D74: .4byte 0x0000046A
_081B3D78: .4byte 0x0000065C
_081B3D7C:
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_TurnTowardWaypoint
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B3DB8
	movs r2, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081B3DD0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081B3DB8:
	ldr r0, _081B3DD0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081B3DC2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B3DD0: .4byte 0x00000484
