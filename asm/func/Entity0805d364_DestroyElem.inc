	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x7c
	bl Hitbox_Unregister
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Remove
	adds r0, r4, #0
	adds r0, #0xdc
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1
