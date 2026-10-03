	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0xac
	lsls r0, r0, #3
	adds r6, r4, r0
	ldr r0, _080AD3E0 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6]
	ldr r0, _080AD3E4 @ =0x00000BE4
	adds r4, r4, r0
	movs r0, #0
	strb r0, [r4]
	movs r5, #0
	movs r7, #4
	rsbs r7, r7, #0
_080AD3A8:
	movs r0, #0x34
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #4
	adds r4, r6, r4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl Particle_SetOffset
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r4, #0x30
	movs r0, #0
	strb r0, [r4]
	adds r5, #1
	cmp r5, #0x1f
	ble _080AD3A8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD3E0: .4byte 0x00001C1E
_080AD3E4: .4byte 0x00000BE4
