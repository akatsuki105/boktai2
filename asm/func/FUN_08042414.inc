	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r2, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0804244C
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xd0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055ef8
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x40
	movs r3, #0
	bl FUN_08055f80
	ldr r0, _0804247C @ =0x00000201
	bl PlaySound_082406e0
_0804244C:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08042464
	b _0804262A
_08042464:
	movs r7, #0x40
	movs r3, #0
	mov r8, r3
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	beq _0804252C
	cmp r0, #1
	bgt _08042480
	cmp r0, #0
	beq _08042488
	b _080425F2
	.align 2, 0
_0804247C: .4byte 0x00000201
_08042480:
	cmp r0, #2
	bne _08042486
	b _080425E4
_08042486:
	b _080425F2
_08042488:
	movs r0, #8
	subs r0, r0, r6
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	mov r8, r0
	adds r1, #0x94
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080424BE
	cmp r1, #0
	blt _080424BE
	ldr r0, _080424C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080424BE
	ldr r0, _080424C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080424CC
_080424BE:
	movs r4, #0
	b _080424DA
	.align 2, 0
_080424C4: .4byte 0x030046A8
_080424C8: .4byte 0x030046AC
_080424CC:
	ldr r0, _080424EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080424DA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080424F0
	adds r0, #4
	b _080424FC
	.align 2, 0
_080424EC: .4byte 0x030046A4
_080424F0:
	ldr r0, _08042528 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080424FC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	cmp r6, #7
	ble _0804251C
	ldrb r0, [r5, #0x18]
	adds r0, #1
	strb r0, [r5, #0x18]
_0804251C:
	adds r0, r5, #0
	adds r0, #0xd0
	movs r1, #1
	movs r2, #0x80
	b _080425D6
	.align 2, 0
_08042528: .4byte 0x030046A4
_0804252C:
	movs r0, #0xf
	subs r2, r0, r6
	lsls r1, r2, #2
	subs r0, r7, r1
	mov sb, r0
	cmp r6, #8
	ble _08042546
	movs r0, #0x18
	subs r0, r0, r6
	lsls r7, r0, #3
	adds r0, r1, r2
	lsls r0, r0, #2
	mov r8, r0
_08042546:
	cmp r6, #0xe
	ble _0804254E
	movs r0, #2
	strb r0, [r5, #0x18]
_0804254E:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0804257A
	cmp r1, #0
	blt _0804257A
	ldr r0, _08042580 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0804257A
	ldr r0, _08042584 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08042588
_0804257A:
	movs r4, #0
	b _08042596
	.align 2, 0
_08042580: .4byte 0x030046A8
_08042584: .4byte 0x030046AC
_08042588:
	ldr r0, _080425A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08042596:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080425AC
	adds r0, #4
	b _080425B8
	.align 2, 0
_080425A8: .4byte 0x030046A4
_080425AC:
	ldr r0, _080425E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080425B8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r0, #0xd0
	mov r1, sb
	adds r2, r7, #0
_080425D6:
	movs r3, #0
	bl FUN_08055f80
	b _080425F2
	.align 2, 0
_080425E0: .4byte 0x030046A4
_080425E4:
	adds r0, r5, #0
	adds r0, #0xd0
	movs r1, #2
	bl FUN_08055f1c
	movs r0, #1
	strb r0, [r5, #7]
_080425F2:
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	movs r4, #0
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
_0804262A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
