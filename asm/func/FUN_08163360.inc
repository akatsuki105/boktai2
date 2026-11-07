	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov sb, r0
	ldr r2, _0816338C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163390
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163392
	.align 2, 0
_0816338C: .4byte 0x0000046D
_08163390:
	movs r0, #0
_08163392:
	cmp r0, #0
	beq _081633F6
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	blt _081633A8
	asrs r1, r0, #2
	b _081633AE
_081633A8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081633AE:
	movs r7, #0xe0
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081633C8
	asrs r1, r0, #2
	b _081633CE
_081633C8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081633CE:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r4, #0
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080efe38
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r7, _08163438 @ =0x0000046E
	adds r0, r5, r7
	strb r4, [r0]
_081633F6:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r5, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x83
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r7, #0
	ldrsh r2, [r0, r7]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, r2, r0
	adds r6, r3, #0
	adds r3, r1, #0
	cmp r0, #0
	blt _0816343C
	asrs r0, r0, #2
	b _08163442
	.align 2, 0
_08163438: .4byte 0x0000046E
_0816343C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08163442:
	adds r4, r0, #0
	movs r7, #0x84
	lsls r7, r7, #2
	adds r0, r5, r7
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r7, #8
	adds r1, r5, r7
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, r2, r0
	cmp r0, #0
	blt _08163460
	asrs r0, r0, #2
	b _08163466
_08163460:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08163466:
	adds r2, r0, #0
	cmp r4, #0xc8
	ble _08163470
	movs r4, #0xc8
	b _0816347A
_08163470:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0816347A
	adds r4, r0, #0
_0816347A:
	cmp r2, #0xc8
	ble _08163482
	movs r2, #0xc8
	b _0816348C
_08163482:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0816348C
	adds r2, r0, #0
_0816348C:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r4
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r3]
	adds r0, r0, r4
	strh r0, [r3]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r4, #0
	bne _081634B0
	cmp r2, #0
	bne _081634B0
	movs r0, #1
	b _081634B2
_081634B0:
	movs r0, #0
_081634B2:
	cmp r0, #0
	bne _081634BC
	mov r1, sb
	strh r0, [r1, #0xe]
	b _081635DE
_081634BC:
	ldr r2, _08163510 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081634C8
	b _081635DE
_081634C8:
	ldr r4, _08163514 @ =0x0000046B
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r5, r7
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #0xdb
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r1, r0
	blt _08163524
	movs r1, #8
	ldr r0, _08163518 @ =0x0000068E
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816351C
	movs r0, #1
	b _0816351E
	.align 2, 0
_08163510: .4byte 0x0000046E
_08163514: .4byte 0x0000046B
_08163518: .4byte 0x0000068E
_0816351C:
	movs r0, #0
_0816351E:
	adds r3, r0, #0
	cmp r3, #0
	beq _08163598
_08163524:
	ldr r3, _08163580 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r6, _08163584 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08163588 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0816358C @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08163590 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r2, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r4, [r0]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, _08163594 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081635DE
	.align 2, 0
_08163580: .4byte Enemy_ClearStateBegun
_08163584: .4byte 0x0000046D
_08163588: .4byte 0x0000046B
_0816358C: .4byte 0x00000469
_08163590: .4byte 0x0000046A
_08163594: .4byte 0xFFFFF67F
_08163598:
	ldr r1, _081635EC @ =FUN_08162df4
	ldr r2, _081635F0 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081635F4 @ =0x0000046B
	adds r0, r5, r4
	strb r3, [r0]
	ldr r6, _081635F8 @ =0x00000553
	adds r0, r5, r6
	strb r3, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r3, [r0]
	subs r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _081635FC @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08163600 @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	adds r4, #4
	adds r0, r5, r4
	strb r2, [r0]
_081635DE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081635EC: .4byte FUN_08162df4
_081635F0: .4byte 0x0000046D
_081635F4: .4byte 0x0000046B
_081635F8: .4byte 0x00000553
_081635FC: .4byte 0x0000046A
_08163600: .4byte 0x00000484
