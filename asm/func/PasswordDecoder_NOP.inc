	push {lr}
	movs r0, #4
_080114A0:
	subs r0, #1
	cmp r0, #0
	bge _080114A0
	pop {r0}
	bx r0
	.align 2, 0
