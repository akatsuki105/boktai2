	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0xa4
	movs r5, #7
_080ABFF4:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080ABFF4
	pop {r4, r5}
	pop {r0}
	bx r0
