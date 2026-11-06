	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x64
	bl Hitbox_Unregister
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Remove
	adds r0, r4, #0
	adds r0, #0xc4
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1
