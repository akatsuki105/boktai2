	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r5, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FD09C
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	bl NestedState_Reset0
	mov r0, r8
	movs r1, #0
	bl NestedState_Set0
	ldr r1, _081FD07C @ =0x000007CC
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_08203d38
	ldr r2, _081FD080 @ =0x000007FA
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _081FD084 @ =0x000007C9
	adds r0, r5, r1
	strb r2, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_081fa620
	ldr r2, _081FD088 @ =0x000007CA
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081fa620
	adds r1, r0, #0
	cmp r1, #0
	bne _081FD08C
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r5, r2
	b _081FD09A
	.align 2, 0
_081FD07C: .4byte 0x000007CC
_081FD080: .4byte 0x000007FA
_081FD084: .4byte 0x000007C9
_081FD088: .4byte 0x000007CA
_081FD08C:
	ldr r0, _081FD0B0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r1, r5, r2
_081FD09A:
	str r0, [r1]
_081FD09C:
	mov r0, r8
	ldrb r6, [r0]
	cmp r6, #1
	beq _081FD15C
	cmp r6, #1
	bgt _081FD0B4
	cmp r6, #0
	beq _081FD0BC
	b _081FD1F8
	.align 2, 0
_081FD0B0: .4byte 0x03003584
_081FD0B4:
	cmp r6, #2
	bne _081FD0BA
	b _081FD1C4
_081FD0BA:
	b _081FD1F8
_081FD0BC:
	mov r1, r8
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FD0E6
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	movs r3, #0xa
	bl Boss_PlayAnimFacing
	mov r1, r8
	str r4, [r1, #4]
_081FD0E6:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sb, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	bl Boss_AdvanceAnim
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FD126
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	mov r0, r8
	movs r1, #1
	bl NestedState_Set0
_081FD126:
	ldr r2, _081FD150 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FD154 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FD158 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	asrs r0, r0, #1
	cmp r0, #0
	beq _081FD1F8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_081fa628
	b _081FD1F8
	.align 2, 0
_081FD150: .4byte 0x030046B8
_081FD154: .4byte 0x000003FF
_081FD158: .4byte 0x0203B400
_081FD15C:
	mov r2, r8
	ldr r3, [r2, #4]
	cmp r3, #0
	bne _081FD182
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	str r6, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0xc
	bl Boss_PlayAnimFacing
	mov r1, r8
	str r6, [r1, #4]
_081FD182:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sb, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	bl Boss_AdvanceAnim
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FD1F8
	movs r0, #2
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	movs r3, #0
	bl Boss_PlayAnimFacing
	mov r0, r8
	movs r1, #2
	bl NestedState_Set0
	b _081FD1F8
_081FD1C4:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r7, r0
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	adds r0, r5, #0
	adds r0, #0xa7
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _081FD208 @ =FUN_081fcf54
	movs r0, #3
	adds r4, r5, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_081FD1F8:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FD208: .4byte FUN_081fcf54
