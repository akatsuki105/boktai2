	push {lr}
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	pop {r0}
	bx r0
