	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0813B380 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813B384
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813B386
	.align 2, 0
_0813B380: .4byte 0x0000046D
_0813B384:
	movs r0, #0
_0813B386:
	cmp r0, #0
	beq _0813B3DA
	movs r0, #0x20
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r1, [r4]
	movs r6, #0
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #8
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813B3B4
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0813B3B4:
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
	ldr r1, _0813B40C @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813B3DA:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x83
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r2, #0
	ldrsh r3, [r0, r2]
	adds r4, #0x98
	adds r2, r5, r4
	movs r6, #0
	ldrsh r0, [r2, r6]
	subs r0, r3, r0
	mov r8, r1
	adds r4, r2, #0
	cmp r0, #0
	blt _0813B410
	asrs r0, r0, #2
	b _0813B416
	.align 2, 0
_0813B40C: .4byte 0x00000474
_0813B410:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813B416:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _0813B436
	asrs r0, r0, #2
	b _0813B43C
_0813B436:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813B43C:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0813B446
	movs r3, #0xc8
	b _0813B450
_0813B446:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0813B450
	adds r3, r0, #0
_0813B450:
	cmp r2, #0xc8
	ble _0813B458
	movs r2, #0xc8
	b _0813B462
_0813B458:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0813B462
	adds r2, r0, #0
_0813B462:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0813B486
	cmp r2, #0
	bne _0813B486
	movs r0, #1
	b _0813B488
_0813B486:
	movs r0, #0
_0813B488:
	cmp r0, #0
	bne _0813B48E
	b _0813B620
_0813B48E:
	ldr r1, _0813B538 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #0
	movs r7, #1
	strb r7, [r0]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldr r0, _0813B53C @ =0xFFFFFEDF
	ldrh r1, [r3]
	ands r0, r1
	movs r6, #0
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xd
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0813B540 @ =0x00000666
	add r0, sb
	strb r6, [r0]
	movs r0, #8
	ldrh r2, [r3]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	beq _0813B554
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0813B544 @ =0x00000469
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r6, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r7, [r0]
	ldr r0, _0813B548 @ =FUN_0813b22c
	mov r8, r0
	movs r1, #0x14
	adds r2, #1
	adds r0, r5, r2
	strb r7, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r6, [r0]
	ldr r6, _0813B54C @ =0x00000553
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r2, r8
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r1, _0813B550 @ =0x00000482
	adds r0, r5, r1
	strh r7, [r0]
	b _0813B620
	.align 2, 0
_0813B538: .4byte 0x0000046B
_0813B53C: .4byte 0xFFFFFEDF
_0813B540: .4byte 0x00000666
_0813B544: .4byte 0x00000469
_0813B548: .4byte FUN_0813b22c
_0813B54C: .4byte 0x00000553
_0813B550: .4byte 0x00000482
_0813B554:
	ldr r4, _0813B5A8 @ =0x0000024E
	adds r1, r5, r4
	ldrh r4, [r1]
	cmp r4, #0
	beq _0813B5BC
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r0, r2
	strh r0, [r3]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _0813B5AC @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0813c9c4
	movs r1, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r6, [r0]
	ldr r6, _0813B5B0 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0813B5B4 @ =0x0000046A
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0813B5B8 @ =0x00000484
	adds r0, r5, r2
	mov r4, r8
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r7, [r0]
	adds r0, r5, #0
	bl FUN_0813c938
	b _0813B620
	.align 2, 0
_0813B5A8: .4byte 0x0000024E
_0813B5AC: .4byte 0x03002BE0
_0813B5B0: .4byte 0x00000469
_0813B5B4: .4byte 0x0000046A
_0813B5B8: .4byte 0x00000484
_0813B5BC:
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	strb r0, [r5, #5]
	ldr r1, _0813B62C @ =FUN_0813b100
	mov r8, r1
	movs r1, #0xa
	ldr r2, _0813B630 @ =0x0000046D
	adds r0, r5, r2
	strb r7, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #0xe8
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r2, r8
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r6, _0813B634 @ =0x00000469
	adds r0, r5, r6
	strb r7, [r0]
	ldr r1, _0813B638 @ =0x0000046A
	adds r0, r5, r1
	strb r7, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0813B63C @ =0x0000046C
	adds r0, r5, r4
	strb r7, [r0]
	ldrb r0, [r3]
	strb r0, [r5, #5]
	adds r6, #0x19
	adds r0, r5, r6
	strh r7, [r0]
	adds r0, r5, #0
	bl FUN_0813c938
_0813B620:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813B62C: .4byte FUN_0813b100
_0813B630: .4byte 0x0000046D
_0813B634: .4byte 0x00000469
_0813B638: .4byte 0x0000046A
_0813B63C: .4byte 0x0000046C
