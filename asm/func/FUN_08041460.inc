	push {r4, lr}
	sub sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	adds r0, #0xd0
	str r2, [sp]
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
