	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819242E
	movs r1, #0x30
	ldr r2, [sp, #0x10]
	ldr r3, _08192418 @ =0x00000F2C
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819241C
	movs r0, #1
	b _0819241E
	.align 2, 0
_08192418: .4byte 0x00000F2C
_0819241C:
	movs r0, #0
_0819241E:
	cmp r0, #0
	bne _0819242E
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08192458
_0819242E:
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
	ldr r1, _08192454 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	b _0819247E
	.align 2, 0
_08192454: .4byte 0x00000474
_08192458:
	movs r2, #0x94
	lsls r2, r2, #1
	adds r3, r5, r2
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r3, _081924CC @ =0x00000474
	adds r2, r5, r3
	ldr r0, _081924D0 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
_0819247E:
	strh r0, [r2]
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, [sp, #0x10]
	ldr r2, _081924D4 @ =0x00000F36
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x14]
	cmp r1, r0
	blt _08192496
	b _08192668
_08192496:
	add r2, sp, #8
	mov sb, r2
	ldr r3, [sp, #0x10]
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r4, r3, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r7, r3, r1
	ldr r2, _081924D8 @ =0x00000674
	adds r2, r3, r2
	str r2, [sp, #0x18]
	adds r0, #0x50
	adds r6, r3, r0
	ldr r1, _081924DC @ =0x0000077A
	adds r1, r3, r1
	str r1, [sp, #0x1c]
	mov r8, r7
_081924BA:
	movs r1, #0x80
	ldr r2, [sp, #0x1c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081924E0
	movs r0, #1
	b _081924E2
	.align 2, 0
_081924CC: .4byte 0x00000474
_081924D0: .4byte 0xFFFFF7FF
_081924D4: .4byte 0x00000F36
_081924D8: .4byte 0x00000674
_081924DC: .4byte 0x0000077A
_081924E0:
	movs r0, #0
_081924E2:
	cmp r0, #0
	bne _081924F6
	ldrh r0, [r4, #6]
	movs r3, #4
	orrs r0, r3
	strh r0, [r4, #6]
	ldrh r0, [r6, #6]
	orrs r0, r3
	strh r0, [r6, #6]
	b _08192638
_081924F6:
	mov r0, r8
	adds r0, #0x98
	mov r1, r8
	adds r1, #0x1c
	movs r2, #0
	bl Hitbox_SetPos
	mov r1, r8
	ldr r0, [r1]
	ldr r1, _08192528 @ =0x00000201
	ands r0, r1
	cmp r0, #0
	bne _08192536
	movs r2, #0x20
	ldr r3, [sp, #0x10]
	ldr r0, _0819252C @ =0x00000F2C
	adds r1, r3, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08192530
	movs r0, #1
	b _08192532
	.align 2, 0
_08192528: .4byte 0x00000201
_0819252C: .4byte 0x00000F2C
_08192530:
	movs r0, #0
_08192532:
	cmp r0, #0
	beq _08192540
_08192536:
	ldrh r0, [r6, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r6, #6]
	b _08192638
_08192540:
	movs r2, #4
	mvns r3, r2
	ldrh r1, [r6, #6]
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r0, _081925BC @ =0x03002BE0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	mov r2, sb
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	mov ip, r2
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, ip
	adds r1, r2, r0
	ldr r0, _081925C0 @ =0x0000FFFF
	cmp r1, r0
	bgt _08192638
	ldrh r0, [r4, #6]
	adds r1, r3, #0
	ands r1, r0
	strh r1, [r4, #6]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	mov r3, sl
	ldrh r0, [r3]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081925C4
	movs r0, #1
	b _081925C6
	.align 2, 0
_081925BC: .4byte 0x03002BE0
_081925C0: .4byte 0x0000FFFF
_081925C4:
	movs r0, #0
_081925C6:
	cmp r0, #0
	beq _08192604
	ldr r0, _081925F8 @ =0xFFFFFEFF
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	ldr r2, _081925FC @ =0x00000226
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08192600 @ =0x0000022E
	adds r0, r5, r3
	ldrh r2, [r0]
	adds r3, #0x12
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xa
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	b _08192638
	.align 2, 0
_081925F8: .4byte 0xFFFFFEFF
_081925FC: .4byte 0x00000226
_08192600: .4byte 0x0000022E
_08192604:
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
_08192638:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp, #0x18]
	adds r1, r1, r0
	str r1, [sp, #0x18]
	adds r6, r6, r0
	ldr r2, [sp, #0x1c]
	adds r2, r2, r0
	str r2, [sp, #0x1c]
	ldr r3, [sp, #0x14]
	adds r3, #1
	str r3, [sp, #0x14]
	ldr r1, [sp, #0x10]
	ldr r2, _08192678 @ =0x00000F36
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x14]
	cmp r1, r0
	bge _08192668
	b _081924BA
_08192668:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08192678: .4byte 0x00000F36
