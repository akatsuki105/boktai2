	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08016654 @ =0x03002B44
	str r4, [r0]
	ldr r0, _08016658 @ =0x0000922E
	ldr r1, _0801665C @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016654: .4byte 0x03002B44
_08016658: .4byte 0x0000922E
_0801665C: .4byte 0x0000931E
