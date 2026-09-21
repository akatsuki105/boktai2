	push {lr}
	bl Entity08004fac_FreeAllNodes
	ldr r1, _08004F98 @ =0x03000024
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08004F98: .4byte 0x03000024
