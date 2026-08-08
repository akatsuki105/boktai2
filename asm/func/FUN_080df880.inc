	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xf4
	adds r4, r6, #0
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	pop {r4, r5, r6}
	pop {r0}
	bx r0
