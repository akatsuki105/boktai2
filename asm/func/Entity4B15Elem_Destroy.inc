	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl Particle_Remove
	pop {r0}
	bx r0
	.align 2, 0
