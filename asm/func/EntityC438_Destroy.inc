	push {lr}
	adds r0, #0x1c
	bl MainSprite_Remove
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
