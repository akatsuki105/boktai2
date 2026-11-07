	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _0816362C @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08163630
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _08163632
	.align 2, 0
_0816362C: .4byte 0x0000046D
_08163630:
	movs r0, #0
_08163632:
	cmp r0, #0
	beq _0816366A
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081636C0 @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnimNoFacing
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816366A:
	movs r7, #0
	strh r7, [r5, #8]
	movs r0, #5
	strh r0, [r5, #0xe]
	adds r0, r6, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0816368C
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0816368C:
	cmp r6, #0x1e
	ble _081636B8
	ldr r3, _081636C4 @ =FUN_081636d4
	movs r2, #0x2a
	ldr r0, _081636C8 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081636CC @ =0x0000046B
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _081636D0 @ =0x00000553
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r7, [r0]
_081636B8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081636C0: .4byte 0x00000482
_081636C4: .4byte FUN_081636d4
_081636C8: .4byte 0x0000046D
_081636CC: .4byte 0x0000046B
_081636D0: .4byte 0x00000553
