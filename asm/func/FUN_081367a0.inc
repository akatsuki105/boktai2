	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, _081367EC @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r3, [sp, #0xc]
	cmp r3, r0
	blt _081367C6
	b _08136968
_081367C6:
	movs r4, #0
	mov sl, r4
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	lsls r2, r2, #0x18
	str r2, [sp, #0x10]
_081367DC:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081367F0
	movs r0, #1
	b _081367F2
	.align 2, 0
_081367EC: .4byte 0x00000B3A
_081367F0:
	movs r0, #0
_081367F2:
	cmp r0, #0
	beq _081367F8
	b _08136948
_081367F8:
	ldrb r0, [r7, #0x15]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _08136806
	movs r0, #1
	b _08136808
_08136806:
	movs r0, #0
_08136808:
	cmp r0, #0
	beq _0813682C
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #8]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #1
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl AuxAnim_RestartAnim
	b _0813686E
_0813682C:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r4, [sp, #8]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl AuxAnim_RestartAnim
	ldr r0, _081368A0 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl AuxAnim_SetAnimSpeed
_0813686E:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _081368A4
	ldr r0, [r6]
	movs r2, #4
	orrs r0, r2
	str r0, [r6]
	b _081368B0
	.align 2, 0
_081368A0: .4byte 0x00000482
_081368A4:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081368B0:
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
	beq _081368D2
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081368DA
_081368D2:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081368DA:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _08136910 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08136948
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08136914
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0813690A
	ldrb r0, [r4, #5]
_0813690A:
	subs r0, #1
	strh r0, [r4, #8]
	b _08136924
	.align 2, 0
_08136910: .4byte 0x0000FFFF
_08136914:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08136924
	strh r1, [r4, #8]
_08136924:
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
	bne _08136948
	movs r3, #1
	strb r3, [r4, #7]
_08136948:
	movs r4, #0x90
	lsls r4, r4, #1
	add sl, r4
	adds r7, r7, r4
	add r8, r4
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	ldr r0, _08136978 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0xc]
	cmp r2, r0
	bge _08136968
	b _081367DC
_08136968:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136978: .4byte 0x00000B3A
