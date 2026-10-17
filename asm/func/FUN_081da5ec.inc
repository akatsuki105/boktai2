	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #4
_081DA5F4:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DA5F4
	pop {r4, r5}
	pop {r0}
	bx r0
