	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081EE294 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r4, #0x18]
	ldr r0, _081EE298 @ =0x0000069C
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _081EE29C @ =0x030001CC
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081EE294: .4byte 0x00001C1E
_081EE298: .4byte 0x0000069C
_081EE29C: .4byte 0x030001CC
