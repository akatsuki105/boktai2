	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, r0, r1
	ldr r1, _08241040 @ =0x00000255
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08241040: .4byte 0x00000255
