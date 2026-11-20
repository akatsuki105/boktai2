	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r1
	adds r7, r2, #0
	ldr r1, _0820844C @ =0x03003584
	ldr r1, [r1]
	ldr r2, _08208450 @ =0x000051E0
	adds r2, r1, r2
	str r2, [sp]
	movs r3, #0xa4
	lsls r3, r3, #7
	adds r3, r3, r1
	mov sb, r3
	ldr r1, _08208454 @ =0x03000228
	str r1, [sp, #4]
	adds r0, #0xdc
	str r1, [r0, #0x68]
	mov r2, r8
	lsls r2, r2, #2
	mov r8, r2
	lsls r7, r7, #2
	subs r2, r7, r2
	str r2, [sp, #0xc]
	movs r3, #0
	mov sl, r3
	movs r0, #0
	str r0, [sp, #0x14]
	movs r1, #0
	str r1, [sp, #0x10]
	movs r2, #0x1f
	movs r3, #0xf
	str r3, [sp, #8]
_08208398:
	ldr r1, [sp]
	ldrh r0, [r1]
	movs r4, #0x1f
	ands r4, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x15
	ands r5, r2
	lsrs r6, r0, #0x1a
	ands r6, r2
	mov r3, sb
	cmp r3, #0
	beq _082083CC
	ldrh r0, [r3]
	movs r1, #0x1f
	ands r1, r0
	str r1, [sp, #0x10]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x15
	ands r3, r2
	str r3, [sp, #0x14]
	lsrs r0, r0, #0x1a
	mov sl, r0
	ands r0, r2
	mov sl, r0
	movs r1, #2
	add sb, r1
_082083CC:
	ldr r3, [sp, #0xc]
	adds r0, r4, #0
	muls r0, r3, r0
	ldr r3, [sp, #0x10]
	mov r1, r8
	muls r1, r3, r1
	adds r0, r0, r1
	adds r1, r7, #0
	str r2, [sp, #0x18]
	bl Div
	adds r4, r0, #0
	ldr r2, [sp, #0x18]
	ands r4, r2
	ldr r1, [sp, #0xc]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r3, [sp, #0x14]
	mov r1, r8
	muls r1, r3, r1
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	adds r5, r0, #0
	ldr r2, [sp, #0x18]
	ands r5, r2
	ldr r1, [sp, #0xc]
	adds r0, r6, #0
	muls r0, r1, r0
	mov r3, r8
	mov r1, sl
	muls r1, r3, r1
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	ldr r2, [sp, #0x18]
	ands r0, r2
	lsls r0, r0, #0xa
	lsls r1, r5, #5
	orrs r0, r1
	orrs r4, r0
	ldr r0, [sp, #4]
	strh r4, [r0]
	ldr r1, [sp]
	adds r1, #2
	str r1, [sp]
	adds r0, #2
	str r0, [sp, #4]
	ldr r3, [sp, #8]
	subs r3, #1
	str r3, [sp, #8]
	cmp r3, #0
	bge _08208398
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820844C: .4byte 0x03003584
_08208450: .4byte 0x000051E0
_08208454: .4byte 0x03000228
