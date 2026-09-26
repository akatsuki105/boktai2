	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x28
	movs r5, #0x2f
_080DDCA8:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _080DDCA8
	movs r1, #0
	ldr r0, _080DDCC4 @ =0x03000174
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080DDCC4: .4byte 0x03000174
