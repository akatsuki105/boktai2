	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081EB2CC @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x1c]
	ldr r0, _081EB2D0 @ =0x0000922E
	ldr r1, _081EB2D4 @ =0x0000D1B8
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081EB2CC: .4byte 0x00001C1A
_081EB2D0: .4byte 0x0000922E
_081EB2D4: .4byte 0x0000D1B8
