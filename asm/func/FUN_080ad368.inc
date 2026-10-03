	push {r4, r5, lr}
	ldr r1, _080AD384 @ =0x00000564
	adds r4, r0, r1
	movs r5, #0x1f
_080AD370:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080AD370
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD384: .4byte 0x00000564
