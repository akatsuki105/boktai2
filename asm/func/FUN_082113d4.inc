	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	ldr r0, _0821162C @ =0x0000CB05
	ldr r1, _08211630 @ =0x00005EBF
	bl FUN_082310cc
	adds r3, r0, #0
	mov r1, sl
	adds r1, #0x28
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4, r6}
	stm r1!, {r2, r4, r6}
	ldm r0!, {r5, r6}
	stm r1!, {r5, r6}
	mov r6, sl
	adds r6, #0x28
	adds r0, r6, #0
	adds r1, r3, #0
	bl FUN_0822f284
	add r5, sp, #0x10
	movs r4, #0
	adds r0, r5, #0
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	mov r0, sl
	adds r0, #0x48
	movs r1, #1
	str r1, [sp]
	movs r1, #2
	mov sb, r1
	str r1, [sp, #4]
	movs r2, #0x3c
	mov r8, r2
	str r2, [sp, #8]
	adds r1, r5, #0
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x1e
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	mov r0, sl
	adds r0, #0xa8
	str r4, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r4, r8
	str r4, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x21
	movs r3, #0x30
	bl FUN_0822f3fc
	mov r5, sl
	adds r5, #0xf0
	ldr r0, [r5]
	ldr r4, _08211634 @ =0x00000848
	add r4, sl
	ldr r2, _08211638 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	str r4, [r5]
	add r4, sp, #0x10
	movs r0, #0
	mov sb, r0
	str r6, [sp, #0x20]
	movs r5, #0x84
	lsls r5, r5, #1
	add r5, sl
	mov r8, r0
	movs r6, #0xb0
	movs r7, #4
_08211486:
	strh r6, [r4]
	movs r1, #0x68
	strh r1, [r4, #2]
	mov r2, sb
	strh r2, [r4, #4]
	mov r0, sb
	str r0, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	adds r1, #0x28
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x88
	lsls r1, r1, #1
	add r1, sl
	add r1, r8
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	adds r5, #0x60
	movs r0, #0x60
	add r8, r0
	adds r6, #8
	subs r7, #1
	cmp r7, #0
	bge _08211486
	add r5, sp, #0x10
	movs r4, #0
	adds r0, r5, #0
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, sl
	str r4, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	adds r6, r5, #0
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xd
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xbc
	lsls r1, r1, #2
	add r1, sl
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xa0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	movs r0, #0xd2
	lsls r0, r0, #2
	add r0, sl
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0xd
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xd4
	lsls r1, r1, #2
	add r1, sl
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0821162C @ =0x0000CB05
	ldr r1, _0821163C @ =0x0000D27A
	bl FUN_082310cc
	adds r3, r0, #0
	movs r0, #0x8d
	lsls r0, r0, #3
	add r0, sl
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl FUN_0822f284
	movs r5, #0x91
	lsls r5, r5, #3
	add r5, sl
	movs r1, #0
	mov r6, sl
	adds r6, #0x25
	str r6, [sp, #0x1c]
	add r4, sp, #0x10
	mov r8, r1
_08211574:
	lsls r0, r1, #2
	adds r2, r1, #1
	str r2, [sp, #0x18]
	movs r7, #0x18
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x18
	mov sb, r0
	movs r6, #4
_08211586:
	strh r7, [r4]
	mov r0, sb
	strh r0, [r4, #2]
	mov r1, r8
	strh r1, [r4, #4]
	strh r1, [r4, #6]
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2]
	bl FUN_08211160
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	str r0, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0x8d
	lsls r1, r1, #3
	add r1, sl
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r5, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #8]
	adds r5, #0x60
	adds r7, #0x28
	subs r6, #1
	cmp r6, #0
	bge _08211586
	ldr r1, [sp, #0x18]
	cmp r1, #1
	ble _08211574
	movs r4, #0
	add r1, sp, #0x10
	adds r0, r1, #0
	strh r4, [r0]
	strh r4, [r1, #2]
	strh r4, [r1, #4]
	movs r0, #0xea
	lsls r0, r0, #2
	add r0, sl
	str r4, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x22
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0x81
	lsls r0, r0, #3
	add r0, sl
	str r4, [sp]
	movs r6, #2
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x23
	movs r3, #0x30
	bl FUN_0822f3fc
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0821162C: .4byte 0x0000CB05
_08211630: .4byte 0x00005EBF
_08211634: .4byte 0x00000848
_08211638: .4byte 0x04000008
_0821163C: .4byte 0x0000D27A
