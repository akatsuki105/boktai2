	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x64
	bl Particle_Remove
	adds r0, r4, #0
	adds r0, #0x14
	bl Hitbox_Unregister
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
