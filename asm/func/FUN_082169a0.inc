	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r0, _08216A48 @ =0x0000166C
	adds r6, r5, r0
	add r1, sp, #0x14
	mov sl, r1
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _08216A4C @ =0x05000002
	bl CpuSet
	adds r7, r5, #0
	adds r7, #0x18
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x3c
	mov r8, r2
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x15
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r6, #8]
	movs r1, #1
	mov sb, r1
	orrs r0, r1
	str r0, [r6, #8]
	ldr r2, _08216A50 @ =0x000016CC
	adds r0, r5, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	mov r2, sl
	str r2, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x4e
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r6, #0x68]
	mov r1, sb
	orrs r0, r1
	str r0, [r6, #0x68]
	ldr r2, _08216A54 @ =0x0000172C
	adds r0, r5, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	mov r2, sl
	str r2, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x21
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, _08216A58 @ =0x00001734
	adds r1, r5, r0
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08216A5C @ =0x00001FDC
	adds r5, r5, r0
	strh r4, [r5]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08216A48: .4byte 0x0000166C
_08216A4C: .4byte 0x05000002
_08216A50: .4byte 0x000016CC
_08216A54: .4byte 0x0000172C
_08216A58: .4byte 0x00001734
_08216A5C: .4byte 0x00001FDC
