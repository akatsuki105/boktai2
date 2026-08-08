	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x3c
	movs r5, #1
_080DF71C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x5c
	subs r5, #1
	cmp r5, #0
	bge _080DF71C
	pop {r4, r5}
	pop {r0}
	bx r0
