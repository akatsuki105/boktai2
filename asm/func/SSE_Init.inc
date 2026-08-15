	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _082473D0 @ =0x030026B0
	str r4, [r0]
	movs r0, #0
	str r0, [r4, #0x20]
	ldr r0, _082473D4 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x18]
	ldr r0, _082473D8 @ =0x0000922E
	ldr r1, _082473DC @ =0x0000D1B8
	bl GetFile
	str r0, [r4, #0x1c]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_082473D0: .4byte 0x030026B0
_082473D4: .4byte 0x00001C1A
_082473D8: .4byte 0x0000922E
_082473DC: .4byte 0x0000D1B8
