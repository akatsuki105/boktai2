	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r2, _081484A8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _081484AC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #8]
	add r0, sp, #8
	mov r8, r0
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0xc]
	movs r0, #0xa0
	lsls r0, r0, #0xe
	str r0, [sp, #0x10]
	add r4, sp, #0x10
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r3, _081484B0 @ =FUN_08147bc0
	movs r5, #0
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl Enemy_InitAtkHitbox
	movs r1, #0x50
	add r0, sp, #8
	strh r1, [r0]
	movs r0, #0x78
	mov r2, r8
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	strh r5, [r4]
	strh r0, [r4, #2]
	strh r5, [r4, #4]
	ldr r3, _081484B4 @ =FUN_08147c00
	str r6, [sp]
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl FUN_080e3834
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081484A8: .4byte 0xFFFF0000
_081484AC: .4byte 0x0000FFFF
_081484B0: .4byte FUN_08147bc0
_081484B4: .4byte FUN_08147c00
