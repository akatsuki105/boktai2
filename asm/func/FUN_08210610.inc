	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	movs r0, #0x24
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	bl FUN_0820ff44
	adds r2, r0, #0
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r6, r7, #0
	adds r6, #0x28
	movs r4, #0
	str r4, [sp]
	movs r1, #0x20
	str r1, [sp, #4]
	movs r5, #0x60
	str r5, [sp, #8]
	movs r1, #8
	mov r8, r1
	str r1, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r1, r6, #0
	movs r3, #2
	bl FUN_082376a4
	movs r0, #0xf4
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x30
	strh r0, [r1]
	movs r1, #0xf5
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	subs r1, #0x22
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0
	bl FUN_0822f3cc
	mov r1, sb
	ldrb r0, [r1]
	bl FUN_0820fedc
	adds r2, r0, #0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	movs r1, #0x38
	str r1, [sp, #4]
	str r5, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r1, r6, #0
	movs r3, #2
	bl FUN_082376a4
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
