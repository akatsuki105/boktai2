	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _0820E76C
	adds r0, r1, #0
	bl MainSprite_Remove
_0820E76C:
	pop {r0}
	bx r0
