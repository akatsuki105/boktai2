	push {r4, r5, lr}
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r5, #0xb
_080AB6E2:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _080AB6E2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
