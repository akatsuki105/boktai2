	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sl, r0
	ldr r7, _08215F28 @ =0x00000E8C
	add r7, sl
	add r5, sp, #0x14
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08215F2C @ =0x05000002
	bl CpuSet
	mov r6, sl
	adds r6, #0x18
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0x3f
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r7, #8]
	movs r1, #1
	mov r8, r1
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, _08215F30 @ =0x00000EEC
	add r0, sl
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x4b
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r7, #0x68]
	mov r1, r8
	orrs r0, r1
	str r0, [r7, #0x68]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x1c]
	ldr r5, _08215F34 @ =0x00000F4C
	add r5, sl
	movs r6, #0
	movs r4, #2
_08215E2A:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	adds r1, #0x18
	movs r2, #0x47
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r2, r7, #0
	adds r2, #0xc8
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r1, r8
	ldrh r0, [r1, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	adds r5, #0x60
	adds r6, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08215E2A
	movs r0, #0xb8
	mov r1, sp
	strh r0, [r1, #0x14]
	add r1, sp, #0x14
	movs r0, #0x40
	strh r0, [r1, #2]
	mov r8, r1
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r6, #0
	movs r4, #2
_08215E7E:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x14
	str r1, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0xf4
	lsls r0, r0, #1
	adds r2, r7, r0
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #8
	strh r0, [r1]
	adds r5, #0x60
	adds r6, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08215E7E
	movs r0, #0xb8
	mov r1, sp
	strh r0, [r1, #0x14]
	add r1, sp, #0x14
	movs r0, #0x60
	strh r0, [r1, #2]
	mov sb, r1
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r4, #2
_08215ED4:
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r2, r7, r1
	add r2, r8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r1, sb
	ldrh r0, [r1]
	adds r0, #8
	strh r0, [r1]
	adds r5, #0x60
	movs r0, #0x60
	add r8, r0
	subs r4, #1
	cmp r4, #0
	bge _08215ED4
	ldr r1, _08215F38 @ =0x00000424
	adds r0, r7, r1
	str r6, [r0]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08215F28: .4byte 0x00000E8C
_08215F2C: .4byte 0x05000002
_08215F30: .4byte 0x00000EEC
_08215F34: .4byte 0x00000F4C
_08215F38: .4byte 0x00000424
