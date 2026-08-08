	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r5, #0
	adds r6, #0x78
	movs r0, #4
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r0, #0xf8
	ldr r2, [r0]
	movs r7, #0
	str r7, [sp]
	movs r0, #1
	mov r8, r0
	str r0, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r7, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	bne _08213A34
	adds r1, #2
	adds r0, r5, r1
	strh r7, [r0]
	adds r0, r5, #0
	adds r0, #0x98
	adds r1, r6, #0
	movs r2, #0x94
	movs r3, #1
	bl FUN_0822f3cc
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, _08213A30 @ =0x0000FFF8
	strh r0, [r1]
	adds r1, #2
	subs r0, #0x38
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0821397c
	b _08213A3C
	.align 2, 0
_08213A30: .4byte 0x0000FFF8
_08213A34:
	ldr r0, [r6, #0x28]
	mov r1, r8
	orrs r0, r1
	str r0, [r6, #0x28]
_08213A3C:
	adds r1, r6, #0
	adds r1, #0x90
	movs r0, #0
	str r0, [r1]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
