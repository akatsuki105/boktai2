	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r0, #0
	strb r2, [r5]
	strb r0, [r5, #1]
	strb r0, [r5, #2]
	strb r0, [r5, #3]
	strh r0, [r5, #6]
	str r0, [r5, #0x20]
	adds r0, r5, #0
	adds r0, #0x24
	adds r3, #0x20
	adds r1, r3, #0
	movs r2, #1
	bl AuxSprite_Add
	adds r4, r5, #0
	adds r4, #0x50
	adds r1, r5, #0
	adds r1, #0x40
	adds r0, r4, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
