	push {r4, r5, lr}
	adds r1, r0, #0
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r4, r1, r2
	movs r5, #0x1f
_08017DCC:
	adds r2, r4, #0
	adds r2, #0x14
	ldrb r1, [r4]
	cmp r1, #0
	beq _08017DE0
	adds r0, r2, #0
	bl Particle_Remove
	movs r1, #0
	strb r1, [r4]
_08017DE0:
	subs r5, #1
	adds r4, #0x3c
	cmp r5, #0
	bge _08017DCC
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
