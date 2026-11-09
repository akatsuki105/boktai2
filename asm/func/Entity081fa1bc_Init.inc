	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081FA220 @ =0x08252698
	bl HashName
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetParticleGroup
	adds r1, r0, #0
	str r1, [r4, #0x40]
	cmp r1, #0
	beq _081FA224
	adds r0, r5, #0
	movs r2, #0
	bl Particle_Add
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x4c]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r1, [r4, #0x40]
	adds r0, r5, #0
	movs r2, #0x20
	bl Particle_SetPose
	movs r0, #0
	strb r0, [r5, #0xf]
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	movs r0, #0
	b _081FA228
	.align 2, 0
_081FA220: .4byte 0x08252698
_081FA224:
	movs r0, #1
	rsbs r0, r0, #0
_081FA228:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
