	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r6, r0, #0
	ldr r0, _080038AC @ =0x0000015B
	bl PlaySound_082406e0
	adds r7, r6, #0
	adds r7, #0x34
	movs r0, #0x1e
	str r0, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0
	mov sl, r1
	str r1, [sp, #0x10]
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	str r2, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #2
	adds r2, r7, #0
	movs r3, #0x3c
	bl FUN_08014da0
	movs r1, #0x1e
	str r1, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r2, sl
	str r2, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r1, r8
	str r1, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #6
	adds r2, r7, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r2, _080038B0 @ =0xFFFF0000
	ldrh r1, [r6, #0x36]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r5, _080038B4 @ =0x0000FFFF
	ldrh r0, [r6, #0x34]
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r6, #0x38]
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r2
	ldr r4, _080038B8 @ =0x0000FFF1
	orrs r0, r4
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldr r0, [sp, #0x30]
	ands r0, r2
	movs r1, #0x1e
	orrs r0, r1
	ands r0, r5
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	ldr r0, [r1, #4]
	ands r0, r2
	movs r2, #0x1e
	orrs r0, r2
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r2, sp, #0x20
	bl FUN_08014730
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080038AC: .4byte 0x0000015B
_080038B0: .4byte 0xFFFF0000
_080038B4: .4byte 0x0000FFFF
_080038B8: .4byte 0x0000FFF1
