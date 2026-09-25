	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DB510 @ =0x00001C1B
	bl Video_GetAuxSprite
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _080DB514 @ =0x0000922E
	ldr r1, _080DB518 @ =0x00003DC2
	bl GetFile
	str r0, [r4, #0x34]
	ldr r0, _080DB51C @ =0x03000160
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DB510: .4byte 0x00001C1B
_080DB514: .4byte 0x0000922E
_080DB518: .4byte 0x00003DC2
_080DB51C: .4byte 0x03000160
