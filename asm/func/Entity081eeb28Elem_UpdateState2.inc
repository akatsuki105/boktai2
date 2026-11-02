	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldrh r0, [r5, #0x2c]
	cmp r0, #0
	beq _081EE982
	movs r0, #0
	strh r0, [r5, #0x2c]
_081EE982:
	ldr r0, _081EE9B8 @ =0x030001D4
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0x2b
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0x2a
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl Particle_Remove
	movs r0, #0xff
	strb r0, [r6]
	strh r4, [r5, #0x28]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081EE9B8: .4byte 0x030001D4
