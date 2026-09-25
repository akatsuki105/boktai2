	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #3
_080AC4E0:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _080AC4E0
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
