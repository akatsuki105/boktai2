	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl MainSprite_Remove
	adds r4, #0x8c
	movs r5, #7
_080A9CB6:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080A9CB6
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
