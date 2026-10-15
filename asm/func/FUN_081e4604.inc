	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r7, #3
	movs r0, #3
	bl FUN_081e45e4
	adds r6, r0, #0
	cmp r5, #0
	ble _081E463C
_081E461C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	adds r1, r0, r7
	strh r1, [r6]
	adds r6, #2
	muls r0, r5, r0
	subs r4, r4, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	cmp r5, #0
	bgt _081E461C
_081E463C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
