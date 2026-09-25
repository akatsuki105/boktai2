	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DD1E4 @ =0x0000E74B
	bl Video_GetAuxSprite
	ldr r0, _080DD1E8 @ =0x0000922E
	ldr r1, _080DD1EC @ =0x0000871C
	bl GetFile
	str r0, [r4, #0x34]
	ldr r0, _080DD1F0 @ =0x00000F68
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _080DD1F4 @ =0x0300016C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1E4: .4byte 0x0000E74B
_080DD1E8: .4byte 0x0000922E
_080DD1EC: .4byte 0x0000871C
_080DD1F0: .4byte 0x00000F68
_080DD1F4: .4byte 0x0300016C
