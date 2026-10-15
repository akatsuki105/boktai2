	push {lr}
	adds r1, r0, #0
	adds r1, #0xc8
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
