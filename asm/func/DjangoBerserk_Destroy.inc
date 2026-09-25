	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	bl MainSprite_Remove
	adds r4, #0xf8
	movs r5, #0xf
_0807FE32:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _0807FE32
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
