	push {lr}
	adds r0, #0x2c
	bl AuxSprite_Remove
	pop {r0}
	bx r0
