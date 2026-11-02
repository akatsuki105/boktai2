	push {lr}
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r0, r1
	bl AuxSprite_Remove
	pop {r0}
	bx r0
