	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r7, r1, #0
	adds r4, r3, #0
	ldr r0, [sp, #0x24]
	mov sb, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0x1f
	ands r1, r2
	str r1, [sp]
	movs r3, #0xf8
	lsls r3, r3, #2
	mov r8, r2
	mov r0, r8
	ands r0, r3
	mov r8, r0
	movs r1, #0xf8
	lsls r1, r1, #7
	adds r6, r2, #0
	ands r6, r1
	movs r0, #1
	mov r2, sb
	lsls r0, r2
	subs r5, r0, r4
	movs r0, #0xf
	mov sl, r0
_08237550:
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	adds r3, r0, #0
	muls r3, r5, r3
	ldr r2, [sp]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r3, r3, r0
	mov r0, sb
	asrs r3, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r2, r0, #0
	muls r2, r5, r2
	mov r0, r8
	muls r0, r4, r0
	adds r2, r2, r0
	mov r0, sb
	asrs r2, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r5, r0
	adds r1, r6, #0
	muls r1, r4, r1
	adds r0, r0, r1
	mov r1, sb
	asrs r0, r1
	movs r1, #0x1f
	ands r3, r1
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r2, r1
	orrs r3, r2
	movs r2, #0xf8
	lsls r2, r2, #7
	ands r0, r2
	orrs r3, r0
	mov r0, ip
	strh r3, [r0]
	adds r7, #2
	movs r1, #2
	add ip, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	bge _08237550
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
