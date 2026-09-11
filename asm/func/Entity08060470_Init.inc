	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08060468 @ =0x03000134
	str r6, [r0]
	movs r0, #0
	str r0, [r6, #0x1c]
	ldr r0, _0806046C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0806044E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080602f4
	adds r4, #1
	adds r5, #0x38
	cmp r4, #0xf
	ble _0806044E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08060468: .4byte 0x03000134
_0806046C: .4byte 0x00001C1E
