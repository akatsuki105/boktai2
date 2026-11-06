	push {lr}
	adds r0, r1, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	pop {r1}
	bx r1
	.align 2, 0
