	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _081F796C @ =0x0000F422
	bl Video_GetAuxSprite
	ldr r0, _081F7970 @ =0x03000200
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F796C: .4byte 0x0000F422
_081F7970: .4byte 0x03000200
