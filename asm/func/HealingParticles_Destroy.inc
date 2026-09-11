	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x74
	movs r5, #7
_080A91C4:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080A91C4
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
