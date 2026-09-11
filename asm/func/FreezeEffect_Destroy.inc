	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x70
	bl FUN_0822dabc
	adds r4, #0xa0
	movs r5, #7
_080A7F72:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A7F72
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
