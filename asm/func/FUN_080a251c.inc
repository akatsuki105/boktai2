	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A2542
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	b _080A25C0
_080A2542:
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r0, _080A2584 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r0, #0
	ldrb r2, [r5]
	lsrs r2, r2, #2
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl Particle_SetFrame
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A2588
	asrs r0, r0, #4
	b _080A258E
	.align 2, 0
_080A2584: .4byte 0x00001C1E
_080A2588:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A258E:
	strh r0, [r4, #0x2c]
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25A0
	asrs r0, r0, #4
	b _080A25A6
_080A25A0:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25A6:
	strh r0, [r4, #0x2e]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25B8
	asrs r0, r0, #4
	b _080A25BE
_080A25B8:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25BE:
	strh r0, [r4, #0x30]
_080A25C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
