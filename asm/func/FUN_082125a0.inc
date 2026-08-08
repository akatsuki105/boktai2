	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	mov r7, sl
	adds r7, #0x94
	add r5, sp, #0x14
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0821277C @ =0x05000002
	bl CpuSet
	movs r0, #0x18
	add r0, sl
	mov sb, r0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	mov r1, sb
	movs r2, #1
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r7, #8]
	movs r6, #1
	orrs r0, r6
	str r0, [r7, #8]
	mov r0, sl
	adds r0, #0xf4
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0xa
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r7, #0x68]
	orrs r0, r6
	str r0, [r7, #0x68]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, sl
	mov sb, r5
	ldr r1, [r0]
	movs r3, #0xf5
	lsls r3, r3, #2
	add r3, sl
	movs r2, #0xe5
	lsls r2, r2, #2
	add r2, sl
	movs r4, #0x1f
_08212620:
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _08212620
	adds r1, r7, #0
	adds r1, #0xa8
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	mov r6, sl
	adds r6, #0x18
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	mov r8, r1
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	mov r2, sb
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r1, r7, #0
	adds r1, #0xc8
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	str r5, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	str r5, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #6
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	str r5, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r5, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #6
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r2, #0x92
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r5, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r2, #0xaa
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, _08212780 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08212784 @ =0x0000093C
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r2, #0xe0
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, _08212788 @ =0x030047A8
	ldr r0, [r0]
	ldrb r0, [r0, #9]
	movs r1, #3
	cmp r0, #0
	beq _08212756
	movs r1, #4
_08212756:
	ldr r2, _0821278C @ =0x00000389
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r2, [r0]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821277C: .4byte 0x05000002
_08212780: .4byte 0x030046A0
_08212784: .4byte 0x0000093C
_08212788: .4byte 0x030047A8
_0821278C: .4byte 0x00000389
