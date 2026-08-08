	push {r4, lr}
	sub sp, #8
	adds r4, r1, #0
	mov r1, sp
	bl FUN_08231880
	add r1, sp, #4
	bl ReadScriptOffset
	ldr r2, [sp]
	adds r1, r4, #0
	bl FUN_08231b7c
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
