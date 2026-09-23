	push {lr}
	ldr r0, _08049E68 @ =0x085AB548
	bl FUN_08049e30
	pop {r1}
	bx r1
	.align 2, 0
_08049E68: .4byte 0x085AB548
