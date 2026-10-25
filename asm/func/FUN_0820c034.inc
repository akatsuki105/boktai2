	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0xd0
	adds r0, r4, #0
	movs r1, #2
	bl SpriteHolder_ClearFlags
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x40
	movs r3, #0
	bl SpriteHolder_SetAffine
	pop {r4}
	pop {r0}
	bx r0
