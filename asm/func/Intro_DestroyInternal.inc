	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x94
	bl MainSprite_Remove
	adds r0, r4, #0
	adds r0, #0xf4
	bl MainSprite_Remove
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0xcd
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	pop {r4}
	pop {r0}
	bx r0
