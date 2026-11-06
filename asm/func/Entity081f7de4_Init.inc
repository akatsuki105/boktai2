	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _081F7DDC @ =0x0000354D
	bl Video_GetAuxSprite
	ldr r0, _081F7DE0 @ =0x03000204
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F7DDC: .4byte 0x0000354D
_081F7DE0: .4byte 0x03000204
