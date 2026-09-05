	ldr r1, _08001A90 @ =0x00000642
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
_08001A90: .4byte 0x00000642
