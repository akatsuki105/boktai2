	ldr r1, _081F7440 @ =0x030001FC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F7440: .4byte 0x030001FC
