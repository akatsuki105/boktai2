	push {lr}
	bl Enemy_Update
	movs r0, #0
	pop {r1}
	bx r1
