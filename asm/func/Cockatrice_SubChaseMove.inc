	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	ldr r0, _08158A90 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158A3C
	movs r0, #0
	strb r0, [r1]
_08158A3C:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158A52
	b _08158D7A
_08158A52:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158A60
	b _08158D7A
_08158A60:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r2, _08158A94 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08158A9C
	ldr r4, _08158A98 @ =0x00000482
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08158AAC
	.align 2, 0
_08158A90: .4byte 0x0000046C
_08158A94: .4byte 0x0000A02F
_08158A98: .4byte 0x00000482
_08158A9C:
	ldr r1, _08158AD0 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08158AAC
	movs r0, #1
	strh r0, [r2]
_08158AAC:
	ldr r3, _08158AD4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08158AD8
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
	b _08158AF0
	.align 2, 0
_08158AD0: .4byte 0x00000482
_08158AD4: .4byte 0x0000025D
_08158AD8:
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
_08158AF0:
	ldr r0, _08158B2C @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	adds r6, r0, #0
	cmp r6, #0
	bne _08158B02
	b _08158D28
_08158B02:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_TurnTowardWaypoint
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08158B18
	b _08158D70
_08158B18:
	movs r2, #4
	ldr r3, _08158B30 @ =0x00000222
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08158B34
	movs r0, #1
	b _08158B36
	.align 2, 0
_08158B2C: .4byte 0x000004A4
_08158B30: .4byte 0x00000222
_08158B34:
	movs r0, #0
_08158B36:
	cmp r0, #0
	beq _08158B3C
	b _08158CF8
_08158B3C:
	adds r0, r5, #0
	bl FUN_0815d6d0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158B4A
	b _08158D7A
_08158B4A:
	movs r1, #1
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08158B58
	movs r0, #1
	b _08158B5A
_08158B58:
	movs r0, #0
_08158B5A:
	cmp r0, #0
	bne _08158B60
	b _08158CF8
_08158B60:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08158B82
	b _08158D7A
_08158B82:
	movs r1, #4
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08158B90
	movs r0, #1
	b _08158B92
_08158B90:
	movs r0, #0
_08158B92:
	cmp r0, #0
	beq _08158B98
	b _08158D7A
_08158B98:
	movs r4, #0
	ldr r3, _08158CB4 @ =0x0000046C
	adds r3, r5, r3
	str r3, [sp, #0x3c]
	ldrb r7, [r5, #5]
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r0, r5, r0
	str r0, [sp, #0x10]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x1c]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r2, r5
	mov sb, r2
	ldr r3, _08158CB8 @ =0x00000553
	adds r3, r3, r5
	mov ip, r3
	ldr r0, _08158CBC @ =0x0000054F
	adds r0, r5, r0
	str r0, [sp, #0x2c]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x34]
	ldr r2, _08158CC0 @ =0x0000054C
	adds r2, r5, r2
	str r2, [sp, #0x20]
	ldr r3, _08158CC4 @ =0x00000469
	adds r3, r3, r5
	mov sl, r3
	ldr r0, _08158CC8 @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x24]
	ldr r1, _08158CCC @ =0x0000046A
	adds r1, r1, r5
	mov r8, r1
	ldr r2, _08158CD0 @ =0x0000054E
	adds r2, r5, r2
	str r2, [sp, #0x28]
	ldr r3, _08158CD4 @ =0x00000541
	adds r3, r5, r3
	str r3, [sp, #0x14]
	ldr r0, _08158CD8 @ =0x000005BC
	adds r0, r5, r0
	str r0, [sp, #0xc]
	ldr r1, _08158CDC @ =0x0000046D
	adds r1, r5, r1
	str r1, [sp, #0x40]
	ldr r2, _08158CE0 @ =0x0000046B
	adds r2, r5, r2
	str r2, [sp, #0x38]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r5, r3
	str r3, [sp, #0x30]
	ldr r0, _08158CE4 @ =0x00000484
	adds r0, r5, r0
	str r0, [sp, #8]
	ldr r1, _08158CE8 @ =0x00000542
	adds r1, r5, r1
	str r1, [sp, #0x18]
	ldr r2, _08158CEC @ =0x0203B400
	ldr r1, _08158CF0 @ =0x030046B8
	ldr r6, _08158CF4 @ =0x000003FF
	movs r5, #3
	adds r3, r7, #0
_08158C22:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _08158C40
	adds r4, #1
	cmp r4, #3
	ble _08158C22
	adds r0, r7, #0
_08158C40:
	movs r3, #0
	ldr r2, [sp, #0x10]
	strb r0, [r2]
	mov r4, sb
	ldr r0, [r4]
	ldr r1, [sp, #0x1c]
	str r0, [r1]
	mov r2, ip
	ldrb r0, [r2]
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	ldr r2, [sp, #0x20]
	strb r0, [r2]
	mov r4, sl
	ldrb r0, [r4]
	ldr r1, [sp, #0x24]
	strb r0, [r1]
	mov r2, r8
	ldrb r0, [r2]
	ldr r4, [sp, #0x28]
	strb r0, [r4]
	mov r0, sp
	ldrb r1, [r0, #4]
	ldr r0, [sp, #0x14]
	strb r1, [r0]
	ldr r4, [sp, #0xc]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r4, [sp, #0x38]
	strb r3, [r4]
	mov r4, ip
	strb r0, [r4]
	mov r0, sb
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	mov r0, sl
	strb r1, [r0]
	mov r4, r8
	strb r2, [r4]
	ldr r0, [sp, #8]
	str r3, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	movs r0, #2
	ldr r3, [sp, #0x18]
	strb r0, [r3]
	b _08158D7A
	.align 2, 0
_08158CB4: .4byte 0x0000046C
_08158CB8: .4byte 0x00000553
_08158CBC: .4byte 0x0000054F
_08158CC0: .4byte 0x0000054C
_08158CC4: .4byte 0x00000469
_08158CC8: .4byte 0x0000054D
_08158CCC: .4byte 0x0000046A
_08158CD0: .4byte 0x0000054E
_08158CD4: .4byte 0x00000541
_08158CD8: .4byte 0x000005BC
_08158CDC: .4byte 0x0000046D
_08158CE0: .4byte 0x0000046B
_08158CE4: .4byte 0x00000484
_08158CE8: .4byte 0x00000542
_08158CEC: .4byte 0x0203B400
_08158CF0: .4byte 0x030046B8
_08158CF4: .4byte 0x000003FF
_08158CF8:
	movs r2, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08158D20 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08158D24 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08158D70
	.align 2, 0
_08158D20: .4byte 0x00000469
_08158D24: .4byte 0x00000484
_08158D28:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158D70
	movs r1, #0xe
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r6, [r0]
	ldr r2, _08158D64 @ =0x00000469
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08158D68 @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r6, [r0]
	ldr r0, _08158D6C @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08158D7A
	.align 2, 0
_08158D64: .4byte 0x00000469
_08158D68: .4byte 0x0000046A
_08158D6C: .4byte 0x0000046C
_08158D70:
	ldr r2, _08158D8C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158D7A:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158D8C: .4byte 0x00000484
