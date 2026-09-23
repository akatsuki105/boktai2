	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	ldr r3, [r4]
	cmp r3, r1
	blt _08048A90
_08048A84:
	adds r0, #1
	subs r2, r3, r1
	adds r3, r2, #0
	cmp r2, r1
	bge _08048A84
	str r2, [r4]
_08048A90:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
