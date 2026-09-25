	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #3
_080AC4BC:
	ldrh r0, [r4, #0x36]
	cmp r0, #0
	beq _080AC4C8
	adds r0, r4, #0
	bl FUN_080ac46c
_080AC4C8:
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _080AC4BC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
