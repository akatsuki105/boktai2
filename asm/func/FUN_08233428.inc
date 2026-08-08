	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r3, [sp, #0x20]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrh r0, [r2]
	ldrh r1, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r6, _08233494 @ =0xFFFF0000
	mov r8, r6
	ldrh r1, [r2, #2]
	ldrh r6, [r4, #2]
	adds r1, r1, r6
	lsls r1, r1, #0x10
	ldr r6, _08233498 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r2, #4]
	ldrh r0, [r4, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	ands r0, r6
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08232df8
	strb r0, [r5]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_082332f8
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08233494: .4byte 0xFFFF0000
_08233498: .4byte 0x0000FFFF
