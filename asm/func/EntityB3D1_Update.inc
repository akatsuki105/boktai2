	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080bfb74
	adds r0, r4, #0
	bl FUN_080c04d8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
