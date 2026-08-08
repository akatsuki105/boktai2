	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080FC560 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FC564
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FC566
	.align 2, 0
_080FC560: .4byte 0x0000046D
_080FC564:
	movs r0, #0
_080FC566:
	cmp r0, #0
	beq _080FC57A
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080ef86c
	ldr r2, _080FC624 @ =0x0000046E
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_080FC57A:
	cmp r5, #0x3c
	bgt _080FC580
	b _080FC6CC
_080FC580:
	ldr r3, _080FC624 @ =0x0000046E
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FC58C
	b _080FC6EE
_080FC58C:
	ldr r1, _080FC628 @ =0x0000046B
	adds r0, r4, r1
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080FC63C
	adds r3, #0x36
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _080FC62C @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _080FC630 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _080FC634 @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r1, _080FC638 @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080FC6EE
	.align 2, 0
_080FC624: .4byte 0x0000046E
_080FC628: .4byte 0x0000046B
_080FC62C: .4byte 0x0000046D
_080FC630: .4byte 0x0000046A
_080FC634: .4byte 0x00000484
_080FC638: .4byte 0x00000222
_080FC63C:
	ldr r2, _080FC6B8 @ =0x000004A4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x1c
	ldrsh r1, [r0, r3]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _080FC6BC @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	ldr r3, _080FC6C0 @ =0x0000046B
	adds r0, r4, r3
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r7, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _080FC6C4 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _080FC6C8 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080FC6EE
	.align 2, 0
_080FC6B8: .4byte 0x000004A4
_080FC6BC: .4byte 0x0000046D
_080FC6C0: .4byte 0x0000046B
_080FC6C4: .4byte 0x0000046A
_080FC6C8: .4byte 0x00000484
_080FC6CC:
	ldr r0, [r4, #0x44]
	adds r2, r0, #0
	adds r2, #0x48
	ldrh r0, [r2, #8]
	cmp r0, #2
	bne _080FC6EE
	ldrh r1, [r2, #0xe]
	ldrb r3, [r2, #7]
	rsbs r0, r3, #0
	orrs r0, r3
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _080FC6EE
	cmp r3, #1
	beq _080FC6EE
	movs r0, #0
	strh r0, [r2, #0xe]
_080FC6EE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
