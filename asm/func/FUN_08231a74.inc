	ldr r0, _08231A7C @ =0x03000758
	ldr r0, [r0, #0xc]
	adds r0, #4
	bx lr
	.align 2, 0
_08231A7C: .4byte 0x03000758
