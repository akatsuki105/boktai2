	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r7, r3, #0
	ldr r0, _08089B80 @ =0x03003584
	ldr r3, _08089B84 @ =0x00000207
	adds r1, r1, r3
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r1, r1, r0
	mov r8, r1
	adds r2, r2, r3
	lsls r2, r2, #5
	adds r0, r0, r2
	mov ip, r0
	cmp r7, #0
	bne _08089B88
	ldr r1, [sp]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	mov r3, r8
	str r3, [r0]
	b _08089C32
	.align 2, 0
_08089B80: .4byte 0x03003584
_08089B84: .4byte 0x00000207
_08089B88:
	cmp r7, #0x40
	bne _08089B9A
	ldr r1, [sp]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	mov r3, ip
	str r3, [r0]
	b _08089C32
_08089B9A:
	ldr r0, [sp]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r0, r1
	mov sl, r0
	movs r0, #0x40
	subs r0, r0, r7
	mov sb, r0
	movs r2, #0xf
	str r2, [sp, #4]
_08089BAE:
	mov r3, r8
	ldrh r0, [r3]
	movs r4, #0x1f
	ands r4, r0
	movs r6, #0xf8
	lsls r6, r6, #2
	ands r6, r0
	movs r5, #0xf8
	lsls r5, r5, #7
	ands r5, r0
	mov r1, ip
	ldrh r0, [r1]
	movs r1, #0x1f
	ands r1, r0
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r2, r0
	movs r3, #0xf8
	lsls r3, r3, #7
	ands r3, r0
	mov r0, sb
	muls r0, r4, r0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r4, r0, #6
	mov r0, sb
	muls r0, r6, r0
	adds r1, r2, #0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r6, r0, #6
	mov r0, sb
	muls r0, r5, r0
	adds r1, r3, #0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r5, r0, #6
	movs r2, #0x1f
	ands r4, r2
	movs r3, #0xf8
	lsls r3, r3, #2
	ands r6, r3
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r5, r0
	orrs r4, r6
	orrs r4, r5
	mov r1, sl
	strh r4, [r1]
	movs r2, #2
	add r8, r2
	add ip, r2
	add sl, r2
	ldr r3, [sp, #4]
	subs r3, #1
	str r3, [sp, #4]
	cmp r3, #0
	bge _08089BAE
	ldr r0, [sp]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
_08089C32:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
