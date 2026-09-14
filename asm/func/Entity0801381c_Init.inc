	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08013814 @ =0x03000050
	str r4, [r0]
	movs r0, #0
	str r0, [r4, #0x1c]
	ldr r0, _08013818 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x18]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08013814: .4byte 0x03000050
_08013818: .4byte 0x00001C1A
