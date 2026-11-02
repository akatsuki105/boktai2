	push {lr}
	adds r1, r0, #0
	adds r0, #0xb8
	adds r1, #0x24
	bl Map_InitNavAgent
	pop {r0}
	bx r0
