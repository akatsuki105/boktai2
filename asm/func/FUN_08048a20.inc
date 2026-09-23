	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl FUN_080489c4
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldrb r3, [r5, #6]
	adds r0, r4, #0
	bl Video_DrawCharNarrow
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08048998
	movs r1, #0
	strb r1, [r5, #0x13]
	pop {r4, r5}
	pop {r1}
	bx r1
