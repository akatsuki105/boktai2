	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818E31E
	b _0818E514
_0818E31E:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r1, #0x20
	ldr r2, _0818E338 @ =0x00000F2C
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818E33C
	movs r0, #1
	b _0818E33E
	.align 2, 0
_0818E338: .4byte 0x00000F2C
_0818E33C:
	movs r0, #0
_0818E33E:
	adds r4, r0, #0
	cmp r4, #0
	beq _0818E346
	b _0818E514
_0818E346:
	ldr r3, _0818E3C4 @ =0x00000ED8
	adds r0, r7, r3
	ldrh r2, [r0]
	cmp r2, #0
	bne _0818E35C
	ldr r6, _0818E3C8 @ =0x0000048A
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _0818E35C
	b _0818E504
_0818E35C:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, r0, r2
	movs r3, #0
	strh r0, [r1]
	movs r2, #0
	ldrsh r6, [r1, r2]
	ldr r0, _0818E3C8 @ =0x0000048A
	adds r2, r5, r0
	ldrh r0, [r2]
	subs r0, r6, r0
	cmp r0, #0
	ble _0818E37C
	b _0818E4EC
_0818E37C:
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r4, [r0]
	adds r6, #5
	adds r0, r5, r6
	strb r3, [r0]
	ldr r6, _0818E3CC @ =0x0000048C
	adds r0, r5, r6
	strb r3, [r0]
	strh r4, [r2]
	ldr r2, _0818E3D0 @ =0x000004BE
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #0x20
	ldr r6, _0818E3D4 @ =0x00000F2C
	adds r0, r0, r6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	movs r2, #4
	adds r1, r7, r6
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0818E3D8
	movs r0, #1
	b _0818E3DA
	.align 2, 0
_0818E3C4: .4byte 0x00000ED8
_0818E3C8: .4byte 0x0000048A
_0818E3CC: .4byte 0x0000048C
_0818E3D0: .4byte 0x000004BE
_0818E3D4: .4byte 0x00000F2C
_0818E3D8:
	movs r0, #0
_0818E3DA:
	cmp r0, #0
	bne _0818E4B8
	movs r1, #0x80
	lsls r1, r1, #6
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818E3EE
	movs r0, #1
	b _0818E3F0
_0818E3EE:
	movs r0, #0
_0818E3F0:
	adds r4, r0, #0
	cmp r4, #0
	beq _0818E468
	ldr r2, _0818E454 @ =FUN_0818a47c
	movs r1, #0x2a
	ldr r3, _0818E458 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0818E45C @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818E460 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r2, _0818E464 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0818E4B8
	.align 2, 0
_0818E454: .4byte FUN_0818a47c
_0818E458: .4byte 0x0000046D
_0818E45C: .4byte 0x0000046B
_0818E460: .4byte 0x00000469
_0818E464: .4byte 0x0000046C
_0818E468:
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _0818E4D8 @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _0818E4DC @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #0xd
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818E4E0 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0818E4E4 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
_0818E4B8:
	ldrh r0, [r5]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _0818E4E8 @ =0x0000025A
	adds r1, r5, r3
	ldrh r3, [r1]
	movs r1, #0
	str r1, [sp]
	bl HUD_ShowEnemyGauge
	bl FUN_080df478
	b _0818E504
	.align 2, 0
_0818E4D8: .4byte 0x0000046D
_0818E4DC: .4byte 0x0000046B
_0818E4E0: .4byte 0x0000046A
_0818E4E4: .4byte 0x00000484
_0818E4E8: .4byte 0x0000025A
_0818E4EC:
	ldrh r0, [r5]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _0818E51C @ =0x0000025A
	adds r1, r5, r3
	ldrh r3, [r1]
	str r4, [sp]
	adds r1, r6, #0
	bl HUD_ShowEnemyGauge
_0818E504:
	ldr r6, _0818E520 @ =0x00000ED8
	adds r0, r7, r6
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0818E514:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818E51C: .4byte 0x0000025A
_0818E520: .4byte 0x00000ED8
