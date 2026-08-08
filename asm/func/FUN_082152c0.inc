	push {lr}
	sub sp, #4
	adds r1, r0, #0
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r2, [r0, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r2, r3
	str r2, [r0, #8]
	adds r1, #0x18
	movs r2, #0
	str r2, [sp]
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
