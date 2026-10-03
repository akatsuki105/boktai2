	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	strb r1, [r4, #1]
	strb r2, [r4, #2]
	bl FUN_0808f98c
	strb r0, [r4, #3]
	strb r5, [r4, #7]
	pop {r4, r5}
	pop {r0}
	bx r0
