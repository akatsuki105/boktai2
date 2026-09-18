	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r7, r3, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r3, _08080A84 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x1e
	orrs r0, r2
	ldr r1, _08080A88 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080A8C
	str r1, [sp, #0x14]
	b _08080A8E
	.align 2, 0
_08080A84: .4byte 0xFFFF0000
_08080A88: .4byte 0x0000FFFF
_08080A8C:
	str r0, [sp, #0x14]
_08080A8E:
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	str r0, [r1, #4]
	adds r3, r1, #0
	ldr r2, _08080AEC @ =0x00002101
	ldr r1, [r4, #0x18]
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	mov r2, r8
	movs r3, #0x10
	bl FUN_082364f8
	ldr r1, _08080AF0 @ =FUN_08080648
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r1, r4, #0
	adds r1, #0x38
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080AEC: .4byte 0x00002101
_08080AF0: .4byte FUN_08080648
