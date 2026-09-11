	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc4
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x58
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_080138fc
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
