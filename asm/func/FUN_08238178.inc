	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08238158
	adds r1, r5, #0
	adds r1, #0x20
	ldr r0, [r5, #0x20]
	str r0, [r4]
	str r1, [r4, #4]
	str r4, [r0, #4]
	str r4, [r5, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0
