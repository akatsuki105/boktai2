	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl FUN_080dc0d0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
