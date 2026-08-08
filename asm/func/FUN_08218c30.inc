	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	ldr r7, _08218DB8 @ =0x000012C8
	add r7, r8
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _08218DBC @ =0x05000002
	bl CpuSet
	ldr r0, _08218DC0 @ =0x0000CB05
	ldr r1, _08218DC4 @ =0x0000D27A
	bl FUN_082310cc
	adds r1, r0, #0
	adds r2, r7, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r7, #0
	bl FUN_0822f284
	movs r0, #0x18
	strh r0, [r4]
	movs r6, #0x28
	strh r6, [r4, #2]
	ldr r0, _08218DC8 @ =0x000012E8
	add r0, r8
	movs r5, #1
	str r5, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r2, #0x3c
	mov sb, r2
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r7, #0x28]
	orrs r0, r5
	str r0, [r7, #0x28]
	movs r3, #0
	strh r3, [r4]
	ldr r0, _08218DCC @ =0x0000FFE0
	strh r0, [r4, #2]
	ldr r0, _08218DD0 @ =0x00001348
	add r0, r8
	movs r6, #0x18
	add r6, r8
	mov sl, r6
	str r5, [sp]
	movs r1, #0
	str r1, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, sl
	movs r2, #0x3e
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _08218DD4 @ =0x00001350
	add r1, r8
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r0, #0xa8
	strh r0, [r4]
	movs r3, #0x28
	strh r3, [r4, #2]
	movs r6, #0
	mov r5, sl
	str r5, [sp, #0x1c]
	movs r0, #1
	mov sb, r0
	ldr r5, _08218DD8 @ =0x000013A8
	add r5, r8
	movs r4, #0
_08218CE6:
	movs r2, #0
	cmp r6, #2
	bne _08218CEE
	movs r2, #0x14
_08218CEE:
	mov r1, sb
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x14
	str r3, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r3, #0x30
	bl FUN_0822f3fc
	lsls r0, r6, #3
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	adds r1, r7, #0
	adds r1, #0xe8
	adds r1, r1, r4
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	adds r5, #0x60
	adds r4, #0x60
	adds r6, #1
	cmp r6, #4
	ble _08218CE6
	movs r0, #0xc0
	mov r3, sp
	strh r0, [r3, #0x14]
	add r1, sp, #0x14
	movs r0, #0x38
	strh r0, [r1, #2]
	movs r6, #0
	movs r5, #1
	mov r8, r5
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r4, #0
_08218D42:
	mov r1, r8
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r2, sp, #0x14
	str r2, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	lsls r0, r6, #3
	ldrh r3, [r5, #0x20]
	adds r0, r0, r3
	strh r0, [r5, #0x20]
	movs r0, #0xb2
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r1, r1, r4
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
	adds r5, #0x60
	adds r4, #0x60
	adds r6, #1
	cmp r6, #1
	ble _08218D42
	movs r0, #8
	movs r1, #7
	movs r2, #0xc
	movs r3, #2
	bl FUN_0804a084
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r1, r7, r3
	str r0, [r1]
	movs r0, #3
	movs r1, #0xa
	movs r2, #0x18
	movs r3, #2
	bl FUN_0804a084
	movs r5, #0xe1
	lsls r5, r5, #2
	adds r1, r7, r5
	str r0, [r1]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08218DB8: .4byte 0x000012C8
_08218DBC: .4byte 0x05000002
_08218DC0: .4byte 0x0000CB05
_08218DC4: .4byte 0x0000D27A
_08218DC8: .4byte 0x000012E8
_08218DCC: .4byte 0x0000FFE0
_08218DD0: .4byte 0x00001348
_08218DD4: .4byte 0x00001350
_08218DD8: .4byte 0x000013A8
