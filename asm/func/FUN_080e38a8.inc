	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r2, [sp, #0x28]
	adds r4, r7, #0
	adds r4, #0xd8
	ldrh r1, [r7]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x10
	str r0, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r3, [r0]
	adds r0, r4, #0
	bl FUN_08236514
	adds r1, r7, #0
	adds r1, #8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	mov r1, r8
	ldr r2, [sp, #0x24]
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
