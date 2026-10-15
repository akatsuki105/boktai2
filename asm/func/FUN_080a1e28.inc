	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x32]
	adds r2, r0, #1
	strh r2, [r3, #0x32]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A1E48
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x30]
	b _080A1E70
_080A1E48:
	ldrh r0, [r3, #0x28]
	ldrh r4, [r3, #0x18]
	adds r0, r0, r4
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x2a]
	ldrh r4, [r3, #0x1a]
	adds r0, r0, r4
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x2c]
	ldrh r4, [r3, #0x1c]
	adds r0, r0, r4
	strh r0, [r3, #0x1c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl Particle_SetFrame
_080A1E70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
