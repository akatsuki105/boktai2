	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0822E4A0 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r1, _0822E4A4 @ =0x00000401
	str r1, [sp, #8]
	cmp r0, #0
	beq _0822E444
	ldr r2, _0822E4A8 @ =0x00000201
	str r2, [sp, #8]
_0822E444:
	ldr r1, _0822E4AC @ =0x03003570
	ldr r0, _0822E4B0 @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _0822E456
	b _0822E71A
_0822E456:
	ldr r3, _0822E4B4 @ =0x03003E40
	mov sl, r3
_0822E45A:
	ldr r1, [r4]
	adds r0, r1, #0
	ldr r5, [sp, #8]
	ands r0, r5
	cmp r0, #0
	beq _0822E468
	b _0822E712
_0822E468:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0822E474
	b _0822E712
_0822E474:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _0822E524
	mov r5, sp
	adds r6, r4, #0
	adds r6, #0x18
	ldrh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822E4B8
	asrs r0, r0, #8
	b _0822E4BE
	.align 2, 0
_0822E4A0: .4byte 0x03002CF0
_0822E4A4: .4byte 0x00000401
_0822E4A8: .4byte 0x00000201
_0822E4AC: .4byte 0x03003570
_0822E4B0: .4byte 0x03003530
_0822E4B4: .4byte 0x03003E40
_0822E4B8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822E4BE:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822E4D0
	asrs r0, r0, #8
	b _0822E4D6
_0822E4D0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822E4D6:
	adds r3, r0, #0
	movs r7, #2
	ldrsh r1, [r6, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0822E4EA
	asrs r0, r0, #8
	b _0822E4F0
_0822E4EA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822E4F0:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r5]
	ldr r6, _0822E520 @ =0x030047C8
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r6, #4]
	subs r3, r3, r0
	strh r3, [r5, #4]
	mov r0, sp
	movs r7, #0
	ldrsh r2, [r0, r7]
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r6, #4
	ldrsh r5, [r0, r6]
	mov sb, r5
	b _0822E532
	.align 2, 0
_0822E520: .4byte 0x030047C8
_0822E524:
	movs r7, #0x18
	ldrsh r2, [r4, r7]
	movs r0, #0x1a
	ldrsh r3, [r4, r0]
	movs r5, #0x1c
	ldrsh r1, [r4, r5]
	mov sb, r1
_0822E532:
	ldr r1, [r4]
	movs r0, #0x40
	ands r0, r1
	adds r6, r1, #0
	movs r7, #0xc
	ldrsb r7, [r4, r7]
	mov ip, r7
	movs r1, #0xd
	ldrsb r1, [r4, r1]
	mov r8, r1
	cmp r0, #0
	bne _0822E576
	ldrb r5, [r4, #0xa]
	ldrb r7, [r4, #0xb]
	str r7, [sp, #0xc]
	mov r1, ip
	adds r0, r2, r1
	mov r7, r8
	adds r1, r3, r7
	cmp r0, #0xf0
	ble _0822E55E
	b _0822E712
_0822E55E:
	cmp r1, #0xb4
	ble _0822E564
	b _0822E712
_0822E564:
	adds r0, r0, r5
	cmp r0, #0
	bge _0822E56C
	b _0822E712
_0822E56C:
	ldr r5, [sp, #0xc]
	adds r0, r1, r5
	cmp r0, #0
	bge _0822E576
	b _0822E712
_0822E576:
	add r2, ip
	add r3, r8
	mov r7, sb
	ldr r0, _0822E5AC @ =0x000001FF
	ands r2, r0
	lsls r0, r2, #0x10
	ldr r5, [r4, #0x14]
	orrs r5, r0
	movs r0, #0xff
	ands r3, r0
	orrs r5, r3
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _0822E5F6
	ldrb r0, [r4, #5]
	cmp r0, #0x3c
	bgt _0822E5A6
	ldrb r0, [r4, #6]
	cmp r0, #0x3c
	bgt _0822E5A6
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0822E5B0
_0822E5A6:
	movs r0, #0xc0
	lsls r0, r0, #2
	b _0822E5B4
	.align 2, 0
_0822E5AC: .4byte 0x000001FF
_0822E5B0:
	movs r0, #0x80
	lsls r0, r0, #1
_0822E5B4:
	orrs r5, r0
	ldrb r1, [r4, #7]
	movs r2, #5
	ldrsb r2, [r4, r2]
	movs r3, #6
	ldrsb r3, [r4, r3]
	mov r6, sl
	ldr r0, [r6]
	cmp r0, #0x1f
	ble _0822E5CC
	movs r1, #0
	b _0822E5F0
_0822E5CC:
	lsls r0, r0, #2
	ldr r6, _0822E698 @ =0x030035B0
	adds r0, r0, r6
	strb r1, [r0]
	mov r1, sl
	ldr r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	strb r2, [r0, #1]
	ldr r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	strb r3, [r0, #2]
	ldr r0, [r1]
	adds r1, r0, #0
	adds r0, #1
	mov r2, sl
	str r0, [r2]
_0822E5F0:
	lsls r0, r1, #0x19
	orrs r5, r0
	ldr r6, [r4]
_0822E5F6:
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _0822E604
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r5, r0
_0822E604:
	movs r0, #8
	ands r0, r6
	cmp r0, #0
	beq _0822E612
	movs r0, #0x80
	lsls r0, r0, #0x16
	orrs r5, r0
_0822E612:
	ldr r3, _0822E69C @ =0x030044AC
	ldr r0, [r3]
	cmp r0, #0
	beq _0822E62A
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r6
	cmp r0, #0
	beq _0822E62A
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r5, r0
_0822E62A:
	ldr r0, _0822E6A0 @ =0x030044B0
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0822E646
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0822E646
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r6
	cmp r0, #0
	beq _0822E650
_0822E646:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r6
	cmp r0, #0
	beq _0822E656
_0822E650:
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r5, r0
_0822E656:
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	adds r7, r7, r0
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0
	beq _0822E6B0
	movs r1, #8
	ldrsh r2, [r4, r1]
	ldrb r0, [r4, #0xf]
	lsls r0, r0, #0xa
	orrs r2, r0
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #0xc
	orrs r2, r0
	ldr r3, _0822E6A4 @ =0x03003A38
	ldr r1, [r3]
	cmp r1, #0x7f
	bgt _0822E712
	lsls r0, r1, #3
	ldr r6, _0822E6A8 @ =0x03003630
	adds r0, r0, r6
	str r5, [r0]
	strh r2, [r0, #4]
	adds r0, r1, #1
	str r0, [r3]
	ldr r7, _0822E6AC @ =0x03002CA4
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	b _0822E712
	.align 2, 0
_0822E698: .4byte 0x030035B0
_0822E69C: .4byte 0x030044AC
_0822E6A0: .4byte 0x030044B0
_0822E6A4: .4byte 0x03003A38
_0822E6A8: .4byte 0x03003630
_0822E6AC: .4byte 0x03002CA4
_0822E6B0:
	cmp r7, #0
	blt _0822E6B8
	asrs r0, r7, #1
	b _0822E6BE
_0822E6B8:
	rsbs r0, r7, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0822E6BE:
	adds r7, r0, #0
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r7, r0
	bge _0822E6CC
	adds r7, r0, #0
	b _0822E6D2
_0822E6CC:
	cmp r7, #0x7f
	ble _0822E6D2
	movs r7, #0x7f
_0822E6D2:
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldrb r6, [r4, #0xf]
	lsls r0, r6, #0xa
	orrs r1, r0
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #0xc
	orrs r1, r0
	ldr r2, _0822E72C @ =0x03003A3C
	ldr r3, [r2]
	cmp r3, #0x7f
	bgt _0822E712
	lsls r2, r3, #3
	ldr r0, _0822E730 @ =0x03003A40
	adds r2, r2, r0
	str r5, [r2]
	strh r1, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r2, #6]
	adds r0, r3, #1
	ldr r1, _0822E72C @ =0x03003A3C
	str r0, [r1]
	lsls r1, r6, #1
	ldr r2, _0822E734 @ =0x03003A30
	adds r1, r1, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0822E712:
	ldr r4, [r4, #0x24]
	cmp r4, #0
	beq _0822E71A
	b _0822E45A
_0822E71A:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822E72C: .4byte 0x03003A3C
_0822E730: .4byte 0x03003A40
_0822E734: .4byte 0x03003A30
