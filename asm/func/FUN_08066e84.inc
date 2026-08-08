	push {lr}
	sub sp, #4
	movs r1, #6
	mov r0, sp
	strh r1, [r0]
	movs r0, #0x11
	mov r1, sp
	bl FUN_080ec79c
	add sp, #4
	pop {r0}
	bx r0
