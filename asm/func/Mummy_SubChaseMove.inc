	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081267A8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081267AC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081267AE
	.align 2, 0
_081267A8: .4byte 0x0000046C
_081267AC:
	movs r0, #0
_081267AE:
	cmp r0, #0
	beq _081267BE
	ldr r3, _08126804 @ =0x0000071E
	adds r0, r7, r3
	ldr r1, _08126808 @ =0xFFFFEFFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081267BE:
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081267D4
	b _08126B1E
_081267D4:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r2, _0812680C @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08126814
	ldr r4, _08126810 @ =0x00000482
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08126824
	.align 2, 0
_08126804: .4byte 0x0000071E
_08126808: .4byte 0xFFFFEFFF
_0812680C: .4byte 0x0000A02F
_08126810: .4byte 0x00000482
_08126814:
	ldr r1, _08126848 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08126824
	movs r0, #1
	strh r0, [r2]
_08126824:
	ldr r3, _0812684C @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08126850
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
	b _08126868
	.align 2, 0
_08126848: .4byte 0x00000482
_0812684C: .4byte 0x0000025D
_08126850:
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
_08126868:
	ldr r0, _081268A4 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl Map_ConsumeNavWaypointChanged
	cmp r0, #0
	bne _08126878
	b _08126AA0
_08126878:
	ldr r1, [r4]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0812688E
	b _08126B14
_0812688E:
	movs r2, #4
	ldr r3, _081268A8 @ =0x00000222
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081268AC
	movs r0, #1
	b _081268AE
	.align 2, 0
_081268A4: .4byte 0x000004A4
_081268A8: .4byte 0x00000222
_081268AC:
	movs r0, #0
_081268AE:
	cmp r0, #0
	beq _081268B4
	b _08126A70
_081268B4:
	adds r0, r5, #0
	bl FUN_080eb2a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081268C2
	b _08126B1E
_081268C2:
	movs r1, #1
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081268D0
	movs r0, #1
	b _081268D2
_081268D0:
	movs r0, #0
_081268D2:
	cmp r0, #0
	bne _081268D8
	b _08126A70
_081268D8:
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
	beq _081268FA
	b _08126B1E
_081268FA:
	movs r1, #4
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08126908
	movs r0, #1
	b _0812690A
_08126908:
	movs r0, #0
_0812690A:
	cmp r0, #0
	beq _08126910
	b _08126B1E
_08126910:
	movs r4, #0
	ldr r3, _08126A2C @ =0x0000046C
	adds r3, r5, r3
	str r3, [sp, #0x14]
	ldrb r7, [r5, #5]
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r0, r5, r0
	str r0, [sp, #0x24]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x30]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r2, r5
	mov sb, r2
	ldr r3, _08126A30 @ =0x00000553
	adds r3, r3, r5
	mov ip, r3
	ldr r0, _08126A34 @ =0x0000054F
	adds r0, r5, r0
	str r0, [sp, #0x40]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0xc]
	ldr r2, _08126A38 @ =0x0000054C
	adds r2, r5, r2
	str r2, [sp, #0x34]
	ldr r3, _08126A3C @ =0x00000469
	adds r3, r3, r5
	mov sl, r3
	ldr r0, _08126A40 @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x38]
	ldr r1, _08126A44 @ =0x0000046A
	adds r1, r1, r5
	mov r8, r1
	ldr r2, _08126A48 @ =0x0000054E
	adds r2, r5, r2
	str r2, [sp, #0x3c]
	ldr r3, _08126A4C @ =0x00000541
	adds r3, r5, r3
	str r3, [sp, #0x28]
	ldr r0, _08126A50 @ =0x000005BC
	adds r0, r5, r0
	str r0, [sp, #0x1c]
	ldr r1, _08126A54 @ =0x0000046D
	adds r1, r5, r1
	str r1, [sp, #0x18]
	ldr r2, _08126A58 @ =0x0000046B
	adds r2, r5, r2
	str r2, [sp, #0x10]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r5, r3
	str r3, [sp, #8]
	ldr r0, _08126A5C @ =0x00000484
	adds r0, r5, r0
	str r0, [sp, #0x20]
	ldr r1, _08126A60 @ =0x00000542
	adds r1, r5, r1
	str r1, [sp, #0x2c]
	ldr r6, _08126A64 @ =0x0203B400
	ldr r1, _08126A68 @ =0x030046B8
	ldr r2, _08126A6C @ =0x000003FF
	movs r5, #3
	adds r3, r7, #0
_0812699A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _081269B8
	adds r4, #1
	cmp r4, #3
	ble _0812699A
	adds r0, r7, #0
_081269B8:
	movs r3, #0
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	mov r4, sb
	ldr r0, [r4]
	ldr r1, [sp, #0x30]
	str r0, [r1]
	mov r2, ip
	ldrb r0, [r2]
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	ldr r2, [sp, #0x34]
	strb r0, [r2]
	mov r4, sl
	ldrb r0, [r4]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	mov r2, r8
	ldrb r0, [r2]
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	mov r0, sp
	ldrb r1, [r0, #4]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	ldr r4, [sp, #0x1c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x18]
	strb r1, [r4]
	ldr r4, [sp, #0x10]
	strb r3, [r4]
	mov r4, ip
	strb r0, [r4]
	mov r0, sb
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #8]
	strh r3, [r4]
	movs r0, #3
	ldr r4, [sp, #0xc]
	strb r0, [r4]
	mov r0, sl
	strb r1, [r0]
	mov r4, r8
	strb r2, [r4]
	ldr r0, [sp, #0x20]
	str r3, [r0]
	ldr r2, [sp, #0x14]
	strb r1, [r2]
	movs r0, #2
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	b _08126B1E
	.align 2, 0
_08126A2C: .4byte 0x0000046C
_08126A30: .4byte 0x00000553
_08126A34: .4byte 0x0000054F
_08126A38: .4byte 0x0000054C
_08126A3C: .4byte 0x00000469
_08126A40: .4byte 0x0000054D
_08126A44: .4byte 0x0000046A
_08126A48: .4byte 0x0000054E
_08126A4C: .4byte 0x00000541
_08126A50: .4byte 0x000005BC
_08126A54: .4byte 0x0000046D
_08126A58: .4byte 0x0000046B
_08126A5C: .4byte 0x00000484
_08126A60: .4byte 0x00000542
_08126A64: .4byte 0x0203B400
_08126A68: .4byte 0x030046B8
_08126A6C: .4byte 0x000003FF
_08126A70:
	movs r2, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08126A98 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08126A9C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08126B14
	.align 2, 0
_08126A98: .4byte 0x00000469
_08126A9C: .4byte 0x00000484
_08126AA0:
	ldr r1, [r4]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl Enemy_MoveAlongNav
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08126B14
	ldr r0, _08126B00 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08126AD8
	ldr r4, _08126B04 @ =0x000006FE
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _08126AD8
	adds r0, r5, #0
	bl Mummy_RouteToFloorEnd
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08126B1E
_08126AD8:
	movs r2, #0xe
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08126B08 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08126B0C @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08126B10 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08126B1E
	.align 2, 0
_08126B00: .4byte 0x03002BE0
_08126B04: .4byte 0x000006FE
_08126B08: .4byte 0x00000469
_08126B0C: .4byte 0x0000046A
_08126B10: .4byte 0x00000484
_08126B14:
	ldr r4, _08126B30 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08126B1E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08126B30: .4byte 0x00000484
