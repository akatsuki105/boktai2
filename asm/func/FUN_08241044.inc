	ldr r0, _08241050 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08241050: .4byte 0x030046A0
