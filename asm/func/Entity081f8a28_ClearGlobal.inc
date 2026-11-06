	ldr r1, _081F8A7C @ =0x03000208
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F8A7C: .4byte 0x03000208
