	push {r4, lr}
	bl FUN_08238138
	ldr r0, _08238498 @ =0x03000820
	ldr r4, [r0]
	adds r0, r4, #0
	bl FUN_0823840c
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08238498: .4byte 0x03000820
