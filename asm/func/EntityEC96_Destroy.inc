	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x30
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_082342a8
	adds r0, r4, #0
	adds r0, #0xac
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
