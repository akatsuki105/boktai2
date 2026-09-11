	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0821c918
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
