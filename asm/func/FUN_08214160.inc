	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	mov sb, r0
	ldr r1, _0821423C @ =0x08252780
	add r0, sp, #0x10
	movs r2, #0x60
	bl memcpy
	movs r6, #0xec
	lsls r6, r6, #1
	add r6, sb
	mov r0, sp
	adds r0, #0x70
	str r0, [sp, #0x80]
	mov r1, sp
	adds r1, #0x74
	str r1, [sp, #0x84]
	mov r2, sb
	adds r2, #0x18
	str r2, [sp, #0x7c]
	add r5, sp, #0x10
	adds r4, r6, #0
	movs r0, #0
	mov r8, r0
	mov sl, r0
	movs r7, #0xb
_0821419C:
	mov r1, sl
	str r1, [sp]
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	adds r1, #0x18
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r1, r6, #0
	adds r1, #8
	add r1, r8
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	adds r5, #8
	adds r4, #0x60
	movs r0, #0x60
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _0821419C
	movs r4, #0
	str r4, [sp, #0x70]
	ldr r0, [sp, #0x80]
	ldr r1, [sp, #0x84]
	ldr r2, _08214240 @ =0x05000002
	bl CpuSet
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	ldr r1, [sp, #0x84]
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x7c]
	movs r2, #0x36
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x9c
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	ldr r2, _08214244 @ =0x000004E4
	adds r0, r6, r2
	strb r4, [r0]
	adds r1, #5
	adds r0, r6, r1
	strb r4, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r4, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821423C: .4byte 0x08252780
_08214240: .4byte 0x05000002
_08214244: .4byte 0x000004E4
