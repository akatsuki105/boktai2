	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081EEB20 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x18]
	movs r0, #0x97
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _081EEB24 @ =0x030001D4
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081EEB20: .4byte 0x00001C1A
_081EEB24: .4byte 0x030001D4
