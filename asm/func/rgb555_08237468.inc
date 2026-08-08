	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov ip, r1
	adds r7, r2, #0
	adds r5, r3, #0
	ldr r0, [sp, #0x20]
	mov sb, r0
	movs r0, #1
	mov r1, sb
	lsls r0, r1
	subs r6, r0, r5
	movs r0, #0xf
	mov sl, r0
_0823748A:
	mov r0, ip
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r3, r0, #0
	muls r3, r6, r3
	ldrh r4, [r7]
	movs r0, #0x1f
	ands r0, r4
	muls r0, r5, r0
	adds r3, r3, r0
	mov r0, sb
	asrs r3, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r2, r0, #0
	muls r2, r6, r2
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r4
	muls r0, r5, r0
	adds r2, r2, r0
	mov r0, sb
	asrs r2, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	adds r1, r0, #0
	muls r1, r6, r1
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r4
	muls r0, r5, r0
	adds r1, r1, r0
	mov r0, sb
	asrs r1, r0
	movs r0, #0x1f
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r2, r0
	orrs r3, r2
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r3, r1
	mov r1, r8
	strh r3, [r1]
	movs r0, #2
	add ip, r0
	adds r7, #2
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r0, sl
	cmp r0, #0
	bge _0823748A
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
