	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r3, [sp]
	str r0, [sp, #4]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r7, r0, r3
	ldr r0, _0817D770 @ =0x03003584
	lsls r4, r1, #5
	ldr r3, [r0]
	lsls r2, r2, #5
	adds r2, r3, r2
	str r2, [sp, #8]
	ldr r5, [sp, #4]
	ldr r2, _0817D774 @ =0x000006DA
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r0, r5, r0
	str r0, [sp, #0x10]
	adds r3, r3, r4
	mov sl, r3
	movs r1, #0
	mov sb, r1
	movs r2, #0xf
	str r2, [sp, #0xc]
_0817D75A:
	adds r0, r7, #0
	adds r0, #0x80
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r0, r3
	beq _0817D778
	mov r5, sb
	adds r0, r7, r5
	b _0817D77C
	.align 2, 0
_0817D770: .4byte 0x03003584
_0817D774: .4byte 0x000006DA
_0817D778:
	ldr r0, [sp, #8]
	add r0, sb
_0817D77C:
	ldrh r5, [r0]
	adds r3, r7, #0
	adds r3, #0xe4
	add r3, sb
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	mov r8, r5
	mov r1, r8
	movs r2, #0x1f
	ands r1, r2
	mov r8, r1
	subs r0, r0, r1
	lsls r0, r0, #8
	strh r0, [r3]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r6, r7, r0
	add r6, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #5
	ands r0, r2
	asrs r2, r5, #5
	movs r1, #0x1f
	ands r2, r1
	subs r0, r0, r2
	lsls r0, r0, #8
	strh r0, [r6]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r7, r0
	add r4, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r5, r5, #0xa
	ands r5, r1
	subs r0, r0, r5
	lsls r0, r0, #8
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, [sp]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	bl Div
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	ldr r1, [sp]
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r4]
	adds r0, r7, #0
	adds r0, #0x84
	add r0, sb
	mov r3, r8
	lsls r3, r3, #8
	strh r3, [r0]
	adds r0, r7, #0
	adds r0, #0xa4
	add r0, sb
	ldr r2, [sp, #0x14]
	lsls r2, r2, #8
	strh r2, [r0]
	adds r0, r7, #0
	adds r0, #0xc4
	add r0, sb
	lsls r5, r5, #8
	strh r5, [r0]
	movs r5, #2
	add sl, r5
	add sb, r5
	ldr r0, [sp, #0xc]
	subs r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0
	bge _0817D75A
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, [sp, #0x10]
	strh r2, [r1]
	movs r2, #0x80
	ldr r3, [sp, #4]
	ldr r5, _0817D858 @ =0x00000898
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817D858: .4byte 0x00000898
