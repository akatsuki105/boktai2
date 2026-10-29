	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x77
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080C1A7C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5, #0x78]
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xa4
	adds r4, r5, #0
	adds r4, #0x7c
	movs r7, #3
_080C1A3C:
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #1
	bl Particle_Add
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #0x11
	bl Particle_SetPose
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	movs r0, #0
	strb r0, [r6]
	adds r6, #0x30
	adds r4, #0x30
	subs r7, #1
	cmp r7, #0
	bge _080C1A3C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1A7C: .4byte 0x00001C1E
