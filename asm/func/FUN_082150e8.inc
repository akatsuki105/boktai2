	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xd8
	lsls r0, r0, #3
	adds r7, r4, r0
	add r1, sp, #0x14
	mov r8, r1
	movs r6, #0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _08215198 @ =0x05000002
	bl CpuSet
	movs r3, #0x18
	adds r3, r3, r4
	mov sl, r3
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0x2a
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r7, #8]
	movs r5, #1
	orrs r0, r5
	str r0, [r7, #8]
	movs r3, #0xe4
	lsls r3, r3, #3
	adds r0, r4, r3
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	mov r3, r8
	str r3, [sp, #0xc]
	mov r1, sl
	movs r2, #0x25
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r7, #0x68]
	orrs r0, r5
	str r0, [r7, #0x68]
	ldr r1, _0821519C @ =0x00000DB4
	adds r0, r4, r1
	strh r5, [r0]
	ldr r3, _082151A0 @ =0x00000DBA
	adds r4, r4, r3
	strh r6, [r4]
	movs r5, #7
	movs r4, #0
_08215166:
	movs r0, #4
	adds r1, r5, #0
	movs r2, #0x10
	movs r3, #2
	bl FUN_0804a084
	lsls r2, r4, #2
	movs r3, #0xdb
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r1, r1, r2
	str r0, [r1]
	adds r5, #2
	adds r4, #1
	cmp r4, #4
	ble _08215166
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08215198: .4byte 0x05000002
_0821519C: .4byte 0x00000DB4
_082151A0: .4byte 0x00000DBA
