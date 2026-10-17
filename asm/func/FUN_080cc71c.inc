	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080CC774 @ =0x00001C1C
	bl GetParticleGroup
	adds r1, r0, #0
	ldr r0, _080CC778 @ =0x0000064C
	adds r6, r5, r0
	str r1, [r6]
	adds r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl Particle_Add
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #4
	bl Particle_SetFrame
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r2, #0
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _080CC77C @ =0x00000679
	adds r5, r5, r0
	strb r2, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC774: .4byte 0x00001C1C
_080CC778: .4byte 0x0000064C
_080CC77C: .4byte 0x00000679
