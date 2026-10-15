	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	adds r4, #0xc0
	movs r5, #7
_080A21E6:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A21E6
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
