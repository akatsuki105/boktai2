	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0813F49C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F45E
	movs r0, #0
	strb r0, [r1]
_0813F45E:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r6, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r3, #0x98
	adds r1, r6, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0813F4A0
	asrs r0, r0, #2
	b _0813F4A6
	.align 2, 0
_0813F49C: .4byte 0x0000046D
_0813F4A0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F4A6:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0813F4C6
	asrs r0, r0, #2
	b _0813F4CC
_0813F4C6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F4CC:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0813F4D6
	movs r3, #0xc8
	b _0813F4E0
_0813F4D6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0813F4E0
	adds r3, r0, #0
_0813F4E0:
	cmp r2, #0xc8
	ble _0813F4E8
	movs r2, #0xc8
	b _0813F4F2
_0813F4E8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0813F4F2
	adds r2, r0, #0
_0813F4F2:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0813F516
	cmp r2, #0
	bne _0813F516
	movs r0, #1
	b _0813F518
_0813F516:
	movs r0, #0
_0813F518:
	cmp r0, #0
	beq _0813F5E4
	adds r0, r6, #0
	bl FUN_08140904
	ldr r0, _0813F57C @ =0x0000024E
	adds r3, r6, r0
	ldrh r4, [r3]
	cmp r4, #0
	beq _0813F58C
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	movs r4, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r3]
	ldr r0, _0813F580 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r6, #0
	bl EnemyBat_BeginCurveMove
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r4, [r0]
	ldr r2, _0813F584 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r6, r3
	strb r4, [r0]
	ldr r1, _0813F588 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _0813F5E4
	.align 2, 0
_0813F57C: .4byte 0x0000024E
_0813F580: .4byte 0x03002BE0
_0813F584: .4byte 0x00000469
_0813F588: .4byte 0x00000484
_0813F58C:
	ldr r3, _0813F5EC @ =FUN_0813f320
	movs r1, #0xa
	ldr r5, _0813F5F0 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #1
	strb r2, [r0]
	subs r5, #2
	adds r0, r6, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r4, [r0]
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0813F5F4 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _0813F5F8 @ =0x0000046A
	adds r0, r6, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r6, r5
	str r4, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r6, #5]
	subs r5, #2
	adds r0, r6, r5
	strh r2, [r0]
_0813F5E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813F5EC: .4byte FUN_0813f320
_0813F5F0: .4byte 0x0000046D
_0813F5F4: .4byte 0x00000469
_0813F5F8: .4byte 0x0000046A
