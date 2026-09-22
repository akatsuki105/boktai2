	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	bl Hitbox_Unregister
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	adds r0, r4, #0
	bl FUN_08022b04
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r4, r1
	bl AuxSprite_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
