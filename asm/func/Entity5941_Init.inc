	movs r1, #0
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	ldr r1, _0807F5EC @ =0x03002BF8
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0807F5EC: .4byte 0x03002BF8
