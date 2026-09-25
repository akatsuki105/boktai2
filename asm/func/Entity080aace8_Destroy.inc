	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x1c
	bl MainSprite_Remove
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080AA90A:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080AA90A
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AA938
	adds r4, r6, #0
	adds r4, #0xe4
	movs r5, #1
_080AA92A:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080AA92A
_080AA938:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
