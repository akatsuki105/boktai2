	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2D94 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bhi _080A2D98
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5]
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r0, [r3]
	subs r1, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	adds r0, #0x16
	subs r1, #0x38
	strh r0, [r1]
	b _080A2E14
	.align 2, 0
_080A2D94: .4byte 0x00000382
_080A2D98:
	cmp r3, #0x40
	bne _080A2DC4
	ldr r0, [r4, #0x50]
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x4f
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080A2E14
_080A2DC4:
	cmp r3, #0x4f
	bls _080A2E14
	adds r1, r4, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r1, #0x2c
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _080A2DF4
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2E14
_080A2DF4:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	ldr r1, _080A2E1C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2E14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E1C: .4byte FUN_080a2e20
