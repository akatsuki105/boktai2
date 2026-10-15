	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x38
	movs r5, #4
_080C1F44:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080C1F44
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
