	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl AuxSprite_Remove
	adds r4, #0x7c
	movs r5, #3
_080C19CA:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080C19CA
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
