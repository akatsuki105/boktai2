	push {r4, r5, lr}
	sub sp, #8
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_080dc0d0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
