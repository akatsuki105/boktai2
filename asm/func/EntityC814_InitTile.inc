	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xa8
	adds r1, r5, #0
	adds r1, #0x24
	adds r0, r4, #0
	bl Map_InitMoverTile
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl Mover_SetCollision
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
