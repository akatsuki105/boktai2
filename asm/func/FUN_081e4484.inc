	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _081E44AC @ =0x00000E4C
	adds r4, r6, r0
	movs r5, #0x11
_081E448E:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E448E
	ldr r1, _081E44B0 @ =0x0000150C
	adds r0, r6, r1
	bl MainSprite_Remove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E44AC: .4byte 0x00000E4C
_081E44B0: .4byte 0x0000150C
