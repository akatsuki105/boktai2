	push {lr}
	adds r0, #0x9c
	bl Map_InitPathWalker
	pop {r0}
	bx r0
