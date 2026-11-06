	push {r4, lr}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0xa8
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
