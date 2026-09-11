	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x1c
	adds r6, r0, #0
	mov sb, r2
	mov sl, r3
	movs r0, #0x20
	adds r0, r0, r6
	mov r8, r0
	ldr r4, _080A8024 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x64
	orrs r0, r3
	ldr r2, _080A8028 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0xc8
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r5, #0
	str r5, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r2, #0x84
	lsls r2, r2, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	mov r0, r8
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x80
	lsls r3, r3, #7
	str r5, [sp]
	str r5, [sp, #4]
	mov r0, r8
	mov r1, sb
	movs r2, #0
	bl FUN_082364f8
	adds r0, r6, #0
	adds r0, #0x62
	mov r1, sl
	strb r1, [r0]
	mov r0, r8
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r6, #0x88
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A8024: .4byte 0xFFFF0000
_080A8028: .4byte 0x0000FFFF
