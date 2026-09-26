	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x13
	ldrsb r1, [r5, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r4, r0
	bl Particle_Remove
	movs r0, #0
	strb r0, [r5, #0x12]
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x18
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0x13]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
