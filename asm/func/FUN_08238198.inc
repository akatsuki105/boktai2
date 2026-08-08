	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08238158
	ldr r0, [r4, #4]
	str r5, [r4, #4]
	str r5, [r0]
	str r4, [r5]
	str r0, [r5, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
