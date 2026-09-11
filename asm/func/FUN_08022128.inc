	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldrh r1, [r6]
	ldrb r2, [r6, #2]
	bl FUN_080220bc
	adds r5, r0, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r1, #1
	subs r4, r1, r2
	cmp r5, #0
	beq _08022164
	adds r1, r5, #6
	adds r3, r1, r4
	ldrb r1, [r3]
	cmp r1, #3
	bhi _08022164
	adds r2, r1, #0
	lsls r2, r2, #2
	lsls r1, r4, #4
	adds r2, r2, r1
	adds r1, r5, #0
	adds r1, #8
	adds r1, r1, r2
	str r6, [r1]
	ldrb r1, [r3]
	adds r1, #1
	strb r1, [r3]
_08022164:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
