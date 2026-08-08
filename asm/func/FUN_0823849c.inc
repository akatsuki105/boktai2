	push {lr}
	ldr r0, _082384AC @ =0x03000820
	ldr r0, [r0]
	bl FUN_08238354
	pop {r0}
	bx r0
	.align 2, 0
_082384AC: .4byte 0x03000820
