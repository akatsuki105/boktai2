	push {r4, r5, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x98
	bl Hitbox_Unregister
	adds r4, #0xf8
	movs r5, #3
_0805A6D8:
	adds r0, r4, #0
	bl AuxSprite_Remove
	subs r5, #1
	adds r4, #0x2c
	cmp r5, #0
	bge _0805A6D8
	pop {r4, r5}
	pop {r1}
	bx r1
