	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r5, r3, #0
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080E0438
	cmp r1, #0
	blt _080E0438
	ldr r0, _080E0440 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080E0438
	ldr r0, _080E0444 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E044C
_080E0438:
	movs r6, #0
	ldr r4, _080E0448 @ =0x030046A4
	b _080E045C
	.align 2, 0
_080E0440: .4byte 0x030046A8
_080E0444: .4byte 0x030046AC
_080E0448: .4byte 0x030046A4
_080E044C:
	ldr r2, _080E048C @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r3
	adds r4, r2, #0
_080E045C:
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	mov sb, r0
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r6, #0
	bl Div
	adds r7, r0, #0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E0490
	adds r0, #4
	b _080E049A
	.align 2, 0
_080E048C: .4byte 0x030046A4
_080E0490:
	ldr r0, [r4]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E049A:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	str r1, [sp, #4]
	mov r2, sb
	subs r2, r2, r5
	mov sl, r2
	subs r7, r7, r5
	mov r8, r7
	lsls r5, r5, #1
	adds r5, #1
	ldr r3, _080E0540 @ =0x0203B400
	mov sb, r3
	ldr r4, _080E0544 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r6, _080E0548 @ =0x000003FF
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	mov r1, sl
	adds r7, r0, r1
	ldr r0, [r4]
	adds r0, #1
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	mov r3, r8
	adds r2, r0, r3
	ldr r1, _080E054C @ =0x085AD374
	lsls r0, r2, #3
	subs r0, #0x45
	adds r0, r7, r0
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [sp, #4]
	cmp r0, r1
	bne _080E0576
	ldr r5, _080E0550 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r2, #0
	muls r0, r1, r0
	adds r6, r7, r0
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r3, [sp]
	strh r4, [r3]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E0554
	adds r0, #4
	b _080E055E
	.align 2, 0
_080E0540: .4byte 0x0203B400
_080E0544: .4byte 0x030046B8
_080E0548: .4byte 0x000003FF
_080E054C: .4byte 0x085AD374
_080E0550: .4byte 0x030046A4
_080E0554:
	ldr r0, [r5]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E055E:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	ldr r0, [sp]
	strh r1, [r0, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	ldr r1, [sp]
	strh r0, [r1, #4]
	movs r0, #1
	b _080E0578
_080E0576:
	movs r0, #0
_080E0578:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
