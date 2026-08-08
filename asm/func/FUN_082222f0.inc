	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x78
	movs r5, #7
_082222F8:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _082222F8
	pop {r4, r5}
	pop {r0}
	bx r0
