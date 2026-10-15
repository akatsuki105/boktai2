	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x3c
	movs r5, #7
_0801957C:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _0801957C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
