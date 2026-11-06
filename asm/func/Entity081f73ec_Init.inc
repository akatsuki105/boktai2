	movs r1, #0
	str r1, [r0, #0x38]
	ldr r1, _081F73E8 @ =0x030001FC
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081F73E8: .4byte 0x030001FC
