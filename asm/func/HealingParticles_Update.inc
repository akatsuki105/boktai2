	push {lr}
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
