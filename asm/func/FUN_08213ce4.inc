	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r6, r7, r0
	add r5, sp, #0x14
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08213D6C @ =0x05000002
	bl CpuSet
	movs r1, #0x18
	adds r1, r1, r7
	mov sb, r1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	mov r8, r0
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	movs r2, #0x45
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0x46
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	ldr r0, [r6, #0x68]
	orrs r0, r1
	str r0, [r6, #0x68]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [r0]
	adds r1, #4
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08213D6C: .4byte 0x05000002
