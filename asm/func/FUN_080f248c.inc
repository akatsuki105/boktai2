	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080F24A4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F24A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F24AA
	.align 2, 0
_080F24A4: .4byte 0x0000046C
_080F24A8:
	movs r0, #0
_080F24AA:
	cmp r0, #0
	beq _080F24DC
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _080F2534 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _080F2538 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_080F24DC:
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F24F2
	b _080F2634
_080F24F2:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F2500
	b _080F2634
_080F2500:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _080F253C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F2544
	ldr r3, _080F2540 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _080F2554
	.align 2, 0
_080F2534: .4byte 0x0000046D
_080F2538: .4byte 0x0000046B
_080F253C: .4byte 0x0000A02F
_080F2540: .4byte 0x00000482
_080F2544:
	ldr r4, _080F2578 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _080F2554
	movs r0, #1
	strh r0, [r2]
_080F2554:
	ldr r1, _080F257C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F2580
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
	b _080F2598
	.align 2, 0
_080F2578: .4byte 0x00000482
_080F257C: .4byte 0x0000025D
_080F2580:
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
_080F2598:
	ldr r2, _080F25E0 @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _080F25F0
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F262A
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _080F25E4 @ =0x00000469
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _080F25E8 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080F25EC @ =0x00000484
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #4
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _080F2634
	.align 2, 0
_080F25E0: .4byte 0x000004A4
_080F25E4: .4byte 0x00000469
_080F25E8: .4byte 0x0000046A
_080F25EC: .4byte 0x00000484
_080F25F0:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F262A
	movs r2, #6
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080F263C @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _080F2640 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_080F262A:
	ldr r4, _080F2640 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F2634:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F263C: .4byte 0x00000469
_080F2640: .4byte 0x00000484
