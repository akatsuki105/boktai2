	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ac18c
	adds r0, r4, #0
	bl FUN_080abf9c
	adds r1, r4, #0
	adds r1, #0x98
	ldrb r1, [r1]
	cmp r1, #0
	bne _080AC308
	adds r1, r4, #0
	adds r1, #0x9e
	ldrb r1, [r1]
	cmp r1, #0
	bne _080AC308
	adds r0, r4, #0
	bl KillEntity
_080AC308:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
