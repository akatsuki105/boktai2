	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r1, #4
	str r2, [sp, #4]
	ldrh r2, [r0, #0x1c]
	lsls r2, r2, #2
	adds r1, #0x24
	adds r2, r1, r2
	ldr r2, [r2]
	str r2, [sp, #8]
	ldrh r2, [r0, #0x1e]
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	mov sl, r1
	ldrh r7, [r0, #0x20]
	cmp r7, #0x40
	ble _0800F9E2
	movs r7, #0x40
_0800F9E2:
	movs r0, #0x1f
	mov sb, r0
	movs r1, #0x1f
	mov ip, r1
	movs r0, #0x40
	subs r0, r0, r7
	mov r8, r0
	movs r2, #0xf
	str r2, [sp]
_0800F9F4:
	ldr r0, [sp, #8]
	ldrh r3, [r0]
	mov r6, ip
	ands r6, r3
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x15
	mov r1, sb
	ands r5, r1
	lsrs r3, r3, #0x1a
	ands r3, r1
	mov r0, sl
	ldrh r2, [r0]
	mov r0, ip
	ands r0, r2
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x15
	ands r4, r1
	lsrs r2, r2, #0x1a
	ands r2, r1
	muls r0, r7, r0
	mov r1, r8
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r6, r0, #6
	adds r0, r4, #0
	muls r0, r7, r0
	mov r1, r8
	muls r1, r5, r1
	adds r0, r0, r1
	asrs r4, r0, #6
	adds r0, r2, #0
	muls r0, r7, r0
	mov r1, r8
	muls r1, r3, r1
	adds r0, r0, r1
	asrs r1, r0, #6
	mov r2, ip
	ands r6, r2
	ands r4, r2
	ands r1, r2
	lsls r0, r4, #5
	orrs r6, r0
	lsls r0, r1, #0xa
	orrs r6, r0
	ldr r0, [sp, #4]
	strh r6, [r0]
	adds r0, #2
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	adds r1, #2
	str r1, [sp, #8]
	movs r2, #2
	add sl, r2
	ldr r0, [sp]
	subs r0, #1
	str r0, [sp]
	cmp r0, #0
	bge _0800F9F4
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
