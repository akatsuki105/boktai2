	push {r4, lr}
	adds r3, r1, #0
	movs r4, #8
	ldrsh r1, [r2, r4]
	str r1, [r0, #0x68]
	cmp r1, #0
	bne _080221F6
	adds r0, r3, #0
	movs r1, #1
	bl FUN_08022488
_080221F6:
	pop {r4}
	pop {r0}
	bx r0
