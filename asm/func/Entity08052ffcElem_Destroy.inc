	push {lr}
	adds r0, r1, #0
	adds r0, #0x14
	bl AuxSprite_Remove
	pop {r0}
	bx r0
	.align 2, 0
