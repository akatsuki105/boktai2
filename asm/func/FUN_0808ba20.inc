	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	mov r8, r1
	adds r4, r2, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r6, r4, #1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
