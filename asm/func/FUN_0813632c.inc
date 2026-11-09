	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _08136370 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	blt _08136350
	b _08136516
_08136350:
	movs r3, #0
	mov sl, r3
	movs r6, #0xe8
	lsls r6, r6, #3
	add r6, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_08136362:
	ldrb r0, [r6, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08136374
	movs r0, #1
	b _08136376
	.align 2, 0
_08136370: .4byte 0x00000B3A
_08136374:
	movs r0, #0
_08136376:
	cmp r0, #0
	beq _0813637C
	b _081364F8
_0813637C:
	movs r1, #4
	ldrb r0, [r6, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _0813638A
	movs r0, #1
	b _0813638C
_0813638A:
	movs r0, #0
_0813638C:
	cmp r0, #0
	beq _081363C2
	ldrb r0, [r6, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	b _08136418
_081363C2:
	ldrb r0, [r6, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	ldrh r4, [r6, #8]
	ldrh r5, [r6, #0xe]
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #0xc]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	bl AuxAnim_SetAnim
	ldr r0, _08136450 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl AuxAnim_SetAnimSpeed
	strh r4, [r6, #8]
	strh r5, [r6, #0xe]
_08136418:
	mov r7, r8
	adds r4, r6, #0
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r6, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _08136454
	mov r1, r8
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _08136460
	.align 2, 0
_08136450: .4byte 0x00000482
_08136454:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08136460:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08136482
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _0813648A
_08136482:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0813648A:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081364C0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081364F8
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081364C4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081364BA
	ldrb r0, [r4, #5]
_081364BA:
	subs r0, #1
	strh r0, [r4, #8]
	b _081364D4
	.align 2, 0
_081364C0: .4byte 0x0000FFFF
_081364C4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081364D4
	strh r1, [r4, #8]
_081364D4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081364F8
	movs r3, #1
	strb r3, [r4, #7]
_081364F8:
	movs r0, #0x90
	lsls r0, r0, #1
	add sl, r0
	adds r6, r6, r0
	add r8, r0
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, _08136528 @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08136516
	b _08136362
_08136516:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136528: .4byte 0x00000B3A
