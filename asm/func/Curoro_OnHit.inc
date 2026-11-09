	push {r4, r5, r6, r7, lr}
	ldrh r0, [r1, #0xa]
	cmp r0, #1
	beq _0813A276
	b _0813A406
_0813A276:
	adds r5, r2, #0
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813A286
	b _0813A406
_0813A286:
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	ldr r2, _0813A2C0 @ =0x03002BE0
	ldr r0, [r2]
	movs r3, #0x2e
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	ldr r0, _0813A2C4 @ =0x03002B8C
	ldrh r0, [r0]
	movs r3, #0
	adds r6, r2, #0
	cmp r0, #0
	beq _0813A2AA
	ldr r0, _0813A2C8 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0813A2AA
	movs r3, #1
_0813A2AA:
	cmp r3, #0
	bne _0813A2BC
	ldr r0, [r6]
	movs r7, #0xd6
	lsls r7, r7, #2
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #3
	bne _0813A2CC
_0813A2BC:
	movs r0, #0x3c
	b _0813A2D0
	.align 2, 0
_0813A2C0: .4byte 0x03002BE0
_0813A2C4: .4byte 0x03002B8C
_0813A2C8: .4byte 0x03002B60
_0813A2CC:
	movs r0, #0x82
	lsls r0, r0, #1
_0813A2D0:
	subs r0, r0, r1
	cmp r0, #0
	bge _0813A2D8
	rsbs r0, r0, #0
_0813A2D8:
	cmp r0, #0x20
	ble _0813A2DE
	b _0813A406
_0813A2DE:
	ldr r3, _0813A3A4 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r1, _0813A3A8 @ =0x0000046D
	adds r0, r5, r1
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _0813A3AC @ =0x0000046B
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0
	strh r1, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0813A3B0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r4, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r5, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _0813A3B4 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r5, r7
	ldr r0, _0813A3B8 @ =0xFFFFFE7F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0813A3C0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r7, #0xcb
	lsls r7, r7, #3
	adds r0, r0, r7
	ldr r0, [r0]
	ands r0, r3
	ldr r0, [r6]
	movs r1, #0
	bl FUN_0807a904
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0813A3BC @ =0x000002AD
	bl PlaySound_082406e0
	b _0813A406
	.align 2, 0
_0813A3A4: .4byte Enemy_ClearStateBegun
_0813A3A8: .4byte 0x0000046D
_0813A3AC: .4byte 0x0000046B
_0813A3B0: .4byte 0x00000484
_0813A3B4: .4byte 0x00000474
_0813A3B8: .4byte 0xFFFFFE7F
_0813A3BC: .4byte 0x000002AD
_0813A3C0:
	movs r7, #0xe6
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r0, [r0]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r3
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r7, #0x90
	lsls r7, r7, #3
	adds r0, r5, r7
	ldrh r0, [r0]
	cmp r0, #1
	bne _0813A3FE
	ldr r0, [r6]
	movs r1, #1
	bl Player_InflictElementalCond
	b _0813A406
_0813A3FE:
	ldr r0, [r6]
	movs r1, #2
	bl Player_InflictElementalCond
_0813A406:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
