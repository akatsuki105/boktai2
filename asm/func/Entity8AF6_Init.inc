	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A5DDC @ =0x03002C4C
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A5DDC: .4byte 0x03002C4C
