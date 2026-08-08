	push {r4, r5, r6, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	movs r2, #0
	ldrsh r3, [r1, r2]
	movs r4, #0
	ldrsh r2, [r0, r4]
	subs r3, r3, r2
	movs r2, #4
	ldrsh r1, [r1, r2]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r2, r1, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, r0
	cmp r4, #0
	bne _0821BD8A
	strb r4, [r5]
	strh r4, [r6]
	b _0821BD9C
_0821BD8A:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	strb r0, [r5]
	adds r0, r4, #0
	bl Sqrt
	strh r0, [r6]
_0821BD9C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
