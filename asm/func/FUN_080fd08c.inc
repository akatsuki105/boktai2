	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xd0
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _080FD0B4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FD0B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FD0BA
	.align 2, 0
_080FD0B4: .4byte 0x0000046D
_080FD0B8:
	movs r0, #0
_080FD0BA:
	cmp r0, #0
	beq _080FD0F6
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080FD0E4
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080FD0E4:
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	movs r1, #0
	strh r0, [r4]
	ldr r3, _080FD1C8 @ =0x0000046E
	adds r0, r7, r3
	strb r1, [r0]
_080FD0F6:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	mov sb, r2
	cmp r6, #0x11
	bgt _080FD136
	ldrh r3, [r5, #8]
	cmp r3, #0
	bne _080FD136
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _080FD136
	cmp r2, #1
	beq _080FD136
	strh r3, [r5, #0xe]
_080FD136:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _080FD1A8
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FD1A8
	ldr r2, _080FD1CC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _080FD1D0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _080FD1D4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080FD1D8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080FD1DC @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl FUN_080ddcc8
_080FD1A8:
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _080FD1E0
	asrs r0, r0, #2
	b _080FD1E6
	.align 2, 0
_080FD1C8: .4byte 0x0000046E
_080FD1CC: .4byte 0xFFFF0000
_080FD1D0: .4byte 0x0000FFFF
_080FD1D4: .4byte 0x030046B8
_080FD1D8: .4byte 0x000003FF
_080FD1DC: .4byte 0x0203B400
_080FD1E0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080FD1E6:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _080FD206
	asrs r0, r0, #2
	b _080FD20C
_080FD206:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080FD20C:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _080FD216
	movs r3, #0xc8
	b _080FD220
_080FD216:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _080FD220
	adds r3, r0, #0
_080FD220:
	cmp r2, #0xc8
	ble _080FD228
	movs r2, #0xc8
	b _080FD232
_080FD228:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _080FD232
	adds r2, r0, #0
_080FD232:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _080FD256
	cmp r2, #0
	bne _080FD256
	movs r0, #1
	b _080FD258
_080FD256:
	movs r0, #0
_080FD258:
	cmp r0, #0
	bne _080FD260
	bl _080FE198
_080FD260:
	ldr r6, _080FD2BC @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FD26E
	bl _080FE198
_080FD26E:
	ldr r1, _080FD2C0 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	mov r8, r2
	mov r3, r8
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _080FD2C4 @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	mov r5, sb
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r3, [r5]
	ands r3, r0
	str r3, [r5]
	ldr r1, _080FD2C8 @ =0x0000049C
	adds r0, r7, r1
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xc
	ands r4, r0
	str r2, [sp, #0xa8]
	cmp r4, #0
	beq _080FD2CC
	movs r0, #2
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _080FE198
	.align 2, 0
_080FD2BC: .4byte 0x0000046E
_080FD2C0: .4byte 0x0000046B
_080FD2C4: .4byte 0xFFFFFEDF
_080FD2C8: .4byte 0x0000049C
_080FD2CC:
	movs r0, #8
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FD358
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _080FD33C @ =0x00000469
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _080FD340 @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _080FD344 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	mov r5, r8
	strb r5, [r0]
	ldr r2, _080FD348 @ =FUN_080fc6f4
	movs r1, #0x14
	adds r3, #1
	adds r0, r7, r3
	strb r5, [r0]
	ldr r5, _080FD34C @ =0x0000046B
	adds r0, r7, r5
	strb r6, [r0]
	ldr r6, _080FD350 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r4, _080FD354 @ =0x00000482
	adds r0, r7, r4
	mov r5, r8
	strh r5, [r0]
	bl _080FE198
	.align 2, 0
_080FD33C: .4byte 0x00000469
_080FD340: .4byte 0x0000046A
_080FD344: .4byte 0x00000484
_080FD348: .4byte FUN_080fc6f4
_080FD34C: .4byte 0x0000046B
_080FD350: .4byte 0x00000553
_080FD354: .4byte 0x00000482
_080FD358:
	movs r2, #0x80
	ands r1, r2
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _080FD366
	b _080FDA7C
_080FD366:
	orrs r3, r2
	str r3, [r5]
	movs r0, #4
	ldr r6, _080FD3C8 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _080FD3CC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xc0]
	str r4, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r5, #0
	blt _080FD3C2
	cmp r1, #0
	blt _080FD3C2
	ldr r0, _080FD3D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _080FD3C2
	ldr r0, _080FD3D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FD3D8
_080FD3C2:
	movs r4, #0
	b _080FD3E6
	.align 2, 0
_080FD3C8: .4byte 0x00000222
_080FD3CC: .4byte 0x03002BE0
_080FD3D0: .4byte 0x030046A8
_080FD3D4: .4byte 0x030046AC
_080FD3D8:
	ldr r0, _080FD3F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_080FD3E6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FD3FC
	adds r0, #4
	b _080FD408
	.align 2, 0
_080FD3F8: .4byte 0x030046A4
_080FD3FC:
	ldr r0, _080FD41C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FD408:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FD420
	cmp r2, #2
	beq _080FD424
	b _080FD428
	.align 2, 0
_080FD41C: .4byte 0x030046A4
_080FD420:
	ldrb r0, [r6, #4]
	b _080FD426
_080FD424:
	ldrb r0, [r6]
_080FD426:
	subs r1, r1, r0
_080FD428:
	strh r1, [r6, #2]
	ldr r0, _080FD43C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080FD440
	movs r0, #1
	b _080FD442
	.align 2, 0
_080FD43C: .4byte 0x030047A4
_080FD440:
	movs r0, #0
_080FD442:
	cmp r0, #0
	beq _080FD478
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _080FD454
	b _080FD988
_080FD454:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _080FD460
	adds r2, r0, #0
_080FD460:
	cmp r2, #0
	bge _080FD466
	b _080FD988
_080FD466:
	ldr r1, _080FD474 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _080FD4C0
	.align 2, 0
_080FD474: .4byte 0x03002BE0
_080FD478:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FD4A4
	cmp r1, #0
	blt _080FD4A4
	ldr r0, _080FD4A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FD4A4
	ldr r0, _080FD4AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FD4B0
_080FD4A4:
	movs r5, #0
	b _080FD4BE
	.align 2, 0
_080FD4A8: .4byte 0x030046A8
_080FD4AC: .4byte 0x030046AC
_080FD4B0:
	ldr r0, _080FD4F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080FD4BE:
	movs r2, #0
_080FD4C0:
	ldr r6, _080FD4FC @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _080FD4E0
	ldr r1, _080FD500 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080FD4E0
	b _080FD8C8
_080FD4E0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _080FD504
	movs r0, #0
	b _080FD9A2
	.align 2, 0
_080FD4F8: .4byte 0x030046A4
_080FD4FC: .4byte 0x00000256
_080FD500: .4byte 0x03002BE0
_080FD504:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r3, [sp, #0xc0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080FD5BC
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _080FD5A4 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x28]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _080FD5A8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _080FD5AC @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x30]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x34]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	mov r1, sb
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _080FD5B0 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _080FD5B4 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _080FD5B8 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x28]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x34]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _080FD786
	.align 2, 0
_080FD5A4: .4byte 0x0000046D
_080FD5A8: .4byte 0x0000046B
_080FD5AC: .4byte 0x00000553
_080FD5B0: .4byte 0x00000469
_080FD5B4: .4byte 0x00000484
_080FD5B8: .4byte 0x0000046C
_080FD5BC:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _080FD67C @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _080FD680 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x38]
	movs r6, #0
	strb r6, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x44]
	strh r2, [r5]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x48]
	movs r3, #0
	strb r3, [r6]
	ldr r4, _080FD684 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r6, _080FD688 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _080FD68C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x4c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x4c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x3c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x40]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x44]
	str r4, [sp, #0xac]
	mov r5, ip
	cmp r5, #0
	blt _080FD678
	cmp r1, #0
	blt _080FD678
	ldr r0, _080FD690 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _080FD678
	ldr r0, _080FD694 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FD698
_080FD678:
	movs r4, #0
	b _080FD6A8
	.align 2, 0
_080FD67C: .4byte 0x0000046D
_080FD680: .4byte 0x0000046B
_080FD684: .4byte 0x00000469
_080FD688: .4byte 0x0000046A
_080FD68C: .4byte 0x00000484
_080FD690: .4byte 0x030046A8
_080FD694: .4byte 0x030046AC
_080FD698:
	ldr r0, _080FD6B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, ip
	adds r4, r0, r6
_080FD6A8:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FD6BC
	adds r0, #4
	b _080FD6C8
	.align 2, 0
_080FD6B8: .4byte 0x030046A4
_080FD6BC:
	ldr r0, _080FD6DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FD6C8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FD6E0
	cmp r2, #2
	beq _080FD6E6
	b _080FD6EC
	.align 2, 0
_080FD6DC: .4byte 0x030046A4
_080FD6E0:
	ldr r2, [sp, #0x4c]
	ldrb r0, [r2, #4]
	b _080FD6EA
_080FD6E6:
	ldr r3, [sp, #0x4c]
	ldrb r0, [r3]
_080FD6EA:
	subs r1, r1, r0
_080FD6EC:
	ldr r4, [sp, #0x4c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FD718
	cmp r1, #0
	blt _080FD718
	ldr r0, _080FD71C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FD718
	ldr r0, _080FD720 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FD724
_080FD718:
	movs r4, #0
	b _080FD732
	.align 2, 0
_080FD71C: .4byte 0x030046A8
_080FD720: .4byte 0x030046AC
_080FD724:
	ldr r0, _080FD748 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FD732:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FD74C
	adds r0, #4
	b _080FD758
	.align 2, 0
_080FD748: .4byte 0x030046A4
_080FD74C:
	ldr r0, _080FD76C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FD758:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080FD770
	cmp r3, #2
	beq _080FD774
	b _080FD778
	.align 2, 0
_080FD76C: .4byte 0x030046A4
_080FD770:
	ldrb r0, [r5, #4]
	b _080FD776
_080FD774:
	ldrb r0, [r5]
_080FD776:
	subs r2, r2, r0
_080FD778:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_080FD786:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x50]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _080FD7B0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _080FD890
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FD7B4
	movs r0, #1
	b _080FD7B6
	.align 2, 0
_080FD7B0: .4byte 0x00000482
_080FD7B4:
	movs r0, #0
_080FD7B6:
	ldr r3, _080FD8A0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _080FD890
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _080FD8A4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _080FD8A8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _080FD8AC @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _080FD8B0 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _080FD8B4 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _080FD8B8 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _080FD8BC @ =0x030046B8
	adds r2, r5, #0
_080FD7FE:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _080FD8C0 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _080FD8C4 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _080FD822
	adds r3, #1
	cmp r3, #3
	ble _080FD7FE
	adds r0, r5, #0
_080FD822:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x50
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_080FD890:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _080FD9A2
	.align 2, 0
_080FD8A0: .4byte 0x00000482
_080FD8A4: .4byte 0x0000054F
_080FD8A8: .4byte 0x0000054C
_080FD8AC: .4byte 0x0000054E
_080FD8B0: .4byte 0x00000541
_080FD8B4: .4byte 0x000005BC
_080FD8B8: .4byte 0x00000542
_080FD8BC: .4byte 0x030046B8
_080FD8C0: .4byte 0x000003FF
_080FD8C4: .4byte 0x0203B400
_080FD8C8:
	add r6, sp, #0x18
	ldr r0, _080FD908 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _080FD90C
	adds r0, #4
	b _080FD918
	.align 2, 0
_080FD908: .4byte 0x030046A4
_080FD90C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080FD918:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _080FD950 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _080FD958
	ldr r0, _080FD954 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _080FD982
	.align 2, 0
_080FD950: .4byte 0x000004A4
_080FD954: .4byte 0xFFFFFDFF
_080FD958:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _080FD978
	cmp r0, #2
	beq _080FD974
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FD974:
	movs r0, #1
	b _080FD984
_080FD978:
	ldr r0, _080FD998 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_080FD982:
	movs r0, #0
_080FD984:
	cmp r0, #0
	bne _080FD9A0
_080FD988:
	ldr r3, _080FD99C @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _080FD9A2
	.align 2, 0
_080FD998: .4byte 0xFFFFFDFF
_080FD99C: .4byte 0x000005C4
_080FD9A0:
	movs r0, #1
_080FD9A2:
	cmp r0, #0
	bne _080FDA12
	ldr r4, _080FD9D8 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FD9E0
	ldr r0, _080FD9DC @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080FDA0A
	.align 2, 0
_080FD9D8: .4byte 0x000004A4
_080FD9DC: .4byte 0xFFFFFDFF
_080FD9E0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FDA00
	cmp r0, #2
	beq _080FD9FC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FD9FC:
	movs r0, #1
	b _080FDA0C
_080FDA00:
	ldr r0, _080FDA68 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080FDA0A:
	movs r0, #0
_080FDA0C:
	cmp r0, #0
	bne _080FDA12
	b _080FE128
_080FDA12:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _080FDA6C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _080FDA70 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080FDA74 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _080FDA78 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _080FE198
	.align 2, 0
_080FDA68: .4byte 0xFFFFFDFF
_080FDA6C: .4byte 0x0000046D
_080FDA70: .4byte 0x0000046B
_080FDA74: .4byte 0x0000046A
_080FDA78: .4byte 0x00000484
_080FDA7C:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _080FDAD8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r0, #0x10
	orrs r3, r0
	mov r0, sb
	str r3, [r0]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r3, r7, r1
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r5, #0
	blt _080FDAD4
	cmp r1, #0
	blt _080FDAD4
	ldr r0, _080FDADC @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _080FDAD4
	ldr r0, _080FDAE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FDAE4
_080FDAD4:
	movs r4, #0
	b _080FDAF2
	.align 2, 0
_080FDAD8: .4byte 0x03002BE0
_080FDADC: .4byte 0x030046A8
_080FDAE0: .4byte 0x030046AC
_080FDAE4:
	ldr r0, _080FDB04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_080FDAF2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FDB08
	adds r0, #4
	b _080FDB14
	.align 2, 0
_080FDB04: .4byte 0x030046A4
_080FDB08:
	ldr r0, _080FDB28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FDB14:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FDB2C
	cmp r2, #2
	beq _080FDB30
	b _080FDB34
	.align 2, 0
_080FDB28: .4byte 0x030046A4
_080FDB2C:
	ldrb r0, [r6, #4]
	b _080FDB32
_080FDB30:
	ldrb r0, [r6]
_080FDB32:
	subs r1, r1, r0
_080FDB34:
	strh r1, [r6, #2]
	ldr r0, _080FDB48 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080FDB4C
	movs r0, #1
	b _080FDB4E
	.align 2, 0
_080FDB48: .4byte 0x030047A4
_080FDB4C:
	movs r0, #0
_080FDB4E:
	cmp r0, #0
	beq _080FDB84
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _080FDB60
	b _080FE0A0
_080FDB60:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _080FDB6C
	adds r2, r0, #0
_080FDB6C:
	cmp r2, #0
	bge _080FDB72
	b _080FE0A0
_080FDB72:
	ldr r1, _080FDB80 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _080FDBCC
	.align 2, 0
_080FDB80: .4byte 0x03002BE0
_080FDB84:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FDBB0
	cmp r1, #0
	blt _080FDBB0
	ldr r0, _080FDBB4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FDBB0
	ldr r0, _080FDBB8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FDBBC
_080FDBB0:
	movs r5, #0
	b _080FDBCA
	.align 2, 0
_080FDBB4: .4byte 0x030046A8
_080FDBB8: .4byte 0x030046AC
_080FDBBC:
	ldr r0, _080FDC04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080FDBCA:
	movs r2, #0
_080FDBCC:
	ldr r6, _080FDC08 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _080FDBEC
	ldr r1, _080FDC0C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080FDBEC
	b _080FDFE0
_080FDBEC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	cmp r0, #0
	beq _080FDC10
	movs r0, #0
	b _080FE0BA
	.align 2, 0
_080FDC04: .4byte 0x030046A4
_080FDC08: .4byte 0x00000256
_080FDC0C: .4byte 0x03002BE0
_080FDC10:
	ldr r3, _080FDCB4 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xc0]
	cmp r6, #0
	beq _080FDCD0
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _080FDCB8 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _080FDCBC @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _080FDCC0 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x60]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x64]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _080FDCC4 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _080FDCC8 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x54]
	str r6, [r1]
	ldr r6, _080FDCCC @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x58]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x64]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _080FDE9E
	.align 2, 0
_080FDCB4: .4byte 0x00000222
_080FDCB8: .4byte 0x0000046D
_080FDCBC: .4byte 0x0000046B
_080FDCC0: .4byte 0x00000553
_080FDCC4: .4byte 0x00000469
_080FDCC8: .4byte 0x00000484
_080FDCCC: .4byte 0x0000046C
_080FDCD0:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _080FDD90 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _080FDD94 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r2, #0
	strb r2, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x74]
	strh r6, [r5]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _080FDD98 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _080FDD9C @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _080FDDA0 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _080FDDA4 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x7c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x7c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x6c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x70]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x74]
	str r4, [sp, #0xac]
	mov r5, sl
	cmp r5, #0
	blt _080FDD8C
	cmp r1, #0
	blt _080FDD8C
	ldr r0, _080FDDA8 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _080FDD8C
	ldr r0, _080FDDAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FDDB0
_080FDD8C:
	movs r4, #0
	b _080FDDC0
	.align 2, 0
_080FDD90: .4byte 0x0000046D
_080FDD94: .4byte 0x0000046B
_080FDD98: .4byte 0x00000469
_080FDD9C: .4byte 0x0000046A
_080FDDA0: .4byte 0x00000484
_080FDDA4: .4byte 0x0000046C
_080FDDA8: .4byte 0x030046A8
_080FDDAC: .4byte 0x030046AC
_080FDDB0:
	ldr r0, _080FDDD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sl
	adds r4, r0, r6
_080FDDC0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FDDD4
	adds r0, #4
	b _080FDDE0
	.align 2, 0
_080FDDD0: .4byte 0x030046A4
_080FDDD4:
	ldr r0, _080FDDF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FDDE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FDDF8
	cmp r2, #2
	beq _080FDDFE
	b _080FDE04
	.align 2, 0
_080FDDF4: .4byte 0x030046A4
_080FDDF8:
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2, #4]
	b _080FDE02
_080FDDFE:
	ldr r3, [sp, #0x7c]
	ldrb r0, [r3]
_080FDE02:
	subs r1, r1, r0
_080FDE04:
	ldr r4, [sp, #0x7c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FDE30
	cmp r1, #0
	blt _080FDE30
	ldr r0, _080FDE34 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FDE30
	ldr r0, _080FDE38 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FDE3C
_080FDE30:
	movs r4, #0
	b _080FDE4A
	.align 2, 0
_080FDE34: .4byte 0x030046A8
_080FDE38: .4byte 0x030046AC
_080FDE3C:
	ldr r0, _080FDE60 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FDE4A:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FDE64
	adds r0, #4
	b _080FDE70
	.align 2, 0
_080FDE60: .4byte 0x030046A4
_080FDE64:
	ldr r0, _080FDE84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FDE70:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080FDE88
	cmp r3, #2
	beq _080FDE8C
	b _080FDE90
	.align 2, 0
_080FDE84: .4byte 0x030046A4
_080FDE88:
	ldrb r0, [r5, #4]
	b _080FDE8E
_080FDE8C:
	ldrb r0, [r5]
_080FDE8E:
	subs r2, r2, r0
_080FDE90:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_080FDE9E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x80]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _080FDEC8 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _080FDFA8
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FDECC
	movs r0, #1
	b _080FDECE
	.align 2, 0
_080FDEC8: .4byte 0x00000482
_080FDECC:
	movs r0, #0
_080FDECE:
	ldr r3, _080FDFB8 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _080FDFA8
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _080FDFBC @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _080FDFC0 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _080FDFC4 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _080FDFC8 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _080FDFCC @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _080FDFD0 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _080FDFD4 @ =0x030046B8
	adds r2, r5, #0
_080FDF16:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _080FDFD8 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _080FDFDC @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _080FDF3A
	adds r3, #1
	cmp r3, #3
	ble _080FDF16
	adds r0, r5, #0
_080FDF3A:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x80
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_080FDFA8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _080FE0BA
	.align 2, 0
_080FDFB8: .4byte 0x00000482
_080FDFBC: .4byte 0x0000054F
_080FDFC0: .4byte 0x0000054C
_080FDFC4: .4byte 0x0000054E
_080FDFC8: .4byte 0x00000541
_080FDFCC: .4byte 0x000005BC
_080FDFD0: .4byte 0x00000542
_080FDFD4: .4byte 0x030046B8
_080FDFD8: .4byte 0x000003FF
_080FDFDC: .4byte 0x0203B400
_080FDFE0:
	add r6, sp, #0x20
	ldr r0, _080FE020 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _080FE024
	adds r0, #4
	b _080FE030
	.align 2, 0
_080FE020: .4byte 0x030046A4
_080FE024:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080FE030:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _080FE068 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _080FE070
	ldr r0, _080FE06C @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _080FE09A
	.align 2, 0
_080FE068: .4byte 0x000004A4
_080FE06C: .4byte 0xFFFFFDFF
_080FE070:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _080FE090
	cmp r0, #2
	beq _080FE08C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FE08C:
	movs r0, #1
	b _080FE09C
_080FE090:
	ldr r0, _080FE0B0 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_080FE09A:
	movs r0, #0
_080FE09C:
	cmp r0, #0
	bne _080FE0B8
_080FE0A0:
	ldr r3, _080FE0B4 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _080FE0BA
	.align 2, 0
_080FE0B0: .4byte 0xFFFFFDFF
_080FE0B4: .4byte 0x000005C4
_080FE0B8:
	movs r0, #1
_080FE0BA:
	cmp r0, #0
	bne _080FE140
	ldr r4, _080FE0F0 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FE0F8
	ldr r0, _080FE0F4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080FE122
	.align 2, 0
_080FE0F0: .4byte 0x000004A4
_080FE0F4: .4byte 0xFFFFFDFF
_080FE0F8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FE118
	cmp r0, #2
	beq _080FE114
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FE114:
	movs r0, #1
	b _080FE124
_080FE118:
	ldr r0, _080FE138 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080FE122:
	movs r0, #0
_080FE124:
	cmp r0, #0
	bne _080FE140
_080FE128:
	ldr r4, _080FE13C @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _080FE198
	.align 2, 0
_080FE138: .4byte 0xFFFFFDFF
_080FE13C: .4byte 0x000005C4
_080FE140:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _080FE1A8 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _080FE1AC @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _080FE1B0 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080FE1B4 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _080FE1B8 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_080FE198:
	add sp, #0xd0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FE1A8: .4byte 0x0000046D
_080FE1AC: .4byte 0x0000046B
_080FE1B0: .4byte 0x00000469
_080FE1B4: .4byte 0x0000046A
_080FE1B8: .4byte 0x00000484
