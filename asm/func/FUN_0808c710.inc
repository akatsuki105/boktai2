	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x39
	ldrb r0, [r5]
	adds r2, r0, #1
	strb r2, [r5]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808C738
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x38
	movs r0, #0
	strb r0, [r1]
	b _0808C766
_0808C738:
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x1b
	adds r2, #2
	adds r0, r4, #0
	bl Particle_SetFrame
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x32]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrb r1, [r5]
	movs r0, #7
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x38
	cmp r0, #0
	bne _0808C766
	adds r0, r2, #1
	strh r0, [r4, #0x32]
_0808C766:
	ldrb r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
