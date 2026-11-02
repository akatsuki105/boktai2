	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	adds r4, #0x1c
	adds r0, r4, #0
	bl Mover_Unlink
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
