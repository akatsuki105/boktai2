	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	mov r8, r1
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x10
	adds r7, r5, #0
	adds r7, #0x28
	adds r6, r5, #2
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	bne _0800B518
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldrb r2, [r5, #2]
	subs r1, r0, r2
	movs r0, #3
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _0800B49C
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B45C
	rsbs r0, r1, #0
_0800B45C:
	cmp r0, #4
	bgt _0800B464
	adds r0, r2, r1
	b _0800B466
_0800B464:
	adds r0, r2, #4
_0800B466:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B4DA
	ldr r2, _0800B490 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B494 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800B498 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0800B4D8
	.align 2, 0
_0800B490: .4byte 0x030046B8
_0800B494: .4byte 0x000003FF
_0800B498: .4byte 0x0203B400
_0800B49C:
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B4A4
	rsbs r0, r1, #0
_0800B4A4:
	cmp r0, #4
	bgt _0800B4AC
	subs r0, r2, r1
	b _0800B4AE
_0800B4AC:
	subs r0, r2, #4
_0800B4AE:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	subs r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B4DA
	ldr r2, _0800B508 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B50C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0800B510 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	subs r0, #0x40
_0800B4D8:
	strb r0, [r5, #3]
_0800B4DA:
	ldr r2, _0800B514 @ =0x085B0A08
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #8]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #0xc]
	b _0800B638
	.align 2, 0
_0800B508: .4byte 0x030046B8
_0800B50C: .4byte 0x000003FF
_0800B510: .4byte 0x0203B400
_0800B514: .4byte 0x085B0A08
_0800B518:
	mov r3, r8
	ldrh r0, [r3, #6]
	cmp r0, #0
	beq _0800B522
	b _0800B638
_0800B522:
	add r6, sp, #4
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B544
	asrs r0, r0, #8
	b _0800B54A
_0800B544:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B54A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B55C
	asrs r0, r0, #8
	b _0800B562
_0800B55C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B562:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800B576
	asrs r1, r0, #8
	b _0800B57C
_0800B576:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800B57C:
	subs r0, r3, r1
	strh r0, [r6, #2]
	adds r0, r3, r1
	strh r0, [r6, #4]
	movs r1, #4
	mov sb, r1
	ldr r2, _0800B628 @ =0x03002BC0
	ldr r6, [r2]
	ands r6, r1
	cmp r6, #0
	bne _0800B638
	add r0, sp, #4
	ldr r3, [sp, #0x30]
	movs r2, #8
	ldrsh r1, [r3, r2]
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r1, r2
	bgt _0800B638
	ldr r1, [sp, #0x30]
	movs r3, #0x10
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _0800B638
	add r0, sp, #4
	ldrh r0, [r0, #2]
	movs r2, #0xa
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0800B638
	ldr r3, [sp, #0x30]
	movs r1, #0x12
	ldrsh r0, [r3, r1]
	cmp r0, r2
	blt _0800B638
	mov r2, sb
	strb r2, [r5]
	adds r0, r5, #0
	adds r0, #0x18
	mov r3, sl
	ldr r1, [r3, #0x24]
	ldr r4, _0800B62C @ =0x085AA6E8
	ldr r3, [r3, #0x18]
	lsls r2, r3, #1
	adds r2, r2, r3
	mov r5, r8
	ldrb r5, [r5, #2]
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2]
	str r6, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _0800B628 @ =0x03002BC0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0800B5FC
	b _0800B790
_0800B5FC:
	ldr r1, _0800B630 @ =0x085AA718
	mov r3, r8
	ldrb r0, [r3, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
	ldr r0, _0800B634 @ =0x085AA70C
	mov r5, r8
	ldrb r2, [r5, #2]
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldrb r1, [r5, #3]
	ldr r2, [r2]
	bl _call_via_r2
	b _0800B790
	.align 2, 0
_0800B628: .4byte 0x03002BC0
_0800B62C: .4byte 0x085AA6E8
_0800B630: .4byte 0x085AA718
_0800B634: .4byte 0x085AA70C
_0800B638:
	ldrh r0, [r5, #8]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldr r2, [sp, #0x30]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	cmp r1, #0x10
	ble _0800B656
	ldrh r0, [r7, #0x1a]
	adds r0, #0x10
	b _0800B668
_0800B656:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800B664
	ldrh r0, [r7, #0x1a]
	subs r0, #0x10
	b _0800B668
_0800B664:
	ldr r3, [sp, #0x30]
	ldrh r0, [r3, #2]
_0800B668:
	strh r0, [r7, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r6, r5, #0
	adds r6, #0x28
	mov r2, sl
	ldr r3, [r2, #0x20]
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800B6BA
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800B6C2
_0800B6BA:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800B6C2:
	str r0, [r5, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800B6E6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800B6EE
_0800B6E6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800B6EE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0800B724 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800B74E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800B728
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800B71E
	ldrb r0, [r4, #5]
_0800B71E:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800B738
	.align 2, 0
_0800B724: .4byte 0x0000FFFF
_0800B728:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800B738
	strh r1, [r4, #8]
_0800B738:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0800B74E:
	ldrh r0, [r5, #6]
	cmp r0, #0
	bne _0800B78C
	movs r0, #2
	strb r0, [r5]
	movs r0, #0xf
	strb r0, [r5, #1]
	movs r0, #0xa
	strh r0, [r5, #6]
	ldr r2, _0800B780 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B784 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0800B788 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x3c
	strh r0, [r5, #4]
	b _0800B790
	.align 2, 0
_0800B780: .4byte 0x030046B8
_0800B784: .4byte 0x000003FF
_0800B788: .4byte 0x0203B400
_0800B78C:
	subs r0, #1
	strh r0, [r5, #6]
_0800B790:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
