	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807f8d0
	movs r1, #0x98
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
