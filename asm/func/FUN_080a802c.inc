	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x70
	ldr r0, _080A807C @ =0x00001C1A
	bl GetParticleGroup
	adds r1, r0, #0
	adds r5, r6, #0
	adds r5, #0x98
	str r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #0xa
	bl FUN_0822dafc
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	ldrh r0, [r4, #0x1a]
	adds r0, #0xd7
	strh r0, [r4, #0x1a]
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A807C: .4byte 0x00001C1A
