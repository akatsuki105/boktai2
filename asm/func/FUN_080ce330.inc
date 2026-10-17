	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080CE370 @ =0x000004C4
	adds r0, r4, r1
	bl Eff082473e0Emitter_Destroy
	ldr r1, _080CE374 @ =0x0000060C
	adds r0, r4, r1
	bl ParticleShadow_Remove
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r4, r1
	bl Particle_Remove
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r4, r1
	bl Particle_Remove
	adds r0, r4, #0
	bl FUN_080cd078
	adds r0, r4, #0
	bl FUN_080cd528
	adds r0, r4, #0
	bl FUN_080cce5c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CE370: .4byte 0x000004C4
_080CE374: .4byte 0x0000060C
