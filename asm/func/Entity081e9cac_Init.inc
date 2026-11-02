	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	ldr r1, _081E9C9C @ =0x00002D41
	bl Video_GetAuxSprite
	ldr r0, _081E9CA0 @ =0x0000922E
	ldr r1, _081E9CA4 @ =0x0000D6C8
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x18]
	ldr r1, _081E9CA8 @ =0x030001B4
	str r4, [r1]
	movs r1, #0
	str r1, [r4, #0x38]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C9C: .4byte 0x00002D41
_081E9CA0: .4byte 0x0000922E
_081E9CA4: .4byte 0x0000D6C8
_081E9CA8: .4byte 0x030001B4
