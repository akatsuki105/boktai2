	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816DF40
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r7, _0816DF08 @ =0x000007DC
	adds r0, r0, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816DF0C
	movs r0, #1
	b _0816DF0E
	.align 2, 0
_0816DF08: .4byte 0x000007DC
_0816DF0C:
	movs r0, #0
_0816DF0E:
	cmp r0, #0
	beq _0816DF38
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0816DF34 @ =0x000007DC
	adds r1, r1, r2
	movs r2, #0x21
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	b _0816E116
	.align 2, 0
_0816DF34: .4byte 0x000007DC
_0816DF38:
	adds r0, r4, #0
	bl Ghost_UpdateBlink
	b _0816E116
_0816DF40:
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0816DF56
	b _0816E0FE
_0816DF56:
	ldr r0, _0816DF78 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #7
	ands r1, r2
	adds r6, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r7, _0816DF7C @ =0x000007DC
	adds r1, r5, r7
	ldr r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0816DF80
	movs r0, #1
	b _0816DF82
	.align 2, 0
_0816DF78: .4byte 0x030047A4
_0816DF7C: .4byte 0x000007DC
_0816DF80:
	movs r0, #0
_0816DF82:
	cmp r0, #0
	beq _0816DFAC
	movs r2, #0x20
	ldr r1, _0816DFA0 @ =0x030046A0
	ldr r0, [r1]
	ldr r7, _0816DFA4 @ =0x00000934
	adds r0, r0, r7
	ldrh r0, [r0]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0816DFA8
	movs r0, #1
	b _0816DFBA
	.align 2, 0
_0816DFA0: .4byte 0x030046A0
_0816DFA4: .4byte 0x00000934
_0816DFA8:
	movs r0, #0
	b _0816DFBA
_0816DFAC:
	ldr r1, _0816DFF0 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _0816DFF4 @ =0x00000942
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	adds r2, r1, #0
_0816DFBA:
	cmp r0, #0
	ble _0816E0A4
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816E008
	ldr r0, _0816DFF8 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0816E004
	ldr r2, _0816DFFC @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0816DFEA
	ldr r6, _0816E000 @ =0x00000442
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #4
	bne _0816DFEA
	movs r2, #1
_0816DFEA:
	adds r0, r2, #0
	b _0816E036
	.align 2, 0
_0816DFF0: .4byte 0x030046A0
_0816DFF4: .4byte 0x00000942
_0816DFF8: .4byte 0x03002BE0
_0816DFFC: .4byte 0x00000446
_0816E000: .4byte 0x00000442
_0816E004:
	movs r0, #0
	b _0816E036
_0816E008:
	ldr r0, _0816E048 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0816E0A4
	ldr r0, [r2]
	movs r7, #0x94
	lsls r7, r7, #2
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	beq _0816E0A4
	ldr r0, _0816E04C @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0816E034
	ldr r0, _0816E050 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0816E034
	movs r1, #1
_0816E034:
	adds r0, r1, #0
_0816E036:
	cmp r0, #0
	bne _0816E0A4
	movs r1, #0x40
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0816E054
	movs r0, #1
	b _0816E056
	.align 2, 0
_0816E048: .4byte 0x03002B48
_0816E04C: .4byte 0x03002B8C
_0816E050: .4byte 0x03002B60
_0816E054:
	movs r0, #0
_0816E056:
	cmp r0, #0
	bne _0816E0FE
	movs r1, #1
	ldr r2, _0816E074 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E078
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816E082
	b _0816E086
	.align 2, 0
_0816E074: .4byte 0x0000025D
_0816E078:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0816E086
_0816E082:
	movs r0, #1
	b _0816E088
_0816E086:
	movs r0, #0
_0816E088:
	adds r1, r0, #0
	cmp r1, #0
	bne _0816E0FE
	ldr r6, _0816E0A0 @ =0x00000836
	adds r0, r5, r6
	strh r1, [r0]
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	movs r1, #0x40
	b _0816E0FA
	.align 2, 0
_0816E0A0: .4byte 0x00000836
_0816E0A4:
	movs r1, #0x20
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0816E0B2
	movs r0, #1
	b _0816E0B4
_0816E0B2:
	movs r0, #0
_0816E0B4:
	cmp r0, #0
	bne _0816E0FE
	movs r1, #1
	ldr r7, _0816E0D0 @ =0x0000025D
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E0D4
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816E0DE
	b _0816E0E2
	.align 2, 0
_0816E0D0: .4byte 0x0000025D
_0816E0D4:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0816E0E2
_0816E0DE:
	movs r0, #1
	b _0816E0E4
_0816E0E2:
	movs r0, #0
_0816E0E4:
	cmp r0, #0
	beq _0816E0FE
	ldr r0, _0816E124 @ =0x00000836
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	movs r1, #0x20
_0816E0FA:
	orrs r0, r1
	str r0, [r3]
_0816E0FE:
	adds r0, r4, #0
	bl Ghost_UpdateBlink
	adds r0, r4, #0
	bl Ghost_TickVisibleTimer
	adds r0, r4, #0
	bl Ghost_UpdateChaseTimeout
	adds r0, r4, #0
	bl Ghost_DetectMovingPlayer
_0816E116:
	adds r0, r4, #0
	bl Ghost_FollowPlayerHeight
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0816E124: .4byte 0x00000836
