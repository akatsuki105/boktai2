	push {lr}
	adds r0, #0x18
	bl Particle_Remove
	pop {r1}
	bx r1
