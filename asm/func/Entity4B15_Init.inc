	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0801A04C @ =0x03000090
	str r5, [r0]
	ldr r0, _0801A050 @ =0x00001C1A
	bl GetParticleGroup
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	movs r1, #0
	movs r0, #0x78
	strh r0, [r5, #0x18]
	movs r0, #0x50
	strh r0, [r5, #0x1a]
	strh r1, [r5, #0x1c]
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_0801A034:
	adds r0, r5, #0
	adds r1, r4, #0
	bl Entity4B15Elem_Init
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _0801A034
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A04C: .4byte 0x03000090
_0801A050: .4byte 0x00001C1A
