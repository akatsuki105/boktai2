	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl EntityC814_InitMover
	adds r0, r4, #0
	bl EntityC814_InitSprite
	adds r0, r4, #0
	bl EntityC814_InitTile
	adds r0, r4, #0
	bl EntityC814_InitNavAgent
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
