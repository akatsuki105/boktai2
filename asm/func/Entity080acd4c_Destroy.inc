	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #7
_080ACC90:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080ACC90
	movs r1, #0
	ldr r0, _080ACCAC @ =0x03002C54
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080ACCAC: .4byte 0x03002C54
