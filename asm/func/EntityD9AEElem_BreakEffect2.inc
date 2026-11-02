	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r6, #0x34
	movs r7, #0x1e
	str r7, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
	str r0, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #1
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	str r7, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r0, r8
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #5
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
