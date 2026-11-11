	push {lr}
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r0, r1
	asrs r0, r0, #0xc
	subs r0, #1
	movs r1, #2
	cmp r0, #3
	bhi _080155DC
	adds r1, r0, #0
_080155DC:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
