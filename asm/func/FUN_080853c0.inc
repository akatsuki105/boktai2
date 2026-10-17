	push {r4, r5, r6, lr}
	movs r1, #0x81
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r6, #4
	rsbs r6, r6, #0
	movs r5, #6
_080853CE:
	ldr r0, _08085404 @ =0x00001C1C
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	bl Particle_Add
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl Particle_SetOffset
	movs r0, #0xff
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	subs r5, #1
	adds r4, #0x28
	cmp r5, #0
	bge _080853CE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085404: .4byte 0x00001C1C
