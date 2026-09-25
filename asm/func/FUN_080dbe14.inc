	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DBE30 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x1c]
	ldr r0, _080DBE34 @ =0x0000922E
	ldr r1, _080DBE38 @ =0x0000D1B8
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DBE30: .4byte 0x00001C1A
_080DBE34: .4byte 0x0000922E
_080DBE38: .4byte 0x0000D1B8
