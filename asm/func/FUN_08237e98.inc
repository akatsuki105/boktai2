	push {lr}
	ldr r1, _08237EAC @ =0x030046D4
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	bl FUN_08237dcc
	pop {r0}
	bx r0
	.align 2, 0
_08237EAC: .4byte 0x030046D4
