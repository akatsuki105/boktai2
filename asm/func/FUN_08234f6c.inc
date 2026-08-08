	adds r1, r0, #0
	ldr r0, _08234F7C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08234F7C: .4byte 0x030046A4
