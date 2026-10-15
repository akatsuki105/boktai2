	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrh r2, [r4, #0x2e]
	lsrs r2, r2, #1
	adds r2, #0xc
	bl Particle_SetFrame
	ldrh r0, [r4, #0x1a]
	adds r0, #0xa
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _080ACC54
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
_080ACC54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
