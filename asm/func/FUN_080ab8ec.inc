	push {lr}
	adds r0, #0xc0
	bl AuxSprite_Remove
	pop {r0}
	bx r0
