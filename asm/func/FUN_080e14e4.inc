	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081eaf6c
	ldr r0, _080E14F8 @ =0x03000180
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080E14F8: .4byte 0x03000180
