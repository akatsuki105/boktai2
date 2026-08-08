	ldr r0, _08241060 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08241064 @ =0x00000928
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08241060: .4byte 0x030046A0
_08241064: .4byte 0x00000928
