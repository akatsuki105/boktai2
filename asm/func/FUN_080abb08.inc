	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x20
	bl AuxSprite_Remove
	adds r4, #0x68
	adds r0, r4, #0
	bl AuxSprite_Remove
	pop {r4}
	pop {r0}
	bx r0
