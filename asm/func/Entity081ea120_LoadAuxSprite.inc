	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _081EA108 @ =0x0000863A
	bl Video_GetAuxSprite
	ldr r0, _081EA10C @ =0x0000922E
	ldr r1, _081EA110 @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081EA108: .4byte 0x0000863A
_081EA10C: .4byte 0x0000922E
_081EA110: .4byte 0x0000931E
