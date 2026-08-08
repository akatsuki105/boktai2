	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _08236418
	adds r0, r2, #0
	bl FUN_082363c4
	b _0823641E
_08236418:
	adds r0, r2, #0
	bl FUN_08236388
_0823641E:
	pop {r0}
	bx r0
	.align 2, 0
