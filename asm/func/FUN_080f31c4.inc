	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080F3204 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F31D8
	movs r0, #0
	strb r0, [r1]
_080F31D8:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _080F3208 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F3210
	ldr r3, _080F320C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _080F3220
	.align 2, 0
_080F3204: .4byte 0x0000046C
_080F3208: .4byte 0x0000A02F
_080F320C: .4byte 0x00000482
_080F3210:
	ldr r4, _080F3244 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _080F3220
	movs r0, #1
	strh r0, [r2]
_080F3220:
	ldr r1, _080F3248 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F324C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _080F3264
	.align 2, 0
_080F3244: .4byte 0x00000482
_080F3248: .4byte 0x0000025D
_080F324C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_080F3264:
	ldr r2, _080F32B4 @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	beq _080F32C0
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F328A
	b _080F33D0
_080F328A:
	movs r2, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _080F32B8 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _080F32BC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _080F33D0
	.align 2, 0
_080F32B4: .4byte 0x000004A4
_080F32B8: .4byte 0x00000469
_080F32BC: .4byte 0x0000046C
_080F32C0:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F32D6
	b _080F33D0
_080F32D6:
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _080F3338 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _080F333C @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080F3340 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r2, #0x13
	adds r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080F3344 @ =0x0000046B
	adds r0, r5, r1
	strb r6, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	ldr r0, _080F3348 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F334C
	movs r0, #1
	b _080F334E
	.align 2, 0
_080F3338: .4byte 0x00000469
_080F333C: .4byte 0x0000046A
_080F3340: .4byte 0x00000484
_080F3344: .4byte 0x0000046B
_080F3348: .4byte 0x030047A4
_080F334C:
	movs r0, #0
_080F334E:
	adds r6, r0, #0
	cmp r6, #0
	beq _080F3368
	adds r0, r5, #0
	bl FUN_080fa7a4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F33DA
	adds r0, r5, #0
	bl FUN_080faad8
	b _080F33DA
_080F3368:
	ldr r4, [r5, #0x24]
	ldr r2, _080F33C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080F33C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080F33C8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne _080F33A0
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080F33A0:
	strb r0, [r4, #2]
	strb r6, [r4, #3]
	ldr r0, _080F33CC @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r4, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #8]
	adds r0, r5, #0
	bl FUN_080e6204
	b _080F33DA
	.align 2, 0
_080F33C0: .4byte 0x030046B8
_080F33C4: .4byte 0x000003FF
_080F33C8: .4byte 0x0203B400
_080F33CC: .4byte 0x030046A4
_080F33D0:
	ldr r2, _080F33E4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F33DA:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F33E4: .4byte 0x00000484
