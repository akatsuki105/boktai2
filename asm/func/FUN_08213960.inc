	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x98
	bl MainSprite_Remove
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Destroy
	pop {r4}
	pop {r0}
	bx r0
