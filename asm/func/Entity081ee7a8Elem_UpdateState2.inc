	push {r4, lr}
	adds r4, r0, #0
	bl AuxSprite_Remove
	adds r1, r4, #0
	adds r1, #0x6c
	movs r0, #0xff
	strb r0, [r1]
	adds r4, #0x58
	movs r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
