	push {lr}
	ldr r1, _08061BA8 @ =0x000006AC
	adds r0, r0, r1
	bl FUN_0822a4e0
	pop {r0}
	bx r0
	.align 2, 0
_08061BA8: .4byte 0x000006AC
