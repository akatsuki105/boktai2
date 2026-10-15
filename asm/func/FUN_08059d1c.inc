	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x6c
	bl Hitbox_Unregister
	adds r4, #0xbc
	adds r0, r4, #0
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
