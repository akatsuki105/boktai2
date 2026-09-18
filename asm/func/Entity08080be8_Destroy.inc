	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0xd4
	movs r5, #3
_080809FA:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080809FA
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
