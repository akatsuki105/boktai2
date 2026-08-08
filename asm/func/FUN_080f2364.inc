	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x24]
	ldr r0, _080F237C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F2380
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F2382
	.align 2, 0
_080F237C: .4byte 0x0000046C
_080F2380:
	movs r0, #0
_080F2382:
	cmp r0, #0
	beq _080F23C4
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #5
	ldr r2, _080F2448 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F244C @ =0x0000046B
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
	ldr r0, [r6, #8]
	ldrh r1, [r0, #4]
	ldr r0, _080F2450 @ =0x00000FFF
	ands r0, r1
	ldr r2, _080F2454 @ =0x00000466
	adds r1, r5, r2
	strh r0, [r1]
_080F23C4:
	ldr r3, _080F2454 @ =0x00000466
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080F23D6
	subs r0, r2, #1
	strh r0, [r1]
_080F23D6:
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080F247E
	ldr r2, _080F244C @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F247E
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F247E
	adds r0, r6, #0
	bl FUN_08234e3c
	adds r0, r5, #0
	bl FUN_080e6204
	adds r1, r5, #0
	adds r1, #8
	adds r0, r6, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_08235038
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080F245C
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _080F2458 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r4, [r0]
	b _080F2476
	.align 2, 0
_080F2448: .4byte 0x0000046D
_080F244C: .4byte 0x0000046B
_080F2450: .4byte 0x00000FFF
_080F2454: .4byte 0x00000466
_080F2458: .4byte 0x00000469
_080F245C:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _080F2484 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
_080F2476:
	ldr r0, _080F2488 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080F247E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F2484: .4byte 0x00000469
_080F2488: .4byte 0x0000046C
