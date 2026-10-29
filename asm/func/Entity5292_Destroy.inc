	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x2c
	movs r5, #0xf
_080ACF7C:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x64
	subs r5, #1
	cmp r5, #0
	bge _080ACF7C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
