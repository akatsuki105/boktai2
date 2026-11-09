	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816E1C4 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816E1C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816E1CA
	.align 2, 0
_0816E1C4: .4byte 0x0000046C
_0816E1C8:
	movs r0, #0
_0816E1CA:
	ldr r3, _0816E298 @ =0x03002BE0
	mov ip, r3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r6, r5, r1
	cmp r0, #0
	beq _0816E236
	ldr r4, _0816E29C @ =Ghost_StateDrainPlayer
	movs r3, #0x22
	ldr r2, _0816E2A0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816E2A4 @ =0x0000046B
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
	ldr r3, _0816E2A8 @ =0x00000878
	adds r2, r7, r3
	mov r1, ip
	ldr r0, [r1]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	strb r0, [r5, #5]
_0816E236:
	ldr r2, _0816E2AC @ =0x00000494
	adds r1, r5, r2
	movs r0, #0x40
	strh r0, [r1]
	mov r4, sp
	ldr r3, _0816E2A8 @ =0x00000878
	adds r2, r7, r3
	mov r1, ip
	ldr r0, [r1]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	mov r1, ip
	ldr r0, [r1]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0816E2B0 @ =0x0000A02F
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816E2B8
	ldr r2, _0816E2B4 @ =0x00000482
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0816E2C8
	.align 2, 0
_0816E298: .4byte 0x03002BE0
_0816E29C: .4byte Ghost_StateDrainPlayer
_0816E2A0: .4byte 0x0000046D
_0816E2A4: .4byte 0x0000046B
_0816E2A8: .4byte 0x00000878
_0816E2AC: .4byte 0x00000494
_0816E2B0: .4byte 0x0000A02F
_0816E2B4: .4byte 0x00000482
_0816E2B8:
	ldr r3, _0816E2EC @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0816E2C8
	movs r0, #1
	strh r0, [r2]
_0816E2C8:
	ldr r6, _0816E2F0 @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E2F4
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
	b _0816E30C
	.align 2, 0
_0816E2EC: .4byte 0x00000482
_0816E2F0: .4byte 0x0000025D
_0816E2F4:
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
_0816E30C:
	ldr r1, _0816E38C @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816E326
	ldr r0, _0816E390 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816E3A0
_0816E326:
	movs r0, #0xf3
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _0816E394 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _0816E398 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0816E39C @ =Enemy_ClearStateBegun
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816E38C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	adds r2, r5, #0
	adds r2, #0xd8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	b _0816E3AA
	.align 2, 0
_0816E38C: .4byte 0x0000046B
_0816E390: .4byte 0x03002BE0
_0816E394: .4byte 0x00000469
_0816E398: .4byte 0x0000046C
_0816E39C: .4byte Enemy_ClearStateBegun
_0816E3A0:
	ldr r6, _0816E3B4 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816E3AA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816E3B4: .4byte 0x00000484
