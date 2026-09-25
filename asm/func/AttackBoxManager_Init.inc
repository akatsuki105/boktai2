	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ddab4
	ldr r0, _080DDACC @ =0x03000170
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DDACC: .4byte 0x03000170
